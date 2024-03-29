/* 
 * File:   calculDirectivite.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:54 PM
 */

#include "calculDirectivite.h"

calculDirectivite::calculDirectivite() {
    calcul=false;
    pasTheta=0;
    pasPhi=0;
}

calculDirectivite::~calculDirectivite() {
}

void calculDirectivite::ecrire(){

    setHeader("[CALCUL_DIRECTIVITE]");
    setExtension(".avc");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Calcul_de_la_directivite_0>Non_1>Oui\n";
    monEcriture << ((int)this->calcul) << std::endl;
    monEcriture << "Pas_de_discretisation_selon_theta_(en_degres):\n";
    monEcriture << this->pasTheta << std::endl;
    monEcriture << "Pas_de_discretisation_selon_phi_(en_degres):\n";
    monEcriture << this->pasPhi << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
