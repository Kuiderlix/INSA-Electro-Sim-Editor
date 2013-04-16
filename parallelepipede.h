/* 
 * File:   parallelepipede.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:12 PM
 */

#ifndef PARALLELEPIPEDE_H
#define	PARALLELEPIPEDE_H

#include "coordonnee.h"
#include "elementBase.h"

class parallelepipede : public elementBase {
public:
    parallelepipede();
    parallelepipede(const parallelepipede& orig);
    virtual ~parallelepipede();
    
    float GetConductivite() const {
        return conductivite;
    }

    void SetConductivite(float conductivite) {
        this->conductivite = conductivite;
    }

    float GetPermeRelative() const {
        return permeRelative;
    }

    void SetPermeRelative(float permeRelative) {
        this->permeRelative = permeRelative;
    }

    float GetPermitRelative() const {
        return permitRelative;
    }

    void SetPermitRelative(float permitRelative) {
        this->permitRelative = permitRelative;
    }

    void ecrire(int nb);

private:
    float permitRelative;
    float permeRelative;
    float conductivite;


};

#endif	/* PARALLELEPIPEDE_H */

