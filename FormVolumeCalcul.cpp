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
    QDoubleSpinBox * longueurWidget = new QDoubleSpinBox();
    longueurWidget->setMaximum(9999.9);
    longueurWidget->setValue(volCal->GetLongueur());
    layoutLongueur->addWidget(longueurWidget);
    layoutDimension->addLayout(layoutLongueur);
    connect(longueurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetLongueur(double)));

    QHBoxLayout * layoutLargeur = new QHBoxLayout;
    layoutLargeur->addWidget(new QLabel("Larg."));
    QDoubleSpinBox * largeurWidget = new QDoubleSpinBox();
    largeurWidget->setMaximum(9999.9);
    largeurWidget->setValue(volCal->GetLargeur());
    layoutLargeur->addWidget(largeurWidget);
    layoutDimension->addLayout(layoutLargeur);
    connect(largeurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetLargeur(double)));

    QHBoxLayout * layoutHauteur = new QHBoxLayout;
    layoutHauteur->addWidget(new QLabel("Haut."));
    QDoubleSpinBox * hauteurWidget = new QDoubleSpinBox();
    hauteurWidget->setMaximum(9999.9);
    hauteurWidget->setValue(volCal->GetHauteur());
    layoutHauteur->addWidget(hauteurWidget);
    layoutDimension->addLayout(layoutHauteur);
    connect(hauteurWidget,SIGNAL(valueChanged(double)),volCal,SLOT(SetHauteur(double)));

    layout->addRow(layoutDimension);

    QHBoxLayout * layoutCoord = new QHBoxLayout;


    QHBoxLayout * layoutNbrY = new QHBoxLayout;
    layoutNbrY->addWidget(new QLabel("NbrY"));
    QSpinBox * nbrYWidget = new QSpinBox();
    nbrYWidget->setMaximum(9999.9);
    nbrYWidget->setValue(volCal->GetNombreY());
    layoutNbrY->addWidget(nbrYWidget);
    layoutCoord->addLayout(layoutNbrY);
    connect(nbrYWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreY(int)));

    QHBoxLayout * layoutNbrX = new QHBoxLayout;
    layoutNbrX->addWidget(new QLabel("NbrX"));
    QSpinBox * nbrXWidget = new QSpinBox();
    nbrXWidget->setMaximum(9999.9);
    nbrXWidget->setValue(volCal->GetNombreX());
    layoutNbrX->addWidget(nbrXWidget);
    layoutCoord->addLayout(layoutNbrX);
    connect(nbrXWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreX(int)));

    QHBoxLayout * layoutNbrZ = new QHBoxLayout;
    layoutNbrZ->addWidget(new QLabel("NbrZ"));
    QSpinBox * nbrZWidget = new QSpinBox();
    nbrZWidget->setMaximum(9999.9);
    nbrZWidget->setValue(volCal->GetNombreZ());
    layoutNbrZ->addWidget(nbrZWidget);
    layoutCoord->addLayout(layoutNbrZ);
    connect(nbrZWidget,SIGNAL(valueChanged(int)),volCal,SLOT(SetNombreZ(int)));

    layout->addRow(layoutCoord);




    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);

}
