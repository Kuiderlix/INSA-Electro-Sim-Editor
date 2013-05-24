/* 
 * File:   champLointain.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:47 PM
 */

#include "champLointain.h"

champLointain::champLointain() {
    this->setHeader("[CALCUL_CHAMP_LOINTAIN]");
    this->setExtension(".ptr");
    frequenceMin=0;
    frequenceMax=0;
    pasFrequence=0;
    calculImage=0;
    hauteurPlanMasse=0;
    pasDiscrTeta=0;
    pasDiscrPhi=0;
}

champLointain::~champLointain() {
}

void champLointain::ecrire(){

    setHeader("[CALCUL_CHAMP_LOINTAIN]");
    setExtension(".ptr");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_surfaces_de_Huygens\n";
    monEcriture << 1 << std::endl;                          //TODO: p-e pb ici si pas de surface
    monEcriture << "Surface_Huygens_1:\n";
    monEcriture << "Nom_du_fichier:\n";
    monEcriture << this->nomFichier << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    //Origine repere
    Ecriture::Ecrire("Origine_repere:\n");
    this->origineRepere.ecrire();

    std::ostringstream finEcriture;
    finEcriture << "Frequences_de_calcul:\n";
    finEcriture << "Frequence_min_en_GHz:\n";
    finEcriture << this->frequenceMin << std::endl;
    finEcriture << "Frequence_max_en_GHz:\n";
    finEcriture << this->frequenceMax << std::endl;
    finEcriture << "Pas_de_frequence_en_GHz:\n";
    finEcriture << this->pasFrequence << std::endl;
    finEcriture << "Calcul_image_pour_champ_lointain_0>NON_1>OUI:\n";
    finEcriture << ((int)this->calculImage) << std::endl;
    finEcriture << "Coordonnees_en_z_du_plan_de_masse_de_reference_pour_le_calcul_du_champ_lointain:\n";
    finEcriture << this->hauteurPlanMasse << std::endl;
    finEcriture << "Plans_calcules:\n";
    finEcriture << "Pas_de_discrétisation_selon_theta_(en_degres):\n";
    finEcriture << this->pasDiscrTeta << std::endl;
    finEcriture << "Pas_de_discrétisation_selon_phi_(en_degres):\n";
    finEcriture << this->pasDiscrPhi << std::endl;
    std::string ecritureFin(finEcriture.str());
    Ecriture::Ecrire(ecritureFin);

    Ecriture::Ecrire("\n");
}

