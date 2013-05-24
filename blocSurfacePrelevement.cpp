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


blocSurfacePrelevement::~blocSurfacePrelevement() {
}

void blocSurfacePrelevement::ecrire(){

    setHeader("[SURFACES_DE_PRELEVEMENT]");
    setExtension(".ana");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_surfaces_de_prelevement_au_total\n";
    monEcriture << this->getNbElement() << std::endl;
    monEcriture << "Nombre_de_surfaces_de_prelevement_DG\n";
    monEcriture << this->nbSurfacesDG << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    for(int i=0; i<this->getNbElement(); i++){
        surfacePrelevement* temp = this->GetSurface(i);
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
