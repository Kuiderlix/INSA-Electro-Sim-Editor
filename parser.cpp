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
/******************************************************************************/
/**>Variables Parser **********************************************************/
/******************************************************************************/
#define TAILLE_NOM_FICHIER 10
#define TAILLE_CHAINE 100
char nomfic[TAILLE_NOM_FICHIER];
FILE *fp;
char chaine[TAILLE_CHAINE];
//Numero du fichier à récupérer !
int numstru = 1;
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
/******************************************************************************/
/**>Fonctions Parser **********************************************************/
/******************************************************************************/
void parserSautLigne(){
    fscanf(fp, "%*s");
}
int parserGetInt(){
    int temp;
    parserSautLigne();
    fscanf(fp, "%d", &temp);
    return temp;
}
float parserGetFloat(){
    float temp;
    parserSautLigne();
    fscanf(fp, "%f", &temp);
    return temp;
}
string parserGetString(){
    char temp[TAILLE_CHAINE];
    parserSautLigne();
    fscanf(fp, "%s", temp);
    std::string retour = std::string(temp);
    return retour;
}
/******************************************************************************/
/**>Fonctions DSC *************************************************************/
/******************************************************************************/
void scanVolumeDeCalcul(){
    printf("    scanVolumeDeCalcul\n");
    volume.SetLongueur(parserGetFloat());
    volume.SetLargeur(parserGetFloat());
    volume.SetHauteur(parserGetFloat());
    volume.SetNombreY(parserGetInt());
    volume.SetNombreX(parserGetInt());
    volume.SetNombreZ(parserGetInt());
}
void scanTypeParoi(){
    printf("    scanTypeParoi\n");
    parois.SetParoiInferieure(parserGetInt());
    parois.SetParoiSuperieure(parserGetInt());
    parois.SetParoiX(parserGetInt());
    parois.SetParoiY(parserGetInt());
}
void scanMetallisation(){
    printf("    scanMetallisation\n");
    int nbMettalisations = parserGetInt();
    metallisations.SetNbMetallisation(nbMettalisations);
    
    int i;
    for(i=0; i<nbMettalisations; i++){
        metallisation temp;
        
        parserSautLigne();
        temp.SetConductivite(parserGetFloat());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp.SetArriereDroit(x,y,z);
        
        metallisations.addMetallisation(temp);
    }
}
void scanParallelepipedes(){
    printf("    scanParallelepipedes\n");
    int nbParallelepipedes = parserGetInt();
    parallelepipedes.SetNbParallelepipede(nbParallelepipedes);
    
    int i;
    for(i=0; i<nbParallelepipedes; i++){
        parallelepipede temp;
        
        parserSautLigne();
        temp.SetPermitRelative(parserGetFloat());
        temp.SetPermeRelative(parserGetFloat());
        temp.SetConductivite(parserGetFloat());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp.SetArriereDroit(x,y,z);
        
        parallelepipedes.addParallelepipede(temp);
    }
}
void scanElementsLocalises(){
    printf("    scanElementsLocalises\n");
    int nbElements = parserGetInt();
    elementLocalises.SetNbElements(nbElements);
    
    int i;
    for(i=0; i<nbElements; i++){
        elementLocalise temp;
        
        parserSautLigne();
        temp.SetType(parserGetInt());
        temp.SetValeur(parserGetFloat());
        temp.SetDirection(parserGetInt());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp.SetArriereDroit(x,y,z);
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
/**>Fonctions ANA *************************************************************/
/******************************************************************************/
void scanPML(){
    printf("    scanPML\n");
    PML.SetEpaisseurCouche(parserGetInt());
    PML.SetOrdreVariation(parserGetInt());
    PML.SetSigmaMax(parserGetFloat());
    PML.SetKMax(parserGetFloat());
}
void scanParametreExcitation(){
    printf("    scanParametreExcitation\n");
    excitation.SetFrequenceMax(parserGetFloat());
    int typeExcitation = parserGetInt();
    excitation.SetType(typeExcitation);
    if(typeExcitation == 1)
        excitation.SetFrequenceSinus(parserGetFloat());
}
void scanAnalyseTemporelle(){
    printf("    scanAnalyseTemporelle\n");
    analyseTemp.SetPeriode(parserGetFloat());
    analyseTemp.SetTemps(parserGetFloat());
}
void scanPortExcitation(){
    printf("    scanPortExcitation\n");
    int nbPorts = parserGetInt();
    portExcitations.SetNbPorts(nbPorts);
    
    int i;
    for(i=0; i<nbPorts; i++){
        portExcitation temp;
        
        parserSautLigne();
        temp.SetPortActif(parserGetInt());
        temp.SetPortInfinitesimal(parserGetInt());
        
        if(temp.IsPortInfinitesimal())
            temp.SetTypePort(parserGetInt());
        
        temp.SetDirection(parserGetInt());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp.SetArriereDroit(x,y,z);
        temp.SetImpedance(parserGetFloat());
        temp.SetTypeSource(parserGetInt());
        temp.SetPonderationAmplitude(parserGetFloat());
        temp.SetPonderationPhase(parserGetFloat());
    }
}
void scanCageExcitation(){
    printf("    scanCageExcitation\n");
    int nbCages = parserGetInt();
    if(nbCages > 1){
        printf("*****************************************\n");
        printf("* Erreur, plus qu'une cage d'excitation *\n");
        printf("*****************************************\n");
        return;
    }
    parserSautLigne();
    cage.SetInsideOutside(parserGetInt());
    cage.SetNbFaces(parserGetInt());
    cage.SetTypeExcitation(parserGetInt());
    
    if(cage.GetNbFaces() == 1 && cage.GetTypeExcitation() <= 3){
        cage.SetModeExcitation(parserGetInt());
        cage.SetHauteur(parserGetInt());
        cage.SetSensPropagation(parserGetInt());
    } else {
        if(cage.GetTypeExcitation() == 4)
            cage.SetNomFichier(parserGetString());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        cage.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        cage.SetArriereDroit(x,y,z);
        if(cage.GetTypeExcitation() <= 3){
            parserSautLigne();
            y = parserGetInt();
            x = parserGetInt();
            z = parserGetInt();
            cage.SetPointReference(x,y,z);
            parserSautLigne();
            cage.SetTheta0(parserGetFloat());
            cage.SetPhi0(parserGetFloat());
            cage.SetPsi0(parserGetFloat());
        }
        if(cage.GetTypeExcitation() == 4){
            cage.SetModulationAmplitude(parserGetFloat());
            cage.SetModulationPhase(parserGetFloat());
        }
    }
}
void scanSondes(){
    printf("    scanSondes\n");
    int nbSondes = parserGetInt();
    sondes.SetNbSondes(nbSondes);
    
    int i;
    for(i=0; i<nbSondes; i++){
        sonde temp;
        
        parserSautLigne();
        temp.SetEx(parserGetInt());
        temp.SetEy(parserGetInt());
        temp.SetEz(parserGetInt());
        temp.SetHx(parserGetInt());
        temp.SetHy(parserGetInt());
        temp.SetHz(parserGetInt());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetPointApplication(x,y,z);
        temp.SetValeurAuCentre(parserGetInt());
        
        sondes.AddSonde(temp);
    }
}
void scanCartographieTemporelle(){
    printf("    scanCartographieTemporelle\n");
    int nbCartos = parserGetInt();
    cartographies.SetNbCarto(nbCartos);
    
    int i;
    for(i=0; i<nbCartos; i++){
        cartographieTemporelle temp;
        
        parserSautLigne();
        temp.SetChampE(parserGetInt());
        temp.SetChampH(parserGetInt());
        temp.SetIterationDebut(parserGetInt());
        temp.SetIterationFin(parserGetInt());
        temp.SetIntervalle(parserGetInt());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp.SetArriereDroit(x,y,z);
    }
}
void scanSurfacePrelevement(){
    printf("    scanSurfacePrelevement\n");
    int nbSurfaces = parserGetInt();
    surfacePrelevements.SetNbSurfaces(nbSurfaces);
    
    int i;
    for(i=0; i<nbSurfaces; i++){
        surfacePrelevement temp;
        
        parserSautLigne();
        temp.SetTypeSurface(parserGetInt());
        temp.SetNomFichier(parserGetString());
        if(temp.GetTypeSurface() == 2)
            temp.SetInsideOutside(parserGetInt());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp.SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp.SetArriereDroit(x,y,z);
        if(temp.GetTypeSurface() == 2){
            parserSautLigne();
            temp.SetCompressionLongueur(parserGetInt());
            temp.SetCompressionLargeur(parserGetInt());
            temp.SetCompressionHauteur(parserGetInt());
        }
    }
}
void parseANA() {
    sprintf(nomfic, "DATA%d.ana\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.ana **\n");
        printf("*****************************************\n");

        bool onde_plane_oblique = false;
        int nbports_excitation = 0;

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
/**>Fonctions PTR *************************************************************/
/******************************************************************************/
void scanChampLointain(){
    printf("    scanCahmpLointain\n");
    parserSautLigne();
    parserSautLigne();
    parserSautLigne();
    champlointain.SetNomFichier(parserGetString());
    parserSautLigne();
    int y = parserGetInt();
    int x = parserGetInt();
    int z = parserGetInt();
    champlointain.SetOrigineRepere(x,y,z);
    parserSautLigne();
    champlointain.SetFrequenceMin(parserGetFloat());
    champlointain.SetFrequenceMax(parserGetFloat());
    champlointain.SetPasFrequence(parserGetFloat());
    champlointain.SetCalculImage(parserGetInt());
    champlointain.SetHauteurPlanMasse(parserGetInt());
    parserSautLigne();
    champlointain.SetPasDiscrTeta(parserGetInt());
    champlointain.SetPasDiscrPhi(parserGetInt());
}
void parsePTR(){
    sprintf(nomfic, "DATA%d.ptr\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.ptr **\n");
        printf("*****************************************\n");

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
/**>Fonctions AVC *************************************************************/
/******************************************************************************/
void scanExcitation(){
    printf("    scanExcitation\n");
    amplitudeV0.SetAmplitudeV0(parserGetFloat());
}
void scanFormatStockage(){
    printf("    scanFormatStockage\n");
    stockage.SetFormat(parserGetInt());
    stockage.SetFormatFichierPrelevement(parserGetInt());
}
void scanEchantillonnage(){
    printf("    scanEchantillonnage\n");
    facteurEchantillonnage.SetFacteurEchatillonnage(parserGetInt());
}
void scanCompressionHuygens(){
    printf("    scanCompressionHuygens\n");
    parserSautLigne();
    compHuygens.SetCompressionLongueur(parserGetInt());
    compHuygens.SetCompressionLargeur(parserGetInt());
    compHuygens.SetCompressionHauteur(parserGetInt());
    compHuygens.SetFacteurMultiplicatif(parserGetInt());
}
void scanCalculDirectivite(){
    printf("    scanCalculDirectivite");
    calculdirectivite.SetCalcul(parserGetInt());
    calculdirectivite.SetPasTheta(parserGetInt());
    calculdirectivite.SetPasPhi(parserGetInt());
}
void parseAVC(){
    sprintf(nomfic, "DATA%d.avc\0", numstru);
    printf("%s \n", nomfic);

    if ((fp = fopen(nomfic, "r")) != NULL) {
        printf("** CHARGEMENT DE LA STRUCTURE DATA.avc **\n");
        printf("*****************************************\n");

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
/******************************************************************************/
/**>Fonction principale *******************************************************/
/******************************************************************************/
void parse(){
    parseDSC();
    parseANA();
    if(surfacePrelevements.GetNbSurfaces() == 1 && surfacePrelevements.GetSurface(0).GetTypeSurface() == 1)
        parsePTR();
    parseAVC();
    volume.ecrire();
}