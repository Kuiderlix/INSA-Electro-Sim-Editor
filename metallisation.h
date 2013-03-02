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


class metallisation : elementBase{
public:
    metallisation();
    metallisation(const metallisation& orig);
    virtual ~metallisation();

    float GetConductivite() const {
        return conductivite;
    }

    void SetConductivite(float conductivite) {
        this->conductivite = conductivite;
    }
private:
    float conductivite;

};

#endif	/* METALLISATION_H */

