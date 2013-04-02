#include "FormCoordonnees.h"

FormCoordonnees::FormCoordonnees(coordonnee * coord,QWidget *parent) :
    QWidget(parent)
{
    this->coord=coord;
    QHBoxLayout * layout = new QHBoxLayout;

    champsX = new QSpinBox();
    champsX->setValue(coord->GetX());
    champsY = new QSpinBox();
    champsX->setValue(coord->GetY());
    champsZ = new QSpinBox();
    champsX->setValue(coord->GetZ());

    layout->addWidget(new QLabel("x:"));
    layout->addWidget(champsX);
    layout->addWidget(new QLabel("y:"));
    layout->addWidget(champsY);
    layout->addWidget(new QLabel("z:"));
    layout->addWidget(champsZ);

    setLayout(layout);
}
