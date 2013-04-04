/* 
 * File:   blocElementLocalise.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 7:29 PM
 */

#include <vector>

#include "blocElementLocalise.h"
#include "elementLocalise.h"

blocElementLocalise::blocElementLocalise() {
    this->setHeader("[ELEMENTS_LOCALISES]");
    this->setExtension(".dsc");
}

blocElementLocalise::blocElementLocalise(const blocElementLocalise& orig) {
}

blocElementLocalise::~blocElementLocalise() {
}