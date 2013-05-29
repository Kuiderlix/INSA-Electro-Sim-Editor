/* 
 * File:   formatStockage.h
 * Author: camille
 *
 * Created on February 26, 2013, 9:51 PM
 */

#ifndef FORMATSTOCKAGE_H
#define	FORMATSTOCKAGE_H

#include "blocConfiguration.h"

/**
 * @brief Cette classe représente la variable formatStockage d'une simulation
 */
class formatStockage : public blocConfiguration{
    Q_OBJECT
public:
    formatStockage();
    virtual ~formatStockage();

    int GetFormat() const {
        return format;
    }

    int GetFormatFichierPrelevement() const {
        return formatFichierPrelevement;
    }

public slots:

    void SetFormat(int format) {
        this->format = format+1;
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

