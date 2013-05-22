#include "FormElementBase.h"

FormElementBase::FormElementBase(elementBase *element, QWidget *parent) :
    QDialog(parent)
{
    this->element=element;
}

QWidget *FormElementBase::getWidgetElementBase()
{
    QWidget * conteneur = new QWidget(this);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    layout->addWidget(new QLabel("Coordonnees Avant Gauche:"));
    formCoord1 = new FormCoordonnees(element->GetAvantGauche());
    layout->addWidget(formCoord1);

    layout->addWidget(new QLabel("Coordonnees Arrière Droit:"));
    formCoord2 = new FormCoordonnees(element->GetArriereDroit());
    layout->addWidget(formCoord2);

    QHBoxLayout * layoutCouleur = new QHBoxLayout;
    layoutCouleur->addWidget(new QLabel("Couleur dans le scène:"));
    couleurPick = new ColorPicker(element->getCouleur());
    connect(couleurPick,SIGNAL(colorChanged(QColor)),this,SLOT(changeCouleur(QColor)));
    layoutCouleur->addWidget(couleurPick);
    layout->addLayout(layoutCouleur);

    boutonValider = new QPushButton("Ajouter");

    layout->addWidget(boutonValider);

    conteneur->setLayout(layout);

    connect(boutonValider, SIGNAL(clicked()),this,SLOT(valider()));

    return conteneur;
}

void FormElementBase::valider()
{
    element->SetAvantGauche(formCoord1->getCoord());
    element->SetArriereDroit(formCoord2->getCoord());
}

void FormElementBase::changeCouleur(QColor c)
{
    element->setCouleur(c);
}

void FormElementBase::reset()
{
    couleurPick->setColor(QColor("red"));
    formCoord1->setCoordonnee(coordonnee());
    formCoord2->setCoordonnee(coordonnee());
}

void FormElementBase::init()
{
    couleurPick->setColor(element->getCouleur());
    formCoord1->setCoordonnee(element->GetAvantGauche());
    formCoord2->setCoordonnee(element->GetArriereDroit());
}

void FormElementBase::setElement(elementBase * elem)
{
    this->element=elem;
}
