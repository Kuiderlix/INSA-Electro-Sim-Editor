#include "zonecentrale.h"

ZoneCentrale::ZoneCentrale(QWidget *parent) :
    QWidget(parent)
{
    visualisation = new Visualisation3D();
    formulaire = new Formulaire();

    // La boite principale de la fenêtre qui va contenir la visualisation 3D et le formulaire d'ajout de forme
    layoutPrincipale = new QHBoxLayout();

    layoutPrincipale->addWidget(visualisation);
    layoutPrincipale->addWidget(formulaire); // pour le formulaire

    this->setLayout(layoutPrincipale);
}
