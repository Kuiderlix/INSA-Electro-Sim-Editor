/* 
 * File:   blocAmplitude.h
 * Author: camille
 *
 * Created on March 4, 2013, 4:20 PM
 */

#ifndef BLOCAMPLITUDE_H
#define	BLOCAMPLITUDE_H

#include "blocConfiguration.h"


class Excitation : public blocConfiguration{
    Q_OBJECT
public:
    Excitation();
    Excitation(const Excitation& orig);
    virtual ~Excitation();
    
    double GetAmplitudeV0() const {
        return amplitudeV0;
    }

public slots:

    void SetAmplitudeV0(double amplitudeV0) {
        this->amplitudeV0 = amplitudeV0;
    }

    void ecrire();
    
private:
    double amplitudeV0;
};

#endif	/* BLOCAMPLITUDE_H */

