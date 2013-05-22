/* 
 * File:   blocParallelepipede.h
 * Author: camille
 *
 * Created on March 3, 2013, 7:20 PM
 */

#ifndef BLOCPARALLELEPIPEDE_H
#define	BLOCPARALLELEPIPEDE_H

#include "BlocElementBase.h"
#include "parallelepipede.h"
#include <vector>

/**
 * @brief Cette classe représente une liste de parallelepipede
 */
class blocParallelepipede : public BlocElementBase{
public:
    blocParallelepipede();
    blocParallelepipede(const blocParallelepipede& orig);
    virtual ~blocParallelepipede();
    

    parallelepipede* getParallelepipede(int i){
        return (parallelepipede*)listElement.at(i);
    }


    void ecrire();
    
};

#endif	/* BLOCPARALLELEPIPEDE_H */

