/******************************************************************************/
/**>INTERFACE SYSTEME *********************************************************/
/******************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <iostream>
#include "constants.h"
#include "structures.h"
#include "CageExcitation.h"
#include "SurfacePrelevement.h"

using namespace std;
/******************************************************************************/
/** >VARIABLES DU PARSER ******************************************************/
/******************************************************************************/
#define TAILLE_NOM_FICHIER 10
#define TAILLE_CHAINE 100
char nomfic[TAILLE_NOM_FICHIER];
FILE *fp;
char chaine[TAILLE_CHAINE];

//TODO: Récupérer le numéro de fichier (ex: 7) pour Data7.dsc
int numstru = 1;

/******************************************************************************/
/** >VARIABLES RECUPEREES .DSC ************************************************/
/******************************************************************************/
//Volume de Calcul
float lxboit, lyboit, lzboit;
int nxboit, nyboit, nzboit;
//Type de Paroi
int typaroi;
int typaroi_inf, typaroi_sup, typaroi_x, typaroi_y; //Variables locales ? Pas utilisées ?
//Metallisation
Metallisation *meta;
int nbmeta;
//Parallelepipedes
Substrat *subs;
int nbsubs;
//Elements localises
ElementLocalise *elts;
int nbelt;

/******************************************************************************/
/** >VARIABLES RECUPEREES .ANA ************************************************/
/******************************************************************************/
int onde_plane_oblique;
int nbports_excitation;
//PML
int n_couche, m_pml;
float sigma_max, k_max;
//Parametres d'excitation
float frehau, f_sinus;
int gausstype;
//Analyse temporelle
float dt, tobs;
//Ports d'Excitation
PortExcitation *portexcit;
//Cages d'Excitation
int nb_cages_excitation;
CageExcitation cageExcitation;
//Sondes
int nbsonde;
Sonde *sonde;
//Cartographie temporelle
int nbcarto;
CartographieTemporelle *CT;
//Surface de prélèvement
int ind_ch_loin, ind_ch_Prel_DG, cpt_surf_DG;
int nbsurf_prel;
int nb_surf_Prel_DG;
SurfacePrelevement surface;

/******************************************************************************/
/** >VARIABLES RECUPEREES .PTR ************************************************/
/******************************************************************************/
//Champ lointain
int nbsurf_huy;
int x_origine;
int y_origine;
int z_origine;
float freq_min_ch_loin;
float freq_max_ch_loin;
float freq_pas_ch_loin;
int ind_cal_image;
int z_masse_ref;
int pas_theta;
int pas_phi;

/******************************************************************************/
/** >VARIABLES RECUPEREES .AVC ************************************************/
/******************************************************************************/
//Excitation
float v0;
//Format stockage
int format_stock;
int flag_EnregChampsPrelBinaire;
//Echantillonnage
int fact_echantill;
//Compression Huygens
int compx_Huy;
int compy_Huy;
int compz_Huy;
int fact_echantill_huy;
int inter_iter;
//Calcul directivité
int ind_direct;
int pas_theta_dir;
int pas_phi_dir;
/******************************************************************************/
/** >FONCTION PARSAGE .DSC ****************************************************/
/******************************************************************************/
void scanVolumeDeCalcul() {
    fscanf(fp, "%*s");
    fscanf(fp, "%f", &lyboit);
    fscanf(fp, "%*s");
    fscanf(fp, "%f", &lxboit);
    fscanf(fp, "%*s");
    fscanf(fp, "%f", &lzboit);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nyboit);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nxboit);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nzboit);

    printf("Longueur_y_de_la_boite_(en_mm):\n");
    printf("%f\n", lyboit);
    printf("Largeur_x_de_la_boite_(en_mm):\n");
    printf("%f\n", lxboit);
    printf("Hauteur_z_de_la_boite_(en_mm):\n");
    printf("%f\n", lzboit);
    printf("Nombre_de_cellules_sur_la_longueur_y:\n");
    printf("%d\n", nyboit);
    printf("Nombre_de_cellules_sur_la_largeur_x:\n");
    printf("%d\n", nxboit);
    printf("Nombre_de_cellules_sur_la_hauteur_z:\n");
    printf("%d\n", nzboit);
}

void scanTypeParoi() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &typaroi_inf); //Paroi inferieure
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &typaroi_sup); //Paroi superieure
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &typaroi_x); //Paroi x=1 , nxboit+1
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &typaroi_y); //Paroi y=1 , nyboit+1

    if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_MUR) &&
            (typaroi_x == PAROI_MUR) &&
            (typaroi_y == PAROI_MUR)) {
        typaroi = 0;
    } else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PEC)) {
        typaroi = 1;
    } else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PEC)) {
        typaroi = 2;
    } else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_FLOQUET) &&
            (typaroi_y == PAROI_FLOQUET)) {
        typaroi = 3;
    } else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_FLOQUET) &&
            (typaroi_y == PAROI_FLOQUET)) {
        typaroi = 4;
    } else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_PML)) {
        typaroi = 5;
    } else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_PML)) {
        typaroi = 6;
    } else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_FLOQUET)) {
        typaroi = 7;
    } else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_FLOQUET)) {
        typaroi = 8;
    } else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PMC)) {
        typaroi = 9;
    } else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PMC)) {
        typaroi = 10;
    } else {
        printf("\n\n\7\7 ** Definition des ABCs non conforme aux fonctionnalites du code **\n");
        exit(0);
    }

    printf("Parois_0>ABC_1>Metal_avec_GND_1>Metal_avec_2PMLs_3>FLOQUET_avec_GND_4>FLOQUET_avec_2PMLs_5>PMLs5faces_6>PMLs6faces:\n");
    printf("%d\n", typaroi);
}

