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

    Q_OBJECT
public:
    pml();
    virtual ~pml();
    
    int GetEpaisseurCouche() const {
        return epaisseurCouche;
    }

    double GetKMax() const {
        return kMax;
    }

    int GetOrdreVariation() const {
        return ordreVariation;
    }

    double GetSigmaMax() const {
        return sigmaMax;
    }

public slots:

    void SetEpaisseurCouche(int epaisseurCouche) {
        this->epaisseurCouche = epaisseurCouche;
    }

    void SetKMax(double kMax) {
        this->kMax = kMax;
    }

    void SetOrdreVariation(int ordreVariation) {
        this->ordreVariation = ordreVariation;
    }

    void SetSigmaMax(double sigmaMax) {
        this->sigmaMax = sigmaMax;
    }

    void ecrire();

private:
    int epaisseurCouche;
    int ordreVariation;
    double sigmaMax;
    double kMax;

};

#endif	/* PML_H */

