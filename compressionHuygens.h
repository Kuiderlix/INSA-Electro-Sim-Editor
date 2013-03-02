/* 
 * File:   compressionHuygens.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:52 PM
 */

#ifndef COMPRESSIONHUYGENS_H
#define	COMPRESSIONHUYGENS_H

class compressionHuygens {
public:
    compressionHuygens();
    compressionHuygens(const compressionHuygens& orig);
    virtual ~compressionHuygens();
    
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

    int GetFacteurMultiplicatif() const {
        return facteurMultiplicatif;
    }

    void SetFacteurMultiplicatif(int facteurMultiplicatif) {
        this->facteurMultiplicatif = facteurMultiplicatif;
    }

private:
    int compressionLongueur;
    int compressionLargeur;
    int compressionHauteur;
    int facteurMultiplicatif;
};

#endif	/* COMPRESSIONHUYGENS_H */

