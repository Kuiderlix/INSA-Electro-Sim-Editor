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


class metallisation : public elementBase{
public:
    metallisation();
    metallisation(const metallisation& orig);
    virtual ~metallisation();

    double GetConductivite() const {
        return conductivite;
    }

    void SetConductivite(float conductivite) {
        this->conductivite = conductivite;
    }

    void ecrire(int nb);
private:
    double conductivite;

    static int nbMetal;

};


#endif	/* METALLISATION_H */

