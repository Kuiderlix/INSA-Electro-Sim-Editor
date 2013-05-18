/*
 * File:   compressionHuygens.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:52 PM
 */

#ifndef COMPRESSIONHUYGENS_H
#define	COMPRESSIONHUYGENS_H

#include "blocConfiguration.h"


class compressionHuygens : public blocConfiguration{
    Q_OBJECT
public:
    compressionHuygens();
    virtual ~compressionHuygens();
    
    int GetCompressionHauteur() const {
        return compressionHauteur;
    }
    int GetCompressionLargeur() const {
        return compressionLargeur;
    }
    int GetCompressionLongueur() const {
        return compressionLongueur;
    }
    int GetFacteurMultiplicatif() const {
        return facteurMultiplicatif;
    }

public slots:

    void SetCompressionHauteur(int compressionHauteur) {
        this->compressionHauteur = compressionHauteur;
    }

    void SetCompressionLargeur(int compressionLargeur) {
        this->compressionLargeur = compressionLargeur;
    }

    void SetCompressionLongueur(int compressionLongueur) {
        this->compressionLongueur = compressionLongueur;
    }

    void SetFacteurMultiplicatif(int facteurMultiplicatif) {
        this->facteurMultiplicatif = facteurMultiplicatif;
    }

    void ecrire();

private:
    int compressionLongueur;
    int compressionLargeur;
    int compressionHauteur;
    int facteurMultiplicatif;
};

#endif	/* COMPRESSIONHUYGENS_H */

