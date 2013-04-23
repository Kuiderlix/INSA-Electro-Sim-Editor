/*
 * File:   blocMetallisation.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 6:50 PM
 */

#include <vector>

#include "blocMetallisation.h"

blocMetallisation::blocMetallisation() {
}

blocMetallisation::blocMetallisation(const blocMetallisation& orig) {
}

blocMetallisation::~blocMetallisation() {
}

void blocMetallisation::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[METALLISATIONS]");
    bC.setExtension(".dsc");
    bC.ecrire();

    //blocConfiguration::ecrire();


    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_plans_de_metallisations\n";
    monEcriture << this->getNbElement() << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->getNbElement() ; i++){
        metallisation* temp = this->GetMetallisation(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
