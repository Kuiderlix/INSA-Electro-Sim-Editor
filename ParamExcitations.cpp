/* 
 * File:   excitations.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:32 PM
 */

#include "ParamExcitations.h"

ParamExcitations::ParamExcitations() {
    frequenceMax=0;
    frequenceSinus=0;
    type=0;
}


ParamExcitations::~ParamExcitations() {
}

void ParamExcitations::ecrire(){

    setHeader("[PARAMETRES_EXCITATION]");
    setExtension(".ana");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Frequence_maximale_de_la_bande_d'analyse_(en_GHz):\n";
    monEcriture << this->frequenceMax << std::endl;
    monEcriture << "Excitation_0>Gaussienne_1>Gaussienne_modulant_un_sinus:\n";
    monEcriture << this->type << std::endl;
    if(this->type == 1){
        monEcriture << "Frequence_du_sinus_(GHz):\n";
        monEcriture << this->frequenceSinus << std::endl;
    }
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
