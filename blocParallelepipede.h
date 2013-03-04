/* 
 * File:   blocParallelepipede.h
 * Author: camille
 *
 * Created on March 3, 2013, 7:20 PM
 */

#ifndef BLOCPARALLELEPIPEDE_H
#define	BLOCPARALLELEPIPEDE_H

#include "blocConfiguration.h"
#include "parallelepipede.h"
#include <vector>


class blocParallelepipede : public blocConfiguration{
public:
    blocParallelepipede();
    blocParallelepipede(const blocParallelepipede& orig);
    virtual ~blocParallelepipede();
    
    int GetNbParallelepipede() const {
        return nbParallelepipede;
    }

    void SetNbParallelepipede(int nbParallelepipede) {
        this->nbParallelepipede = nbParallelepipede;
        parallelepipedes.resize(nbParallelepipede);
    }
    
    parallelepipede GetParallelepipede(int i){
        return parallelepipedes[i];
    }
    
    void setParallelepipede(int i, parallelepipede para){
        if(i> nbParallelepipede)return;
        parallelepipedes[i] = para;
    }
    
    void addParallelepipede(parallelepipede para){
        parallelepipedes.push_back(para);
    }

private:
    int nbParallelepipede;
    std::vector <parallelepipede> parallelepipedes;
    
};

#endif	/* BLOCPARALLELEPIPEDE_H */

