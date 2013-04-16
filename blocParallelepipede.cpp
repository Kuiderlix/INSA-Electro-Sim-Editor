/* 
 * File:   blocParallelepipede.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 7:20 PM
 */

#include "blocParallelepipede.h"

blocParallelepipede::blocParallelepipede() {
}

blocParallelepipede::blocParallelepipede(const blocParallelepipede& orig) {
}

blocParallelepipede::~blocParallelepipede() {
}

void blocParallelepipede::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[PARALLELEPIPEDES_MATERIAUX]");
    bC.setExtension(".dsc");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_parallelepipedes:\n";
    monEcriture << this->nbParallelepipede << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->nbParallelepipede; i++){
        parallelepipede temp = this->parallelepipedes[i];
        temp.ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
