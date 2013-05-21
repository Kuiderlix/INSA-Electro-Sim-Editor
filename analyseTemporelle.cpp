/* 
 * File:   anayseTemporelle.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:34 PM
 */

#include "analyseTemporelle.h"

analyseTemporelle::analyseTemporelle() {
    periode=0;
    temps=0;
}


analyseTemporelle::~analyseTemporelle() {
}

void analyseTemporelle::ecrire(){

    setHeader("[ANALYSE_TEMPORELLE]");
    setExtension(".ana");
    blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Periode_d'echantillonnage_temporelle_(en_s):\n";
    monEcriture << this->periode << std::endl;
    monEcriture << "Temps_d'observation_(en_s):\n";
    monEcriture << this->temps << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
