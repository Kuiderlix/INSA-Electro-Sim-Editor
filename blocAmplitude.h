/* 
 * File:   blocAmplitude.h
 * Author: camille
 *
 * Created on March 4, 2013, 4:20 PM
 */

#ifndef BLOCAMPLITUDE_H
#define	BLOCAMPLITUDE_H

#include "blocConfiguration.h"


class blocAmplitude : public blocConfiguration{
public:
    blocAmplitude();
    blocAmplitude(const blocAmplitude& orig);
    virtual ~blocAmplitude();
    
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

