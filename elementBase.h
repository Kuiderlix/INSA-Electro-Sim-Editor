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
#include <QObject>

/**
 * Cette classe représente un élement de base affichable dans la scène 3D et contenu dans un tableau
 * @brief The elementBase class
 */
class elementBase{
public:
    elementBase();
    virtual ~elementBase();

    coordonnee GetArriereDroit() const {
        return arriereDroit;
    }

    coordonnee GetAvantGauche() const {
        return avantGauche;
    }

    QColor getCouleur() const
    {
        return couleur;
    }

    void ecrireElementBase();

    bool operator==(elementBase const& b);


    void invertColor()
    {
        couleur.setRed(255-couleur.red());
        couleur.setBlue(255-couleur.blue());
        couleur.setGreen(255-couleur.green());
    }

    QColor getInvertColor()
    {
        QColor inv=couleur;
        inv.setRed(255-inv.red());
        inv.setBlue(255-inv.blue());
        inv.setGreen(255-inv.green());
        return inv;
    }


    void setCouleur(QColor c)
    {
        couleur=c;
    }
    void setAlpha(int a)
    {
        couleur.setAlpha(a);
    }
    void SetAvantGauche(int x, int y, int z) {
        this->avantGauche = coordonnee(x,y,z);
    }

    void SetAvantGauche(coordonnee copie) {
        avantGauche=copie;
    }
    void SetArriereDroit(int x, int y, int z) {
        this->arriereDroit = coordonnee(x,y,z);
    }

    void SetArriereDroit(coordonnee copie) {
        arriereDroit=copie;
    }



protected:

    QColor couleur;

    coordonnee avantGauche;
    coordonnee arriereDroit;

};

#endif	/* ELEMENTBASE_H */

