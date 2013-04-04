/* 
 * File:   blocMetallisation.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 6:50 PM
 */

#include <vector>

#include "blocMetallisation.h"

blocMetallisation::blocMetallisation() {
    this->setHeader("[METALLISATIONS]");
    this->setHeader(".dsc");
    this->setTest(2);
}

blocMetallisation::blocMetallisation(const blocMetallisation& orig) {
}

blocMetallisation::~blocMetallisation() {
}