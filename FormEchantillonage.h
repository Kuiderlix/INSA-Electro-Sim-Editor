#ifndef FORMECHANTILLONAGE_H
#define FORMECHANTILLONAGE_H

#include <QtWidgets>
#include "blocEchantillonnage.h"
/**
 * @brief Cette classe fournit un formulaire pour modifier l'objet blocEchantillonnage
 */
class FormEchantillonage : public QWidget
{
    Q_OBJECT
public:
    explicit FormEchantillonage(blocEchantillonnage * echanti,QWidget *parent = 0);

    void setEchantillonnage(blocEchantillonnage * e)
    {
        echanti=e;
        init();
    }

    void init();
    
signals:
    
public slots:

private:
    blocEchantillonnage * echanti;

    QSpinBox * facteurWidget;
    
};

#endif // FORMECHANTILLONAGE_H
