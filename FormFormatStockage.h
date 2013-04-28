#ifndef FORMFORMATSTOCKAGE_H
#define FORMFORMATSTOCKAGE_H

#include <QtWidgets>
#include "formatStockage.h"

class FormFormatStockage : public QWidget
{
    Q_OBJECT
public:
    explicit FormFormatStockage(formatStockage * format,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    formatStockage * format;
    
};

#endif // FORMFORMATSTOCKAGE_H
