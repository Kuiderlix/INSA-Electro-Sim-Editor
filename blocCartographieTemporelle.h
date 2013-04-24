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


class blocCartographieTemporelle : public BlocElementBase{
public:
    blocCartographieTemporelle();
    blocCartographieTemporelle(const blocCartographieTemporelle& orig);
    virtual ~blocCartographieTemporelle();
    

    
    cartographieTemporelle* GetCarto(int i){
        return (cartographieTemporelle*)listElement.at(i);
    }

    void ecrire();

private:
};

#endif	/* BLOCCARTOGRAPHIETEMPORELLE_H */

