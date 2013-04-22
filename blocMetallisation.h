/* 
 * File:   blocMetallisation.h
 * Author: camille
 *
 * Created on March 3, 2013, 6:50 PM
 */

#ifndef BLOCMETALLISATION_H
#define	BLOCMETALLISATION_H

#include "metallisation.h"
#include <QDebug>

class blocMetallisation : public blocConfiguration{
public:
    blocMetallisation();
    blocMetallisation(const blocMetallisation& orig);
    virtual ~blocMetallisation();
    
    int GetNbMetallisation() const {
        return metallisations.size();
    }
    
    metallisation* GetMetallisation(int i){
        return metallisations.at(i);
    }
    
    void setMetallisation(int i, metallisation* met){
        if(i> metallisations.size())return;
        metallisations[i] = met;
    }

    void removeMetallisation(metallisation * met)
    {
        metallisations.removeOne(met);
    }

    void removeMetallisation(int i)
    {
        qDebug() << "i" << i << " conductivité:" << GetMetallisation(i)->GetConductivite();
        metallisations.removeAt(i);
    }
    
    void addMetallisation(metallisation* met){
        metallisations.push_back(met);
    }
    
    void ecrire();
    
private:
    QList<metallisation*> metallisations;

};

#endif	/* BLOCMETALLISATION_H */

