/* 
 * File:   blocSonde.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:44 PM
 */

#include <vector>

#include "blocSonde.h"

blocSonde::blocSonde() {
    this->setHeader("[SONDES]");
    this->setExtension(".ana");
}

blocSonde::blocSonde(const blocSonde& orig) {
}

blocSonde::~blocSonde() {
}

void blocSonde::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[SONDES]");
    bC.setExtension(".ana");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_sondes:\n";
    monEcriture << this->getNbElement() << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->getNbElement(); i++){
        sonde* temp = this->GetSonde(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
