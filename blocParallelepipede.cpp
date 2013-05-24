/* 
 * File:   blocParallelepipede.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 7:20 PM
 */

#include "blocParallelepipede.h"

blocParallelepipede::blocParallelepipede() {
}

blocParallelepipede::~blocParallelepipede() {
}

void blocParallelepipede::ecrire(){

    setHeader("[PARALLELEPIPEDES_MATERIAUX]");
    setExtension(".dsc");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_parallelepipedes:\n";
    monEcriture << this->getNbElement() << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    for(int i=0; i<this->getNbElement(); i++){
        parallelepipede *temp = this->getParallelepipede(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
