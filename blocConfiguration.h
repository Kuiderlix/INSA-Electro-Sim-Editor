/* 
 * File:   blocConfiguration.h
 * Author: camille
 *
 * Created on February 26, 2013, 6:58 PM
 */

#ifndef BLOCCONFIGURATION_H
#define	BLOCCONFIGURATION_H

#include <string>

class blocConfiguration {
public:
    blocConfiguration();
    blocConfiguration(const blocConfiguration& orig);
    virtual ~blocConfiguration();
    
    std::string getHeader() const {
        return header;
    }

    void setHeader(std::string header) {
        this->header = header;
    }
    
private:
    std::string header;
};

#endif	/* BLOCCONFIGURATION_H */

