/* 
 * File:   excitations.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:31 PM
 */

#ifndef EXCITATIONS_H
#define	EXCITATIONS_H

#include "blocConfiguration.h"


class excitations : blocConfiguration{
public:
    excitations();
    excitations(const excitations& orig);
    virtual ~excitations();
    
    float GetFrequenceMax() const {
        return frequenceMax;
    }

    void SetFrequenceMax(float frequenceMax) {
        this->frequenceMax = frequenceMax;
    }

    float GetFrequenceSinus() const {
        return frequenceSinus;
    }

    void SetFrequenceSinus(float frequenceSinus) {
        this->frequenceSinus = frequenceSinus;
    }

    int GetType() const {
        return type;
    }

    void SetType(int type) {
        this->type = type;
    }

private:
    float frequenceMax;
    int type;
    //SI type = 1
    float frequenceSinus;

};

#endif	/* EXCITATIONS_H */

