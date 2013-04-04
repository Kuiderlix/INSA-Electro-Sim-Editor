/* 
 * File:   blocPortExcitation.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:15 PM
 */

#include <vector>

#include "blocPortExcitation.h"

blocPortExcitation::blocPortExcitation() {
    this->setHeader("[PORTS_EXCITATION]");
    this->setExtension(".ana");
}

blocPortExcitation::blocPortExcitation(const blocPortExcitation& orig) {
}

blocPortExcitation::~blocPortExcitation() {
}