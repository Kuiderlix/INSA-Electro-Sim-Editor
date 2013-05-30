#include "FormCageExcitation.h"



FormCageExcitation::FormCageExcitation(cageExcitation *cageExci, QWidget *parent) :
    FormElementBase(cageExci,parent)
{
    this->cageExci=cageExci;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    group = new QGroupBox("Cage Excitation");
    group->setCheckable(true);
    group->setChecked(cageExci->isCreate());
    connect(group,SIGNAL(toggled(bool)),this,SLOT(changeCreate(bool)));

    QFormLayout * layout = new QFormLayout;

    insideOutsideWidget = new QComboBox();
    insideOutsideWidget->addItems(QStringList() << "Inside" << "Outside");
    connect(insideOutsideWidget,SIGNAL(currentIndexChanged(int)),this,SLOT(changeBackgroundRed()));
    layout->addRow("Inside/Outside:",insideOutsideWidget);

    nbFacesWidget = new QSpinBox();
    layout->addRow("Nombres Faces:",nbFacesWidget);
    connect(nbFacesWidget,SIGNAL(valueChanged(int)),this,SLOT(changeBackgroundRed()));
    this->connect(nbFacesWidget, SIGNAL(valueChanged(int)), this, SLOT(actualiseFormulaire(int)));

    typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "onde_plane" << "TE10" << "TM10" << "fichier_excitation");
    layout->addRow("Type d'excitation:",typeWidget);
    connect(typeWidget,SIGNAL(currentIndexChanged(int)),this,SLOT(changeBackgroundRed()));
    this->connect(typeWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(manageFormulaire(int)));

    formFace1 = new QWidget();

    QFormLayout * layoutFormFace1 = new QFormLayout;
    layoutFormFace1->setMargin(0);

    modeWidget = new QComboBox();
    modeWidget->addItems(QStringList() << "OndeplaneX" << "OndeplaneY" << "GuideTE10X" << "GuideTE10Y");
    connect(modeWidget,SIGNAL(currentIndexChanged(int)),this,SLOT(changeBackgroundRed()));
    layoutFormFace1->addRow("Mode d'excitation:",modeWidget);

    hauteurWidget = new QSpinBox();
    connect(hauteurWidget,SIGNAL(valueChanged(int)),this,SLOT(changeBackgroundRed()));
    layoutFormFace1->addRow("Hauteur:",hauteurWidget);

    sensPropaWidget = new QComboBox();
    sensPropaWidget->addItems(QStringList() << "Z_croissant" << "Z_decroissant");
    connect(sensPropaWidget,SIGNAL(currentIndexChanged(int)),this,SLOT(changeBackgroundRed()));
    layoutFormFace1->addRow("Sens propagation:",sensPropaWidget);

    formFace1->setLayout(layoutFormFace1);
    layout->addRow(formFace1);

    formFaceDif1 = new QWidget();
    QFormLayout* layoutFormFaceDif1 = new QFormLayout;
    layoutFormFaceDif1->setMargin(0);

    pointRefWidget = new FormCoordonnees(cageExci->GetPointReference());
    connect(pointRefWidget,SIGNAL(coordonneeChanged(coordonnee)),this,SLOT(changeBackgroundRed()));
    layoutFormFaceDif1->addRow("Point référence:",pointRefWidget);

    theta0Widget = new QDoubleSpinBox();
    connect(theta0Widget,SIGNAL(valueChanged(double)),this,SLOT(changeBackgroundRed()));
    layoutFormFaceDif1->addRow("Theta0:",theta0Widget);

    phi0Widget = new QDoubleSpinBox();
    connect(phi0Widget,SIGNAL(valueChanged(double)),this,SLOT(changeBackgroundRed()));
    layoutFormFaceDif1->addRow("Phi0:",phi0Widget);

    psi0Widget = new QDoubleSpinBox();
    connect(psi0Widget,SIGNAL(valueChanged(double)),this,SLOT(changeBackgroundRed()));
    layoutFormFaceDif1->addRow("Psi0:",psi0Widget);

    formFaceDif1->setLayout(layoutFormFaceDif1);

    layout->addRow(formFaceDif1);

    formType4 = new QWidget();
    QFormLayout * layoutFormType4 = new QFormLayout;
    layoutFormType4->setMargin(0);

    modulationAmplitudeWidget = new QDoubleSpinBox();
    connect(modulationAmplitudeWidget,SIGNAL(valueChanged(double)),this,SLOT(changeBackgroundRed()));
    layoutFormType4->addRow("Modulation Amplitude:",modulationAmplitudeWidget);

    modulationPhaseWidget = new QDoubleSpinBox();
    connect(modulationPhaseWidget,SIGNAL(valueChanged(double)),this,SLOT(changeBackgroundRed()));
    layoutFormType4->addRow("Modulation Phase:",modulationPhaseWidget);

    nomFichierWidget = new QLineEdit();
    connect(nomFichierWidget,SIGNAL(textChanged(QString)),this,SLOT(changeBackgroundRed()));
    layoutFormType4->addRow("Nom Fichier:",nomFichierWidget);

    formType4->setLayout(layoutFormType4);
    layout->addRow(formType4);

    layout->addRow(getWidgetElementBase());


    connect(formCoord1,SIGNAL(coordonneeChanged(coordonnee)),this,SLOT(changeBackgroundRed()));
    connect(formCoord2,SIGNAL(coordonneeChanged(coordonnee)),this,SLOT(changeBackgroundRed()));

    if (this->cageExci->isCreate())
    {
        boutonValider->setText("Modifier");
    }

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

    manageFormulaire(typeWidget->currentIndex());

    init();
}

