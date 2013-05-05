/*
 * File:   elementBase.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:19 PM
 */

#ifndef ELEMENTBASE_H
#define	ELEMENTBASE_H

#include "coordonnee.h"
#include <QColor>


class elementBase {
public:
    elementBase();
    elementBase(const elementBase& orig);
    virtual ~elementBase();

    coordonnee GetArriereDroit() const {
        return arriereDroit;
    }

    void SetArriereDroit(int x, int y, int z) {
        this->arriereDroit = coordonnee(x,y,z);
    }

    void SetArriereDroit(coordonnee copie) {
        arriereDroit=copie;
    }

    coordonnee GetAvantGauche() const {
        return avantGauche;
    }

    void SetAvantGauche(int x, int y, int z) {
        this->avantGauche = coordonnee(x,y,z);
    }

    void SetAvantGauche(coordonnee copie) {
        avantGauche=copie;
    }

    QColor getCouleur() const
    {
        return couleur;
    }

    void setCouleur(QColor c)
    {
        couleur=c;
    }
    void setAlpha(int a)
    {
        couleur.setAlpha(a);
    }

    void ecrireElementBase();

    bool operator==(elementBase const& b);


    void invertColor()
    {
        couleur.setRed(255-couleur.red());
        couleur.setBlue(255-couleur.blue());
        couleur.setGreen(255-couleur.green());
    }


protected:

    QColor couleur;

    coordonnee avantGauche;
    coordonnee arriereDroit;

};

#endif	/* ELEMENTBASE_H */

