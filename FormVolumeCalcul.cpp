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

    QHBoxLayout * layoutLargeur = new QHBoxLayout;
    layoutLargeur->addWidget(new QLabel("Larg."));
    QDoubleSpinBox * largeurWidget = new QDoubleSpinBox();
    largeurWidget->setMaximum(9999.9);
    largeurWidget->setValue(volCal->GetLargeur());
    layoutLargeur->addWidget(largeurWidget);
    layoutDimension->addLayout(layoutLargeur);

    QHBoxLayout * layoutHauteur = new QHBoxLayout;
    layoutHauteur->addWidget(new QLabel("Haut."));
    QDoubleSpinBox * hauteurWidget = new QDoubleSpinBox();
    hauteurWidget->setMaximum(9999.9);
    hauteurWidget->setValue(volCal->GetHauteur());
    layoutHauteur->addWidget(hauteurWidget);
    layoutDimension->addLayout(layoutHauteur);

    layout->addRow(layoutDimension);

    QHBoxLayout * layoutCoord = new QHBoxLayout;


    QHBoxLayout * layoutNbrY = new QHBoxLayout;
    layoutNbrY->addWidget(new QLabel("NbrY"));
    QDoubleSpinBox * nbrYWidget = new QDoubleSpinBox();
    nbrYWidget->setMaximum(9999.9);
    nbrYWidget->setValue(volCal->GetNombreY());
    layoutNbrY->addWidget(nbrYWidget);
    layoutCoord->addLayout(layoutNbrY);

    QHBoxLayout * layoutNbrX = new QHBoxLayout;
    layoutNbrX->addWidget(new QLabel("NbrX"));
    QDoubleSpinBox * nbrXWidget = new QDoubleSpinBox();
    nbrXWidget->setMaximum(9999.9);
    nbrXWidget->setValue(volCal->GetNombreX());
    layoutNbrX->addWidget(nbrXWidget);
    layoutCoord->addLayout(layoutNbrX);

    QHBoxLayout * layoutNbrZ = new QHBoxLayout;
    layoutNbrZ->addWidget(new QLabel("NbrZ"));
    QDoubleSpinBox * nbrZWidget = new QDoubleSpinBox();
    nbrZWidget->setMaximum(9999.9);
    nbrZWidget->setValue(volCal->GetNombreZ());
    layoutNbrZ->addWidget(nbrZWidget);
    layoutCoord->addLayout(layoutNbrZ);

    layout->addRow(layoutCoord);




    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);

}
