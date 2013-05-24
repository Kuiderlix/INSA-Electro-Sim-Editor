/* 
 * File:   blocSonde.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:44 PM
 */

#ifndef BLOCSONDE_H
#define	BLOCSONDE_H

#include "BlocElementBase.h"
#include "sonde.h"

/**
 * @brief Cette classe représente une liste de sonde
 */
class blocSonde : public BlocElementBase{
public:
    blocSonde();
    virtual ~blocSonde();
    

    sonde* GetSonde(int i){
        return (sonde*)listElement.at(i);
    }


    void ecrire();

private:
};

#endif	/* BLOCSONDE_H */

