/* 
 * File:   anayseTemporelle.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:34 PM
 */

#ifndef ANAYSETEMPORELLE_H
#define	ANAYSETEMPORELLE_H

#include "blocConfiguration.h"

/**
 * @brief Cette classe représente la variable analyseTemporelle d'une simulation
 */
class analyseTemporelle : public blocConfiguration {
    Q_OBJECT
public:
    analyseTemporelle();
    virtual ~analyseTemporelle();

    double GetPeriode() const {
        return periode;
    }

    double GetTemps() const {
        return temps;
    }

public slots:

    void SetPeriode(double periode) {
        this->periode = periode;
    }

    void SetTemps(double temps) {
        this->temps = temps;
    }

    void ecrire();

private:
    double periode;
    double temps;

};

#endif	/* ANAYSETEMPORELLE_H */

