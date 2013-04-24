/* 
 * File:   blocSurfacePrelevement.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 10:58 PM
 */

#include <vector>

#include "blocSurfacePrelevement.h"

blocSurfacePrelevement::blocSurfacePrelevement() {
    this->setHeader("[SURFACES_DE_PRELEVEMENT]");
    this->setExtension(".ana");
}

blocSurfacePrelevement::blocSurfacePrelevement(const blocSurfacePrelevement& orig) {
}

blocSurfacePrelevement::~blocSurfacePrelevement() {
}

void blocSurfacePrelevement::ecrire(){

    blocConfiguration bC = blocConfiguration(*this);
    bC.setHeader("[SURFACES_DE_PRELEVEMENT]");
    bC.setExtension(".ana");
    bC.ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_surfaces_de_prelevement_au_total\n";
    monEcriture << this->getNbElement() << std::endl;
    monEcriture << "Nombre_de_surfaces_de_prelevement_DG\n";
    monEcriture << this->nbSurfacesDG << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    for(int i=0; i<this->getNbElement(); i++){
        surfacePrelevement* temp = this->GetSurface(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
