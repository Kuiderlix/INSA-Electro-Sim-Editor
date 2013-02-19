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
CageExcitation *cageExcitations;
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
SurfacePrelevement *surfaces;

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
            (typaroi_y == PAROI_MUR))
 {
        typaroi = 0;
    }
    else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PEC))
 {
        typaroi = 1;
    }
    else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PEC))
 {
        typaroi = 2;
    }
    else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_FLOQUET) &&
            (typaroi_y == PAROI_FLOQUET))
 {
        typaroi = 3;
    }
    else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_FLOQUET) &&
            (typaroi_y == PAROI_FLOQUET))
 {
        typaroi = 4;
    }
    else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_PML))
 {
        typaroi = 5;
    }
    else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_PML))
 {
        typaroi = 6;
    }
    else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_FLOQUET))
 {
        typaroi = 7;
    }
    else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PML) &&
            (typaroi_y == PAROI_FLOQUET))
 {
        typaroi = 8;
    }
    else if ((typaroi_inf == PAROI_PEC) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PMC))
 {
        typaroi = 9;
    }
    else if ((typaroi_inf == PAROI_PML) &&
            (typaroi_sup == PAROI_PML) &&
            (typaroi_x == PAROI_PEC) &&
            (typaroi_y == PAROI_PMC))
 {
        typaroi = 10;
    }
    else {
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

void scanParallelepipedes(){
    fscanf(fp,"%*s");
    fscanf(fp,"%d",&nbsubs);

    printf("Nombre_de_parallelepipedes:\n");
    printf("%d\n",nbsubs);

    subs=(Substrat *)calloc( nbsubs+1 , sizeof(Substrat) );   // Modif GODI/QUEUDET : allocation dynamique de la liste de substrats

    int i;
    for ( i=0 ; i<nbsubs ; i++ )
    {
        fscanf(fp,"%*s");
        fscanf(fp,"%*s");
        fscanf(fp,"%f",&subs[i].perm);
        fscanf(fp,"%*s");
        fscanf(fp,"%f",&subs[i].permea);
        fscanf(fp,"%*s");
        fscanf(fp,"%f",&subs[i].cond);
        fscanf(fp,"%*s");
        fscanf(fp,"%*s");
        fscanf(fp,"%d",&subs[i].iys1);
        fscanf(fp,"%*s");
        fscanf(fp,"%d",&subs[i].ixs1);
        fscanf(fp,"%*s");
        fscanf(fp,"%d",&subs[i].izs1);
        fscanf(fp,"%*s");
        fscanf(fp,"%*s");
        fscanf(fp,"%d",&subs[i].iys2);
        fscanf(fp,"%*s");
        fscanf(fp,"%d",&subs[i].ixs2);
        fscanf(fp,"%*s");
        fscanf(fp,"%d",&subs[i].izs2);

        printf("parallelepipede_numero_%d\n",i+1);
        printf("Permittivite_relative:\n"); printf("%f\n",subs[i].perm);
        printf("Permeabilite_relative:\n"); printf("%f\n",subs[i].permea);
        printf("Conductivite:\n"); 			printf("%f\n",subs[i].cond);

        if (subs[i].permea!=1.0)
                 {printf("Les materiaux magnetiques ne sont pas pris en compte dans cette version du code\n");}

        printf("Coordonnees_du_coin_inferieur_avant_gauche\n");
        printf("Sur_la_longueur_y_(en_cellules):\n"); printf("%d\n",subs[i].iys1);
        printf("Sur_la_largeur_x_(en_cellules):\n"); printf("%d\n",subs[i].ixs1);
        printf("Sur_la_hauteur_z_(en_cellules):\n"); printf("%d\n",subs[i].izs1);

        printf("Coordonnees_du_coin_superieur_arriere_droit\n");
        printf("Sur_la_longueur_y_(en_cellules):\n"); printf("%d\n",subs[i].iys2);
        printf("Sur_la_largeur_x_(en_cellules):\n"); printf("%d\n",subs[i].ixs2);
        printf("Sur_la_hauteur_z_(en_cellules):\n"); printf("%d\n",subs[i].izs2);
    }
}

void scanElementsLocalises(){
    fscanf(fp,"%*s");
    fscanf(fp,"%d",&nbelt);

    printf("Nombre_d_elements_localises:\n");
    printf("%d\n",nbelt);

    if (nbelt > 0)
    {
        elts=(ElementLocalise *)calloc( nbelt+1 , sizeof(ElementLocalise) );  // Modif QUEUDET : allocation dynamique de la liste des elements localises
        
        int i;
        for ( i=0 ; i<nbelt ; i++ )
        {
           fscanf(fp,"%*s");
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].type);
           fscanf(fp,"%*s");
           fscanf(fp,"%e",&elts[i].val);
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].dir);
           fscanf(fp,"%*s");
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].iy1);
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].ix1);
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].iz1);
           fscanf(fp,"%*s");
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].iy2);
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].ix2);
           fscanf(fp,"%*s");
           fscanf(fp,"%d",&elts[i].iz2);

           printf("Element_Localise_numero_%i\n",i+1);
           printf("Type_d_element_1>resistance_2>capacite_3>self:\n"); printf("%d\n",elts[i].type);
           printf("Valeur_de_l_element_en_Ohm_Farad_ou_Henry:\n"); printf("%e\n",elts[i].val);
           printf("Direction_1>x_2>y_3>z\n"); printf("%d\n",elts[i].dir);

           printf("Coordonnees_du_coin_inferieur:\n");
           printf("Sur_la_longueur_y_(en_cellules):\n"); printf("%d\n",elts[i].iy1);
           printf("Sur_la_largeur_x_(en_cellules):\n"); printf("%d\n",elts[i].ix1);
           printf("Sur_la_hauteur_z_(en_cellules):\n"); printf("%d\n",elts[i].iz1);

           printf("Coordonnee_du_coin_superieur\n");
           printf("Sur_la_longueur_y_(en_cellules):\n"); printf("%d\n",elts[i].iy2);
           printf("Sur_la_largeur_x_(en_cellules):\n"); printf("%d\n",elts[i].ix2);
           printf("Sur_la_hauteur_z_(en_cellules):\n"); printf("%d\n",elts[i].iz2);

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
            if (0 == strcmp(chaine,"[PARALLELEPIPEDES_MATERIAUX]\n"))
                scanParallelepipedes();
            if (0 == strcmp(chaine,"[ELEMENTS_LOCALISES]\n"))
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
void scanPML(){
    fscanf(fp,"%*s");
    fscanf(fp,"%d",&n_couche);
    fscanf(fp,"%*s");
    fscanf(fp,"%d",&m_pml);
    fscanf(fp,"%*s");
    fscanf(fp,"%f",&sigma_max);
    fscanf(fp,"%*s");
    fscanf(fp,"%f",&k_max);

    printf("Epaisseur_de_la_couche_(en_cellules):\n"); printf("%d\n",n_couche);
    printf("Ordre_de_la_variation_geometrique_de_sigma_(valeur_de_m):\n"); printf("%d\n",m_pml);
    printf("Sigma_max:\n"); printf("%f\n",sigma_max);
    printf("K_max:\n"); printf("%f\n",k_max);
}

