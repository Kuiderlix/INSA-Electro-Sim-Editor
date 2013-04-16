/* 
 * File:   elementBase.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:19 PM
 */

#include "elementBase.h"
#include "Ecriture.h"

elementBase::elementBase() {
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
