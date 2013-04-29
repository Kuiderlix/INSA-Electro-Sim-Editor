/* 
 * File:   paroi.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:33 PM
 */

#ifndef PAROI_H
#define	PAROI_H

#include "blocConfiguration.h"
#include <QDebug>


class paroi : public blocConfiguration {
    Q_OBJECT
public:
    paroi();
    paroi(const paroi& orig);
    virtual ~paroi();


    int GetParoiInferieure() const {
        return paroiInferieure;
    }
    int GetParoiSuperieure() const {
        return paroiSuperieure;
    }
    int GetParoiX() const {
        return paroiX;
    }
    int GetParoiY() const {
        return paroiY;
    }

signals:
    void paroiInfChanged();
    void paroiSupChanged();
    void paroiXChanged();
    void paroiYChanged();

public slots:

    void SetParoiInferieure(int paroiInferieure) {
        this->paroiInferieure = paroiInferieure; emit paroiInfChanged();
    }
    void SetParoiSuperieure(int paroiSuperieure) {
        this->paroiSuperieure = paroiSuperieure; emit paroiSupChanged();
    }
    void SetParoiX(int paroiX) {
        this->paroiX = paroiX; emit paroiXChanged();
    }
    void SetParoiY(int paroiY) {
        this->paroiY = paroiY; emit paroiYChanged();
    }

    void ecrire();

private:
    int paroiInferieure;
    int paroiSuperieure;
    int paroiX;
    int paroiY;

};

#endif	/* PAROI_H */

