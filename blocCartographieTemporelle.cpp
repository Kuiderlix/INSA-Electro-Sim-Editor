/* 
 * File:   blocCartographieTemporelle.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:51 PM
 */

#include <vector>

#include "blocCartographieTemporelle.h"
#include "cartographieTemporelle.h"

blocCartographieTemporelle::blocCartographieTemporelle() {
    this->setHeader("[CARTOGRAPHIES_TEMPORELLES]");
    this->setExtension(".ana");
}

blocCartographieTemporelle::blocCartographieTemporelle(const blocCartographieTemporelle& orig) {
}

blocCartographieTemporelle::~blocCartographieTemporelle() {
}