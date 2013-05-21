#ifndef FORMFORMATSTOCKAGE_H
#define FORMFORMATSTOCKAGE_H

#include <QtWidgets>
#include "formatStockage.h"

class FormFormatStockage : public QWidget
{
    Q_OBJECT
public:
    explicit FormFormatStockage(formatStockage * format,QWidget *parent = 0);

    void setFormatStockage(formatStockage * f)
    {
        format=f;
        init();
    }

    void init();
    
signals:
    
public slots:

private:
    formatStockage * format;

    QComboBox * formatWidget;
    QComboBox * formatFichierPrelevementWidget;
    
};

#endif // FORMFORMATSTOCKAGE_H
