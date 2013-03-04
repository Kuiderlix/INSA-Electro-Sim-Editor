/* 
 * File:   blocEchantillonnage.h
 * Author: camille
 *
 * Created on March 4, 2013, 4:24 PM
 */

#ifndef BLOCECHANTILLONNAGE_H
#define	BLOCECHANTILLONNAGE_H

#include "blocConfiguration.h"


class blocEchantillonnage : public blocConfiguration{
public:
    blocEchantillonnage();
    blocEchantillonnage(const blocEchantillonnage& orig);
    virtual ~blocEchantillonnage();
    
    int GetFacteurEchatillonnage() const {
        return facteurEchatillonnage;
    }

    void SetFacteurEchatillonnage(int facteurEchatillonnage) {
        this->facteurEchatillonnage = facteurEchatillonnage;
    }
    
private:
    int facteurEchatillonnage;
};

#endif	/* BLOCECHANTILLONNAGE_H */

