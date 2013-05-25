/* 
 * File:   formatStockage.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:51 PM
 */

#include "formatStockage.h"

formatStockage::formatStockage() {
    format=0;
    formatFichierPrelevement=0;
}

formatStockage::~formatStockage() {
}

void formatStockage::ecrire(){

    setHeader("[FORMAT_STOCKAGE]");
    setExtension(".avc");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Format_binaire>1_texte>2:\n";
    monEcriture << this->format << std::endl;
    monEcriture << "Format_stockage_fichier_prelevement_DG_0>texte_1>binaire:\n";
    monEcriture << this->formatFichierPrelevement << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