void FormCageExcitation::valider()
{
    //on enregistre les données dans l'objet
    FormElementBase::valider();
    cageExci->setCreate(true);
    cageExci->SetTypeExcitation(typeWidget->currentIndex()+1);
    cageExci->SetNbFaces(nbFacesWidget->value());
    cageExci->SetInsideOutside(insideOutsideWidget->currentIndex()+1);
    cageExci->SetModeExcitation(modeWidget->currentIndex());
    cageExci->SetHauteur(hauteurWidget->value());
    cageExci->SetSensPropagation(sensPropaWidget->currentIndex()+1);
    cageExci->SetPointReference(pointRefWidget->getCoord());
    cageExci->SetTheta0(theta0Widget->value());
    cageExci->SetPhi0(phi0Widget->value());
    cageExci->SetPsi0(psi0Widget->value());
    cageExci->SetModulationAmplitude(modulationAmplitudeWidget->value());
    cageExci->SetModulationPhase(modulationPhaseWidget->value());
    cageExci->SetNomFichier(nomFichierWidget->text().toStdString());

    // on remet les champs du formulaire dans leur couleur normal
    changeBackgroundNormal(nbFacesWidget);
    changeBackgroundNormal(typeWidget);
    changeBackgroundNormal(insideOutsideWidget);
    changeBackgroundNormal(modeWidget);
    changeBackgroundNormal(hauteurWidget);
    changeBackgroundNormal(sensPropaWidget);
    changeBackgroundNormal(pointRefWidget);
    changeBackgroundNormal(theta0Widget);
    changeBackgroundNormal(phi0Widget);
    changeBackgroundNormal(psi0Widget);
    changeBackgroundNormal(modulationPhaseWidget);
    changeBackgroundNormal(modulationAmplitudeWidget);
    changeBackgroundNormal(nomFichierWidget);
    changeBackgroundNormal(formCoord1);
    changeBackgroundNormal(formCoord2);

    boutonValider->setText("Modifier");

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
    Q_UNUSED(val);
    manageFormulaire(typeWidget->currentIndex());
}

void FormCageExcitation::changeCreate(bool c)
{
    this->cageExci->setCreate(c);
    if (this->cageExci->isCreate())
    {
        boutonValider->setText("Modifier");
    }
    else
    {
        boutonValider->setText("Ajouter");
    }
}

void FormCageExcitation::changeBackgroundRed()
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Window, Qt::red);
    ((QWidget*)sender())->setAutoFillBackground(true);
    ((QWidget*)sender())->setPalette(Pal);
}


void FormCageExcitation::init()
{
    FormElementBase::init();
    group->setChecked(cageExci->isCreate());
    nbFacesWidget->setValue(cageExci->GetNbFaces());
    typeWidget->setCurrentIndex(cageExci->GetTypeExcitation()-1);
    insideOutsideWidget->setCurrentIndex(cageExci->GetInsideOutside()-1);
    modeWidget->setCurrentIndex(cageExci->GetModeExcitation());
    hauteurWidget->setValue(cageExci->GetHauteur());
    sensPropaWidget->setCurrentIndex(cageExci->GetSensPropagation()-1);
    pointRefWidget->setCoordonnee(cageExci->GetPointReference());
    theta0Widget->setValue(cageExci->GetTheta0());
    phi0Widget->setValue(cageExci->GetPhi0());
    psi0Widget->setValue(cageExci->GetPsi0());
    modulationPhaseWidget->setValue(cageExci->GetModulationPhase());
    modulationAmplitudeWidget->setValue(cageExci->GetModulationAmplitude());
    nomFichierWidget->setText(QString(cageExci->GetNomFichier().c_str()));

    // on remet les champs du formulaire dans leur couleur normal
    changeBackgroundNormal(nbFacesWidget);
    changeBackgroundNormal(typeWidget);
    changeBackgroundNormal(insideOutsideWidget);
    changeBackgroundNormal(modeWidget);
    changeBackgroundNormal(hauteurWidget);
    changeBackgroundNormal(sensPropaWidget);
    changeBackgroundNormal(pointRefWidget);
    changeBackgroundNormal(theta0Widget);
    changeBackgroundNormal(phi0Widget);
    changeBackgroundNormal(psi0Widget);
    changeBackgroundNormal(modulationPhaseWidget);
    changeBackgroundNormal(modulationAmplitudeWidget);
    changeBackgroundNormal(nomFichierWidget);
    changeBackgroundNormal(formCoord1);
    changeBackgroundNormal(formCoord2);
}


void FormCageExcitation::changeBackgroundNormal(QWidget * w)
{
    QPalette Pal(palette());
    w->setAutoFillBackground(true);
    w->setPalette(Pal);
}
