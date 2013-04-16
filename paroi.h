/* 
 * File:   paroi.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:33 PM
 */

#ifndef PAROI_H
#define	PAROI_H

#include "blocConfiguration.h"


class paroi : blocConfiguration {
public:
    paroi();
    paroi(const paroi& orig);
    virtual ~paroi();
    
    int GetParoiInferieure() const {
        return paroiInferieure;
    }

    void SetParoiInferieure(int paroiInferieure) {
        this->paroiInferieure = paroiInferieure;
    }

    int GetParoiSuperieure() const {
        return paroiSuperieure;
    }

    void SetParoiSuperieure(int paroiSuperieure) {
        this->paroiSuperieure = paroiSuperieure;
    }

    int GetParoiX() const {
        return paroiX;
    }

    void SetParoiX(int paroiX) {
        this->paroiX = paroiX;
    }

    int GetParoiY() const {
        return paroiY;
    }

    void SetParoiY(int paroiY) {
        this->paroiY = paroiY;
    }

    void ecrire();

private:
    int paroiInferieure;
    int paroiSuperieure;
    int paroiX;
    int paroiY;

};

#endif	/* PAROI_H */

