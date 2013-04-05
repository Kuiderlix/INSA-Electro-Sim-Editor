#include "FormCageExcitation.h"



FormCageExcitation::FormCageExcitation(cageExcitation *cageExci, int mode, QWidget *parent) :
    FormElementBase(cageExci,mode,parent)
{
    this->cageExci=cageExci;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->setMargin(0);
    QGroupBox * groupGeo = new QGroupBox("Cage Excitation");


    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutInsideOutside = new QHBoxLayout;
    layoutInsideOutside->addWidget(new QLabel("Inside/Outside:"));
    QComboBox * insideOutsideWidget = new QComboBox();
    insideOutsideWidget->addItems(QStringList() << "Inside" << "Outside");
    layoutInsideOutside->addWidget(insideOutsideWidget);
    layout->addLayout(layoutInsideOutside);


    QHBoxLayout * layoutNbFaces = new QHBoxLayout;
    layoutNbFaces->addWidget(new QLabel("Nombres Faces:"));
    nbFacesWidget = new QSpinBox();
    layoutNbFaces->addWidget(nbFacesWidget);
    layout->addLayout(layoutNbFaces);
    this->connect(nbFacesWidget, SIGNAL(valueChanged(int)), this, SLOT(actualiseFormulaire(int)));


    QHBoxLayout * layoutType = new QHBoxLayout;
    layoutType->addWidget(new QLabel("Type d'excitation:"));
    typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "onde_plane" << "TE10" << "TM10" << "fichier_excitation");
    layoutType->addWidget(typeWidget);
    layout->addLayout(layoutType);
    this->connect(typeWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(manageFormulaire(int)));


    formFace1 = new QWidget();
    QVBoxLayout * layoutFormFace1 = new QVBoxLayout;
    layoutFormFace1->setMargin(0);

    QHBoxLayout * layoutMode = new QHBoxLayout;
    layoutMode->addWidget(new QLabel("Mode d'excitation:"));
    QComboBox * modeWidget = new QComboBox();
    modeWidget->addItems(QStringList() << "OndeplaneX" << "OndeplaneY" << "GuideTE10X" << "GuideTE10Y");
    layoutMode->addWidget(modeWidget);
    layoutFormFace1->addLayout(layoutMode);


    QHBoxLayout * layoutHauteur = new QHBoxLayout;
    layoutHauteur->addWidget(new QLabel("Hauteur:"));
    QSpinBox * hauteurWidget = new QSpinBox();
    layoutHauteur->addWidget(hauteurWidget);
    layoutFormFace1->addLayout(layoutHauteur);

    QHBoxLayout * layoutSensPropa = new QHBoxLayout;
    layoutSensPropa->addWidget(new QLabel("Sens propagation:"));
    QComboBox * sensPropaWidget = new QComboBox();
    sensPropaWidget->addItems(QStringList() << "Z_croissant" << "Z_decroissant");
    layoutSensPropa->addWidget(sensPropaWidget);
    layoutFormFace1->addLayout(layoutSensPropa);


    formFace1->setLayout(layoutFormFace1);
    layout->addWidget(formFace1);


    formFaceDif1 = new QWidget();
    QVBoxLayout* layoutFormFaceDif1 = new QVBoxLayout;
    layoutFormFaceDif1->setMargin(0);

    //formulaire de pointReference
    layoutFormFaceDif1->addWidget(new QLabel("Point référence:"));
    FormCoordonnees* pointRefWidget = new FormCoordonnees(cageExci->GetPointReference());
    layoutFormFaceDif1->addWidget(pointRefWidget);



    QHBoxLayout * layoutTheta0 = new QHBoxLayout;
    layoutTheta0->addWidget(new QLabel("theta0:"));
    QDoubleSpinBox * theta0Widget = new QDoubleSpinBox();
    layoutTheta0->addWidget(theta0Widget);
    layoutFormFaceDif1->addLayout(layoutTheta0);



    QHBoxLayout * layoutPhi0 = new QHBoxLayout;
    layoutPhi0->addWidget(new QLabel("phi0:"));
    QDoubleSpinBox * phi0Widget = new QDoubleSpinBox();
    layoutPhi0->addWidget(phi0Widget);
    layoutFormFaceDif1->addLayout(layoutPhi0);



    QHBoxLayout * layoutPsi0 = new QHBoxLayout;
    layoutPsi0->addWidget(new QLabel("psi0:"));
    QDoubleSpinBox * psi0Widget = new QDoubleSpinBox();
    layoutPsi0->addWidget(psi0Widget);
    layoutFormFaceDif1->addLayout(layoutPsi0);



    formFaceDif1->setLayout(layoutFormFaceDif1);
    layout->addWidget(formFaceDif1);


    formType4 = new QWidget();
    QVBoxLayout * layoutFormType4 = new QVBoxLayout;
    layoutFormType4->setMargin(0);

    QHBoxLayout * layoutModulationAmplitude = new QHBoxLayout;
    layoutModulationAmplitude->addWidget(new QLabel("Modulation Amplitude:"));
    QDoubleSpinBox * modulationAmplitudeWidget = new QDoubleSpinBox();
    layoutModulationAmplitude->addWidget(modulationAmplitudeWidget);
    layoutFormType4->addLayout(layoutModulationAmplitude);


    QHBoxLayout * layoutModulationPhase = new QHBoxLayout;
    layoutModulationPhase->addWidget(new QLabel("Modulation Phase:"));
    QDoubleSpinBox * modulationPhaseWidget = new QDoubleSpinBox();
    layoutModulationPhase->addWidget(modulationPhaseWidget);
    layoutFormType4->addLayout(layoutModulationPhase);


    QHBoxLayout * layoutNomFichier = new QHBoxLayout;
    layoutNomFichier->addWidget(new QLabel("Nom Fichier:"));
    QDoubleSpinBox * nomFichierWidget = new QDoubleSpinBox();
    layoutNomFichier->addWidget(nomFichierWidget);
    layoutFormType4->addLayout(layoutNomFichier);


    formType4->setLayout(layoutFormType4);
    layout->addWidget(formType4);


    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    manageFormulaire(typeWidget->currentIndex());


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
