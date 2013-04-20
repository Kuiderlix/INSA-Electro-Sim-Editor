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
        return metallisations.size();
    }
    
    metallisation* GetMetallisation(int i){
        return metallisations[i];
    }
    
    void setMetallisation(int i, metallisation* met){
        if(i> metallisations.size())return;
        metallisations[i] = met;
    }

    void removeMetallisation(metallisation * met)
    {
        std::vector<metallisation*>::iterator it = metallisations.begin();
        for (;it!=metallisations.end();it++)
        {
            if (*it == met)
            {
                metallisations.erase(it);
                break;
            }
        }
    }

    int GetMetalPosition(metallisation * met)
    {
        std::vector<metallisation*>::iterator it = metallisations.begin();
        for (int i=0;it!=metallisations.end();it++,i++)
        {
            if (*it == met)
            {
                return i;
            }
        }
    }
    
    void addMetallisation(metallisation* met){
        metallisations.push_back(met);
    }
    
    void ecrire();
    
private:
    std::vector <metallisation*> metallisations;

};

#endif	/* BLOCMETALLISATION_H */

