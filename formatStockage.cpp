/* 
 * File:   formatStockage.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:51 PM
 */

#include "formatStockage.h"

formatStockage::formatStockage() {
    this->setHeader("[FORMAT_STOCKAGE]");
    this->setExtension(".avc");
}

formatStockage::formatStockage(const formatStockage& orig) {
}

formatStockage::~formatStockage() {
}

void formatStockage::ecrire(){
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[FORMAT_STOCKAGE]");
    bC.setExtension(".avc");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Format_binaire>1_texte>2:\n";
    monEcriture << this->format << std::endl;
    monEcriture << "Format_stockage_fichier_prelevement_DG_0>texte_1>binaire:\n";
    monEcriture << this->formatFichierPrelevement << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
