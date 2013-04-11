/* 
 * File:   coordonnee.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:38 PM
 */

#include "coordonnee.h"
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


