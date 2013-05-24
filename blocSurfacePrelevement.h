/* 
 * File:   blocSurfacePrelevement.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:58 PM
 */

#ifndef BLOCSURFACEPRELEVEMENT_H
#define	BLOCSURFACEPRELEVEMENT_H

#include "surfacePrelevement.h"
#include "BlocElementBase.h"

/**
 * @brief Cette classe représente une liste de surfacePrelevement
 */
class blocSurfacePrelevement : public BlocElementBase{
public:
    blocSurfacePrelevement();
    virtual ~blocSurfacePrelevement();

    int GetNbSurfacesDG() const {
        return nbSurfacesDG;
    }

    void SetNbSurfacesDG(int nbSurfacesDG) {
        this->nbSurfacesDG = nbSurfacesDG;
    }


    surfacePrelevement* GetSurface(int i){
        return (surfacePrelevement*) listElement.at(i);
    }

    void ecrire();

private:
    int nbSurfacesDG;
};

#endif	/* BLOCSURFACEPRELEVEMENT_H */

