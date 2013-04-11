/* 
 * File:   metallisation.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:37 PM
 */

#include "metallisation.h"

metallisation::metallisation() {
    conductivite=4.5;
    this->arriereDroit = coordonnee(1,2,3);
    this->avantGauche = coordonnee(3,2,1);
}

metallisation::metallisation(const metallisation& orig) {
}

metallisation::~metallisation() {
}

