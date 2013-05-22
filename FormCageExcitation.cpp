#include "FormCageExcitation.h"



FormCageExcitation::FormCageExcitation(cageExcitation *cageExci, int mode, QWidget *parent) :
    FormElementBase(cageExci,mode,parent)
{
    this->cageExci=cageExci;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Cage Excitation");
    groupGeo->setCheckable(true);
    groupGeo->setChecked(cageExci->isCreate());
    connect(groupGeo,SIGNAL(toggled(bool)),cageExci,SLOT(setCreate(bool)));

    QFormLayout * layout = new QFormLayout;

    insideOutsideWidget = new QComboBox();
    insideOutsideWidget->addItems(QStringList() << "Inside" << "Outside");
    layout->addRow("Inside/Outside:",insideOutsideWidget);

    nbFacesWidget = new QSpinBox();
    layout->addRow("Nombres Faces:",nbFacesWidget);
    this->connect(nbFacesWidget, SIGNAL(valueChanged(int)), this, SLOT(actualiseFormulaire(int)));

    typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "onde_plane" << "TE10" << "TM10" << "fichier_excitation");
    layout->addRow("Type d'excitation:",typeWidget);
    this->connect(typeWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(manageFormulaire(int)));

    formFace1 = new QWidget();

    QFormLayout * layoutFormFace1 = new QFormLayout;
    layoutFormFace1->setMargin(0);

    modeWidget = new QComboBox();
    modeWidget->addItems(QStringList() << "OndeplaneX" << "OndeplaneY" << "GuideTE10X" << "GuideTE10Y");
    layoutFormFace1->addRow("Mode d'excitation:",modeWidget);

    hauteurWidget = new QSpinBox();
    layoutFormFace1->addRow("Hauteur:",hauteurWidget);

    sensPropaWidget = new QComboBox();
    sensPropaWidget->addItems(QStringList() << "Z_croissant" << "Z_decroissant");
    layoutFormFace1->addRow("Sens propagation:",sensPropaWidget);

    formFace1->setLayout(layoutFormFace1);
    layout->addRow(formFace1);

    formFaceDif1 = new QWidget();
    QFormLayout* layoutFormFaceDif1 = new QFormLayout;
    layoutFormFaceDif1->setMargin(0);

    pointRefWidget = new FormCoordonnees(cageExci->GetPointReference());
    layoutFormFaceDif1->addRow("Point référence:",pointRefWidget);

    theta0Widget = new QDoubleSpinBox();
    layoutFormFaceDif1->addRow("Theta0:",theta0Widget);

    phi0Widget = new QDoubleSpinBox();
    layoutFormFaceDif1->addRow("Phi0:",phi0Widget);

    psi0Widget = new QDoubleSpinBox();
    layoutFormFaceDif1->addRow("Psi0:",psi0Widget);

    formFaceDif1->setLayout(layoutFormFaceDif1);

    layout->addRow(formFaceDif1);

    formType4 = new QWidget();
    QFormLayout * layoutFormType4 = new QFormLayout;
    layoutFormType4->setMargin(0);

    modulationAmplitudeWidget = new QDoubleSpinBox();
    layoutFormType4->addRow("Modulation Amplitude:",modulationAmplitudeWidget);

    modulationPhaseWidget = new QDoubleSpinBox();
    layoutFormType4->addRow("Modulation Phase:",modulationPhaseWidget);

    nomFichierWidget = new QLineEdit();
    layoutFormType4->addRow("Nom Fichier:",nomFichierWidget);

    formType4->setLayout(layoutFormType4);
    layout->addRow(formType4);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    manageFormulaire(typeWidget->currentIndex());

    init();
}

void FormCageExcitation::valider()
{
    FormElementBase::valider();
    cageExci->SetTypeExcitation(typeWidget->currentIndex());
    cageExci->SetNbFaces(nbFacesWidget->value());
    cageExci->SetInsideOutside(insideOutsideWidget->currentIndex());
    cageExci->SetModeExcitation(modeWidget->currentIndex());
    cageExci->SetHauteur(hauteurWidget->value());
    cageExci->SetSensPropagation(sensPropaWidget->currentIndex());
    cageExci->SetPointReference(pointRefWidget->getCoord());
    cageExci->SetTheta0(theta0Widget->value());
    cageExci->SetPhi0(phi0Widget->value());
    cageExci->SetPsi0(psi0Widget->value());
    cageExci->SetModulationAmplitude(modulationAmplitudeWidget->value());
    cageExci->SetModulationPhase(modulationPhaseWidget->value());
    cageExci->SetNomFichier(nomFichierWidget->text().toStdString());

    emit elementValide(this->cageExci);
}

void FormCageExcitation::reset()
{
    FormElementBase::reset();
    this->cageExci = new cageExcitation();
    setElement(this->cageExci);
    init();
}

void FormCageExcitation::manageFormulaire(int val)
{
    if (val==3)
    {
        formType4->setVisible(true);
        formFace1->setVisible(false);
        formFaceDif1->setVisible(false);
    }
    else
    {
        if (nbFacesWidget->value()==1)
        {
            formType4->setVisible(false);
            formFace1->setVisible(true);
            formFaceDif1->setVisible(false);
        }
        else
        {
            formType4->setVisible(false);
            formFace1->setVisible(false);
            formFaceDif1->setVisible(true);
        }
    }
}

void FormCageExcitation::actualiseFormulaire(int val)
{
    manageFormulaire(typeWidget->currentIndex());
}

void FormCageExcitation::init()
{
    FormElementBase::init();
    nbFacesWidget->setValue(cageExci->GetNbFaces());
    typeWidget->setCurrentIndex(cageExci->GetTypeExcitation());
    insideOutsideWidget->setCurrentIndex(cageExci->GetInsideOutside());
    modeWidget->setCurrentIndex(cageExci->GetModeExcitation());
    hauteurWidget->setValue(cageExci->GetHauteur());
    sensPropaWidget->setCurrentIndex(cageExci->GetSensPropagation());
    pointRefWidget->setCoordonnee(cageExci->GetPointReference());
    theta0Widget->setValue(cageExci->GetTheta0());
    phi0Widget->setValue(cageExci->GetPhi0());
    psi0Widget->setValue(cageExci->GetPsi0());
    modulationPhaseWidget->setValue(cageExci->GetModulationPhase());
    modulationAmplitudeWidget->setValue(cageExci->GetModulationAmplitude());
    nomFichierWidget->setText(QString(cageExci->GetNomFichier().c_str()));
}
