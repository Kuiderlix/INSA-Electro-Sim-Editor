/* 
 * File:   blocSonde.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:44 PM
 */

#include <vector>

#include "blocSonde.h"

blocSonde::blocSonde() {
    this->setHeader("[SONDES]");
    this->setExtension(".ana");
}

blocSonde::blocSonde(const blocSonde& orig) {
}

blocSonde::~blocSonde() {
}