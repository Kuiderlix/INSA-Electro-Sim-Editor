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

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[ANALYSE_TEMPORELLE]");
    bC.setExtension(".ana");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Periode_d'echantillonnage_temporelle_(en_s):\n";
    monEcriture << this->periode << std::endl;
    monEcriture << "Temps_d'observation_(en_s):\n";
    monEcriture << this->temps << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
