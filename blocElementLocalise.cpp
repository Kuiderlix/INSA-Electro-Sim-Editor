/* 
 * File:   blocElementLocalise.cpp
 * Author: camille
 * 
 * Created on March 3, 2013, 7:29 PM
 */

#include <vector>

#include "blocElementLocalise.h"
#include "elementLocalise.h"

blocElementLocalise::blocElementLocalise() {
    this->setHeader("[ELEMENTS_LOCALISES]");
    this->setExtension(".dsc");
}


blocElementLocalise::~blocElementLocalise() {
}

void blocElementLocalise::ecrire(){
    /*
    blocConfiguration bC = blocConfiguration(*this); //on copie l'objet, ce qui prend du temps et de la mémoire
    bC.setHeader("[ELEMENTS_LOCALISES]");
    bC.setExtension(".dsc");
    bC.ecrire();*/

    this->blocConfiguration::ecrire(); // on appel direct la fonction de la classe de base, l'inialisation
                                       // de l'header et de l'extension est faite dans le constructeur de cette classe


    std::ostringstream monEcriture;
    monEcriture << "Nombre_d_elements_localises:\n";
    monEcriture << this->getNbElement() << std::endl;


    //std::string ecriture(monEcriture.str());
    //Ecriture::Ecrire(ecriture);

    Ecriture::Ecrire(monEcriture.str()); // on met direct la fonction, pourquoi perdre du temps à faire une copie de la chaine ?

    for(int i=0; i<this->getNbElement(); i++){
        elementLocalise *temp = this->GetElementLocalise(i); //utilisation de pointeur plutot que de copier l'objet
        temp->ecrire(i+1);
    }

    Ecriture::Ecrire("\n");
}
