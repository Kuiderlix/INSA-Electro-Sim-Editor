/* 
 * File:   sonde.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:37 PM
 */

#ifndef SONDE_H
#define	SONDE_H

#include "elementBase.h"
#include "coordonnee.h"


class sonde : public elementBase{
public:
    sonde();
    sonde(const sonde& orig);
    virtual ~sonde();
    
    bool IsEx() const {
        return ex;
    }

    void SetEx(bool ex) {
        this->ex = ex;
    }

    bool IsEy() const {
        return ey;
    }

    void SetEy(bool ey) {
        this->ey = ey;
    }

    bool IsEz() const {
        return ez;
    }

    void SetEz(bool ez) {
        this->ez = ez;
    }

    bool IsHx() const {
        return hx;
    }

    void SetHx(bool hx) {
        this->hx = hx;
    }

    bool IsHy() const {
        return hy;
    }

    void SetHy(bool hy) {
        this->hy = hy;
    }

    bool IsHz() const {
        return hz;
    }

    void SetHz(bool hz) {
        this->hz = hz;
    }

    coordonnee GetPointApplication() const {
        return pointApplication;
    }

    void SetPointApplication(int x, int y, int z) {
        this->pointApplication = coordonnee(x,y,z);
    }
    void SetPointApplication(coordonnee c) {
        this->pointApplication = c;
    }

    bool IsValeurAuCentre() const {
        return valeurAuCentre;
    }

    void SetValeurAuCentre(bool valeurAuCentre) {
        this->valeurAuCentre = valeurAuCentre;
    }

    void ecrire(int nb);

private:
    bool ex;
    bool ey;
    bool ez;
    bool hx;
    bool hy;
    bool hz;
    coordonnee pointApplication;
    bool valeurAuCentre;

};

#endif	/* SONDE_H */

