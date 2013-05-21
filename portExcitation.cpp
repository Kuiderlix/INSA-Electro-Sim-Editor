/*
 * File:   portExcitation.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:37 PM
 */

#include "portExcitation.h"
#include <string>
#include <sstream>
#include "Ecriture.h"

portExcitation::portExcitation() {

    portActif=false;
    portInfinitesimal=false;
    typePort=0;
    direction=0;
    impedance=0;
    typeSource=0;
    ponderationAmplitude=0;
    ponderationPhase=0;
}


portExcitation::~portExcitation() {
}

void portExcitation::ecrire(int nb){

    std::ostringstream monEcriture;
    monEcriture << "Port_d'excitation_numero_" << nb << "\n";
    monEcriture << "Port_actif_OUI>1_NON>0:\n";
    monEcriture << ((int)this->portActif) << std::endl;
    monEcriture << "Port_infinitésimal_OUI>1_NON>0\n";
    monEcriture << ((int)this->portInfinitesimal) << std::endl;
    if(this->portInfinitesimal){
        monEcriture << "Port_type_Magnétique>1_Electrique>2\n";
        monEcriture << this->typePort << std::endl;
    }
    monEcriture << "Direction_1>x_2>y_3>z\n";
    monEcriture << this->direction << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    //Les coordonnées
    this->ecrireElementBase();

    std::ostringstream finEcriture;
    finEcriture << "Impedance_de_la_source_(en_Ohm):\n";
    finEcriture << this->impedance << std::endl;
    finEcriture << "Source_de_tension>1_Source_de_courant:\n";
    finEcriture << this->typeSource << std::endl;
    finEcriture << "Ponderation_amplitude_(coefficient_multiplicatif):\n";
    finEcriture << this->ponderationAmplitude << std::endl;
    finEcriture << "Ponderation_phase_(retard_temporel_en_s):\n";
    finEcriture << this->ponderationPhase << std::endl;
    std::string ecritureFin(finEcriture.str());
    Ecriture::Ecrire(ecritureFin);
}
