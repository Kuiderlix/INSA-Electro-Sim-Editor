/* 
 * File:   pml.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:26 PM
 */

#include "pml.h"

pml::pml() {
    epaisseurCouche=0;
    ordreVariation=0;
    sigmaMax=0;
    kMax=0;
}

pml::~pml() {
}

void pml::ecrire(){

    setHeader("[PML]");
    setExtension(".ana");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Epaisseur_de_la_couche_(en_cellules):\n";
    monEcriture << this->epaisseurCouche << std::endl;
    monEcriture << "Ordre_de_la_variation_geometrique_de_sigma_(valeur_de_m):\n";
    monEcriture << this->ordreVariation << std::endl;
    monEcriture << "Sigma_max:\n";
    monEcriture << this->sigmaMax << std::endl;
    monEcriture << "K_max:\n";
    monEcriture << this->kMax << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
