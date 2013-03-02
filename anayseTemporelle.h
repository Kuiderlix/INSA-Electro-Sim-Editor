/* 
 * File:   anayseTemporelle.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:34 PM
 */

#ifndef ANAYSETEMPORELLE_H
#define	ANAYSETEMPORELLE_H

#include "blocConfiguration.h"


class anayseTemporelle : blocConfiguration {
public:
    anayseTemporelle();
    anayseTemporelle(const anayseTemporelle& orig);
    virtual ~anayseTemporelle();
    
    float GetPeriode() const {
        return periode;
    }

    void SetPeriode(float periode) {
        this->periode = periode;
    }

    float GetTemps() const {
        return temps;
    }

    void SetTemps(float temps) {
        this->temps = temps;
    }

private:
    float periode;
    float temps;

};

#endif	/* ANAYSETEMPORELLE_H */

