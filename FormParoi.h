#ifndef FORMPAROI_H
#define FORMPAROI_H

#include <QtWidgets>
#include "paroi.h"

/**
 * @brief Cette classe fournit un formulaire pour modifier l'objet paroi
 */
class FormParoi : public QWidget
{
    Q_OBJECT
public:
    explicit FormParoi(paroi* m_paroi, QWidget *parent = 0);

    void setParoi(paroi * p)
    {
        m_paroi=p;
        init();
    }

    void init();
    
signals:
    
public slots:


private:
    paroi* m_paroi;

    QComboBox * inferieurWidget;
    QComboBox * superieurWidget;
    QComboBox * axeXWidget;
    QComboBox * axeYWidget;
    
};

#endif // FORMPAROI_H
