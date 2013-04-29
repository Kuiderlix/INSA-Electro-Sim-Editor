#include "FormCoordonnees.h"

FormCoordonnees::FormCoordonnees(QWidget *parent):
    QWidget(parent)
{
    QHBoxLayout * layout = new QHBoxLayout;
    layout->setMargin(0);

    champsX = new QSpinBox();
    champsX->setValue(coord.GetX());
    this->connect(champsX, SIGNAL(valueChanged(QString)), this, SLOT(changeX(QString)));

    champsY = new QSpinBox();
    champsY->setValue(coord.GetY());
    this->connect(champsY, SIGNAL(valueChanged(QString)), this, SLOT(changeY(QString)));

    champsZ = new QSpinBox();
    champsZ->setValue(coord.GetZ());
    this->connect(champsZ, SIGNAL(valueChanged(QString)), this, SLOT(changeZ(QString)));

    layout->addWidget(new QLabel("x:"));
    layout->addWidget(champsX);
    layout->addWidget(new QLabel("y:"));
    layout->addWidget(champsY);
    layout->addWidget(new QLabel("z:"));
    layout->addWidget(champsZ);

    setLayout(layout);

}

FormCoordonnees::FormCoordonnees(coordonnee coord,QWidget *parent) :
    QWidget(parent)
{
    this->coord=coord;
    QHBoxLayout * layout = new QHBoxLayout;
    layout->setMargin(0);

    champsX = new QSpinBox();
    champsX->setValue(coord.GetX());
    this->connect(champsX, SIGNAL(valueChanged(QString)), this, SLOT(changeX(QString)));

    champsY = new QSpinBox();
    champsY->setValue(coord.GetY());
    this->connect(champsY, SIGNAL(valueChanged(QString)), this, SLOT(changeY(QString)));

    champsZ = new QSpinBox();
    champsZ->setValue(coord.GetZ());
    this->connect(champsZ, SIGNAL(valueChanged(QString)), this, SLOT(changeZ(QString)));

    layout->addWidget(new QLabel("x:"));
    layout->addWidget(champsX);
    layout->addWidget(new QLabel("y:"));
    layout->addWidget(champsY);
    layout->addWidget(new QLabel("z:"));
    layout->addWidget(champsZ);

    setLayout(layout);
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

void FormCoordonnees::changeX(QString v)
{
    coord.SetX(v.toInt());
}

void FormCoordonnees::changeY(QString v)
{
    coord.SetY(v.toInt());
}

void FormCoordonnees::changeZ(QString v)
{
    coord.SetZ(v.toInt());
}