void scanMetallisation() {

    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbmeta);

    printf("Nombre_de_plans_de_metallisation:\n");
    printf("%d\n", nbmeta);

    meta = (Metallisation *) calloc(nbmeta + 1, sizeof (Metallisation)); // Modif QUEUDET : allocation dynamique de la liste des m�tallisations

    int i;
    for (i = 0; i < nbmeta; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &meta[i].metal_cond);

        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &meta[i].iym1);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &meta[i].ixm1);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &meta[i].izm1);

        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &meta[i].iym2);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &meta[i].ixm2);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &meta[i].izm2);

        // verification des donnees
        if (meta[i].izm1 != meta[i].izm2)
            if (meta[i].iym1 != meta[i].iym2)
                if (meta[i].ixm1 != meta[i].ixm2) {
                    printf("Erreur: Les metallisations sont forcement des plans");
                    exit(0);
                }
    }

    //Affichage des m�talisations
    for (i = 0; i < nbmeta; i++) {
        printf("Metallisation_numero_%d\n", i + 1);
        printf("Conductivit�:\n");
        printf("%f\n", meta[i].metal_cond);

        printf("Coordonnees_du_coin_inferieur_avant_gauche\n");
        printf("Sur_la_longueur_y_(en_cellules):\n");
        printf("%d\n", meta[i].iym1);
        printf("Sur_la_largeur_x_(en_cellules):\n");
        printf("%d\n", meta[i].ixm1);
        printf("Sur_la_hauteur_z_(en_cellules):\n");
        printf("%d\n", meta[i].izm1);

        printf("Coordonnees_du_coin_superieur_arriere_droit\n");
        printf("Sur_la_longueur_y_(en_cellules):\n");
        printf("%d\n", meta[i].iym2);
        printf("Sur_la_largeur_x_(en_cellules):\n");
        printf("%d\n", meta[i].ixm2);
        printf("Sur_la_hauteur_z_(en_cellules):\n");
        printf("%d\n", meta[i].izm2);

    }
}

void scanParallelepipedes() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbsubs);

    printf("Nombre_de_parallelepipedes:\n");
    printf("%d\n", nbsubs);

    subs = (Substrat *) calloc(nbsubs + 1, sizeof (Substrat)); // Modif GODI/QUEUDET : allocation dynamique de la liste de substrats

    int i;
    for (i = 0; i < nbsubs; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &subs[i].perm);
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &subs[i].permea);
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &subs[i].cond);
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &subs[i].iys1);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &subs[i].ixs1);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &subs[i].izs1);
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &subs[i].iys2);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &subs[i].ixs2);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &subs[i].izs2);

        printf("parallelepipede_numero_%d\n", i + 1);
        printf("Permittivite_relative:\n");
        printf("%f\n", subs[i].perm);
        printf("Permeabilite_relative:\n");
        printf("%f\n", subs[i].permea);
        printf("Conductivite:\n");
        printf("%f\n", subs[i].cond);

        if (subs[i].permea != 1.0) {
            printf("Les materiaux magnetiques ne sont pas pris en compte dans cette version du code\n");
        }

        printf("Coordonnees_du_coin_inferieur_avant_gauche\n");
        printf("Sur_la_longueur_y_(en_cellules):\n");
        printf("%d\n", subs[i].iys1);
        printf("Sur_la_largeur_x_(en_cellules):\n");
        printf("%d\n", subs[i].ixs1);
        printf("Sur_la_hauteur_z_(en_cellules):\n");
        printf("%d\n", subs[i].izs1);

        printf("Coordonnees_du_coin_superieur_arriere_droit\n");
        printf("Sur_la_longueur_y_(en_cellules):\n");
        printf("%d\n", subs[i].iys2);
        printf("Sur_la_largeur_x_(en_cellules):\n");
        printf("%d\n", subs[i].ixs2);
        printf("Sur_la_hauteur_z_(en_cellules):\n");
        printf("%d\n", subs[i].izs2);
    }
}

