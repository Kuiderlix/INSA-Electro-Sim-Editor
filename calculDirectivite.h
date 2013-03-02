/* 
 * File:   calculDirectivite.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:54 PM
 */

#ifndef CALCULDIRECTIVITE_H
#define	CALCULDIRECTIVITE_H

class calculDirectivite {
public:
    calculDirectivite();
    calculDirectivite(const calculDirectivite& orig);
    virtual ~calculDirectivite();
    
    bool IsCalcul() const {
        return calcul;
    }

    void SetCalcul(bool calcul) {
        this->calcul = calcul;
    }

    int GetPasPhi() const {
        return pasPhi;
    }

    void SetPasPhi(int pasPhi) {
        this->pasPhi = pasPhi;
    }

    int GetPasTheta() const {
        return pasTheta;
    }

    void SetPasTheta(int pasTheta) {
        this->pasTheta = pasTheta;
    }

private:
    bool calcul;
    int pasTheta;
    int pasPhi;
};

#endif	/* CALCULDIRECTIVITE_H */

