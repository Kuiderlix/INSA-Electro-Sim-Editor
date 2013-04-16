/* 
 * File:   blocPortExcitation.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:15 PM
 */

#include <vector>

#include "blocPortExcitation.h"

blocPortExcitation::blocPortExcitation() {
}

blocPortExcitation::blocPortExcitation(const blocPortExcitation& orig) {
}

blocPortExcitation::~blocPortExcitation() {
}

void blocPortExcitation::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[PORTS_EXCITATION]");
    bC.setExtension(".ana");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_ports_d_excitation:\n";
    monEcriture << this->nbPorts << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->nbPorts; i++){
        portExcitation temp = this->portExcitations[i];
        temp.ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
