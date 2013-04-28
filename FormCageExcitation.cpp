#include "FormCageExcitation.h"



FormCageExcitation::FormCageExcitation(cageExcitation *cageExci, int mode, QWidget *parent) :
    FormElementBase(cageExci,mode,parent)
{
    this->cageExci=cageExci;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Cage Excitation");


    QFormLayout * layout = new QFormLayout;

    QComboBox * insideOutsideWidget = new QComboBox();
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

    QComboBox * modeWidget = new QComboBox();
    modeWidget->addItems(QStringList() << "OndeplaneX" << "OndeplaneY" << "GuideTE10X" << "GuideTE10Y");
    layoutFormFace1->addRow("Mode d'excitation:",modeWidget);

    QSpinBox * hauteurWidget = new QSpinBox();
    layoutFormFace1->addRow("Hauteur:",hauteurWidget);

    QComboBox * sensPropaWidget = new QComboBox();
    sensPropaWidget->addItems(QStringList() << "Z_croissant" << "Z_decroissant");
    layoutFormFace1->addRow("Sens propagation:",sensPropaWidget);

    formFace1->setLayout(layoutFormFace1);
    layout->addRow(formFace1);


    formFaceDif1 = new QWidget();
    QFormLayout* layoutFormFaceDif1 = new QFormLayout;
    layoutFormFaceDif1->setMargin(0);

    FormCoordonnees* pointRefWidget = new FormCoordonnees(cageExci->GetPointReference());
    layoutFormFaceDif1->addRow("Point référence:",pointRefWidget);


    QDoubleSpinBox * theta0Widget = new QDoubleSpinBox();
    layoutFormFaceDif1->addRow("Theta0:",theta0Widget);


    QDoubleSpinBox * phi0Widget = new QDoubleSpinBox();
    layoutFormFaceDif1->addRow("Phi0:",phi0Widget);


    QDoubleSpinBox * psi0Widget = new QDoubleSpinBox();
    layoutFormFaceDif1->addRow("Psi0:",psi0Widget);

    formFaceDif1->setLayout(layoutFormFaceDif1);



    layout->addRow(formFaceDif1);


    formType4 = new QWidget();
    QFormLayout * layoutFormType4 = new QFormLayout;
    layoutFormType4->setMargin(0);

    QDoubleSpinBox * modulationAmplitudeWidget = new QDoubleSpinBox();
    layoutFormType4->addRow("Modulation Amplitude:",modulationAmplitudeWidget);

    QDoubleSpinBox * modulationPhaseWidget = new QDoubleSpinBox();
    layoutFormType4->addRow("Modulation Phase:",modulationPhaseWidget);

    QLineEdit * nomFichierWidget = new QLineEdit();
    layoutFormType4->addRow("Nom Fichier:",nomFichierWidget);

    formType4->setLayout(layoutFormType4);
    layout->addRow(formType4);


    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    manageFormulaire(typeWidget->currentIndex());


}

void FormCageExcitation::valider()
{
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
