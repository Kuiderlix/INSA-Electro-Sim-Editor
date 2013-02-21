#include "formulaire.h"

Formulaire::Formulaire(QWidget *parent) :
    QWidget(parent)
{
    layoutPrincipale = new QVBoxLayout();
    QGroupBox* conteneurPrincipale = new QGroupBox("Formulaire");

    QVBoxLayout *layoutGroupBox = new QVBoxLayout();


    xEditLine = new QLineEdit();
    yEditLine = new QLineEdit();
    zEditLine = new QLineEdit();

    layoutGroupBox->addWidget(new QLabel("x:"));
    layoutGroupBox->addWidget(xEditLine);
    layoutGroupBox->addWidget(new QLabel("y:"));
    layoutGroupBox->addWidget(yEditLine);
    layoutGroupBox->addWidget(new QLabel("z:"));
    layoutGroupBox->addWidget(zEditLine);
    QPushButton* boutonAjoutCube = new QPushButton("Ajouter Cube");
    layoutGroupBox->addWidget(boutonAjoutCube);
    layoutGroupBox->setAlignment(Qt::AlignTop);

    conteneurPrincipale->setLayout(layoutGroupBox);

    layoutPrincipale->addWidget(conteneurPrincipale);

    QObject::connect(boutonAjoutCube, SIGNAL(clicked()),this, SLOT(sendCube()));

    this->setLayout(layoutPrincipale);
}

void Formulaire::sendCube()
{
    float x = xEditLine->text().toFloat();
    float y = yEditLine->text().toFloat();
    float z = zEditLine->text().toFloat();
    emit cubeSent(new Cube(Point(x,y,z),Point(x+1,y+1,z+1)));
}


