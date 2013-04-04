/* 
 * File:   blocEchantillonnage.cpp
 * Author: camille
 * 
 * Created on March 4, 2013, 4:24 PM
 */

#include "blocEchantillonnage.h"

blocEchantillonnage::blocEchantillonnage() {
    this->setHeader("[ECHANTILLONNAGE]");
    this->setExtension(".avc");
}

blocEchantillonnage::blocEchantillonnage(const blocEchantillonnage& orig) {
}

blocEchantillonnage::~blocEchantillonnage() {
}

