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
    longueur=0;
    largeur=0;
    hauteur=0;
    nombreX=0;
    nombreY=0;
    nombreZ=0;
}

volumeCalcul::~volumeCalcul() {
}

void volumeCalcul::ecrire(){

    setHeader("[VOLUME_DE_CALCUL]");
    setExtension(".dsc");
    blocConfiguration::ecrire();

    
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

    Ecriture::Ecrire(monEcriture.str());

    Ecriture::Ecrire("\n");
}