void scanParametreExcitation(){
    fscanf(fp,"%*s");
    fscanf(fp,"%e",&frehau);
    fscanf(fp,"%*s");
    fscanf(fp,"%i",&gausstype);

    printf("Frequence_maximale_de_la_bande_d'analyse_(en_GHz):\n");
    printf("%e\n",frehau);
    printf("Excitation_0>Gaussienne_1>Gaussienne_modulant_un_sinus:\n");
    printf("%i\n",gausstype);

    if ( gausstype ==  1 )
      {
                fscanf(fp,"%*s");
                fscanf(fp,"%e",&f_sinus);

                printf("Frequence_du_sinus_(GHz):\n");
        printf("%e\n",f_sinus);
      }
}

void scanAnalyseTemporelle(){
    fscanf(fp,"%*s");
    fscanf(fp,"%e",&dt);
    fscanf(fp,"%*s");
    fscanf(fp,"%e",&tobs);

    printf("Periode_d'echantillonnage_temporelle_(en_s):\n");
    printf("%e\n",dt);
    printf("Temps_d'observation_(en_s):\n");
    printf("%e\n",tobs);
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

void scanCageExcitation(){
    onde_plane_oblique = NON; // flags indiquant la presence ou non d'une excitation par onde plane 5 ou 6 faces

    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nb_cages_excitation);

    if (nb_cages_excitation > 0)
        cageExcitations = (CageExcitation *) calloc(nb_cages_excitation + 1, sizeof (CageExcitation));

    printf("Nombre de cages d'excitation:\n");
    printf("%d\n", nb_cages_excitation);

    int i;
    for (i = 0; i < nb_cages_excitation; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &cageExcitations[i].inside_outside);

        if (cageExcitations[i].inside_outside == 1) //si excitation de type inside
        {
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &cageExcitations[i].nb_faces_excitation);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &cageExcitations[i].type_excitation);

            if ((cageExcitations[i].type_excitation == 1) || 
                    (cageExcitations[i].type_excitation == 2) || 
                    (cageExcitations[i].type_excitation == 3)) {
                printf("Cage_d_excitation numero%d\n", i + 1);
                printf("Nombre_de_faces_d_excitation:\n");
                printf("%d\n", cageExcitations[i].nb_faces_excitation);
                printf("Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation:\n");
                printf("%d\n", cageExcitations[i].type_excitation);


                if ((cageExcitations[i].nb_faces_excitation == 5) || 
                        (cageExcitations[i].nb_faces_excitation == 6)) {
                    // activation du flag onde plane oblique
                    onde_plane_oblique = OUI;

                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].my_inc_inf);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].mx_inc_inf);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].mz_inc_inf);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].my_inc_sup);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].mx_inc_sup);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].mz_inc_sup);
                    //TODO : les variables dessous étaient à l'origine uniques
                    // (pas de [i]) mais il fallait quand même les déclarer
                    // pour chaque cage. À garder ?????
                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].y_inc0);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].x_inc0);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].z_inc0);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%*s");
                    fscanf(fp, "%f", &cageExcitations[i].theta0deg);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%f", &cageExcitations[i].phi0deg);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%f", &cageExcitations[i].psi0deg);

                    printf("Coordonnees_du_coin_inferieur_gauche\n");
                    printf("Sur_la_longueur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].my_inc_inf);
                    printf("Sur_la_largeur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].mx_inc_inf);
                    printf("Sur_la_hauteur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].mz_inc_inf);

                    printf("Coordonnee_du_coin_superieur_droit\n");
                    printf("Sur_la_longueur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].my_inc_sup);
                    printf("Sur_la_largeur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].mx_inc_sup);
                    printf("Sur_la_hauteur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].mz_inc_sup);

                    printf("Coordonnees_du_point_de_reference\n");
                    printf("Sur_la_longueur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].y_inc0);
                    printf("Sur_la_largeur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].x_inc0);
                    printf("Sur_la_hauteur_(en_cellules):\n");
                    printf("%d\n", cageExcitations[i].z_inc0);

                    printf("Avec_les_angles_d_incidence_en_degres\n");
                    printf("theta0:\n");
                    printf("%f\n", cageExcitations[i].theta0deg);
                    printf("phi0:\n");
                    printf("%f\n", cageExcitations[i].phi0deg);
                    printf("psi0:\n");
                    printf("%f\n", cageExcitations[i].psi0deg);

                } else if (cageExcitations[i].nb_faces_excitation == 1) {
                    onde_plane_oblique = NON;

                    //Ces valeurs également étaient uniques également
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].mode_excitation);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].zexc);
                    fscanf(fp, "%*s");
                    fscanf(fp, "%d", &cageExcitations[i].sens_propa);

                    printf("Type_0>OndeplaneX_1>OndeplaneY_2>GuideTE10X_3>GuideTE10Y:\n");
                    printf("%d\n", cageExcitations[i].mode_excitation);
                    printf("Coordonnees_sur_la_hauteur:\n");
                    printf("%d\n", cageExcitations[i].zexc);
                    printf("Sens_de_propagation_de_l_onde_-1>z_croissants_1>z_decroissants:\n");
                    printf("%d\n", cageExcitations[i].sens_propa);
                } else {
                    printf("\n\7 excitation non disponible dans ce code\n");
                    exit(0);
                }

            } else if (cageExcitations[i].type_excitation == 4) // excitation inside � partir d'un fichier d'excitation
            {

                fscanf(fp, "%*s");
                fscanf(fp, "%*s"); // nom du fichier d'excitation;
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].my_inc_inf);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mx_inc_inf);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mz_inc_inf);
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].my_inc_sup);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mx_inc_sup);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mz_inc_sup);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &cageExcitations[i].mod_ampl_Exci);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &cageExcitations[i].mod_ret_Exci);

                printf("Cage_d_excitation numero%d\n", i + 1);
                printf("Nombre_de_faces_d_excitation:\n");
                printf("%d\n", cageExcitations[i].nb_faces_excitation);
                printf("Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation:\n");
                printf("%d\n", cageExcitations[i].type_excitation);

                printf("Coordonnees_du_coin_inferieur_gauche\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].my_inc_inf);
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mx_inc_inf);
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mz_inc_inf);

                printf("Coordonnee_du_coin_superieur_droit\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].my_inc_sup);
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mx_inc_sup);
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mz_inc_sup);

                printf("Coefficient_modulation_amplitude: %e\n", cageExcitations[i].mod_ampl_Exci);
                printf("Coefficient_modulation_phase_(retard_temporel): %e\n", cageExcitations[i].mod_ret_Exci);

                cageExcitations[i].nbx_inc_prel = cageExcitations[i].mx_inc_sup - cageExcitations[i].mx_inc_inf;
                cageExcitations[i].nby_inc_prel = cageExcitations[i].my_inc_sup - cageExcitations[i].my_inc_inf;
                cageExcitations[i].nbz_inc_prel = cageExcitations[i].mz_inc_sup - cageExcitations[i].mz_inc_inf;

                printf("nbx_inc_prel[i]: %d\n", cageExcitations[i].nbx_inc_prel);
                printf("nby_inc_prel[i]: %d\n", cageExcitations[i].nby_inc_prel);
                printf("nbz_inc_prel[i]: %d\n", cageExcitations[i].nbz_inc_prel);

            }
        }

        if (cageExcitations[i].inside_outside == 2) //excitation de type outside
        {
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &cageExcitations[i].nb_faces_excitation);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &cageExcitations[i].type_excitation);

            if (cageExcitations[i].type_excitation == 4) // excitation outside � partir d'un fichier de description
            {

                fscanf(fp, "%*s");
                fscanf(fp, "%*s"); // nom du fichier d'excitation;
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].my_inc_inf);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mx_inc_inf);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mz_inc_inf);
                fscanf(fp, "%*s");
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].my_inc_sup);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mx_inc_sup);
                fscanf(fp, "%*s");
                fscanf(fp, "%d", &cageExcitations[i].mz_inc_sup);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &cageExcitations[i].mod_ampl_Exci);
                fscanf(fp, "%*s");
                fscanf(fp, "%f", &cageExcitations[i].mod_ret_Exci);

                printf("Cage_d_excitation numero%d\n", i + 1);
                printf("Nombre_de_faces_d_excitation:\n");
                printf("%d\n", cageExcitations[i].nb_faces_excitation);
                printf("Type_excitation_1>onde_plane_2>TE10_3>TM10_4>fichier_excitation:\n");
                printf("%d\n", cageExcitations[i].type_excitation);

                printf("Coordonnees_du_coin_inferieur_gauche\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].my_inc_inf);
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mx_inc_inf);
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mz_inc_inf);

                printf("Coordonnee_du_coin_superieur_droit\n");
                printf("Sur_la_longueur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].my_inc_sup);
                printf("Sur_la_largeur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mx_inc_sup);
                printf("Sur_la_hauteur_(en_cellules):\n");
                printf("%d\n", cageExcitations[i].mz_inc_sup);

                printf("Coefficient_modulation_amplitude: %e\n", cageExcitations[i].mod_ampl_Exci);
                printf("Coefficient_modulation_phase_(retard_temporel): %e\n", cageExcitations[i].mod_ret_Exci);

                cageExcitations[i].nbx_inc_prel = cageExcitations[i].mx_inc_sup - cageExcitations[i].mx_inc_inf;
                cageExcitations[i].nby_inc_prel = cageExcitations[i].my_inc_sup - cageExcitations[i].my_inc_inf;
                cageExcitations[i].nbz_inc_prel = cageExcitations[i].mz_inc_sup - cageExcitations[i].mz_inc_inf;

                printf("nbx_inc_prel[i]: %d\n", cageExcitations[i].nbx_inc_prel);
                printf("nby_inc_prel[i]: %d\n", cageExcitations[i].nby_inc_prel);
                printf("nbz_inc_prel[i]: %d\n", cageExcitations[i].nbz_inc_prel);

            } else {
                printf("\n\7 L'excitation outside ne peut se faire qu'a partir d'un fichier d'entree\n");
                exit(0);
            }
        }
    }
}

