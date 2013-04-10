/* 
 * File:   coordonnee.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:38 PM
 */

#include "coordonnee.h"
coordonnee::coordonnee(){
    
}

coordonnee::coordonnee(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

coordonnee::coordonnee(const coordonnee& orig) {
}

coordonnee::~coordonnee() {
}


