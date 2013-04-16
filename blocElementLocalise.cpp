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
    this->setHeader("[ELEMENTS_LOCALISES]");
    this->setExtension(".dsc");
}

blocElementLocalise::blocElementLocalise(const blocElementLocalise& orig) {
}

blocElementLocalise::~blocElementLocalise() {
}

void blocElementLocalise::ecrire(){
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[ELEMENTS_LOCALISES]");
    bC.setExtension(".dsc");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_d_elements_localises:\n";
    monEcriture << this->nbElements << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->nbElements; i++){
        elementLocalise temp = this->elements[i];
        temp.ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
