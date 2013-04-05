#include "FormVolumeCalcul.h"

FormVolumeCalcul::FormVolumeCalcul(volumeCalcul * volCal, QWidget *parent) :
    QWidget(parent)
{
    this->volCal=volCal;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->setMargin(0);
    QGroupBox * groupGeo = new QGroupBox("Volume Calcul");

    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutLongueur = new QHBoxLayout;
    layoutLongueur->addWidget(new QLabel("Longueur:"));
    QDoubleSpinBox * longueurWidget = new QDoubleSpinBox();
    layoutLongueur->addWidget(longueurWidget);
    layout->addLayout(layoutLongueur);

    QHBoxLayout * layoutLargeur = new QHBoxLayout;
    layoutLargeur->addWidget(new QLabel("Largeur:"));
    QDoubleSpinBox * largeurWidget = new QDoubleSpinBox();
    layoutLargeur->addWidget(largeurWidget);
    layout->addLayout(layoutLargeur);

    QHBoxLayout * layoutHauteur = new QHBoxLayout;
    layoutHauteur->addWidget(new QLabel("Hauteur:"));
    QDoubleSpinBox * hauteurWidget = new QDoubleSpinBox();
    layoutHauteur->addWidget(hauteurWidget);
    layout->addLayout(layoutHauteur);


    QHBoxLayout * layoutNbrY = new QHBoxLayout;
    layoutNbrY->addWidget(new QLabel("NombreY:"));
    QDoubleSpinBox * nbrYWidget = new QDoubleSpinBox();
    layoutNbrY->addWidget(nbrYWidget);
    layout->addLayout(layoutNbrY);

    QHBoxLayout * layoutNbrX = new QHBoxLayout;
    layoutNbrX->addWidget(new QLabel("NombreX:"));
    QDoubleSpinBox * nbrXWidget = new QDoubleSpinBox();
    layoutNbrX->addWidget(nbrXWidget);
    layout->addLayout(layoutNbrX);

    QHBoxLayout * layoutNbrZ = new QHBoxLayout;
    layoutNbrZ->addWidget(new QLabel("NombreZ:"));
    QDoubleSpinBox * nbrZWidget = new QDoubleSpinBox();
    layoutNbrZ->addWidget(nbrZWidget);
    layout->addLayout(layoutNbrZ);


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);

}
