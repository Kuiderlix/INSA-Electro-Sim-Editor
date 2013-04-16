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

void blocAmplitude::ecrire(){
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[EXCITATION]");
    bC.setExtension(".avc");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Amplitude_V0:\n";
    monEcriture << this->amplitudeV0 << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
