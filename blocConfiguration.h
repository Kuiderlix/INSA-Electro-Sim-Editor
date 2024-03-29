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
#include <QObject>

#include "Ecriture.h"

/**
 * @brief Classe de base pour les données de configuration d'une simulation
 */
class blocConfiguration : public QObject {
    Q_OBJECT
public:
    blocConfiguration();
    virtual ~blocConfiguration();
    
    std::string getHeader() const {
        return header;
    }

    void setHeader(std::string header) {
        this->header = header;
    }
    
    void setExtension(std::string extension) {
        this->extension = extension;
    }
    
    void ecrire(){
        std::ostringstream name;
        name << this->extension;
        Ecriture::SetNomFichier(name.str());

        Ecriture::Ecrire(this->getHeader());
        Ecriture::Ecrire("\n");
    }

    
protected:
    std::string header;
    std::string extension;
};

#endif	/* BLOCCONFIGURATION_H */

