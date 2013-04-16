/* 
 * File:   blocSurfacePrelevement.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:58 PM
 */

#ifndef BLOCSURFACEPRELEVEMENT_H
#define	BLOCSURFACEPRELEVEMENT_H

#include "surfacePrelevement.h"
#include "blocConfiguration.h"


class blocSurfacePrelevement : public blocConfiguration{
public:
    blocSurfacePrelevement();
    blocSurfacePrelevement(const blocSurfacePrelevement& orig);
    virtual ~blocSurfacePrelevement();

    int GetNbSurfaces() const {
        return nbSurfaces;
    }

    void SetNbSurfaces(int nbSurfaces) {
        this->nbSurfaces = nbSurfaces;
        surfaces.resize(nbSurfaces);
    }

    int GetNbSurfacesDG() const {
        return nbSurfacesDG;
    }

    void SetNbSurfacesDG(int nbSurfacesDG) {
        this->nbSurfacesDG = nbSurfacesDG;
    }
    
    void AddSurface(surfacePrelevement surface){
        surfaces.push_back(surface);
    }
    
    void SetSurface(int i, surfacePrelevement surface){
        if(i>nbSurfaces)return;
        surfaces[i] = surface;
    }
    
    surfacePrelevement GetSurface(int i){
        return surfaces[i];
    }

    void ecrire();

private:
    int nbSurfaces;
    int nbSurfacesDG;
    std::vector <surfacePrelevement> surfaces;
};

#endif	/* BLOCSURFACEPRELEVEMENT_H */

