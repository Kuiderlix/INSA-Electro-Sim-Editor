/* 
 * File:   parallelepipede.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:12 PM
 */

#include "parallelepipede.h"
#include <string>
#include <sstream>
#include "Ecriture.h"

parallelepipede::parallelepipede() {
    conductivite=2;
    permitRelative=8;
    permeRelative=4;
    this->arriereDroit = coordonnee(1,2,3);
    this->avantGauche = coordonnee(3,2,1);
}

parallelepipede::parallelepipede(const parallelepipede& orig) {
}

parallelepipede::~parallelepipede() {
}

void parallelepipede::ecrire(int nb){

    std::ostringstream monEcriture;
    monEcriture << "parallelepipede_numero_" << nb << "\n";
    monEcriture << "Permittivite_relative:\n";
    monEcriture << this->permitRelative << std::endl;
    monEcriture << "Permeabilite_relative:\n";
    monEcriture << this->permeRelative << std::endl;
    monEcriture << "Conductivite:\n";
    monEcriture << this->conductivite << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    this->ecrireElementBase();
}
