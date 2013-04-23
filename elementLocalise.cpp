/* 
 * File:   elementLocalise.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:17 PM
 */

#include "elementLocalise.h"
#include <string>
#include <sstream>
#include "Ecriture.h"

elementLocalise::elementLocalise() {
    type=1;
    direction=1;
}

elementLocalise::elementLocalise(const elementLocalise& orig) {
}

elementLocalise::~elementLocalise() {
}

void elementLocalise::ecrire(int nb){

    std::ostringstream monEcriture;
    monEcriture << "Element_Localise_numero_" << nb << "\n";
    monEcriture << "Type_d_element_1>resistance_2>capacite_3>self:\n";
    monEcriture << this->type << std::endl;
    monEcriture << "Valeur_de_l_element_en_Ohm_Farad_ou_Henry:\n";
    monEcriture << this->valeur << std::endl;
    monEcriture << "Direction_1>x_2>y_3>z\n";
    monEcriture << this->direction << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    this->ecrireElementBase();
}
