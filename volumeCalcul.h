/* 
 * File:   volumeCalcul.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:23 PM
 */

#ifndef VOLUMECALCUL_H
#define	VOLUMECALCUL_H

#include "blocConfiguration.h"


class volumeCalcul : public blocConfiguration {
    Q_OBJECT
public:
    volumeCalcul();
    virtual ~volumeCalcul();


    double GetHauteur() const {
        return hauteur;
    }
    double GetLargeur() const {
        return largeur;
    }
    double GetLongueur() const {
        return longueur;
    }
    int GetNombreX() const {
        return nombreX;
    }
    int GetNombreY() const {
        return nombreY;
    }
    int GetNombreZ() const {
        return nombreZ;
    }


signals:
    void hauteurChanged();
    void largeurChanged();
    void longueurChanged();

    void nbXChanged();
    void nbYChanged();
    void nbZChanged();

public slots:

    void SetHauteur(double hauteur) {
        this->hauteur = hauteur; emit hauteurChanged();
    }
    void SetLargeur(double largeur) {
        this->largeur = largeur; emit largeurChanged();
    }
    void SetLongueur(double longueur) {
        this->longueur = longueur; emit longueurChanged();
    }
    void SetNombreX(int nombreX) {
        this->nombreX = nombreX; emit nbXChanged();
    }
    void SetNombreY(int nombreY) {
        this->nombreY = nombreY; emit nbYChanged();
    }
    void SetNombreZ(int nombreZ) {
        this->nombreZ = nombreZ; emit nbZChanged();
    }

    void ecrire();
    
private:
    double longueur;
    double largeur;
    double hauteur;
    int nombreY;
    int nombreX;
    int nombreZ;
};

#endif	/* VOLUMECALCUL_H */

