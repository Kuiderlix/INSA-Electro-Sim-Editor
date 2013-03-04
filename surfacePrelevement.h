/* 
 * File:   surfacePrelevement.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:44 PM
 */

#ifndef SURFACEPRELEVEMENT_H
#define	SURFACEPRELEVEMENT_H

#include "elementBase.h"
#include <string>


class surfacePrelevement : public elementBase{
public:
    surfacePrelevement();
    surfacePrelevement(const surfacePrelevement& orig);
    virtual ~surfacePrelevement();
    
    int GetCompressionHauteur() const {
        return compressionHauteur;
    }

    void SetCompressionHauteur(int compressionHauteur) {
        this->compressionHauteur = compressionHauteur;
    }

    int GetCompressionLargeur() const {
        return compressionLargeur;
    }

    void SetCompressionLargeur(int compressionLargeur) {
        this->compressionLargeur = compressionLargeur;
    }

    int GetCompressionLongueur() const {
        return compressionLongueur;
    }

    void SetCompressionLongueur(int compressionLongueur) {
        this->compressionLongueur = compressionLongueur;
    }

    int GetInsideOutside() const {
        return insideOutside;
    }

    void SetInsideOutside(int insideOutside) {
        this->insideOutside = insideOutside;
    }

    int GetTypeSurface() const {
        return typeSurface;
    }

    void SetTypeSurface(int typeSurface) {
        this->typeSurface = typeSurface;
    }
    
    std::string GetNomFichier() const {
        return nomFichier;
    }

    void SetNomFichier(std::string nomFichier) {
        this->nomFichier = nomFichier;
    }

private:
    int typeSurface;
    std::string nomFichier;
    //SI typeSurface = 2
    int insideOutside;
    int compressionLongueur;
    int compressionLargeur;
    int compressionHauteur;
};

#endif	/* SURFACEPRELEVEMENT_H */

