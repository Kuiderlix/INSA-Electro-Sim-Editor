#ifndef PARSER_H
#define	PARSER_H
/*
 * File:   parser.h
 * Author: camille
 *
 * Created on March 4, 2013, 4:35 PM
 */
/******************************************************************************/
/**>INTERFACE SYSTEME *********************************************************/
/******************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <iostream>
#include <list>
#include "volumeCalcul.h"
#include "paroi.h"
#include "metallisation.h"
#include "blocMetallisation.h"
#include "parallelepipede.h"
#include "blocParallelepipede.h"
#include "blocElementLocalise.h"
#include "pml.h"
#include "excitations.h"
#include "analyseTemporelle.h"
#include "blocPortExcitation.h"
#include "cageExcitation.h"
#include "blocSonde.h"
#include "blocCartographieTemporelle.h"
#include "blocSurfacePrelevement.h"
#include "champLointain.h"
#include "blocAmplitude.h"
#include "formatStockage.h"
#include "blocEchantillonnage.h"
#include "compressionHuygens.h"
#include "calculDirectivite.h"
using namespace std;

#define TAILLE_NOM_FICHIER 10
#define TAILLE_CHAINE 100

class Parser {
public:

    Parser();

    /******************************************************************************/
    /**>Fonction principale *******************************************************/
    /******************************************************************************/
    void parse();

    volumeCalcul * getVolumeCalcul() {return &volume;}
    blocMetallisation * getBlocMetallisations() {return &metallisations;}
    blocParallelepipede * getBlocParallelepipede() {return &parallelepipedes;}
    blocSonde * getBlocSonde() {return &sondes;}
    blocElementLocalise * getBlocElementLocalise() {return &elementLocalises;}
    blocPortExcitation * getBlocPortExcitation()  {return &portExcitations;}



private:

    /******************************************************************************/
    /**>Fonctions Parser **********************************************************/
    /******************************************************************************/
    void parserSautLigne();
    int parserGetInt();
    float parserGetFloat();
    string parserGetString();

    /******************************************************************************/
    /**>Fonctions DSC *************************************************************/
    /******************************************************************************/

    void scanVolumeDeCalcul();
    void scanTypeParoi();
    void scanMetallisation();
    void scanParallelepipedes();
    void scanElementsLocalises();
    void parseDSC();


    /******************************************************************************/
    /**>Fonctions ANA *************************************************************/
    /******************************************************************************/

    void scanPML();
    void scanParametreExcitation();
    void scanAnalyseTemporelle();
    void scanPortExcitation();
    void scanCageExcitation();
    void scanSondes();
    void scanCartographieTemporelle();
    void scanSurfacePrelevement();
    void parseANA();


    /******************************************************************************/
    /**>Fonctions PTR *************************************************************/
    /******************************************************************************/

    void scanChampLointain();
    void parsePTR();


    /******************************************************************************/
    /**>Fonctions AVC *************************************************************/
    /******************************************************************************/

    void scanExcitation();
    void scanFormatStockage();
    void scanEchantillonnage();
    void scanCompressionHuygens();
    void scanCalculDirectivite();
    void parseAVC();


    /******************************************************************************/
    /**>Variables Parser **********************************************************/
    /******************************************************************************/
    char nomfic[TAILLE_NOM_FICHIER];
    FILE *fp;
    char chaine[TAILLE_CHAINE];
    //Numero du fichier à récupérer !
    int numstru;
    /******************************************************************************/
    /**>Variables récupérées .DSC *************************************************/
    /******************************************************************************/
    volumeCalcul volume;
    paroi parois;
    blocMetallisation metallisations;
    blocParallelepipede parallelepipedes;
    blocElementLocalise elementLocalises;
    /******************************************************************************/
    /**>Variables récupérées .ANA *************************************************/
    /******************************************************************************/
    pml PML;
    excitations excitation;
    analyseTemporelle analyseTemp;
    blocPortExcitation portExcitations;
    cageExcitation cage;
    blocSonde sondes;
    blocCartographieTemporelle cartographies;
    blocSurfacePrelevement surfacePrelevements;
    /******************************************************************************/
    /**>Variables récupérées .PTR *************************************************/
    /******************************************************************************/
    champLointain champlointain;
    /******************************************************************************/
    /**>Variables récupérées .AVC *************************************************/
    /******************************************************************************/
    blocAmplitude amplitudeV0;
    formatStockage stockage;
    blocEchantillonnage facteurEchantillonnage;
    compressionHuygens compHuygens;
    calculDirectivite calculdirectivite;

};

#endif	/* PARSER_H */

