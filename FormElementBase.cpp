#include "FormElementBase.h"

FormElementBase::FormElementBase(elementBase *element, int mode, QWidget *parent) :
    QDialog(parent)
{
    this->element=element;
    this->mode=mode;
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

    if (mode == NOUVEAU)
    {
        boutonValider = new QPushButton("Ajouter");
    }
    else
    {
        boutonValider = new QPushButton("Modifier");
    }
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

void FormElementBase::reset()
{
    formCoord1->setCoordonnee(coordonnee());
    formCoord2->setCoordonnee(coordonnee());
}

void FormElementBase::setElement(elementBase * elem)
{
    this->element=elem;
}
