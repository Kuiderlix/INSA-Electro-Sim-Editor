/* 
 * File:   pml.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:26 PM
 */

#include "pml.h"

pml::pml() {
}

pml::pml(const pml& orig) {
}

pml::~pml() {
}

void pml::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[PML]");
    bC.setExtension(".ana");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Epaisseur_de_la_couche_(en_cellules):\n";
    monEcriture << this->epaisseurCouche << std::endl;
    monEcriture << "Ordre_de_la_variation_geometrique_de_sigma_(valeur_de_m):\n";
    monEcriture << this->ordreVariation << std::endl;
    monEcriture << "Sigma_max:\n";
    monEcriture << this->sigmaMax << std::endl;
    monEcriture << "K_max:\n";
    monEcriture << this->kMax << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
