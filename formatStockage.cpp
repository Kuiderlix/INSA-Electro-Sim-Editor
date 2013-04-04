/* 
 * File:   formatStockage.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:51 PM
 */

#include "formatStockage.h"

formatStockage::formatStockage() {
    this->setHeader("[FORMAT_STOCKAGE]");
    this->setExtension(".avc");
}

formatStockage::formatStockage(const formatStockage& orig) {
}

formatStockage::~formatStockage() {
}

