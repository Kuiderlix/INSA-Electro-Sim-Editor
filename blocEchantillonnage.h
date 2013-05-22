/* 
 * File:   blocEchantillonnage.h
 * Author: camille
 *
 * Created on March 4, 2013, 4:24 PM
 */

#ifndef BLOCECHANTILLONNAGE_H
#define	BLOCECHANTILLONNAGE_H

#include "blocConfiguration.h"

/**
 * @brief Cette classe représente la variable echantillonnage d'une simulation
 */
class blocEchantillonnage : public blocConfiguration{
    Q_OBJECT
public:
    blocEchantillonnage();
    blocEchantillonnage(const blocEchantillonnage& orig);
    virtual ~blocEchantillonnage();
    
    int GetFacteurEchatillonnage() const {
        return facteurEchatillonnage;
    }

public slots:

    void SetFacteurEchatillonnage(int facteurEchatillonnage) {
        this->facteurEchatillonnage = facteurEchatillonnage;
    }
    
    void ecrire();

private:
    int facteurEchatillonnage;
};

#endif	/* BLOCECHANTILLONNAGE_H */