void scanElementsLocalises() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbelt);

    printf("Nombre_d_elements_localises:\n");
    printf("%d\n", nbelt);

    if (nbelt > 0) {
        elts = (ElementLocalise *) calloc(nbelt + 1, sizeof (ElementLocalise)); // Modif QUEUDET : allocation dynamique de la liste des elements localises

        int i;
        for (i = 0; i < nbelt; i++) {
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].type);
            fscanf(fp, "%*s");
            fscanf(fp, "%e", &elts[i].val);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].dir);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].iy1);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].ix1);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].iz1);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].iy2);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].ix2);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &elts[i].iz2);

            printf("Element_Localise_numero_%i\n", i + 1);
            printf("Type_d_element_1>resistance_2>capacite_3>self:\n");
            printf("%d\n", elts[i].type);
            printf("Valeur_de_l_element_en_Ohm_Farad_ou_Henry:\n");
            printf("%e\n", elts[i].val);
            printf("Direction_1>x_2>y_3>z\n");
            printf("%d\n", elts[i].dir);

            printf("Coordonnees_du_coin_inferieur:\n");
            printf("Sur_la_longueur_y_(en_cellules):\n");
            printf("%d\n", elts[i].iy1);
            printf("Sur_la_largeur_x_(en_cellules):\n");
            printf("%d\n", elts[i].ix1);
            printf("Sur_la_hauteur_z_(en_cellules):\n");
            printf("%d\n", elts[i].iz1);

            printf("Coordonnees_du_coin_superieur\n");
            printf("Sur_la_longueur_y_(en_cellules):\n");
            printf("%d\n", elts[i].iy2);
            printf("Sur_la_largeur_x_(en_cellules):\n");
            printf("%d\n", elts[i].ix2);
            printf("Sur_la_hauteur_z_(en_cellules):\n");
            printf("%d\n", elts[i].iz2);

        }
    }
}

void parseDSC() {
    sprintf(nomfic, "DATA%d.dsc\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.dsc **\n");
        printf("*****************************************\n");

        do {
            fgets(chaine, 100, fp);
            //printf("%s\n",chaine);

            /*
             * Dimensions du volume de simulation.
             */
            if (0 == strcmp(chaine, "[VOLUME_DE_CALCUL]\n"))
                scanVolumeDeCalcul();
            if (0 == strcmp(chaine, "[TYPE_PAROIS_0>Mur_1>PEC_2>FLOQUET_3>PML_4>PMC]\n"))
                scanTypeParoi();
            if (0 == strcmp(chaine, "[METALLISATIONS]\n"))
                scanMetallisation();
            if (0 == strcmp(chaine, "[PARALLELEPIPEDES_MATERIAUX]\n"))
                scanParallelepipedes();
            if (0 == strcmp(chaine, "[ELEMENTS_LOCALISES]\n"))
                scanElementsLocalises();


        } while (!feof(fp));

        fclose(fp);
        printf("**  FIN CHARGEMENT STRUCTURE DATA.dsc  **\n");
        printf("*****************************************\n");
    }
}

/******************************************************************************/
/** >FONCTION PARSAGE .ANA ****************************************************/

/******************************************************************************/
void scanPML() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &n_couche);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &m_pml);
    fscanf(fp, "%*s");
    fscanf(fp, "%f", &sigma_max);
    fscanf(fp, "%*s");
    fscanf(fp, "%f", &k_max);

    printf("Epaisseur_de_la_couche_(en_cellules):\n");
    printf("%d\n", n_couche);
    printf("Ordre_de_la_variation_geometrique_de_sigma_(valeur_de_m):\n");
    printf("%d\n", m_pml);
    printf("Sigma_max:\n");
    printf("%f\n", sigma_max);
    printf("K_max:\n");
    printf("%f\n", k_max);
}

void scanParametreExcitation() {
    fscanf(fp, "%*s");
    fscanf(fp, "%e", &frehau);
    fscanf(fp, "%*s");
    fscanf(fp, "%i", &gausstype);

    printf("Frequence_maximale_de_la_bande_d'analyse_(en_GHz):\n");
    printf("%e\n", frehau);
    printf("Excitation_0>Gaussienne_1>Gaussienne_modulant_un_sinus:\n");
    printf("%i\n", gausstype);

    if (gausstype == 1) {
        fscanf(fp, "%*s");
        fscanf(fp, "%e", &f_sinus);

        printf("Frequence_du_sinus_(GHz):\n");
        printf("%e\n", f_sinus);
    }
}

void scanAnalyseTemporelle() {
    fscanf(fp, "%*s");
    fscanf(fp, "%e", &dt);
    fscanf(fp, "%*s");
    fscanf(fp, "%e", &tobs);

    printf("Periode_d'echantillonnage_temporelle_(en_s):\n");
    printf("%e\n", dt);
    printf("Temps_d'observation_(en_s):\n");
    printf("%e\n", tobs);
}

void scanPortExcitation() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbports_excitation);

    if (nbports_excitation > 0) {
        portexcit = (PortExcitation *) calloc(nbports_excitation + 1, sizeof (PortExcitation));

        int i;
        for (i = 0; i < nbports_excitation; i++) {
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].port_actif);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].port_inf);
            if (portexcit[i].port_inf) {
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &portexcit[i].port_type);
            }
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].dir);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].iy1);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].ix1);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].iz1);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].iy2);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].ix2);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].iz2);
            fscanf(fp, "%*s");
            fscanf(fp, "%f", &portexcit[i].imp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &portexcit[i].type);
            fscanf(fp, "%*s");
            fscanf(fp, "%f", &portexcit[i].ampl);
            fscanf(fp, "%*s");
            fscanf(fp, "%f", &portexcit[i].delai);

            printf("Port_d'excitation_numero_%i\n", i + 1);
            printf("Port_actif_OUI>1_NON>0:\n");
            printf("%d\n", portexcit[i].port_actif);
            printf("Port_infinitésimal_OUI>1_NON>0\n");
            printf("%d\n", portexcit[i].port_inf);
            if (portexcit[i].port_inf) {
                printf("Port_type_Magnétique>1_Electrique>2\n");
                printf("%d\n", portexcit[i].port_type);
            }
            printf("Direction_1>x_2>y_3>z\n");
            printf("%d\n", portexcit[i].dir);

            printf("Coordonnees_du_coin_inferieur_gauche:\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d\n", portexcit[i].iy1);
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d\n", portexcit[i].ix1);
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d\n", portexcit[i].iz1);

            printf("Coordonnee_du_coin_superieur_droit\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d\n", portexcit[i].iy2);
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d\n", portexcit[i].ix2);
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d\n", portexcit[i].iz2);

            printf("Impedance_de_la_source_(en_Ohm):\n");
            printf("%f\n", portexcit[i].imp);
            printf("Source_de_tension>1_Source_de_courant):\n");
            printf("%d\n", portexcit[i].type);
            printf("PondEration_d_amplitude:\n");
            printf("%f\n", portexcit[i].ampl);
            printf("Ponderation_phase_(retard_temporel_en_s):\n");
            printf("%f\n", portexcit[i].delai);

        }
    }
}

