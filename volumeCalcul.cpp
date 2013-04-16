/* 
 * File:   volumeCalcul.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:23 PM
 */

#include "volumeCalcul.h"
#include <sstream>
#include <string>

volumeCalcul::volumeCalcul() {
}

volumeCalcul::volumeCalcul(const volumeCalcul& orig) {
}

volumeCalcul::~volumeCalcul() {
}

void volumeCalcul::ecrire(){
    
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[VOLUME_DE_CALCUL]");
    bC.setExtension(".dsc");
    bC.ecrire();

    
    std::ostringstream monEcriture;
    monEcriture << "Longueur_y_de_la_boite_(en_mm):\n";
    monEcriture << this->longueur << std::endl;
    monEcriture << "Largeur_x_de_la_boite_(en_mm):\n";
    monEcriture << this->largeur << std::endl;
    monEcriture << "Hauteur_z_de_la_boite_(en_mm):\n";
    monEcriture << this->hauteur << std::endl;
    monEcriture << "Nombre_de_cellules_sur_la_longueur_y:\n";
    monEcriture << this->nombreY << std::endl;
    monEcriture << "Nombre_de_cellules_sur_la_largeur_x:\n";
    monEcriture << this->nombreX << std::endl;
    monEcriture << "Nombre_de_cellules_sur_la_hauteur_z:\n";
    monEcriture << this->nombreZ << std::endl;
    
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
