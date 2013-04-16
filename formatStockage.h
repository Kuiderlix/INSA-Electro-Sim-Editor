/* 
 * File:   formatStockage.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:51 PM
 */

#ifndef FORMATSTOCKAGE_H
#define	FORMATSTOCKAGE_H

#include "blocConfiguration.h"


class formatStockage : public blocConfiguration{
public:
    formatStockage();
    formatStockage(const formatStockage& orig);
    virtual ~formatStockage();
    
    int GetFormat() const {
        return format;
    }

    void SetFormat(int format) {
        this->format = format;
    }

    int GetFormatFichierPrelevement() const {
        return formatFichierPrelevement;
    }

    void SetFormatFichierPrelevement(int formatFichierPrelevement) {
        this->formatFichierPrelevement = formatFichierPrelevement;
    }

    void ecrire();

private:
    int format;
    int formatFichierPrelevement;
};

#endif	/* FORMATSTOCKAGE_H */

