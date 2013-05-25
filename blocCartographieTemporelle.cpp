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

}

blocCartographieTemporelle::~blocCartographieTemporelle() {
}

void blocCartographieTemporelle::ecrire(){

    setHeader("[CARTOGRAPHIES_TEMPORELLES]");
    setExtension(".ana");
    blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_cartos_temporelles_: \n";
    monEcriture << this->getNbElement() << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    cartographieTemporelle* temp;
    for(int i=0; i<this->getNbElement(); i++){
        temp = this->GetCarto(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
