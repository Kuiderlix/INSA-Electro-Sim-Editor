/* 
 * File:   cageExcitation.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:29 PM
 */

#ifndef CAGEEXCITATION_H
#define	CAGEEXCITATION_H

#include "elementBase.h"
#include "coordonnee.h"
#include "blocConfiguration.h"
#include <string>

/**
 * @brief Cette classe représente la variable cageExcitations d'une simulation
 */
class cageExcitation : public elementBase, public blocConfiguration{
public:
    cageExcitation();

    virtual ~cageExcitation();
    
    int GetHauteur() const {
        return hauteur;
    }

    void SetHauteur(int hauteur) {
        this->hauteur = hauteur;
    }

    int GetInsideOutside() const {
        return insideOutside;
    }

    void SetInsideOutside(int insideOutside) {
        this->insideOutside = insideOutside;
    }

    int GetModeExcitation() const {
        return modeExcitation;
    }

    void SetModeExcitation(int modeExcitation) {
        this->modeExcitation = modeExcitation;
    }

    float GetModulationAmplitude() const {
        return modulationAmplitude;
    }

    void SetModulationAmplitude(float modulationAmplitude) {
        this->modulationAmplitude = modulationAmplitude;
    }

    float GetModulationPhase() const {
        return modulationPhase;
    }

    void SetModulationPhase(float modulationPhase) {
        this->modulationPhase = modulationPhase;
    }

    int GetNbFaces() const {
        return nbFaces;
    }

    void SetNbFaces(int nbFaces) {
        this->nbFaces = nbFaces;
    }

    float GetPhi0() const {
        return phi0;
    }

    void SetPhi0(float phi0) {
        this->phi0 = phi0;
    }

    coordonnee GetPointReference() const {
        return pointReference;
    }

    void SetPointReference(int x, int y, int z) {
        this->pointReference = coordonnee(x,y,z);
    }
    void SetPointReference(coordonnee c) {
        this->pointReference = c;
    }

    float GetPsi0() const {
        return psi0;
    }

    void SetPsi0(float psi0) {
        this->psi0 = psi0;
    }

    int GetSensPropagation() const {
        return sensPropagation;
    }

    void SetSensPropagation(int sensPropagation) {
        this->sensPropagation = sensPropagation;
    }

    float GetTheta0() const {
        return theta0;
    }

    void SetTheta0(float theta0) {
        this->theta0 = theta0;
    }

    int GetTypeExcitation() const {
        return typeExcitation;
    }

    void SetTypeExcitation(int typeExcitation) {
        this->typeExcitation = typeExcitation;
    }
    
    std::string GetNomFichier() const {
        return nomFichier;
    }

    void SetNomFichier(std::string nomFichier) {
        this->nomFichier = nomFichier;
    }

    void ecrire();


    bool isCreate()
    {
        return create;
    }

    void setCreate(bool c)
    {
        create=c;
    }


private:
    bool create;

    int insideOutside;
    int nbFaces;
    int typeExcitation;
    //SI nbFaces = 1 et typeExcitation = 1|2|3
    int modeExcitation;
    int hauteur;
    int sensPropagation;
    //Si typeExcitation = 1|2|3 et nbFaces =! 1
    coordonnee pointReference;
    float theta0;
    float phi0;
    float psi0;
    //Si typeExcitation = 4
    float modulationAmplitude;
    float modulationPhase;
    std::string nomFichier;
};

#endif	/* CAGEEXCITATION_H */

