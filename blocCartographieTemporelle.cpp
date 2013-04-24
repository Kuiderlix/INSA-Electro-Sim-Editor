/* 
 * File:   blocCartographieTemporelle.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:51 PM
 */

#include <vector>

#include "blocCartographieTemporelle.h"
#include "cartographieTemporelle.h"

blocCartographieTemporelle::blocCartographieTemporelle() {
    this->setHeader("[CARTOGRAPHIES_TEMPORELLES]");
    this->setExtension(".ana");
}

blocCartographieTemporelle::blocCartographieTemporelle(const blocCartographieTemporelle& orig) {
}

blocCartographieTemporelle::~blocCartographieTemporelle() {
}

void blocCartographieTemporelle::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[CARTOGRAPHIES_TEMPORELLES]");
    bC.setExtension(".ana");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_cartos_temporelles_: \n";
    monEcriture << this->getNbElement() << std::endl;

    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->getNbElement(); i++){
        cartographieTemporelle* temp = this->GetCarto(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
