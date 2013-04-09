#include "FormElementBase.h"

FormElementBase::FormElementBase(elementBase *element, int mode, QWidget *parent) :
    QWidget(parent)
{
    this->element=element;
    this->mode=mode;
}

QWidget *FormElementBase::getWidgetElementBase()
{
    QWidget * conteneur = new QWidget(this);
    QVBoxLayout * layout = new QVBoxLayout;

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

    return conteneur;
}
