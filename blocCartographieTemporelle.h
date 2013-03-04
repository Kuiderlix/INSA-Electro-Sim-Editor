/* 
 * File:   blocCartographieTemporelle.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:51 PM
 */

#ifndef BLOCCARTOGRAPHIETEMPORELLE_H
#define	BLOCCARTOGRAPHIETEMPORELLE_H

#include "cartographieTemporelle.h"
#include "blocConfiguration.h"


class blocCartographieTemporelle : public blocConfiguration{
public:
    blocCartographieTemporelle();
    blocCartographieTemporelle(const blocCartographieTemporelle& orig);
    virtual ~blocCartographieTemporelle();
    
    int GetNbCarto() const {
        return nbCarto;
    }

    void SetNbCarto(int nbCarto) {
        this->nbCarto = nbCarto;
        cartos.resize(nbCarto);
    }
    
    void AddCarto(cartographieTemporelle carto){
        cartos.push_back(carto);
    }
    
    void SetCarto(int i, cartographieTemporelle carto){
        if(i>nbCarto)return;
        cartos[i]=carto;
    }
    
    cartographieTemporelle GetCarto(int i){
        return cartos[i];
    }

private:
    int nbCarto;
    std::vector <cartographieTemporelle> cartos;
};

#endif	/* BLOCCARTOGRAPHIETEMPORELLE_H */

