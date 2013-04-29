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
public:
    Excitation();
    Excitation(const Excitation& orig);
    virtual ~Excitation();
    
    float GetAmplitudeV0() const {
        return amplitudeV0;
    }

    void SetAmplitudeV0(float amplitudeV0) {
        this->amplitudeV0 = amplitudeV0;
    }

    void ecrire();
    
private:
    float amplitudeV0;
};

#endif	/* BLOCAMPLITUDE_H */
