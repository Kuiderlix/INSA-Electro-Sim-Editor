/* 
 * File:   blocPortExcitation.h
 * Author: camille
 *
 * Created on March 3, 2013, 10:15 PM
 */

#ifndef BLOCPORTEXCITATION_H
#define	BLOCPORTEXCITATION_H

#include "blocConfiguration.h"
#include "portExcitation.h"


class blocPortExcitation : public blocConfiguration{
public:
    blocPortExcitation();
    blocPortExcitation(const blocPortExcitation& orig);
    virtual ~blocPortExcitation();
    
    int GetNbPorts() const {
        return nbPorts;
    }

    void SetNbPorts(int nbPorts) {
        this->nbPorts = nbPorts;
        portExcitations.resize(nbPorts);
    }
    
    portExcitation GetPortExcitation(int i){
        return portExcitations[i];
    }
    
    void SetPortExcitation(int i, portExcitation port){
        if(i>nbPorts)return;
        portExcitations[i] = port;
    }
    
    void AddPortExcitation(portExcitation port){
        portExcitations.push_back(port);
    }

private:
    int nbPorts;
    std::vector <portExcitation> portExcitations;

};

#endif	/* BLOCPORTEXCITATION_H */

