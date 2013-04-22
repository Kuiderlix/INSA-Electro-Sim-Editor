/* 
 * File:   metallisation.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:37 PM
 */

#include "metallisation.h"

int metallisation::nbMetal = 0;
metallisation::metallisation() {
    conductivite=nbMetal++;
    this->arriereDroit = coordonnee(1,2,3);
    this->avantGauche = coordonnee(3,2,1);
}

metallisation::metallisation(const metallisation& orig) {
}

metallisation::~metallisation() {
}

void metallisation::ecrire(int nb){
    std::ostringstream monEcriture;
    monEcriture << "Metallisation_numero_" << nb << "\n";
    monEcriture << "Conductivité:\n";
    monEcriture << this->conductivite << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    this->ecrireElementBase();
}

