/* 
 * File:   volumeCalcul.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:23 PM
 */

#ifndef VOLUMECALCUL_H
#define	VOLUMECALCUL_H

#include "blocConfiguration.h"


class volumeCalcul : blocConfiguration {
public:
    volumeCalcul();
    volumeCalcul(const volumeCalcul& orig);
    virtual ~volumeCalcul();

    float GetHauteur() const {
        return hauteur;
    }

    void SetHauteur(float hauteur) {
        this->hauteur = hauteur;
    }

    float GetLargeur() const {
        return largeur;
    }

    void SetLargeur(float largeur) {
        this->largeur = largeur;
    }

    float GetLongueur() const {
        return longueur;
    }

    void SetLongueur(float longueur) {
        this->longueur = longueur;
    }

    int GetNombreX() const {
        return nombreX;
    }

    void SetNombreX(int nombreX) {
        this->nombreX = nombreX;
    }

    int GetNombreY() const {
        return nombreY;
    }

    void SetNombreY(int nombreY) {
        this->nombreY = nombreY;
    }

    int GetNombreZ() const {
        return nombreZ;
    }

    void SetNombreZ(int nombreZ) {
        this->nombreZ = nombreZ;
    }

    void ecrire();
    
private:
    float longueur;
    float largeur;
    float hauteur;
    int nombreY;
    int nombreX;
    int nombreZ;
};

#endif	/* VOLUMECALCUL_H */

