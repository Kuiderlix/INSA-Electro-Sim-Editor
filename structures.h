/* 
 * File:   structures.h
 * Author: camille
 *
 * Created on February 16, 2013, 3:22 PM
 */

#ifndef STRUCTURES_H
#define	STRUCTURES_H


/**
 * IL FAUDRAIT LES TRANSFORMER EN CLASSES POUR UTILISATION PLUS SIMPLE
 *

*/
/*-----------------------------------------------------------------------------
 *                                                           metal          
 *-----------------------------------------------------------------------------
 *  metal.                                   
 */

typedef struct {
  int ixm1;
  int iym1;
  int izm1;

  int ixm2;
  int iym2;
  int izm2;
  
  float metal_cond;
}             Metallisation;


/*-----------------------------------------------------------------------------
 *                                                           substrat       
 *-----------------------------------------------------------------------------
 *  Substrat.                                   
 */

typedef struct {
  int ixs1;    
  int iys1;
  int izs1;
  int ixs2;
  int iys2;
  int izs2;
  float perm;
  float permea;
  float cond;
}               Substrat;    

/*-----------------------------------------------------------------------------
 *                                                           ���l���ment localis���
 *-----------------------------------------------------------------------------
 *  eltlocalise.                              
 */

typedef struct {
 int type;
 float val;
 int dir;
 int ix1;
 int iy1;
 int iz1;
 int ix2;
 int iy2;
 int iz2;
 
 float *stockself;  //Tableau contenant la somme des champs ���l���ctriques pour le cas de la self
}            ElementLocalise;

/*-----------------------------------------------------------------------------
 *                                                           port d'excitation
 *-----------------------------------------------------------------------------
 *  portexcitation.                              
 */

typedef struct {
 int port_actif;
 int port_inf;
 int port_type;
 int dir;
 int ix1;
 int iy1;
 int iz1;
 int ix2;
 int iy2;
 int iz2;
 float imp;
 int type;
 float ampl;
 float delai;
}            PortExcitation;

/*-----------------------------------------------------------------------------
 *                                                           cage d'excitation
 *-----------------------------------------------------------------------------
 *  CageExcitation.                              
 */

typedef struct {
    int inside_outside;
    int nb_faces_excitation;
    int type_excitation;
    int my_inc_inf;
    int mx_inc_inf;
    int mz_inc_inf;
    int my_inc_sup;
    int mx_inc_sup;
    int mz_inc_sup;
    int y_inc0;
    int x_inc0;
    int z_inc0;
    float theta0deg;
    float phi0deg;
    float psi0deg;
    
    int mode_excitation;
    int zexc;
    int sens_propa;
    
    float mod_ampl_Exci;
    float mod_ret_Exci;
    
    int nbx_inc_prel;
    int nby_inc_prel;
    int nbz_inc_prel;
}            structCageExcitation;

/*-----------------------------------------------------------------------------
 *                                                           portacces = sonde     
 *-----------------------------------------------------------------------------
 *  portacces.                               
 */

typedef struct {

 //composantes effectivement stock���es dans les fichiers de r���sultats
 int flag_ex;
 int flag_ey;
 int flag_ez;
 int flag_hx;
 int flag_hy;
 int flag_hz;
 
 // Coordonn���es de la sonde
 int ix;
 int iy;
 int iz;

 // Valeur calcul���es au centre de la cellule de YEE
 int centre;

}            Sonde;


/*-----------------------------------------------------------------------------
 *                                            structure pour cartos temporelles
 *-----------------------------------------------------------------------------
 */
typedef struct
{
  int SauveE;
  int SauveH;
  long IterDeb;
  long IterFin;
  long IterPas;
  int x1;
  int y1;
  int z1;
  int x2;
  int y2;
  int z2;
}            CartographieTemporelle;



/*-----------------------------------------------------------------------------
 *                                        structure pour surface de prélèvement
 *-----------------------------------------------------------------------------
 */
typedef struct
{
    //Général
    int typ_surf_prelev;
    //Pour les deux
    int nb_surf_ch_loin;
    int mx_surfHuy_inf;
    int my_surfHuy_inf;
    int mz_surfHuy_inf;
    int mx_surfHuy_sup;
    int my_surfHuy_sup;
    int mz_surfHuy_sup;
    //DG
    int surf_prel_inside_outside;
    int compx_Prel;
    int compy_Prel;
    int compz_Prel;
    int nbx_surfPrel;
    int nby_surfPrel;
    int nbz_surfPrel;
}            structSurfacePrelevement;





#endif	/* STRUCTURES_H */