void scanCageExcitation() {
    onde_plane_oblique = NON; // flags indiquant la presence ou non d'une excitation par onde plane 5 ou 6 faces

    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nb_cages_excitation);

    if (nb_cages_excitation > 1) {
        printf("Erreur. Il ne peut y avoir qu'une seule cage d'excitation dans le programme.");
        exit(0);
    }

    printf("Nombre de cages d'excitation:\n");
    printf("%d\n", nb_cages_excitation);

    if (nb_cages_excitation == 1) {
        int int_temp;
        float float_temp;
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &int_temp);
        cageExcitation.setInside_outside(int_temp);

        if (cageExcitation.getInside_outside() == 1) //si excitation de type inside
        {
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            cageExcitation.setNb_faces_excitation(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            cageExcitation.setType_excitation(int_temp);

            if (cageExcitation.getType_excitation() == 1 ||
                    cageExcitation.getType_excitation() == 2 ||
                    cageExcitation.getType_excitation() == 3) {

                printf("Cage_d_excitation");
                printf("Nombre_de_faces_d_excitation:\n");
                printf("%d\n", cageExcitation.getNb_faces_excitation());
                printf("Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation:\n");
                printf("%d\n", cageExcitation.getType_excitation());


                if ((cageExcitation.getNb_faces_excitation() == 5) ||
                        (cageExcitation.getNb_faces_excitation() == 6)) {
                    // activation du flag onde plane oblique
                    onde_plane_oblique = OUI;

                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMy_inc_inf(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMx_inc_inf(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMz_inc_inf(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMy_inc_sup(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMx_inc_sup(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMz_inc_sup(int_temp);
                    //TODO : les variables dessous étaient à l'origine uniques
                    // (pas de [i]) mais il fallait quand même les déclarer
                    // pour chaque cage. À garder ?????
                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setY_inc0(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setX_inc0(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setZ_inc0(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%f", &float_temp);
                    cageExcitation.setTheta0deg(float_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%f", &float_temp);
                    cageExcitation.setPhi0deg(float_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%f", &float_temp);
                    cageExcitation.setPsi0deg(float_temp);

                    printf("Coordonnees_du_coin_inferieur_gauche\n");
                    printf("Sur_la_longueur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getMy_inc_inf());
                    printf("Sur_la_largeur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getMx_inc_inf());
                    printf("Sur_la_hauteur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getMz_inc_inf());

                    printf("Coordonnee_du_coin_superieur_droit\n");
                    printf("Sur_la_longueur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getMy_inc_sup());
                    printf("Sur_la_largeur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getMx_inc_sup());
                    printf("Sur_la_hauteur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getMz_inc_sup());

                    printf("Coordonnees_du_point_de_reference\n");
                    printf("Sur_la_longueur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getY_inc0());
                    printf("Sur_la_largeur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getX_inc0());
                    printf("Sur_la_hauteur_(en_cellules):\n");
                    printf("%d\n", cageExcitation.getZ_inc0());

                    printf("Avec_les_angles_d_incidence_en_degres\n");
                    printf("theta0:\n");
                    printf("%f\n", cageExcitation.getTheta0deg());
                    printf("phi0:\n");
                    printf("%f\n", cageExcitation.getPhi0deg());
                    printf("psi0:\n");
                    printf("%f\n", cageExcitation.getPsi0deg());

                } else if (cageExcitation.getNb_faces_excitation() == 1) {
                    onde_plane_oblique = NON;

                    //Ces valeurs également étaient uniques également
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setMode_excitation(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setZexc(int_temp);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &int_temp);
                    cageExcitation.setSens_propa(int_temp);

                    printf("Type_0>OndeplaneX_1>OndeplaneY_2>GuideTE10X_3>GuideTE10Y:\n");
                    printf("%d\n", cageExcitation.getMode_excitation());
                    printf("Coordonnees_sur_la_hauteur:\n");
                    printf("%d\n", cageExcitation.getZexc());
                    printf("Sens_de_propagation_de_l_onde_-1>z_croissants_1>z_decroissants:\n");
                    printf("%d\n", cageExcitation.getSens_propa());
                } else {
                    printf("\n\7 excitation non disponible dans ce code\n");
                    exit(0);
                }

            } else if (cageExcitation.getType_excitation() == 4) // excitation inside � partir d'un fichier d'excitation
            {

                fscanf(fp, "%*s");
                fscanf(fp, "%*s"); // nom du fichier d'excitation;
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMy_inc_inf(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMx_inc_inf(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMz_inc_inf(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMy_inc_sup(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMx_inc_sup(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMz_inc_sup(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &float_temp);
                cageExcitation.setMod_ampl_Exci(float_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &float_temp);
                cageExcitation.setMod_ret_Exci(float_temp);

                printf("Cage_d_excitation\n");
                printf("Nombre_de_faces_d_excitation:\n");
                printf("%d\n", cageExcitation.getNb_faces_excitation());
                printf("Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation:\n");
                printf("%d\n", cageExcitation.getType_excitation());

                printf("Coordonnees_du_coin_inferieur_gauche\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMy_inc_inf());
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMx_inc_inf());
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMz_inc_inf());

                printf("Coordonnee_du_coin_superieur_droit\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMy_inc_sup());
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMx_inc_sup());
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMz_inc_sup());

                printf("Coefficient_modulation_amplitude: %e\n", cageExcitation.getMod_ampl_Exci());
                printf("Coefficient_modulation_phase_(retard_temporel): %e\n", cageExcitation.getMod_ret_Exci());

                cageExcitation.setNbx_inc_prel(cageExcitation.getMx_inc_sup() - cageExcitation.getMx_inc_inf());
                cageExcitation.setNby_inc_prel(cageExcitation.getMy_inc_sup() - cageExcitation.getMy_inc_inf());
                cageExcitation.setNbz_inc_prel(cageExcitation.getMz_inc_sup() - cageExcitation.getMz_inc_inf());

                printf("nbx_inc_prel[i]: %d\n", cageExcitation.getNbx_inc_prel());
                printf("nby_inc_prel[i]: %d\n", cageExcitation.getNby_inc_prel());
                printf("nbz_inc_prel[i]: %d\n", cageExcitation.getNbz_inc_prel());

            }
        }

        if (cageExcitation.getInside_outside() == 2) //excitation de type outside
        {
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            cageExcitation.setNb_faces_excitation(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            cageExcitation.setType_excitation(int_temp);

            if (cageExcitation.getType_excitation() == 4) // excitation outside � partir d'un fichier de description
            {

                fscanf(fp, "%*s");
                fscanf(fp, "%*s"); // nom du fichier d'excitation;
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMy_inc_inf(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMx_inc_inf(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMz_inc_inf(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMy_inc_sup(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMx_inc_sup(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &int_temp);
                cageExcitation.setMz_inc_sup(int_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &float_temp);
                cageExcitation.setMod_ampl_Exci(float_temp);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &float_temp);
                cageExcitation.setMod_ret_Exci(float_temp);

                printf("Cage_d_excitation\n");
                printf("Nombre_de_faces_d_excitation:\n");
                printf("%d\n", cageExcitation.getNb_faces_excitation());
                printf("Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation:\n");
                printf("%d\n", cageExcitation.getType_excitation());

                printf("Coordonnees_du_coin_inferieur_gauche\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMy_inc_inf());
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMx_inc_inf());
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMz_inc_inf());

                printf("Coordonnee_du_coin_superieur_droit\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMy_inc_sup());
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMx_inc_sup());
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitation.getMz_inc_sup());

                printf("Coefficient_modulation_amplitude: %e\n", cageExcitation.getMod_ampl_Exci());
                printf("Coefficient_modulation_phase_(retard_temporel): %e\n", cageExcitation.getMod_ret_Exci());

                cageExcitation.setNbx_inc_prel(cageExcitation.getMx_inc_sup() - cageExcitation.getMx_inc_inf());
                cageExcitation.setNby_inc_prel(cageExcitation.getMy_inc_sup() - cageExcitation.getMy_inc_inf());
                cageExcitation.setNbz_inc_prel(cageExcitation.getMz_inc_sup() - cageExcitation.getMz_inc_inf());

                printf("nbx_inc_prel[i]: %d\n", cageExcitation.getNbx_inc_prel());
                printf("nby_inc_prel[i]: %d\n", cageExcitation.getNby_inc_prel());
                printf("nbz_inc_prel[i]: %d\n", cageExcitation.getNbz_inc_prel());

            } else {
                printf("\n\7 L'excitation outside ne peut se faire qu'a partir d'un fichier d'entree\n");
                exit(0);
            }
        }
    }
}

void scanSondes() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbsonde);

    printf("Nombre_de_sondes:\n");
    printf("%d\n", nbsonde);

    sonde = (Sonde *) calloc(nbsonde + 1, sizeof (Sonde)); // Modif QUEUDET : allocation dynamique de la liste des sondes

    int i;
    for (i = 0; i < nbsonde; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].flag_ex);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].flag_ey);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].flag_ez);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].flag_hx);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].flag_hy);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].flag_hz);
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].iy);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].ix);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].iz);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &sonde[i].centre);

        printf("Sonde_numero_%d\n", i + 1);
        printf("Coordonnees_du_point_d_application\n");
        printf("Sur_la_longueur:\n");
        printf("%d\n", sonde[i].iy);
        printf("Sur_la_largeur:\n");
        printf("%d\n", sonde[i].ix);
        printf("Sur_la_hauteur:\n");
        printf("%d\n", sonde[i].iz);

    }
}

void scanCartographieTemporelle() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbcarto);

    printf("Nombre_de_cartographies_temporelles: %d\n", nbcarto);

    CT = (CartographieTemporelle *) calloc(nbcarto, sizeof (CartographieTemporelle)); // Allocation dynamique de la liste des cartos temporelles

    int i;
    for (i = 0; i < nbcarto; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].SauveE);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].SauveH);
        fscanf(fp, "%*s");
        fscanf(fp, "%ld", &CT[i].IterDeb);
        fscanf(fp, "%*s");
        fscanf(fp, "%ld", &CT[i].IterFin);
        fscanf(fp, "%*s");
        fscanf(fp, "%ld", &CT[i].IterPas);
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].y1);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].x1);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].z1);
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].y2);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].x2);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &CT[i].z2);

        if (CT[i].x1 == CT[i].x2) CT[i].x2++;
        else if (CT[i].y1 == CT[i].y2) CT[i].y2++;
        else if (CT[i].z1 == CT[i].z2) CT[i].z2++;
        else printf("ERREUR : la cartographie n'est pas un plan !!");

        if (CT[i].IterDeb == -1)
            CT[i].IterDeb = 0;

        if (CT[i].IterFin == -1)
            CT[i].IterFin = ((long) ((double) tobs / (double) dt)); //la fin est ntotal (pas encore calcul� � ce stade)

        printf("Cartographie_numero_%d\n", i + 1);
        printf("Coordonnees_du_coin_inferieur_gauche\n");
        printf("Sur_la_longueur_(en_cellules):\n");
        printf("%d\n", CT[i].y1);
        printf("Sur_la_largeur_(en_cellules):\n");
        printf("%d\n", CT[i].x1);
        printf("Sur_la_hauteur_(en_cellules):\n");
        printf("%d\n", CT[i].z1);

        printf("Coordonnee_du_coin_superieur_droit\n");
        printf("Sur_la_longueur_(en_cellules):\n");
        printf("%d\n", CT[i].y2);
        printf("Sur_la_largeur_(en_cellules):\n");
        printf("%d\n", CT[i].x2);
        printf("Sur_la_hauteur_(en_cellules):\n");
        printf("%d\n", CT[i].z2);

    }
}

