/* 
 * File:   blocElementLocalise.h
 * Author: camille
 *
 * Created on March 3, 2013, 7:29 PM
 */

#ifndef BLOCELEMENTLOCALISE_H
#define	BLOCELEMENTLOCALISE_H

#include "elementLocalise.h"
#include "BlocElementBase.h"

class blocElementLocalise : public BlocElementBase{
public:
    blocElementLocalise();
    blocElementLocalise(const blocElementLocalise& orig);
    virtual ~blocElementLocalise();

    elementLocalise* GetElementLocalise(int i){
        return (elementLocalise*)listElement.at(i);
    }

    void ecrire();

private:
};

#endif	/* BLOCELEMENTLOCALISE_H */

