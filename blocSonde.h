/* 
 * File:   blocSonde.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:44 PM
 */

#ifndef BLOCSONDE_H
#define	BLOCSONDE_H

#include "blocConfiguration.h"
#include "sonde.h"


class blocSonde : public blocConfiguration{
public:
    blocSonde();
    blocSonde(const blocSonde& orig);
    virtual ~blocSonde();
    
    int GetNbSondes() const {
        return nbSondes;
    }

    void SetNbSondes(int nbSondes) {
        this->nbSondes = nbSondes;
        sondes.resize(nbSondes);
    }
    
    sonde GetSonde(int i){
        return sondes[i];
    }
    
    void SetSonde(int i, sonde s){
        if(i>nbSondes)return;
        sondes[i] = s;
    }
    
    void AddSonde(sonde s){
        sondes.push_back(s);
    }

private:
    int nbSondes;
    std::vector <sonde> sondes;
};

#endif	/* BLOCSONDE_H */

