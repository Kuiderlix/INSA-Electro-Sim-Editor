/* 
 * File:   Ecriture.cpp
 * Author: camille
 * 
 * Created on March 5, 2013, 8:37 PM
 */

#include "Ecriture.h"


bool Ecriture::opened = false;
std::string Ecriture::nomFichier = "";
FILE* Ecriture::fp;
int Ecriture::numstru = 1;
