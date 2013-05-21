#ifndef DATA_H
#define DATA_H
#include "volumeCalcul.h"
#include "paroi.h"
#include "metallisation.h"
#include "blocMetallisation.h"
#include "parallelepipede.h"
#include "blocParallelepipede.h"
#include "blocElementLocalise.h"
#include "pml.h"
#include "ParamExcitations.h"
#include "analyseTemporelle.h"
#include "blocPortExcitation.h"
#include "cageExcitation.h"
#include "blocSonde.h"
#include "blocCartographieTemporelle.h"
#include "blocSurfacePrelevement.h"
#include "champLointain.h"
#include "Excitation.h"
#include "formatStockage.h"
#include "blocEchantillonnage.h"
#include "compressionHuygens.h"
#include "calculDirectivite.h"

class Parser;
/**
 * @brief Contient toutes les données utiles pour la simulation.
 */
class Data
{
public:
    Data();
    Data(Parser * p);


    volumeCalcul * getVolumeCalcul() {return &volume;}
    paroi * getParoi() {return &parois;}

    blocMetallisation * getBlocMetallisations() {return &metallisations;}
    blocParallelepipede * getBlocParallelepipede() {return &parallelepipedes;}
    blocSonde * getBlocSonde() {return &sondes;}
    blocElementLocalise * getBlocElementLocalise() {return &elementLocalises;}
    blocPortExcitation * getBlocPortExcitation()  {return &portExcitations;}
    blocCartographieTemporelle * getBlocCartoTempo() {return &cartographies;}
    blocSurfacePrelevement * getBlocSurfacePrelev() {return &surfacePrelevements;}

    pml * getPML() {return &PML;}
    ParamExcitations* getParamExcitations() {return &excitation;}
    analyseTemporelle* getAnalyseTempo() {return &analyseTemp;}
    blocPortExcitation* getPortExcitations() {return &portExcitations;}
    cageExcitation* getCageExcitation() {return &cage;}
    champLointain * getChampLointain() {return &champlointain;}
    Excitation* getExcitation() {return &amplitudeV0;}
    formatStockage* getFormatStockage() {return &stockage;}
    blocEchantillonnage* getBlocEchantillonnage() {return &facteurEchantillonnage;}
    compressionHuygens* getCompressionHuygens() {return &compHuygens;}
    calculDirectivite* getCalculDirective() {return &calculdirectivite;}


private:
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
    ParamExcitations excitation;
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
    Excitation amplitudeV0;
    formatStockage stockage;
    blocEchantillonnage facteurEchantillonnage;
    compressionHuygens compHuygens;
    calculDirectivite calculdirectivite;
};

#endif // DATA_H
