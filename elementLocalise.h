/* 
 * File:   elementLocalise.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:17 PM
 */

#ifndef ELEMENTLOCALISE_H
#define	ELEMENTLOCALISE_H

#include "elementBase.h"


class elementLocalise : public elementBase{
public:
    elementLocalise();
    elementLocalise(const elementLocalise& orig);
    virtual ~elementLocalise();
    
    int GetDirection() const {
        return direction;
    }

    void SetDirection(int direction) {
        this->direction = direction;
    }

    int GetType() const {
        return type;
    }

    void SetType(int type) {
        this->type = type;
    }

    double GetValeur() const {
        return valeur;
    }

    void SetValeur(double valeur) {
        this->valeur = valeur;
    }

    void ecrire(int nb);

private:
    int type;
    double valeur;
    int direction;

};

#endif	/* ELEMENTLOCALISE_H */

