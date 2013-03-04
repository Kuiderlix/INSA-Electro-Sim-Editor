/* 
 * File:   blocElementLocalise.h
 * Author: camille
 *
 * Created on March 3, 2013, 7:29 PM
 */

#ifndef BLOCELEMENTLOCALISE_H
#define	BLOCELEMENTLOCALISE_H

#include "elementLocalise.h"
#include "blocConfiguration.h"

class blocElementLocalise : public blocConfiguration{
public:
    blocElementLocalise();
    blocElementLocalise(const blocElementLocalise& orig);
    virtual ~blocElementLocalise();

    int GetNbElements() const {
        return nbElements;
    }

    void SetNbElements(int nbElements) {
        this->nbElements = nbElements;
        elements.resize(nbElements);
    }
    
    elementLocalise GetElementLocalise(int i){
        return elements[i];
    }
    
    void setElementLocalise(int i, elementLocalise elt){
        if(i>nbElements)return;
        elements[i] = elt;
    }
    
    void addElementLocalise(elementLocalise elt){
        elements.push_back(elt);
    }

private:
    int nbElements;
    std::vector <elementLocalise> elements;
};

#endif	/* BLOCELEMENTLOCALISE_H */

