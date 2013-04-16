/* 
 * File:   portExcitation.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:37 PM
 */

#ifndef PORTEXCITATION_H
#define	PORTEXCITATION_H

#include "elementBase.h"


class portExcitation : public elementBase{
public:
    portExcitation();
    portExcitation(const portExcitation& orig);
    virtual ~portExcitation();
    
    int GetDirection() const {
        return direction;
    }

    void SetDirection(int direction) {
        this->direction = direction;
    }

    float GetImpedance() const {
        return impedance;
    }

    void SetImpedance(float impedance) {
        this->impedance = impedance;
    }

    float GetPonderationAmplitude() const {
        return ponderationAmplitude;
    }

    void SetPonderationAmplitude(float ponderationAmplitude) {
        this->ponderationAmplitude = ponderationAmplitude;
    }

    float GetPonderationPhase() const {
        return ponderationPhase;
    }

    void SetPonderationPhase(float ponderationPhase) {
        this->ponderationPhase = ponderationPhase;
    }

    bool IsPortActif() const {
        return portActif;
    }

    void SetPortActif(bool portActif) {
        this->portActif = portActif;
    }

    bool IsPortInfinitesimal() const {
        return portInfinitesimal;
    }

    void SetPortInfinitesimal(bool portInfinitesimal) {
        this->portInfinitesimal = portInfinitesimal;
    }

    int GetTypePort() const {
        return typePort;
    }

    void SetTypePort(int typePort) {
        this->typePort = typePort;
    }

    int GetTypeSource() const {
        return typeSource;
    }

    void SetTypeSource(int typeSource) {
        this->typeSource = typeSource;
    }

    void ecrire(int nb);

private:
    bool portActif;
    bool portInfinitesimal;
    int typePort;
    int direction;
    float impedance;
    int typeSource;
    float ponderationAmplitude;
    float ponderationPhase;
};

#endif	/* PORTEXCITATION_H */

