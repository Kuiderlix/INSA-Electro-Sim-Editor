/* 
 * File:   cageExcitation.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:29 PM
 */

#include "cageExcitation.h"

cageExcitation::cageExcitation() : elementBase(), blocConfiguration() {
    this->setHeader("[CAGES_EXCITATION]");
    this->setExtension(".ana");
}

cageExcitation::cageExcitation(const cageExcitation& orig) : elementBase(), blocConfiguration()  {
}

cageExcitation::~cageExcitation() {
}

