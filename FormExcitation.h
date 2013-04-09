#ifndef FORMEXCITATION_H
#define FORMEXCITATION_H

#include <QtWidgets>
#include "excitations.h"

class FormExcitation : public QWidget
{
    Q_OBJECT
public:
    explicit FormExcitation(excitations *excit,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    excitations *excit;
    QWidget * formTypeSinus;
    
};

#endif // FORMEXCITATION_H
