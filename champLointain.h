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


class champLointain : public blocConfiguration{
    Q_OBJECT
public:
    champLointain();
    virtual ~champLointain();
    
    bool IsCalculImage() const {
        return calculImage;
    }
    double GetFrequenceMax() const {
        return frequenceMax;
    }
    double GetFrequenceMin() const {
        return frequenceMin;
    }
    int GetHauteurPlanMasse() const {
        return hauteurPlanMasse;
    }
    coordonnee GetOrigineRepere() const {
        return origineRepere;
    }
    int GetPasDiscrPhi() const {
        return pasDiscrPhi;
    }
    int GetPasDiscrTeta() const {
        return pasDiscrTeta;
    }
    double GetPasFrequence() const {
        return pasFrequence;
    }
    std::string GetNomFichier() const {
        return nomFichier;
    }

public slots:

    void SetCalculImage(bool calculImage) {
        this->calculImage = calculImage;
    }
    void SetFrequenceMax(double frequenceMax) {
        this->frequenceMax = frequenceMax;
    }

    void SetFrequenceMin(double frequenceMin) {
        this->frequenceMin = frequenceMin;
    }

    void SetHauteurPlanMasse(int hauteurPlanMasse) {
        this->hauteurPlanMasse = hauteurPlanMasse;
    }

    void SetOrigineRepere(int x, int y, int z) {
        this->origineRepere = coordonnee(x,y,z);
    }
    void SetOrigineRepere(coordonnee c) {
        this->origineRepere = c;
    }


    void SetPasDiscrPhi(int pasDiscrPhi) {
        this->pasDiscrPhi = pasDiscrPhi;
    }


    void SetPasDiscrTeta(int pasDiscrTeta) {
        this->pasDiscrTeta = pasDiscrTeta;
    }


    void SetPasFrequence(double pasFrequence) {
        this->pasFrequence = pasFrequence;
    }


    void SetNomFichier(std::string nomFichier) {
        this->nomFichier = nomFichier;
    }

    void ecrire();

private:
    coordonnee origineRepere;
    double frequenceMin;
    double frequenceMax;
    double pasFrequence;
    bool calculImage;
    int hauteurPlanMasse;
    int pasDiscrTeta;
    int pasDiscrPhi;
    std::string nomFichier;
};

#endif	/* CHAMPLOINTAIN_H */