void scanSondes(){
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

void scanCartographieTemporelle(){
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

void scanSurfacePrelevement(){
    //flags suivant le type de surfaces de prelevement
    ind_ch_loin = 0;
    ind_ch_Prel_DG = 0;

    cpt_surf_DG = 0; // compteur de surface DG

    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nbsurf_prel);
    fscanf(fp, "%*s");
    fscanf(fp, "%d", &nb_surf_Prel_DG); // ajout LE LEPVRIER : nombre de surfaces de pr�l�vement DG
    if(nbsurf_prel >0) 
        surfaces = (SurfacePrelevement *) calloc(nbsurf_prel, sizeof (SurfacePrelevement));

    printf("Nombre_de_surfaces de prelevement:\n");
    printf("%d\n", nbsurf_prel);
    printf("Nombre_de_surfaces de prelevement DG:\n");
    printf("%d\n", nb_surf_Prel_DG);

    int i;
    for (i = 0; i < nbsurf_prel; i++) {
        fscanf(fp, "%*s");
        fscanf(fp, "%*s");
        fscanf(fp, "%d", &surfaces[i].typ_surf_prelev);

        if (surfaces[i].typ_surf_prelev == 1) {
            ind_ch_loin = 1; //indique la presence d'une surface de Huygens


            fscanf(fp, "%*s");
            fscanf(fp, "%*s"); //nom du fichier

            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].nb_surf_ch_loin); // nombre de faces de la surface de Huygens

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].my_surfHuy_inf);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mx_surfHuy_inf);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mz_surfHuy_inf);
            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].my_surfHuy_sup);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mx_surfHuy_sup);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mz_surfHuy_sup);

            printf("Surface_de_prelevement_%d\n", i + 1);
            printf("Type_de_surface_1>Huygens_2>Surface_de_prelevement_DG_3>Kirchhoff\n");
            printf("%d \n", surfaces[i].typ_surf_prelev);
            printf("Coordonnees_du_coin_inferieur_gauche\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surfaces[i].my_surfHuy_inf);
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mx_surfHuy_inf);
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mz_surfHuy_inf);
            printf("Coordonnee_du_coin_superieur_droit\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surfaces[i].my_surfHuy_sup);
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mx_surfHuy_sup);
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mz_surfHuy_sup);
            printf("Surface de Huygens: \n");
            if (surfaces[i].nb_surf_ch_loin == 1) printf("1 face (la face sup�rieure)\n");
            if (surfaces[i].nb_surf_ch_loin == 5) printf("5 faces\n");
            if (surfaces[i].nb_surf_ch_loin == 6) printf("6 faces \n");

        }//fin du if surface de Huygens
        else if (surfaces[i].typ_surf_prelev == 2) {
            ind_ch_Prel_DG = 1; //indique la pr�sence d'une surface de prelevement DG

            fscanf(fp, "%*s");
            fscanf(fp, "%*s"); //nom du fichier pas recuperer pour le moment
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].surf_prel_inside_outside);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].nb_faces_surf_Prel_DG); //nombre de faces de la surface de prelevement DG

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].my_surfPrel_DG_inf);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mx_surfPrel_DG_inf);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mz_surfPrel_DG_inf);

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].my_surfPrel_DG_sup);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mx_surfPrel_DG_sup);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].mz_surfPrel_DG_sup);

            fscanf(fp, "%*s");
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].compy_Prel);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].compx_Prel);
            fscanf(fp, "%*s");
            fscanf(fp, "%d", &surfaces[i].compz_Prel);

            surfaces[i].nbx_surfPrel = (surfaces[i].mx_surfPrel_DG_sup - surfaces[i].mx_surfPrel_DG_inf) / surfaces[i].compx_Prel;
            surfaces[i].nby_surfPrel = (surfaces[i].my_surfPrel_DG_sup - surfaces[i].my_surfPrel_DG_inf) / surfaces[i].compy_Prel;
            surfaces[i].nbz_surfPrel = (surfaces[i].mz_surfPrel_DG_sup - surfaces[i].mz_surfPrel_DG_inf) / surfaces[i].compz_Prel;

            //affichages des donnees recuperees

            printf("Surface_de_prelevement_%d:\n", i + 1);
            printf("Type_de_surface_1>Huygens_2>Surface_de_prelevement_DG_3>Kirchhoff\n");
            printf("%d \n", surfaces[i].typ_surf_prelev);
            if (surfaces[i].surf_prel_inside_outside == 1) printf("surface_de_prelevement_DG_de_type_inside\n");
            if (surfaces[i].surf_prel_inside_outside == 2) printf("surface_de_prelevement_DG_de_type_outside\n");

            printf("Coordonnees_du_coin_inferieur_gauche\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surfaces[i].my_surfPrel_DG_inf);
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mx_surfPrel_DG_inf);
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mz_surfPrel_DG_inf);
            printf("Coordonnee_du_coin_superieur_droit\n");
            printf("Sur_la_longueur_(en_cellules):\n");
            printf("%d \n", surfaces[i].my_surfPrel_DG_sup);
            printf("Sur_la_largeur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mx_surfPrel_DG_sup);
            printf("Sur_la_hauteur_(en_cellules):\n");
            printf("%d \n", surfaces[i].mz_surfPrel_DG_sup);
            printf("Surface_de_prelevement_DG: \n");
            if (surfaces[i].nb_faces_surf_Prel_DG == 5) printf("5 faces + plan de masse \n");
            if (surfaces[i].nb_faces_surf_Prel_DG == 6) printf("6 faces \n");

            printf("cpt_surf_DG : %d \n", cpt_surf_DG);

            cpt_surf_DG++; //incrementation du nombre de surface DG

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
            
            if ( 0 == strcmp(chaine,"[PML]\n") )
                scanPML();
            if (0 == strcmp(chaine,"[PARAMETRES_EXCITATION]\n"))
                scanParametreExcitation();
            if (0 == strcmp(chaine,"[ANALYSE_TEMPORELLE]\n"))
                scanAnalyseTemporelle();
            if (0 == strcmp(chaine,"[PORTS_EXCITATION]\n"))
                scanPortExcitation();
            if (0 == strcmp(chaine,"[CAGES_EXCITATION]\n"))
                scanCageExcitation();
            if (0 == strcmp(chaine,"[SONDES]\n"))
                scanSondes();
            if ( 0 == strcmp(chaine,"[CARTOGRAPHIES_TEMPORELLES]\n") )
                scanCartographieTemporelle();
            if (0 == strcmp(chaine,"[SURFACES_DE_PRELEVEMENT]\n"))
                scanSurfacePrelevement();
            
        } while (!feof(fp));

        fclose(fp);
        printf("**  FIN CHARGEMENT STRUCTURE DATA.ana  **\n");
        printf("*****************************************\n");
    }
}

int parse() {
    parseDSC();
    parseANA();
    return 0;
}
