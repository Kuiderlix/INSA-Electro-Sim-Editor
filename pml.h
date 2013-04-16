/* 
 * File:   pml.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:26 PM
 */

#ifndef PML_H
#define	PML_H

#include "blocConfiguration.h"


class pml : public blocConfiguration{
public:
    pml();
    pml(const pml& orig);
    virtual ~pml();
    
    int GetEpaisseurCouche() const {
        return epaisseurCouche;
    }

    void SetEpaisseurCouche(int epaisseurCouche) {
        this->epaisseurCouche = epaisseurCouche;
    }

    float GetKMax() const {
        return kMax;
    }

    void SetKMax(float kMax) {
        this->kMax = kMax;
    }

    int GetOrdreVariation() const {
        return ordreVariation;
    }

    void SetOrdreVariation(int ordreVariation) {
        this->ordreVariation = ordreVariation;
    }

    float GetSigmaMax() const {
        return sigmaMax;
    }

    void SetSigmaMax(float sigmaMax) {
        this->sigmaMax = sigmaMax;
    }

    void ecrire();

private:
    int epaisseurCouche;
    int ordreVariation;
    float sigmaMax;
    float kMax;

};

#endif	/* PML_H */

