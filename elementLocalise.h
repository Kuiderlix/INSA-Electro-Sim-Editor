/* 
 * File:   elementLocalise.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:17 PM
 */

#ifndef ELEMENTLOCALISE_H
#define	ELEMENTLOCALISE_H

#include "elementBase.h"

/**
 * @brief Cette classe représente la variable elementLocalise d'une simulation
 */
class elementLocalise : public elementBase{
public:
    elementLocalise();
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

    float GetValeur() const {
        return valeur;
    }

    void SetValeur(float valeur) {
        this->valeur = valeur;
    }

    void ecrire(int nb);

private:
    int type;
    float valeur;
    int direction;

};

#endif	/* ELEMENTLOCALISE_H */

