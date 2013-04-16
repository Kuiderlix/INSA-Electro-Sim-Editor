/* 
 * File:   blocEchantillonnage.cpp
 * Author: camille
 * 
 * Created on March 4, 2013, 4:24 PM
 */

#include "blocEchantillonnage.h"

blocEchantillonnage::blocEchantillonnage() {
    this->setHeader("[ECHANTILLONNAGE]");
    this->setExtension(".avc");
}

blocEchantillonnage::blocEchantillonnage(const blocEchantillonnage& orig) {
}

blocEchantillonnage::~blocEchantillonnage() {
}

void blocEchantillonnage::ecrire(){
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[ECHANTILLONNAGE]");
    bC.setExtension(".avc");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Facteur_multiplicatif_pour_le_nombre_d_echantillons_preleves:\n";
    monEcriture << this->facteurEchatillonnage << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
