#include "parser.h"

Parser::Parser()
{
    numstru = 1;
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
    data->getVolumeCalcul()->SetLongueur(parserGetDouble());
    data->getVolumeCalcul()->SetLargeur(parserGetDouble());
    data->getVolumeCalcul()->SetHauteur(parserGetDouble());
    data->getVolumeCalcul()->SetNombreY(parserGetInt());
    data->getVolumeCalcul()->SetNombreX(parserGetInt());
    data->getVolumeCalcul()->SetNombreZ(parserGetInt());
}
void Parser::scanTypeParoi(){
    cout << "    scanTypeParoi" << endl;
    data->getParoi()->SetParoiInferieure(parserGetInt());
    data->getParoi()->SetParoiSuperieure(parserGetInt());
    data->getParoi()->SetParoiX(parserGetInt());
    data->getParoi()->SetParoiY(parserGetInt());
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
        
        data->getBlocMetallisations()->addElement(temp);
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
        
        data->getBlocParallelepipede()->addElement(temp);
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

        data->getBlocElementLocalise()->addElement(temp);
    }
}
void Parser::parseDSC() {

    QString nomFichier;
    nomFichier = emplacementFichier + "/DATA"+QString::number(numstru)+".dsc";

    fi.open(nomFichier.toStdString().c_str());
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
    data->getPML()->SetEpaisseurCouche(parserGetInt());
    data->getPML()->SetOrdreVariation(parserGetInt());
    data->getPML()->SetSigmaMax(parserGetDouble());
    data->getPML()->SetKMax(parserGetDouble());
}
void Parser::scanParametreExcitation(){
    cout << "    scanParametreExcitation" << endl;
    data->getParamExcitations()->SetFrequenceMax(parserGetDouble());
    int typeExcitation = parserGetInt();
    data->getParamExcitations()->SetType(typeExcitation);
    if(typeExcitation == 1)
        data->getParamExcitations()->SetFrequenceSinus(parserGetDouble());
}
void Parser::scanAnalyseTemporelle(){
    cout << "    scanAnalyseTemporelle" << endl;
    data->getAnalyseTempo()->SetPeriode(parserGetDouble());
    data->getAnalyseTempo()->SetTemps(parserGetDouble());
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
        data->getBlocPortExcitation()->addElement(temp);
    }
}
void Parser::scanCageExcitation(){
    cout << "    scanCageExcitation" << endl;
    data->getCageExcitation()->setCreate(false);
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

    data->getCageExcitation()->setCreate(true);

    parserSautLigne();
    data->getCageExcitation()->SetInsideOutside(parserGetInt());
    data->getCageExcitation()->SetNbFaces(parserGetInt());
    data->getCageExcitation()->SetTypeExcitation(parserGetInt());
    
    if(data->getCageExcitation()->GetNbFaces() == 1 && data->getCageExcitation()->GetTypeExcitation() <= 3){
        data->getCageExcitation()->SetModeExcitation(parserGetInt());
        data->getCageExcitation()->SetHauteur(parserGetInt());
        data->getCageExcitation()->SetSensPropagation(parserGetInt());
    } else {
        if(data->getCageExcitation()->GetTypeExcitation() == 4)
            data->getCageExcitation()->SetNomFichier(parserGetString());
        parserSautLigne();
        int y = parserGetInt();
        int x = parserGetInt();
        int z = parserGetInt();
        data->getCageExcitation()->SetAvantGauche(x,y,z);
        parserSautLigne();
        y = parserGetInt();
        x = parserGetInt();
        z = parserGetInt();
        data->getCageExcitation()->SetArriereDroit(x,y,z);
        if(data->getCageExcitation()->GetTypeExcitation() <= 3){
            parserSautLigne();
            y = parserGetInt();
            x = parserGetInt();
            z = parserGetInt();
            data->getCageExcitation()->SetPointReference(x,y,z);
            parserSautLigne();
            data->getCageExcitation()->SetTheta0(parserGetDouble());
            data->getCageExcitation()->SetPhi0(parserGetDouble());
            data->getCageExcitation()->SetPsi0(parserGetDouble());
        }
        if(data->getCageExcitation()->GetTypeExcitation() == 4){
            data->getCageExcitation()->SetModulationAmplitude(parserGetDouble());
            data->getCageExcitation()->SetModulationPhase(parserGetDouble());
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
        
        data->getBlocSonde()->addElement(temp);
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
        data->getBlocCartoTempo()->addElement(temp);
    }
}
void Parser::scanSurfacePrelevement(){
    cout << "    scanSurfacePrelevement" << endl;
    int nbSurfaces = parserGetInt();

    data->getBlocSurfacePrelev()->SetNbSurfacesDG(parserGetInt()); //Rajouté dernièrement. À vérifier !!
    
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
        data->getBlocSurfacePrelev()->addElement(temp);
    }
}
void Parser::parseANA() {

    QString nomFichier;
    nomFichier = emplacementFichier + "/DATA"+QString::number(numstru)+".ana";

    fi.open(nomFichier.toStdString().c_str());
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.ana **" << endl;
        cout << "*****************************************" << endl;

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
    data->getChampLointain()->SetNomFichier(parserGetString());
    parserSautLigne();
    int y = parserGetInt();
    int x = parserGetInt();
    int z = parserGetInt();
    data->getChampLointain()->SetOrigineRepere(x,y,z);
    parserSautLigne();
    data->getChampLointain()->SetFrequenceMin(parserGetDouble());
    data->getChampLointain()->SetFrequenceMax(parserGetDouble());
    data->getChampLointain()->SetPasFrequence(parserGetDouble());
    data->getChampLointain()->SetCalculImage(parserGetInt());
    data->getChampLointain()->SetHauteurPlanMasse(parserGetInt());
    parserSautLigne();
    data->getChampLointain()->SetPasDiscrTeta(parserGetInt());
    data->getChampLointain()->SetPasDiscrPhi(parserGetInt());
}
void Parser::parsePTR(){
    QString nomFichier;
    nomFichier = emplacementFichier + "/DATA"+QString::number(numstru)+".ptr";

    fi.open(nomFichier.toStdString().c_str());
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.ptr **" << endl;
        cout << "*****************************************" << endl;

        do {
            fi.getline(chaine,100,'\n');
            if (!strcmp(chaine, "[CALCUL_CHAMP_LOINTAIN]"))
                scanChampLointain();
        } while (!fi.eof());

        fi.close();
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.ptr  **" << endl;
        cout << "*****************************************" << endl;
    }
}
/******************************************************************************/
/**>Fonctions AVC *************************************************************/
/******************************************************************************/
void Parser::scanExcitation(){
    cout << "    scanExcitation" << endl;
    data->getExcitation()->SetAmplitudeV0(parserGetDouble());
}
void Parser::scanFormatStockage(){
    cout << "    scanFormatStockage" << endl;
    data->getFormatStockage()->SetFormat(parserGetInt());
    data->getFormatStockage()->SetFormatFichierPrelevement(parserGetInt());
}
void Parser::scanEchantillonnage(){
    cout << "    scanEchantillonnage" << endl;
    data->getBlocEchantillonnage()->SetFacteurEchatillonnage(parserGetInt());
}
void Parser::scanCompressionHuygens(){
    cout << "    scanCompressionHuygens" << endl;
    parserSautLigne();
    data->getCompressionHuygens()->SetCompressionLongueur(parserGetInt());
    data->getCompressionHuygens()->SetCompressionLargeur(parserGetInt());
    data->getCompressionHuygens()->SetCompressionHauteur(parserGetInt());
    data->getCompressionHuygens()->SetFacteurMultiplicatif(parserGetInt());
}
void Parser::scanCalculDirectivite(){
    cout << "    scanCalculDirectivite" << endl;
    data->getCalculDirective()->SetCalcul(parserGetInt());
    data->getCalculDirective()->SetPasTheta(parserGetInt());
    data->getCalculDirective()->SetPasPhi(parserGetInt());
}
void Parser::parseAVC(){
    QString nomFichier;
    nomFichier = emplacementFichier + "/DATA"+QString::number(numstru)+".avc";

    fi.open(nomFichier.toStdString().c_str());
    if (fi.is_open()) {
        cout << "** CHARGEMENT DE LA STRUCTURE DATA.avc **" << endl;
        cout << "*****************************************" << endl;

        do {
            fi.getline(chaine,100,'\n');

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
        cout << "**  FIN CHARGEMENT STRUCTURE DATA.avc  **" << endl;
        cout << "*****************************************" << endl;
    }
}
/******************************************************************************/
/**>Fonction principale *******************************************************/
/******************************************************************************/

void Parser::parse(Data * data){
    QSettings settings("INSAProj", "EditSimuIETR");
    emplacementFichier=settings.value("PathSimu",QCoreApplication::applicationDirPath()).toString();
    qDebug() << emplacementFichier;
    this->data=data;
    parseDSC();
    parseANA();
    if(data->getBlocSurfacePrelev()->getNbElement() == 1 && data->getBlocSurfacePrelev()->GetSurface(0)->GetTypeSurface() == 1)
        parsePTR();
    parseAVC();

}

int Parser::getNumStru()
{
    return this->numstru;
}
