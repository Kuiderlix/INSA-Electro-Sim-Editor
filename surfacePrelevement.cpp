/*
 * File:   surfacePrelevement.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:44 PM
 */

#include "surfacePrelevement.h"
#include <string>
#include <sstream>
#include "Ecriture.h"

surfacePrelevement::surfacePrelevement() {
    typeSurface=1;
    insideOutside=0;
    nbFaces=0;
    compressionLongueur=0;
    compressionLargeur=0;
    compressionHauteur=0;
}


surfacePrelevement::~surfacePrelevement() {
}

void surfacePrelevement::ecrire(int type){

    //Etablissons le type :
    std::string Stype = (type == 1) ? "Huygens" : ((type == 2) ? "DG" : "Kirchoff");

    std::ostringstream monEcriture;
    monEcriture << "Surface_de_prelevement_" << Stype << "\n";
    monEcriture << "Type_de_surface_1>Huygens_2>Surface_de_prelevement_DG_3>Kirchhoff\n";
    monEcriture << this->typeSurface << std::endl;
    monEcriture << "Nom_du_fichier\n";
    monEcriture << this->nomFichier << std::endl;
    if(this->typeSurface == 2){
        monEcriture << "Excitation_1>inside_2>outside\n";
        monEcriture << this->insideOutside << std::endl;
    }
    monEcriture << "Nombre_de_faces_:\n";
    monEcriture << this->nbFaces << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    this->ecrireElementBase();

    if(this->GetTypeSurface() == 2){
        std::ostringstream finEcriture;
        finEcriture << "Compression_pour_le_calcul_du_champ_proche,_en_nombre_de_cellules\n";
        finEcriture << "Sur_la_longueur_(en_cellules),_un_diviseur_de_??\n";
        finEcriture << this->compressionLongueur << std::endl;
        finEcriture << "Sur_la_largeur_(en_cellules),_un_diviseur_de_??\n";
        finEcriture << this->compressionLargeur << std::endl;
        finEcriture << "Sur_la_hauteur_(en_cellules),_un_diviseur_de_??\n";
        finEcriture << this->compressionHauteur << std::endl;
        std::string ecritureFin(finEcriture.str());
        Ecriture::Ecrire(ecritureFin);
    }

}
