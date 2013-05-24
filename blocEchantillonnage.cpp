/* 
 * File:   blocEchantillonnage.cpp
 * Author: camille
 * 
 * Created on March 4, 2013, 4:24 PM
 */

#include "blocEchantillonnage.h"

blocEchantillonnage::blocEchantillonnage() : blocConfiguration() {
    this->setHeader("[ECHANTILLONNAGE]");
    this->setExtension(".avc");

    facteurEchatillonnage=0;
}


blocEchantillonnage::~blocEchantillonnage() {
}

void blocEchantillonnage::ecrire(){
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Facteur_multiplicatif_pour_le_nombre_d_echantillons_preleves:\n";
    monEcriture << this->facteurEchatillonnage << std::endl;
    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
