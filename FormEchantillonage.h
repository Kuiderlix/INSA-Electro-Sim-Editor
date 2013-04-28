#ifndef FORMECHANTILLONAGE_H
#define FORMECHANTILLONAGE_H

#include <QtWidgets>
#include "blocEchantillonnage.h"

class FormEchantillonage : public QWidget
{
    Q_OBJECT
public:
    explicit FormEchantillonage(blocEchantillonnage * echanti,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    blocEchantillonnage * echanti;
    
};

#endif // FORMECHANTILLONAGE_H
