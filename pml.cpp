/* 
 * File:   pml.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 6:26 PM
 */

#include "pml.h"

pml::pml() {
    this->setHeader("[PML]");
    this->setExtension(".ana");
}

pml::pml(const pml& orig) {
}

pml::~pml() {
}

