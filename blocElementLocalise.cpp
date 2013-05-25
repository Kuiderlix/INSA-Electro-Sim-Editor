/* 
 * File:   blocElementLocalise.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 7:29 PM
 */

#include <vector>

#include "blocElementLocalise.h"
#include "elementLocalise.h"

blocElementLocalise::blocElementLocalise() {
}


blocElementLocalise::~blocElementLocalise() {
}

void blocElementLocalise::ecrire(){

    setHeader("[ELEMENTS_LOCALISES]");
    setExtension(".dsc");
    this->blocConfiguration::ecrire();


    std::ostringstream monEcriture;
    monEcriture << "Nombre_d_elements_localises:\n";
    monEcriture << this->getNbElement() << std::endl;

    Ecriture::Ecrire(monEcriture.str());
    for(int i=0; i<this->getNbElement(); i++){
        elementLocalise *temp = this->GetElementLocalise(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
