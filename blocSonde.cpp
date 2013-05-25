/* 
 * File:   blocSonde.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:44 PM
 */

#include <vector>

#include "blocSonde.h"

blocSonde::blocSonde() {
}


blocSonde::~blocSonde() {
}

void blocSonde::ecrire(){

    setHeader("[SONDES]");
    setExtension(".ana");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_sondes:\n";
    monEcriture << this->getNbElement() << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    for(int i=0; i<this->getNbElement(); i++){
        sonde* temp = this->GetSonde(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