void scanSurfacePrelevement() {
    //flags suivant le type de surfaces de prelevement
    ind_ch_loin = 0;
    ind_ch_Prel_DG = 0;

    cpt_surf_DG = 0; // compteur de surface DG

    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbsurf_prel);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nb_surf_Prel_DG); // ajout LE LEPVRIER : nombre de surfaces de pr�l�vement DG
    if (nbsurf_prel > 1){
        printf("Erreur : Une seule surface de prélèvement permise");
        exit(0);
    }

    printf("Nombre_de_surfaces de prelevement:\n");
    printf("%d\n", nbsurf_prel);
    printf("Nombre_de_surfaces de prelevement DG:\n");
    printf("%d\n", nb_surf_Prel_DG);

    if (nbsurf_prel == 1) {
        int int_temp;
        
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &int_temp);
        surface.setTyp_surf_prelev(int_temp);

        if (surface.getTyp_surf_prelev() == 1) {
            ind_ch_loin = 1; //indique la presence d'une surface de Huygens


            fscanf(fp, "%*s");
            fscanf(fp, "%*s"); //nom du fichier

            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setNb_surfaces(int_temp);// nombre de faces de la surface de Huygens

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMy_surf_inf(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMx_surf_inf(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMz_surf_inf(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMy_surf_sup(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMx_surf_sup(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMz_surf_sup(int_temp);

            printf("Surface_de_prelevement\n");
            printf("Type_de_surface_1>Huygens_2>Surface_de_prelevement_DG_3>Kirchhoff\n");
            printf("%d \n", surface.getTyp_surf_prelev());
            printf("Coordonnees_du_coin_inferieur_gauche\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surface.getMy_surf_inf());
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surface.getMx_surf_inf());
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surface.getMz_surf_inf());
            printf("Coordonnee_du_coin_superieur_droit\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surface.getMy_surf_sup());
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surface.getMx_surf_sup());
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surface.getMz_surf_sup());
            printf("Surface de Huygens: \n");
            if (surface.getNb_surfaces() == 1) printf("1 face (la face sup�rieure)\n");
            if (surface.getNb_surfaces() == 5) printf("5 faces\n");
            if (surface.getNb_surfaces() == 6) printf("6 faces \n");

        }//fin du if surface de Huygens
        else if (surface.getTyp_surf_prelev() == 2) {
            ind_ch_Prel_DG = 1; //indique la pr�sence d'une surface de prelevement DG

            fscanf(fp, "%*s");
            fscanf(fp, "%*s"); //nom du fichier pas recuperer pour le moment
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setSurf_prel_inside_outside(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setNb_surfaces(int_temp);// nombre de faces de la surface DG

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMy_surf_inf(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMx_surf_inf(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMz_surf_inf(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMy_surf_sup(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMx_surf_sup(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setMz_surf_sup(int_temp);

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setCompy_Prel(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setCompx_Prel(int_temp);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &int_temp);
            surface.setCompz_Prel(int_temp);

            surface.setNbx_surfPrel( (surface.getMx_surf_sup() - surface.getMx_surf_inf()) / surface.getCompx_Prel());
            surface.setNby_surfPrel( (surface.getMy_surf_sup() - surface.getMy_surf_inf()) / surface.getCompy_Prel());
            surface.setNbz_surfPrel( (surface.getMz_surf_sup() - surface.getMz_surf_inf()) / surface.getCompz_Prel());

            //affichages des donnees recuperees

            printf("Surface_de_prelevement\n");
            printf("Type_de_surface_1>Huygens_2>Surface_de_prelevement_DG_3>Kirchhoff\n");
            printf("%d \n", surface.getTyp_surf_prelev());
            if (surface.getSurf_prel_inside_outside() == 1) printf("surface_de_prelevement_DG_de_type_inside\n");
            if (surface.getSurf_prel_inside_outside() == 2) printf("surface_de_prelevement_DG_de_type_outside\n");

            printf("Coordonnees_du_coin_inferieur_gauche\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surface.getMy_surf_inf());
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surface.getMx_surf_inf());
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surface.getMz_surf_inf());
            printf("Coordonnee_du_coin_superieur_droit\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surface.getMy_surf_sup());
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surface.getMx_surf_sup());
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surface.getMz_surf_sup());
            printf("Surface_de_prelevement_DG: \n");
            if (surface.getNb_surfaces() == 5) printf("5 faces + plan de masse \n");
            if (surface.getNb_surfaces() == 6) printf("6 faces \n");

            cpt_surf_DG++; //incrementation du nombre de surface DG

            printf("cpt_surf_DG : %d \n", cpt_surf_DG);

        } else {
            printf("Ce type de surface de pr�l�vement n'est pas disponible dans ce code\n");
            exit(0);
        }
    }
}

void parseANA() {
    sprintf(nomfic, "DATA%d.ana\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.ana **\n");
        printf("*****************************************\n");

        onde_plane_oblique = NON;
        nbports_excitation = 0;

        do {
            fgets(chaine, 100, fp);
            //printf("%s\n", chaine);

            if (0 == strcmp(chaine, "[PML]\n"))
                scanPML();
            if (0 == strcmp(chaine, "[PARAMETRES_EXCITATION]\n"))
                scanParametreExcitation();
            if (0 == strcmp(chaine, "[ANALYSE_TEMPORELLE]\n"))
                scanAnalyseTemporelle();
            if (0 == strcmp(chaine, "[PORTS_EXCITATION]\n"))
                scanPortExcitation();
            if (0 == strcmp(chaine, "[CAGES_EXCITATION]\n"))
                scanCageExcitation();
            if (0 == strcmp(chaine, "[SONDES]\n"))
                scanSondes();
            if (0 == strcmp(chaine, "[CARTOGRAPHIES_TEMPORELLES]\n"))
                scanCartographieTemporelle();
            if (0 == strcmp(chaine, "[SURFACES_DE_PRELEVEMENT]\n"))
                scanSurfacePrelevement();

        } while (!feof(fp));

        fclose(fp);
        printf("**  FIN CHARGEMENT STRUCTURE DATA.ana  **\n");
        printf("*****************************************\n");
    }
}

/******************************************************************************/
/** >FONCTION PARSAGE .ANA ****************************************************/

/******************************************************************************/
void scanChampLointain() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbsurf_huy);

    if (nbsurf_huy > 1) {
        printf("Une seule surface de Huygens disponible dans ce code");
        exit(0);
    }

    int i;
    for (i = 0; i < nbsurf_huy; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &y_origine);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &x_origine);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &z_origine);

        printf("Origine_repere:\n");
        printf("Coordonnees_en_y_de_l_origine_du_repere_en_nombre_de_cellules:\n");
        printf("%d \n", y_origine);
        printf("Coordonnees_en_x_de_l_origine_du_repere_en_nombre_de_cellules:\n");
        printf("%d \n", x_origine);
        printf("Coordonnees_en_z_de_l_origine_du_repere_en_nombre_de_cellules:\n");
        printf("%d \n", z_origine);


        // frequences de calcul du champ lointain          
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &freq_min_ch_loin);
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &freq_max_ch_loin);
        fscanf(fp, "%*s");
        fscanf(fp, "%f", &freq_pas_ch_loin);

        printf("Frequences_de_calcul:\n");
        printf("Frequence_min_en_GHz:\n");
        printf("%f \n", freq_min_ch_loin);
        printf("Frequence_max_en_GHz:\n");
        printf("%f \n", freq_max_ch_loin);
        printf("Pas_de_frequence_en_GHz:\n");
        printf("%f \n", freq_pas_ch_loin);


        //Calcul du champ lointain avec ou sans image et plan de masse de r���f���rence
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &ind_cal_image);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &z_masse_ref);

        printf("Plan de masse de r���f���rence en z = %d\n", z_masse_ref);
        if (ind_cal_image == 1) {
            printf("Calcul avec prise en compte des images des courants\n");
        } else {
            printf("Calcul sans prise en compte des images des courants\n");
        }


        // Pas des plans de fr���quences qui sont ��� calculer
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &pas_theta);
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &pas_phi);

        printf("Plans_calcules:\n");
        printf("Pas_de_discr���tisation_selon_theta_(en_degres):\n");
        printf("%d \n", pas_theta);

        printf("Pas_de_discr���tisation_selon_phi_(en_degres):\n");
        printf("%d \n", pas_phi);

    }
}

