/* 
 * File:   elementBase.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:19 PM
 */

#ifndef ELEMENTBASE_H
#define	ELEMENTBASE_H

#include "coordonnee.h"


class elementBase {
public:
    elementBase();
    elementBase(const elementBase& orig);
    virtual ~elementBase();

    coordonnee GetArriereDroit() const {
        return arriereDroit;
    }

    void SetArriereDroit(int x, int y, int z) {
        this->arriereDroit = coordonnee(x,y,z);
    }

    void SetArriereDroit(coordonnee copie) {
        arriereDroit=copie;
    }

    coordonnee GetAvantGauche() const {
        return avantGauche;
    }

    void SetAvantGauche(int x, int y, int z) {
        this->avantGauche = coordonnee(x,y,z);
    }

    void SetAvantGauche(coordonnee copie) {
        avantGauche=copie;
    }

    void ecrireElementBase();

protected:
    coordonnee avantGauche;
    coordonnee arriereDroit;

};

#endif	/* ELEMENTBASE_H */

