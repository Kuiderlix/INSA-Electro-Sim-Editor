/* 
 * File:   elementBase.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:19 PM
 */

#include "elementBase.h"
#include "Ecriture.h"

elementBase::elementBase() {
    couleur = QColor("red");
    this->arriereDroit = coordonnee(0,0,0);
    this->avantGauche = coordonnee(0,0,0);
}

elementBase::elementBase(const elementBase& orig) {
}

elementBase::~elementBase() {
}

void elementBase::ecrireElementBase(){
    Ecriture::Ecrire("Coordonnees_du_coin_inferieur_avant_gauche\n");
    this->GetAvantGauche().ecrire();

    Ecriture::Ecrire("Coordonnees_du_coin_superieur_arriere_droit\n");
    this->GetArriereDroit().ecrire();
}

bool elementBase::operator==(elementBase const &b)
{
    return this->arriereDroit==b.arriereDroit & this->avantGauche == b.avantGauche;
}
