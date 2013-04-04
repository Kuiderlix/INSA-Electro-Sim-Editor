/* 
 * File:   blocAmplitude.cpp
 * Author: camille
 * 
 * Created on March 4, 2013, 4:20 PM
 */

#include "blocAmplitude.h"

blocAmplitude::blocAmplitude() {
    this->setHeader("[EXCITATION]");
    this->setExtension(".avc");
}

blocAmplitude::blocAmplitude(const blocAmplitude& orig) {
}

blocAmplitude::~blocAmplitude() {
}

