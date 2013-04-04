/* 
 * File:   compressionHuygens.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:52 PM
 */

#include "compressionHuygens.h"

compressionHuygens::compressionHuygens() {
    this->setHeader("[COMPRESSION_HUYGENS]");
    this->setExtension(".avc");
}

compressionHuygens::compressionHuygens(const compressionHuygens& orig) {
}

compressionHuygens::~compressionHuygens() {
}

