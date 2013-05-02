/* 
 * File:   calculDirectivite.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:54 PM
 */

#ifndef CALCULDIRECTIVITE_H
#define	CALCULDIRECTIVITE_H

#include "blocConfiguration.h"


class calculDirectivite : public blocConfiguration{
    Q_OBJECT
public:
    calculDirectivite();
    calculDirectivite(const calculDirectivite& orig);
    virtual ~calculDirectivite();
    
    bool IsCalcul() const {
        return calcul;
    }
    int GetPasPhi() const {
        return pasPhi;
    }
    int GetPasTheta() const {
        return pasTheta;
    }


public slots:

    void SetCalcul(bool calcul) {
        this->calcul = calcul;
    }

    void SetPasPhi(int pasPhi) {
        this->pasPhi = pasPhi;
    }

    void SetPasTheta(int pasTheta) {
        this->pasTheta = pasTheta;
    }

    void ecrire();

private:
    bool calcul;
    int pasTheta;
    int pasPhi;
};

#endif	/* CALCULDIRECTIVITE_H */

