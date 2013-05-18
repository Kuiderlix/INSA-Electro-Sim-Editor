/* 
 * File:   blocAmplitude.cpp
 * Author: camille
 * 
 * Created on March 4, 2013, 4:20 PM
 */

#include "Excitation.h"

Excitation::Excitation() {
    this->setHeader("[Excitation]");
    this->setExtension(".avc");

    amplitudeV0=0;
}

Excitation::~Excitation() {
}

void Excitation::ecrire(){
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[Excitation]");
    bC.setExtension(".avc");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Amplitude_V0:\n";
    monEcriture << this->amplitudeV0 << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
