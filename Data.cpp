#include "Data.h"

#include "parser.h"

Data::Data()
{
}

Data::Data(Parser *p)
{
    p->parse(this);
}

void Data::ecrire(int numstru){

    //On donne le bon numéro de structure à la classe Ecriture
    Ecriture::setNumStru(numstru);

    //DSC
    volume.ecrire();
    parois.ecrire();
    metallisations.ecrire();
    parallelepipedes.ecrire();
    elementLocalises.ecrire();
    //ANA
    PML.ecrire();
    excitation.ecrire();
    analyseTemp.ecrire();
    portExcitations.ecrire();
    cage.ecrire();
    sondes.ecrire();
    cartographies.ecrire();
    surfacePrelevements.ecrire();
    //PTR
    if(surfacePrelevements.getNbElement() == 1 && surfacePrelevements.GetSurface(0)->GetTypeSurface() == 1)
        champlointain.ecrire();
    //AVC
    amplitudeV0.ecrire();
    stockage.ecrire();
    facteurEchantillonnage.ecrire();
    compHuygens.ecrire();
    calculdirectivite.ecrire();
}
