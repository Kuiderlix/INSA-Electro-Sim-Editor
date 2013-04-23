/* 
 * File:   blocPortExcitation.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:15 PM
 */

#ifndef BLOCPORTEXCITATION_H
#define	BLOCPORTEXCITATION_H

#include "BlocElementBase.h"
#include "portExcitation.h"


class blocPortExcitation : public BlocElementBase{
public:
    blocPortExcitation();
    blocPortExcitation(const blocPortExcitation& orig);
    virtual ~blocPortExcitation();

    
    portExcitation* GetPortExcitation(int i){
        return (portExcitation*) listElement.at(i);
    }

    void ecrire();

};

#endif	/* BLOCPORTEXCITATION_H */

