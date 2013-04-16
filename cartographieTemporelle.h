/* 
 * File:   cartographieTemporelle.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:42 PM
 */

#ifndef CARTOGRAPHIETEMPORELLE_H
#define	CARTOGRAPHIETEMPORELLE_H

#include "elementBase.h"


class cartographieTemporelle : public elementBase{
public:
    cartographieTemporelle();
    cartographieTemporelle(const cartographieTemporelle& orig);
    virtual ~cartographieTemporelle();
    
    bool IsChampE() const {
        return champE;
    }

    void SetChampE(bool champE) {
        this->champE = champE;
    }

    bool IsChampH() const {
        return champH;
    }

    void SetChampH(bool champH) {
        this->champH = champH;
    }

    int GetIntervalle() const {
        return intervalle;
    }

    void SetIntervalle(int intervalle) {
        this->intervalle = intervalle;
    }

    int GetIterationDebut() const {
        return iterationDebut;
    }

    void SetIterationDebut(int iterationDebut) {
        this->iterationDebut = iterationDebut;
    }

    int GetIterationFin() const {
        return iterationFin;
    }

    void SetIterationFin(int iterationFin) {
        this->iterationFin = iterationFin;
    }

    void ecrire(int nb);

private:
    bool champE;
    bool champH;
    int iterationDebut;
    int iterationFin;
    int intervalle;
};

#endif	/* CARTOGRAPHIETEMPORELLE_H */

