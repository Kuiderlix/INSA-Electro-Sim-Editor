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
#include <fstream>
#include <limits>
#include <list>
#include "Data.h"
using namespace std;

#define TAILLE_NOM_FICHIER 10
#define TAILLE_CHAINE 100

/**
 * @brief Le parser de fichier de configuration
 */
class Parser {
public:

    Parser();

    /**
     * @brief Fonction principale. Elle démarre le parsing.
     * @param data Le conteneur des données récupérées.
     */
    void parse(Data *data);

private:

    /******************************************************************************/
    /**>Fonctions Parser **********************************************************/
    /******************************************************************************/
    void parserSautLigne();
    int parserGetInt();
    double parserGetDouble();
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
    ifstream fi;
    char chaine[TAILLE_CHAINE];
    //Numero du fichier à récupérer !
    int numstru;

    Data* data;


};

#endif	/* PARSER_H */

