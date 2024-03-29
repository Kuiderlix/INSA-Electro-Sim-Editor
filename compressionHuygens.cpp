/* 
 * File:   compressionHuygens.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:52 PM
 */

#include "compressionHuygens.h"

compressionHuygens::compressionHuygens() {
    compressionLongueur=0;
    compressionLargeur=0;
    compressionHauteur=0;
    facteurMultiplicatif=0;
}

compressionHuygens::~compressionHuygens() {
}

void compressionHuygens::ecrire(){

    setHeader("[COMPRESSION_HUYGENS]");
    setExtension(".avc");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Compression_pour_le_calcul_du_champ_lointain,_en_nombre_de_cellules\n";
    monEcriture << "Sur_la_longueur_y_(en_cellules):\n";
    monEcriture << this->compressionLongueur << std::endl;
    monEcriture << "Sur_la_largeur_x_(en_cellules):\n";
    monEcriture << this->compressionLargeur << std::endl;
    monEcriture << "Sur_la_hauteur_z_(en_cellules):\n";
    monEcriture << this->compressionHauteur << std::endl;
    monEcriture << "Facteur_multiplicatif_pour_le_nombre_d_echantillons_preleves:\n";
    monEcriture << this->facteurMultiplicatif << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
