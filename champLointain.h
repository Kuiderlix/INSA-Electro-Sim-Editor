/* 
 * File:   champLointain.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:47 PM
 */

#ifndef CHAMPLOINTAIN_H
#define	CHAMPLOINTAIN_H

#include "coordonnee.h"
#include "blocConfiguration.h"


class champLointain : blocConfiguration{
public:
    champLointain();
    champLointain(const champLointain& orig);
    virtual ~champLointain();
    
    bool IsCalculImage() const {
        return calculImage;
    }

    void SetCalculImage(bool calculImage) {
        this->calculImage = calculImage;
    }

    float GetFrequenceMax() const {
        return frequenceMax;
    }

    void SetFrequenceMax(float frequenceMax) {
        this->frequenceMax = frequenceMax;
    }

    float GetFrequenceMin() const {
        return frequenceMin;
    }

    void SetFrequenceMin(float frequenceMin) {
        this->frequenceMin = frequenceMin;
    }

    int GetHauteurPlanMasse() const {
        return hauteurPlanMasse;
    }

    void SetHauteurPlanMasse(int hauteurPlanMasse) {
        this->hauteurPlanMasse = hauteurPlanMasse;
    }

    coordonnee GetOrigineRepere() const {
        return origineRepere;
    }

    void SetOrigineRepere(int x, int y, int z) {
        this->origineRepere = coordonnee(x,y,z);
    }

    int GetPasDiscrPhi() const {
        return pasDiscrPhi;
    }

    void SetPasDiscrPhi(int pasDiscrPhi) {
        this->pasDiscrPhi = pasDiscrPhi;
    }

    int GetPasDiscrTeta() const {
        return pasDiscrTeta;
    }

    void SetPasDiscrTeta(int pasDiscrTeta) {
        this->pasDiscrTeta = pasDiscrTeta;
    }

    float GetPasFrequence() const {
        return pasFrequence;
    }

    void SetPasFrequence(float pasFrequence) {
        this->pasFrequence = pasFrequence;
    }
    
    std::string GetNomFichier() const {
        return nomFichier;
    }

    void SetNomFichier(std::string nomFichier) {
        this->nomFichier = nomFichier;
    }

    void ecrire();

private:
    coordonnee origineRepere;
    float frequenceMin;
    float frequenceMax;
    float pasFrequence;
    bool calculImage;
    int hauteurPlanMasse;
    int pasDiscrTeta;
    int pasDiscrPhi;
    std::string nomFichier;
};

#endif	/* CHAMPLOINTAIN_H */

