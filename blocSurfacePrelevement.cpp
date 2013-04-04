/* 
 * File:   blocSurfacePrelevement.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:58 PM
 */

#include <vector>

#include "blocSurfacePrelevement.h"

blocSurfacePrelevement::blocSurfacePrelevement() {
    this->setHeader("[SURFACES_DE_PRELEVEMENT]");
    this->setExtension(".ana");
}

blocSurfacePrelevement::blocSurfacePrelevement(const blocSurfacePrelevement& orig) {
}

blocSurfacePrelevement::~blocSurfacePrelevement() {
}