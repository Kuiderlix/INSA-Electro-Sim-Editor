/* 
 * File:   excitations.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:31 PM
 */

#ifndef EXCITATIONS_H
#define	EXCITATIONS_H

#include "blocConfiguration.h"

/**
 * @brief Cette classe représente la variable ParamExcitations d'une simulation
 */
class ParamExcitations : public blocConfiguration{

    Q_OBJECT
public:
    ParamExcitations();
    virtual ~ParamExcitations();

    double GetFrequenceMax() const {
        return frequenceMax;
    }

    double GetFrequenceSinus() const {
        return frequenceSinus;
    }

    int GetType() const {
        return type;
    }

public slots:
    void SetFrequenceMax(double frequenceMax) {
        this->frequenceMax = frequenceMax;
    }
    void SetFrequenceSinus(double frequenceSinus) {
        this->frequenceSinus = frequenceSinus;
    }
    void SetType(int type) {
        this->type = type;
    }


    void ecrire();

private:
    double frequenceMax;
    int type;
    //SI type = 1
    double frequenceSinus;

};

#endif	/* EXCITATIONS_H */