void parsePTR() {
    sprintf(nomfic, "DATA%d.ptr\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.ptr **\n");
        printf("*****************************************\n");

        onde_plane_oblique = NON;
        nbports_excitation = 0;

        do {
            fgets(chaine, 100, fp);
            //printf("%s\n", chaine);

            if (0 == strcmp(chaine, "[CALCUL_CHAMP_LOINTAIN]\n"))
                scanChampLointain();
        } while (!feof(fp));

        fclose(fp);
        printf("**  FIN CHARGEMENT STRUCTURE DATA.ptr  **\n");
        printf("*****************************************\n");
    }
}

/******************************************************************************/
/** >FONCTION PARSAGE .AVC ****************************************************/

/******************************************************************************/
void scanExcitation() {
    fscanf(fp, "%*s");
    fscanf(fp, "%e", &v0);

    printf("Amplitude_V0:\n");
    printf("%e\n", v0);
}

void scanFormatStockage() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &format_stock);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &flag_EnregChampsPrelBinaire);

    printf("Format_binaire>1_texte>2::\n");
    printf("%d\n", format_stock);
    printf("Format_stockage_fichier_prelevement_DG_0>texte_1>binaire::\n");
    printf("%d\n", flag_EnregChampsPrelBinaire);
}

void scanEchantillonnage() {
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &fact_echantill);

    printf("Facteur_multiplicatif_pour_le_nombre_d_echantillons_preleves:\n");
    printf("%d\n", fact_echantill);
}

