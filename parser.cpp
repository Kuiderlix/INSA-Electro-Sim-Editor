#include "parser.h"

Parser::Parser()
{
    numstru = 9;
}


/******************************************************************************/
/**>Fonctions Parser **********************************************************/
/******************************************************************************/
void Parser::parserSautLigne(){
    //fscanf(fp, "%*s");
    char temp[100];
    fi >> temp;
}
int Parser::parserGetInt(){
    int temp;
    parserSautLigne();
    fi >> temp;
    //fscanf(fp, "%i", &temp);
    return temp;
}
double Parser::parserGetDouble(){
    double temp;
    parserSautLigne();
    fi >> temp;
    //fscanf(fp, "%f", &temp);
    return temp;
}
string Parser::parserGetString(){
    char temp[TAILLE_CHAINE];
    parserSautLigne();
    fi >> temp;
    //fscanf(fp, "%s", temp);
    std::string retour = std::string(temp);
    return retour;
}
/******************************************************************************/
/**>Fonctions DSC *************************************************************/
/******************************************************************************/
void Parser::scanVolumeDeCalcul(){
    cout << "    scanVolumeDeCalcul" << endl;
    volume.SetLongueur(parserGetDouble());
    volume.SetLargeur(parserGetDouble());
    volume.SetHauteur(parserGetDouble());
    volume.SetNombreY(parserGetInt());
    volume.SetNombreX(parserGetInt());
    volume.SetNombreZ(parserGetInt());
}
void Parser::scanTypeParoi(){
    cout << "    scanTypeParoi" << endl;
    parois.SetParoiInferieure(parserGetInt());
    parois.SetParoiSuperieure(parserGetInt());
    parois.SetParoiX(parserGetInt());
    parois.SetParoiY(parserGetInt());
}
void Parser::scanMetallisation(){
    cout << "    scanMetallisation" << endl;
    int nbMettalisations = parserGetInt();
    
    int i;
    for(i=0; i<nbMettalisations; i++){
        metallisation *temp = new metallisation();
        
        parserSautLigne();
        temp->SetConductivite(parserGetDouble());
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
        
        metallisations.addElement(temp);
    }
}
void Parser::scanParallelepipedes(){
    cout << "    scanParallelepipedes" << endl;
    int nbParallelepipedes = parserGetInt();
    
    int i;
    for(i=0; i<nbParallelepipedes; i++){
        parallelepipede* temp = new parallelepipede;
        
        parserSautLigne();
        temp->SetPermitRelative(parserGetDouble());
        temp->SetPermeRelative(parserGetDouble());
        temp->SetConductivite(parserGetDouble());
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
        
        parallelepipedes.addElement(temp);
    }
}
void Parser::scanElementsLocalises(){
    cout << "    scanElementsLocalises" << endl;
    int nbElements = parserGetInt();
    
    int i;
    for(i=0; i<nbElements; i++){
        elementLocalise *temp;
        
        parserSautLigne();
        temp->SetType(parserGetInt());
        temp->SetValeur(parserGetDouble());
        temp->SetDirection(parserGetInt());
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

        elementLocalises.addElement(temp);
    }
}
void Parser::parseDSC() {
    sprintf(nomfic, "DATA%d.dsc\0", numstru);
    cout << nomfic << endl;
    fi.open(nomfic);
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.dsc **" << endl;
        cout << "*****************************************" << endl;

        do {
            fi.getline(chaine,100,'\n');
            //fgets(chaine, 100, fp);
            cout << chaine << endl << endl;

            /*
             * Dimensions du volume de simulation.
             */
            if (!strcmp(chaine, "[VOLUME_DE_CALCUL]"))
                scanVolumeDeCalcul();
            if (!strcmp(chaine, "[TYPE_PAROIS_0>Mur_1>PEC_2>FLOQUET_3>PML_4>PMC]"))
                scanTypeParoi();
            if (!strcmp(chaine, "[METALLISATIONS]"))
                scanMetallisation();
            if (!strcmp(chaine, "[PARALLELEPIPEDES_MATERIAUX]"))
                scanParallelepipedes();
            if (!strcmp(chaine, "[ELEMENTS_LOCALISES]"))
                scanElementsLocalises();


        } while (!fi.eof());
        fi.close();
        //fclose(fp);
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.dsc  **" << endl;
        cout << "*****************************************" << endl;
    }
}
/******************************************************************************/
/**>Fonctions ANA *************************************************************/
/******************************************************************************/
void Parser::scanPML(){
    cout << "    scanPML" << endl;
    PML.SetEpaisseurCouche(parserGetInt());
    PML.SetOrdreVariation(parserGetInt());
    PML.SetSigmaMax(parserGetDouble());
    PML.SetKMax(parserGetDouble());
}
void Parser::scanParametreExcitation(){
    cout << "    scanParametreExcitation" << endl;
    excitation.SetFrequenceMax(parserGetDouble());
    int typeExcitation = parserGetInt();
    excitation.SetType(typeExcitation);
    if(typeExcitation == 1)
        excitation.SetFrequenceSinus(parserGetDouble());
}
void Parser::scanAnalyseTemporelle(){
    cout << "    scanAnalyseTemporelle" << endl;
    analyseTemp.SetPeriode(parserGetDouble());
    analyseTemp.SetTemps(parserGetDouble());
}
void Parser::scanPortExcitation(){
    cout << "    scanPortExcitation" << endl;
    int nbPorts = parserGetInt();
    
    int i;
    for(i=0; i<nbPorts; i++){
        portExcitation* temp;
        
        parserSautLigne();
        temp->SetPortActif(parserGetInt());
        temp->SetPortInfinitesimal(parserGetInt());
        
        if(temp->IsPortInfinitesimal())
            temp->SetTypePort(parserGetInt());
        
        temp->SetDirection(parserGetInt());
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
        temp->SetImpedance(parserGetDouble());
        temp->SetTypeSource(parserGetInt());
        temp->SetPonderationAmplitude(parserGetDouble());
        temp->SetPonderationPhase(parserGetDouble());
        portExcitations.addElement(temp);
    }
}
void Parser::scanCageExcitation(){
    cout << "    scanCageExcitation" << endl;
    int nbCages = parserGetInt();
    if(nbCages > 1){
        cout << "*****************************************" << endl;
        cout << "* Erreur, plus qu'une cage d'excitation *" << endl;
        cout << "*****************************************" << endl;
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
            cage.SetTheta0(parserGetDouble());
            cage.SetPhi0(parserGetDouble());
            cage.SetPsi0(parserGetDouble());
        }
        if(cage.GetTypeExcitation() == 4){
            cage.SetModulationAmplitude(parserGetDouble());
            cage.SetModulationPhase(parserGetDouble());
        }
    }
}
void Parser::scanSondes(){
    cout << "    scanSondes" << endl;
    int nbSondes = parserGetInt();
    
    int i;
    for(i=0; i<nbSondes; i++){
        sonde *temp = new sonde();
        
        parserSautLigne();
        temp->SetEx(parserGetInt());
        temp->SetEy(parserGetInt());
        temp->SetEz(parserGetInt());
        temp->SetHx(parserGetInt());
        temp->SetHy(parserGetInt());
        temp->SetHz(parserGetInt());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        temp->SetPointApplication(x,y,z);
        temp->SetValeurAuCentre(parserGetInt());
        
        sondes.addElement(temp);
    }
}
void Parser::scanCartographieTemporelle(){
    cout << "    scanCartographieTemporelle" << endl;
    int nbCartos = parserGetInt();
    
    int i;
    for(i=0; i<nbCartos; i++){
        cartographieTemporelle *temp;
        
        parserSautLigne();
        temp->SetChampE(parserGetInt());
        temp->SetChampH(parserGetInt());
        temp->SetIterationDebut(parserGetInt());
        temp->SetIterationFin(parserGetInt());
        temp->SetIntervalle(parserGetInt());
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
        cartographies.addElement(temp);
    }
}
void Parser::scanSurfacePrelevement(){
    cout << "    scanSurfacePrelevement" << endl;
    int nbSurfaces = parserGetInt();

    surfacePrelevements.SetNbSurfacesDG(parserGetInt()); //Rajouté dernièrement. À vérifier !!
    
    int i;
    for(i=0; i<nbSurfaces; i++){
        surfacePrelevement *temp = new surfacePrelevement;
        
        parserSautLigne();
        temp->SetTypeSurface(parserGetInt());
        temp->SetNomFichier(parserGetString());
        if(temp->GetTypeSurface() == 2)
            temp->SetInsideOutside(parserGetInt());
        temp->SetNbFaces(parserGetInt()); //Rajouté dernièrement. À vérifier !!
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
        if(temp->GetTypeSurface() == 2){
            parserSautLigne();
            temp->SetCompressionLongueur(parserGetInt());
            temp->SetCompressionLargeur(parserGetInt());
            temp->SetCompressionHauteur(parserGetInt());
        }
        surfacePrelevements.addElement(temp);
    }
}
void Parser::parseANA() {
    sprintf(nomfic, "DATA%d.ana", numstru);
    cout << nomfic << endl;
    fi.open(nomfic);
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.ana **" << endl;
        cout << "*****************************************" << endl;

        bool onde_plane_oblique = false;
        int nbports_excitation = 0;

        do {
            fi.getline(chaine,100,'\n');
            //fgets(chaine, 100, fp);
            //cout << "%s\n", chaine);

            if (!strcmp(chaine, "[PML]"))
                scanPML();
            if (!strcmp(chaine, "[PARAMETRES_EXCITATION]"))
                scanParametreExcitation();
            if (!strcmp(chaine, "[ANALYSE_TEMPORELLE]"))
                scanAnalyseTemporelle();
            if (!strcmp(chaine, "[PORTS_EXCITATION]"))
                scanPortExcitation();
            if (!strcmp(chaine, "[CAGES_EXCITATION]"))
                scanCageExcitation();
            if (!strcmp(chaine, "[SONDES]"))
                scanSondes();
            if (!strcmp(chaine, "[CARTOGRAPHIES_TEMPORELLES]"))
                scanCartographieTemporelle();
            if (!strcmp(chaine, "[SURFACES_DE_PRELEVEMENT]"))
                scanSurfacePrelevement();

        } while (!fi.eof());
        fi.close();
        //fclose(fp);
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.ana  **" << endl;
        cout << "*****************************************" << endl;
    }
}
/******************************************************************************/
/**>Fonctions PTR *************************************************************/
/******************************************************************************/
void Parser::scanChampLointain(){
    cout << "    scanCahmpLointain" << endl;
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
    champlointain.SetFrequenceMin(parserGetDouble());
    champlointain.SetFrequenceMax(parserGetDouble());
    champlointain.SetPasFrequence(parserGetDouble());
    champlointain.SetCalculImage(parserGetInt());
    champlointain.SetHauteurPlanMasse(parserGetInt());
    parserSautLigne();
    champlointain.SetPasDiscrTeta(parserGetInt());
    champlointain.SetPasDiscrPhi(parserGetInt());
}
void Parser::parsePTR(){
    sprintf(nomfic, "DATA%d.ptr", numstru);
    cout << nomfic << endl;
    fi.open(nomfic, ifstream::in);
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.ptr **" << endl;
        cout << "*****************************************" << endl;

        do {
            fi.getline(chaine,100,'\n');
            //fgets(chaine, 100, fp);
            //cout << "%s\n", chaine);

            if (!strcmp(chaine, "[CALCUL_CHAMP_LOINTAIN]"))
                scanChampLointain();
        } while (!fi.eof());

        fi.close();
        //fclose(fp);
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.ptr  **" << endl;
        cout << "*****************************************" << endl;
    }
}
/******************************************************************************/
/**>Fonctions AVC *************************************************************/
/******************************************************************************/
void Parser::scanExcitation(){
    cout << "    scanExcitation" << endl;
    amplitudeV0.SetAmplitudeV0(parserGetDouble());
}
void Parser::scanFormatStockage(){
    cout << "    scanFormatStockage" << endl;
    stockage.SetFormat(parserGetInt());
    stockage.SetFormatFichierPrelevement(parserGetInt());
}
void Parser::scanEchantillonnage(){
    cout << "    scanEchantillonnage" << endl;
    facteurEchantillonnage.SetFacteurEchatillonnage(parserGetInt());
}
void Parser::scanCompressionHuygens(){
    cout << "    scanCompressionHuygens" << endl;
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
    cout << nomfic << endl;
    fi.open(nomfic);
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.avc **" << endl;
        cout << "*****************************************" << endl;

        do {
            fi.getline(chaine,100,'\n');
            //fgets(chaine, 100, fp);
            //cout << "%s\n", chaine);

            if (!strcmp(chaine, "[EXCITATION]"))
                scanExcitation();
            if (!strcmp(chaine, "[FORMAT_STOCKAGE]"))
                scanFormatStockage();
            if (!strcmp(chaine, "[ECHANTILLONNAGE]"))
                scanEchantillonnage();
            if (!strcmp(chaine, "[COMPRESSION_HUYGENS]"))
                scanCompressionHuygens();
            if (!strcmp(chaine,"[CALCUL_DIRECTIVITE]"))
                scanCalculDirectivite();
        } while (!fi.eof());

        fi.close();
        //fclose(fp);
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.avc  **" << endl;
        cout << "*****************************************" << endl;
    }
}
/******************************************************************************/
/**>Fonction principale *******************************************************/
/******************************************************************************/

void Parser::parse(){
    parseDSC();
    parseANA();
    if(surfacePrelevements.getNbElement() == 1 && surfacePrelevements.GetSurface(0)->GetTypeSurface() == 1)
        parsePTR();
    parseAVC();
    
    cout << volume.GetHauteur() << " " << volume.GetLargeur() << " " << volume.GetLongueur() << endl;
    cout << volume.GetNombreY() << " " << volume.GetNombreX() << " " << volume.GetNombreZ() << endl;
/*
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
    calculdirectivite.ecrire();*/
}
