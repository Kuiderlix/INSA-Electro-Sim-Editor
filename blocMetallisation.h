/* 
 * File:   blocMetallisation.h
 * Author: camille
 *
 * Created on March 3, 2013, 6:50 PM
 */

#ifndef BLOCMETALLISATION_H
#define	BLOCMETALLISATION_H

#include "BlocElementBase.h"
#include "metallisation.h"
#include <QDebug>
/**
 * @brief Cette classe représente une liste de metallisation
 */
class blocMetallisation : public BlocElementBase{
public:
    blocMetallisation();
    virtual ~blocMetallisation();

    metallisation* GetMetallisation(int i){
        return (metallisation*)listElement.at(i);
    }
    
    
    void ecrire();
    
private:

};

#endif	/* BLOCMETALLISATION_H */