//Est ce que cela ne se lance que si une surface de Huygens existe ?
void scanCompressionHuygens() {
    int temp;
    fscanf(fp, "%*s");
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &temp);
    surface.setCompy_Prel(temp);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &temp);
    surface.setCompx_Prel(temp);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &temp);
    surface.setCompz_Prel(temp);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &fact_echantill_huy);

    //Calcul des parametres de la compression Huygens
    surface.setNbx_surfPrel( (surface.getMx_surf_sup() - surface.getMx_surf_inf()) / surface.getCompx_Prel());  
    surface.setNby_surfPrel( (surface.getMy_surf_sup() - surface.getMy_surf_inf()) / surface.getCompy_Prel());  
    surface.setNbz_surfPrel( (surface.getMz_surf_sup() - surface.getMz_surf_inf()) / surface.getCompz_Prel());
    inter_iter = (1 / (2 * frehau * 1e9 * dt * fact_echantill_huy)) - 1;

    printf("\nCompression pour le calcul du champ lointain, en nombre de cellules\n");
    printf("Sur la longueur (en cellules), un diviseur de %d :\n%d\n", surface.getMy_surf_sup() - surface.getMy_surf_inf(),  surface.getCompy_Prel());
    printf("Sur la largeur (en cellules), un diviseur de %d :\n%d\n", surface.getMx_surf_sup() - surface.getMx_surf_inf(),  surface.getCompx_Prel());
    printf("Sur la hauteur (en cellules), un diviseur de %d :\n%d\n", surface.getMz_surf_sup() - surface.getMz_surf_inf(),  surface.getCompz_Prel());
    printf("\nFacteur_multiplicatif_pour_le_nombre_d_echantillons_preleves:\n");
    printf("%d \n", fact_echantill_huy);
    printf("\nIntervalle_echantillonnage_(en_iterations):\n");
    printf("%d \n", inter_iter);
}

