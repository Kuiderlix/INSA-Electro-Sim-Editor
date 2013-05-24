/* 
 * File:   cartographieTemporelle.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:42 PM
 */

#include "cartographieTemporelle.h"
#include <string>
#include <sstream>
#include "Ecriture.h"

cartographieTemporelle::cartographieTemporelle() {
    champE=false;
    champH=false;
    iterationDebut=0;
    iterationFin=0;
    intervalle=0;
}

cartographieTemporelle::~cartographieTemporelle() {
}

void cartographieTemporelle::ecrire(int nb){

    std::ostringstream monEcriture;
    monEcriture << "Carto_" << nb << "\n";
    monEcriture << "Sauve_ChampE_(1=OUI_0=NON)_:\n";
    monEcriture << ((int)this->champE) << std::endl;
    monEcriture << "Sauve_ChampH_(1=OUI_0=NON)_:\n";
    monEcriture << ((int)this->champH) << std::endl;
    monEcriture << "Iteration_debut_(moins1=debut_simu)_:\n";
    monEcriture << this->iterationDebut << std::endl;
    monEcriture << "Iteration_fin___(moins1=fin_simu)___:\n";
    monEcriture << this->iterationFin << std::endl;
    monEcriture << "Intervalle_d_enregistrement_____:\n";
    monEcriture << this->intervalle << std::endl;

    Ecriture::Ecrire(monEcriture.str());

    //Les coordonnées
    this->ecrireElementBase();
}
