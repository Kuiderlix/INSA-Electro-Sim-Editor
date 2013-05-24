/* 
 * File:   blocCartographieTemporelle.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:51 PM
 */

#ifndef BLOCCARTOGRAPHIETEMPORELLE_H
#define	BLOCCARTOGRAPHIETEMPORELLE_H

#include "cartographieTemporelle.h"
#include "BlocElementBase.h"

/**
 * @brief Cette classe représente une liste de cartographieTemporelle
 */
class blocCartographieTemporelle : public BlocElementBase{
public:
    blocCartographieTemporelle();
    virtual ~blocCartographieTemporelle();
    

    
    cartographieTemporelle* GetCarto(int i){
        return (cartographieTemporelle*)listElement.at(i);
    }

    void ecrire();

private:
};

#endif	/* BLOCCARTOGRAPHIETEMPORELLE_H */