void scanCalculDirectivite(){
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &ind_direct);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &pas_theta_dir);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &pas_phi_dir);

    printf("\nCalcul_de_la_directivite_0>Non_1>Oui\n");
    printf("%d \n", ind_direct);
    printf("Plans_calcules:\n");
    printf("Pas_de_discretisation_selon_theta_(en_degres):\n");
    printf("%d \n", pas_theta_dir);
    printf("Pas_de_discretisation_selon_phi_(en_degres):\n");
    printf("%d \n", pas_phi_dir);
}

void parseAVC() {
    sprintf(nomfic, "DATA%d.avc\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.avc **\n");
        printf("*****************************************\n");

        onde_plane_oblique = NON;
        nbports_excitation = 0;

        do {
            fgets(chaine, 100, fp);
            //printf("%s\n", chaine);

            if (0 == strcmp(chaine, "[EXCITATION]\n"))
                scanExcitation();
            if (0 == strcmp(chaine, "[FORMAT_STOCKAGE]\n"))
                scanFormatStockage();
            if (0 == strcmp(chaine, "[ECHANTILLONNAGE]\n"))
                scanEchantillonnage();
            if (0 == strcmp(chaine, "[COMPRESSION_HUYGENS]\n"))
                scanCompressionHuygens();
            if ( 0 == strcmp(chaine,"[CALCUL_DIRECTIVITE]\n") )
                scanCalculDirectivite();
        } while (!feof(fp));

        fclose(fp);
        printf("**  FIN CHARGEMENT STRUCTURE DATA.avc  **\n");
        printf("*****************************************\n");
    }
}

int parse() {
    parseDSC();
    parseANA();
    if (ind_ch_loin == 1)parsePTR();
    parseAVC();
    return 0;
}
