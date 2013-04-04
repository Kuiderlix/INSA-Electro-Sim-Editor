/* 
 * File:   paroi.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:33 PM
 */

#include "paroi.h"

paroi::paroi() {
    this->setHeader("[TYPE_PAROIS_0>Mur_1>PEC_2>FLOQUET_3>PML_4>PMC]");
    this->setExtension(".dsc");
}

paroi::paroi(const paroi& orig) {
}

paroi::~paroi() {
}

