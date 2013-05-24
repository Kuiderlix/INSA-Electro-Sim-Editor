/* 
 * File:   metallisation.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:37 PM
 */

#ifndef METALLISATION_H
#define	METALLISATION_H

#include "coordonnee.h"
#include "elementBase.h"
#include "blocConfiguration.h"

/**
 * @brief Cette classe représente la variable metallisation d'une simulation
 */
class metallisation : public elementBase{
public:
    metallisation();
    virtual ~metallisation();

    float GetConductivite() const {
        return conductivite;
    }

    void SetConductivite(float conductivite) {
        this->conductivite = conductivite;
    }

    void ecrire(int nb);
private:
    float conductivite;

};


#endif	/* METALLISATION_H */

