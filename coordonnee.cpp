/* 
 * File:   coordonnee.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:38 PM
 */

#include "coordonnee.h"
#include "Ecriture.h"
#include <string>
#include <sstream>
coordonnee::coordonnee(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

coordonnee::coordonnee(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

coordonnee::coordonnee(const coordonnee& orig) {
    this->x = orig.x;
    this->y = orig.y;
    this->z = orig.z;
}

coordonnee::~coordonnee() {
}

bool coordonnee::operator ==(const coordonnee &b)
{
    return this->x==b.x && this->y==b.y && this->z==b.z;;
}

void coordonnee::ecrire(){
    std::ostringstream monEcriture;

    monEcriture << "Sur_la_longueur_y_(en_cellules):\n";
    monEcriture << this->GetY() << std::endl;
    monEcriture << "Sur_la_largeur_x_(en_cellules):\n";
    monEcriture << this->GetX() << std::endl;
    monEcriture << "Sur_la_hauteur_z_(en_cellules):\n";
    monEcriture << this->GetZ() << std::endl;

    Ecriture::Ecrire(monEcriture.str());
}
