/*
 * File:   cageExcitation.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:29 PM
 */

#include "cageExcitation.h"

cageExcitation::cageExcitation() : elementBase(), blocConfiguration() {
    create = false;


    insideOutside=0;
    nbFaces=0;
    typeExcitation=0;
    modeExcitation=0;
    hauteur=0;
    sensPropagation=0;
    theta0=0;
    phi0=0;
    psi0=0;
    modulationAmplitude=0;
    modulationPhase=0;

    nomFichier="";

    // on affiche la cage d'excitation avec une transparence dès le début car
    // elle recouvre la plupart du temps le reste du scénario
    this->setAlpha(125);


}


cageExcitation::~cageExcitation() {
}

void cageExcitation::ecrire(){

    setHeader("[CAGES_EXCITATION]");
    setExtension(".ana");
    this->blocConfiguration::ecrire();

    std::ostringstream monEcriture;
    monEcriture << "Nombre_de_cages_d_excitation:\n";
    if (!isCreate())
    {
        monEcriture << 0 << std::endl;
        Ecriture::Ecrire(monEcriture.str());
    }
    else
    {
        monEcriture << 1 << std::endl;
        monEcriture << "Cage_excitation_numero_1\n";
        monEcriture << "Type_excitation_1>inside_2>outside\n";
        monEcriture << this->insideOutside << std::endl;
        monEcriture << "Nombre_de_faces_d_excitation:\n";
        monEcriture << this->nbFaces << std::endl;
        monEcriture << "Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation\n";
        monEcriture << this->typeExcitation << std::endl;

        if(this->nbFaces == 1 && this->typeExcitation >= 1 && this->typeExcitation <= 3){
            monEcriture << "Type_0>OndeplaneX_1>OndeplaneY_2>GuideTE10X_3>GuideTE10Y:\n";
            monEcriture << this->modeExcitation << std::endl;
            monEcriture << "Coordonnees_sur_la_hauteur:\n";
            monEcriture << this->hauteur << std::endl;
            monEcriture << "Sens_de_propagation_de_l_onde_-1>z_croissants_2>z_decroissants:\n";
            monEcriture << this->sensPropagation << std::endl;

            std::string ecriture(monEcriture.str()); //Il faut qu'on écrive ici, car il y a les coordonnées après
            Ecriture::Ecrire(ecriture);
        } else {

            if(this->typeExcitation == 4){
                monEcriture << "Nom_du_fichier\n";
                monEcriture << this->nomFichier << std::endl;
            }

            //Du coup on écrit aussi dans le else
            Ecriture::Ecrire(monEcriture.str());

            //On écrit les coordonnées
            this->ecrireElementBase();

            //On ouvre un aute flux
            std::ostringstream finEcriture;

            if(this->typeExcitation >= 1 && this->typeExcitation <= 3){
                Ecriture::Ecrire("Coordonnees_du_point_de_reference\n");
                this->GetPointReference().ecrire();

                finEcriture << "Avec_les_angles_d_incidence_en_degres\n";
                finEcriture << "theta0:\n";
                finEcriture << this->theta0 << std::endl;
                finEcriture << "phi0:\n";
                finEcriture << this->phi0 << std::endl;
                finEcriture << "psi0_(angle_forme_par_vecteur_E_et_e_theta):\n";
                finEcriture << this->psi0 << std::endl;
            }

            if(this->typeExcitation == 4){
                finEcriture << "Coefficient_modulation_amplitude:\n";
                finEcriture << this->modulationAmplitude << std::endl;
                finEcriture << "Coefficient_modulation_phase_(retard_temporel):\n";
                finEcriture << this->modulationPhase << std::endl;
            }

            Ecriture::Ecrire(finEcriture.str());
        }

    }

    Ecriture::Ecrire("\n");
}
