/* 
 * File:   blocMetallisation.h
 * Author: camille
 *
 * Created on March 3, 2013, 6:50 PM
 */

#ifndef BLOCMETALLISATION_H
#define	BLOCMETALLISATION_H

#include "metallisation.h"
#include <vector>


class blocMetallisation : public blocConfiguration{
public:
    blocMetallisation();
    blocMetallisation(const blocMetallisation& orig);
    virtual ~blocMetallisation();
    
    int GetNbMetallisation() const {
        return nbMetallisation;
    }

    void SetNbMetallisation(int nbMetallisation) {
        this->nbMetallisation = nbMetallisation;
        metallisations.resize(nbMetallisation);
    }
    
    metallisation* GetMetallisation(int i){
        return metallisations[i];
    }
    
    void setMetallisation(int i, metallisation* met){
        if(i> nbMetallisation)return;
        metallisations[i] = met;
    }
    
    void addMetallisation(metallisation* met){
        metallisations.push_back(met);
        nbMetallisation++;
    }
    
    void ecrire();
    
private:
    int nbMetallisation;
    std::vector <metallisation*> metallisations;

};

#endif	/* BLOCMETALLISATION_H */

