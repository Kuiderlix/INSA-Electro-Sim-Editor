/* 
 * File:   blocConfiguration.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:58 PM
 */

#ifndef BLOCCONFIGURATION_H
#define	BLOCCONFIGURATION_H

#include <string>
#include <sstream>

#include "Ecriture.h"

class blocConfiguration {
public:
    blocConfiguration();
    blocConfiguration(const blocConfiguration& orig);
    virtual ~blocConfiguration();
    
    std::string getHeader() const {
        return header;
    }

    void setHeader(std::string header) {
        this->header.reserve(header.length());
        this->header.append(header);
    }
    
    void setExtension(std::string extension) {
        this->extension = extension;
    }
    
    void setTest(int test){
        this->test = test;
    }
    
    void ecrire(){
        //TODO: extension & header ne s'écrivent pas.
        std::ostringstream name;
        name << "DATA1" << this->extension << "s";
        std::string nomFichier(name.str());
        Ecriture::SetNomFichier(nomFichier);
        
        std::ostringstream header;
        header << this->getHeader() << this->test << std::endl;
        std::string ecriture(header.str());
        Ecriture::Ecrire(ecriture);
    }

    
protected:
    std::string header;
    std::string extension;
    int test;
};

#endif	/* BLOCCONFIGURATION_H */

