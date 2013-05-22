/* 
 * File:   Ecriture.cpp
 * Author: camille
 * 
 * Created on March 5, 2013, 8:37 PM
 */

#include "Ecriture.h"

Ecriture::Ecriture() {
}

Ecriture::Ecriture(const Ecriture& orig) {
}

Ecriture::~Ecriture() {
}

bool Ecriture::opened = false;
std::string Ecriture::nomFichier = "";
FILE* Ecriture::fp;
int Ecriture::numstru = 1;
