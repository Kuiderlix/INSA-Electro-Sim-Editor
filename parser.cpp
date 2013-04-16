#include "parser.h"

Parser::Parser()
{
    numstru = 1;
}


/******************************************************************************/
/**>Fonctions Parser **********************************************************/
/******************************************************************************/
void Parser::parserSautLigne(){
    fscanf(fp, "%*s");
}
int Parser::parserGetInt(){
    int temp;
    parserSautLigne();
    fscanf(fp, "%d", &temp);
    return temp;
}
float Parser::parserGetFloat(){
    float temp;
    parserSautLigne();
    fscanf(fp, "%f", &temp);
    return temp;
}
string Parser::parserGetString(){
    char temp[TAILLE_CHAINE];
    parserSautLigne();
    fscanf(fp, "%s", temp);
    std::string retour = std::string(temp);
    return retour;
}
/******************************************************************************/
/**>Fonctions DSC *************************************************************/
/******************************************************************************/
void Parser::scanVolumeDeCalcul(){
    cout << "    scanVolumeDeCalcul\n" << endl;
    volume.SetLongueur(parserGetFloat());
    volume.SetLargeur(parserGetFloat());
    volume.SetHauteur(parserGetFloat());
    volume.SetNombreY(parserGetInt());
    volume.SetNombreX(parserGetInt());
    volume.SetNombreZ(parserGetInt());
}
void Parser::scanTypeParoi(){
    cout << "    scanTypeParoi\n" << endl;
    parois.SetParoiInferieure(parserGetInt());
    parois.SetParoiSuperieure(parserGetInt());
    parois.SetParoiX(parserGetInt());
    parois.SetParoiY(parserGetInt());
}
void Parser::scanMetallisation(){
    cout << "    scanMetallisation\n" << endl;
    int nbMettalisations = parserGetInt();
    metallisations.SetNbMetallisation(nbMettalisations);
    
    int i;
    for(i=0; i<nbMettalisations; i++){
        metallisation *temp = new metallisation();
        
        parserSautLigne();
        temp->SetConductivite(parserGetFloat());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp->SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        temp->SetArriereDroit(x,y,z);
        
        metallisations.addMetallisation(temp);
    }
}
void Parser::scanParallelepipedes(){
    cout << "    scanParallelepipedes\n" << endl;
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
void Parser::scanElementsLocalises(){
    cout << "    scanElementsLocalises\n" << endl;
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
void Parser::parseDSC() {
    sprintf(nomfic, "DATA%d.dsc\0", numstru);
    cout << nomfic << "\n" << endl;

    if ((fp = fopen(nomfic, "r")) != NULL) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.dsc **\n" << endl;
        cout << "*****************************************\n" << endl;

        do {
            fgets(chaine, 100, fp);
            //cout << "%s\n",chaine);

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
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.dsc  **\n" << endl;
        cout << "*****************************************\n" << endl;
    }
}
/******************************************************************************/
/**>Fonctions ANA *************************************************************/
/******************************************************************************/
void Parser::scanPML(){
    cout << "    scanPML\n" << endl;
    PML.SetEpaisseurCouche(parserGetInt());
    PML.SetOrdreVariation(parserGetInt());
    PML.SetSigmaMax(parserGetFloat());
    PML.SetKMax(parserGetFloat());
}
void Parser::scanParametreExcitation(){
    cout << "    scanParametreExcitation\n" << endl;
    excitation.SetFrequenceMax(parserGetFloat());
    int typeExcitation = parserGetInt();
    excitation.SetType(typeExcitation);
    if(typeExcitation == 1)
        excitation.SetFrequenceSinus(parserGetFloat());
}
void Parser::scanAnalyseTemporelle(){
    cout << "    scanAnalyseTemporelle\n" << endl;
    analyseTemp.SetPeriode(parserGetFloat());
    analyseTemp.SetTemps(parserGetFloat());
}
void Parser::scanPortExcitation(){
    cout << "    scanPortExcitation\n" << endl;
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
void Parser::scanCageExcitation(){
    cout << "    scanCageExcitation\n" << endl;
    int nbCages = parserGetInt();
    if(nbCages > 1){
        cout << "*****************************************\n" << endl;
        cout << "* Erreur, plus qu'une cage d'excitation *\n" << endl;
        cout << "*****************************************\n" << endl;
        return;
    }
    if(nbCages < 1){
        return; //On veut exactement une cage d'excitation.
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
void Parser::scanSondes(){
    cout << "    scanSondes\n" << endl;
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
void Parser::scanCartographieTemporelle(){
    cout << "    scanCartographieTemporelle\n" << endl;
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
void Parser::scanSurfacePrelevement(){
    cout << "    scanSurfacePrelevement\n" << endl;
    int nbSurfaces = parserGetInt();
    surfacePrelevements.SetNbSurfaces(nbSurfaces);

    surfacePrelevements.SetNbSurfacesDG(parserGetInt()); //Rajouté dernièrement. À vérifier !!
    
    int i;
    for(i=0; i<nbSurfaces; i++){
        surfacePrelevement temp;
        
        parserSautLigne();
        temp.SetTypeSurface(parserGetInt());
        temp.SetNomFichier(parserGetString());
        if(temp.GetTypeSurface() == 2)
            temp.SetInsideOutside(parserGetInt());
        temp.SetNbFaces(parserGetInt()); //Rajouté dernièrement. À vérifier !!
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
void Parser::parseANA() {
    sprintf(nomfic, "DATA%d.ana\0", numstru);
    cout << nomfic << "\n" << endl;

    if ((fp = fopen(nomfic, "r")) != NULL) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.ana **\n" << endl;
        cout << "*****************************************\n" << endl;

        bool onde_plane_oblique = false;
        int nbports_excitation = 0;

        do {
            fgets(chaine, 100, fp);
            //cout << "%s\n", chaine);

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
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.ana  **\n" << endl;
        cout << "*****************************************\n" << endl;
    }
}
/******************************************************************************/
/**>Fonctions PTR *************************************************************/
/******************************************************************************/
void Parser::scanChampLointain(){
    cout << "    scanCahmpLointain\n" << endl;
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
void Parser::parsePTR(){
    sprintf(nomfic, "DATA%d.ptr\0", numstru);
    cout << nomfic << "\n" << endl;

    if ((fp = fopen(nomfic, "r")) != NULL) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.ptr **\n" << endl;
        cout << "*****************************************\n" << endl;

        do {
            fgets(chaine, 100, fp);
            //cout << "%s\n", chaine);

            if (0 == strcmp(chaine, "[CALCUL_CHAMP_LOINTAIN]\n"))
                scanChampLointain();
        } while (!feof(fp));

        fclose(fp);
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.ptr  **\n" << endl;
        cout << "*****************************************\n" << endl;
    }
}
/******************************************************************************/
/**>Fonctions AVC *************************************************************/
/******************************************************************************/
void Parser::scanExcitation(){
    cout << "    scanExcitation\n" << endl;
    amplitudeV0.SetAmplitudeV0(parserGetFloat());
}
void Parser::scanFormatStockage(){
    cout << "    scanFormatStockage\n" << endl;
    stockage.SetFormat(parserGetInt());
    stockage.SetFormatFichierPrelevement(parserGetInt());
}
void Parser::scanEchantillonnage(){
    cout << "    scanEchantillonnage\n" << endl;
    facteurEchantillonnage.SetFacteurEchatillonnage(parserGetInt());
}
void Parser::scanCompressionHuygens(){
    cout << "    scanCompressionHuygens\n" << endl;
    parserSautLigne();
    compHuygens.SetCompressionLongueur(parserGetInt());
    compHuygens.SetCompressionLargeur(parserGetInt());
    compHuygens.SetCompressionHauteur(parserGetInt());
    compHuygens.SetFacteurMultiplicatif(parserGetInt());
}
void Parser::scanCalculDirectivite(){
    cout << "    scanCalculDirectivite" << endl;
    calculdirectivite.SetCalcul(parserGetInt());
    calculdirectivite.SetPasTheta(parserGetInt());
    calculdirectivite.SetPasPhi(parserGetInt());
}
void Parser::parseAVC(){
    sprintf(nomfic, "DATA%d.avc\0", numstru);
    cout << nomfic << "\n" << endl;

    if ((fp = fopen(nomfic, "r")) != NULL) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.avc **\n" << endl;
        cout << "*****************************************\n" << endl;

        do {
            fgets(chaine, 100, fp);
            //cout << "%s\n", chaine);

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
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.avc  **\n" << endl;
        cout << "*****************************************\n" << endl;
    }
}
/******************************************************************************/
/**>Fonction principale *******************************************************/
/******************************************************************************/

void Parser::parse(){
    parseDSC();
    parseANA();
    if(surfacePrelevements.GetNbSurfaces() == 1 && surfacePrelevements.GetSurface(0).GetTypeSurface() == 1)
        parsePTR();
    parseAVC();
    
    cout << volume.GetHauteur() << " " << volume.GetLargeur() << " " << volume.GetLongueur() << endl;
    cout << volume.GetNombreY() << " " << volume.GetNombreX() << " " << volume.GetNombreZ() << endl;

    //On réécrit tout pour vérifier.
    volume.ecrire();
    parois.ecrire();
    metallisations.ecrire();
    parallelepipedes.ecrire();
    elementLocalises.ecrire();
    PML.ecrire();
    excitation.ecrire();
    analyseTemp.ecrire();
    portExcitations.ecrire();
    cage.ecrire();
    sondes.ecrire();
    cartographies.ecrire();
    surfacePrelevements.ecrire();
    champlointain.ecrire();
    amplitudeV0.ecrire();
    stockage.ecrire();
    facteurEchantillonnage.ecrire();
    compHuygens.ecrire();
    calculdirectivite.ecrire();
}
