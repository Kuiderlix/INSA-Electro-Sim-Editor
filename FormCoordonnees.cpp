#include "FormCoordonnees.h"

FormCoordonnees::FormCoordonnees(QWidget *parent):
    QWidget(parent)
{
    init();

}

FormCoordonnees::FormCoordonnees(coordonnee coord,QWidget *parent) :
    QWidget(parent)
{
    this->coord=coord;
    init();
}

void FormCoordonnees::setCoordonnee(coordonnee c)
{
    coord=c;
    champsX->setValue(coord.GetX());
    champsY->setValue(coord.GetY());
    champsZ->setValue(coord.GetZ());
}

coordonnee FormCoordonnees::getCoord()
{
    return coord;
}

void FormCoordonnees::changeX(int v)
{
    coord.SetX(v);
    emit coordonneeChanged(coord);
}

void FormCoordonnees::changeY(int v)
{
    coord.SetY(v);
    emit coordonneeChanged(coord);
}

void FormCoordonnees::changeZ(int v)
{
    coord.SetZ(v);
    emit coordonneeChanged(coord);
}

void FormCoordonnees::init()
{
    QHBoxLayout * layout = new QHBoxLayout;
    layout->setMargin(0);

    champsX = new QSpinBox();
    champsX->setValue(coord.GetX());
    this->connect(champsX, SIGNAL(valueChanged(int)), this, SLOT(changeX(int)));

    champsY = new QSpinBox();
    champsY->setValue(coord.GetY());
    this->connect(champsY, SIGNAL(valueChanged(int)), this, SLOT(changeY(int)));

    champsZ = new QSpinBox();
    champsZ->setValue(coord.GetZ());
    this->connect(champsZ, SIGNAL(valueChanged(int)), this, SLOT(changeZ(int)));

    layout->addWidget(new QLabel("x:"));
    layout->addWidget(champsX);
    layout->addWidget(new QLabel("y:"));
    layout->addWidget(champsY);
    layout->addWidget(new QLabel("z:"));
    layout->addWidget(champsZ);

    setLayout(layout);
}

