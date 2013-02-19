/* 
 * File:   constants.h
 * Author: camille
 *
 * Created on February 16, 2013, 2:39 PM
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H

/******************************************************************************/
/**>CONSTANTES EXPORTEES ******************************************************/
/******************************************************************************/

#define CVIDE      3.E+8
#define MU0        1.257E-6
#define EPS0       8.85E-12
#define PI         3.14159265358979323846
#define ETA        376.87385

#define NB_SUBS_MX 500          // nombre max de substrats par volume FDTD
#define NB_META_MX 600          // nombre max de metallisations par volume FDTD
#define NB_PLAQ_X_MX    500
#define NB_PLAQ_Y_MX    500
#define NB_PORT_MX 20           // nombre max de sondes et de ports adaptes par volume FDTD
#define NB_MIN_CEL_LAMBDA0 25   // nombre min de celulles par longueur d'onde
#define NB_SURF_PREL_MAX  5     // nombre max de surface de prelevement tout type confondu
#define NB_SURF_DG_MAX 2        // nombre max de surface de prelevement DG
#define NB_SURF_EXCI_MAX 5              // nombre maximum de surface d'excitation toute surface confondue
#define NON        0            
#define OUI        1  

#define BINAIRE    1
#define TEXTE      2

#define PAROI_MUR     0
#define PAROI_PEC     1
#define PAROI_FLOQUET 2
#define PAROI_PML     3 
#define PAROI_PMC     4

// CONSTANTES DE CHOIX DU TYPE D'EXCITATION
#define ONDEPLANEX              0
#define ONDEPLANEY              1
#define TE10X                   2
#define TE10Y                   3

#define NB_PAROI_ANA_MX 10

#define TRAITEMENT_HUYGENS 0
#define GAUSS_MODULE_SINUS      1

#endif	/* CONSTANTS_H */

