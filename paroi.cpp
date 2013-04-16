/* 
 * File:   paroi.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 5:33 PM
 */

#include "paroi.h"

paroi::paroi() {
}

paroi::paroi(const paroi& orig) {
}

paroi::~paroi() {
}

void paroi::ecrire(){
    
    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[TYPE_PAROIS_0>Mur_1>PEC_2>FLOQUET_3>PML_4>PMC]");
    bC.setExtension(".dsc");
    bC.ecrire();

    
    std::ostringstream monEcriture;
    monEcriture << "Paroi_z_inferieure:\n";
    monEcriture << this->paroiInferieure << std::endl;
    monEcriture << "Paroi_z_superieur:\n";
    monEcriture << this->paroiSuperieure << std::endl;
    monEcriture << "Parois_x=0_x=xmax:\n";
    monEcriture << this->paroiX << std::endl;
    monEcriture << "Paroi_y=0_y=ymax:\n";
    monEcriture << this->paroiY << std::endl;
    
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire("\n");
}
