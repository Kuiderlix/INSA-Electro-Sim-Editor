#include "FormVolumeCalcul.h"

FormVolumeCalcul::FormVolumeCalcul(volumeCalcul * volCal, QWidget *parent) :
    QWidget(parent)
{
    this->volCal=volCal;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Volume Calcul");

    QFormLayout * layout = new QFormLayout;

    QHBoxLayout * layoutDimension = new QHBoxLayout;

    QHBoxLayout * layoutLongueur = new QHBoxLayout;
    layoutLongueur->addWidget(new QLabel("Long."));
    longueurWidget = new QDoubleSpinBox();
    longueurWidget->setMaximum(INT_MAX);
    layoutLongueur->addWidget(longueurWidget);
    layoutDimension->addLayout(layoutLongueur);
    connect(longueurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetLongueur(double)));

    QHBoxLayout * layoutLargeur = new QHBoxLayout;
    layoutLargeur->addWidget(new QLabel("Larg."));
    largeurWidget = new QDoubleSpinBox();
    largeurWidget->setMaximum(INT_MAX);
    layoutLargeur->addWidget(largeurWidget);
    layoutDimension->addLayout(layoutLargeur);
    connect(largeurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetLargeur(double)));

    QHBoxLayout * layoutHauteur = new QHBoxLayout;
    layoutHauteur->addWidget(new QLabel("Haut."));
    hauteurWidget = new QDoubleSpinBox();
    hauteurWidget->setMaximum(INT_MAX);
    layoutHauteur->addWidget(hauteurWidget);
    layoutDimension->addLayout(layoutHauteur);
    connect(hauteurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetHauteur(double)));

    layout->addRow(layoutDimension);

    QHBoxLayout * layoutCoord = new QHBoxLayout;


    QHBoxLayout * layoutNbrY = new QHBoxLayout;
    layoutNbrY->addWidget(new QLabel("NbrY"));
    nbrYWidget = new QSpinBox();
    nbrYWidget->setMaximum(INT_MAX);
    layoutNbrY->addWidget(nbrYWidget);
    layoutCoord->addLayout(layoutNbrY);
    connect(nbrYWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreY(int)));

    QHBoxLayout * layoutNbrX = new QHBoxLayout;
    layoutNbrX->addWidget(new QLabel("NbrX"));
    nbrXWidget = new QSpinBox();
    nbrXWidget->setMaximum(INT_MAX);
    layoutNbrX->addWidget(nbrXWidget);
    layoutCoord->addLayout(layoutNbrX);
    connect(nbrXWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreX(int)));

    QHBoxLayout * layoutNbrZ = new QHBoxLayout;
    layoutNbrZ->addWidget(new QLabel("NbrZ"));
    nbrZWidget = new QSpinBox();
    nbrZWidget->setMaximum(INT_MAX);
    layoutNbrZ->addWidget(nbrZWidget);
    layoutCoord->addLayout(layoutNbrZ);
    connect(nbrZWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreZ(int)));

    layout->addRow(layoutCoord);


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);

    init();

}

void FormVolumeCalcul::init()
{
    longueurWidget->setValue(volCal->GetLongueur());
    connect(longueurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetLongueur(double)));
    largeurWidget->setValue(volCal->GetLargeur());
    connect(largeurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetLargeur(double)));
    hauteurWidget->setValue(volCal->GetHauteur());
    connect(hauteurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetHauteur(double)));

    nbrYWidget->setValue(volCal->GetNombreY());
    connect(nbrYWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreY(int)));
    nbrXWidget->setValue(volCal->GetNombreX());
    connect(nbrXWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreX(int)));
    nbrZWidget->setValue(volCal->GetNombreZ());
    connect(nbrZWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreZ(int)));
}
