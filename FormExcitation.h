#ifndef FORMEXCITATION_H
#define FORMEXCITATION_H

#include <QtWidgets>
#include "Excitation.h"

class FormExcitation : public QWidget
{
    Q_OBJECT
public:
    explicit FormExcitation(Excitation * excitation,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    Excitation * excitation;
    
};

#endif // FORMEXCITATION_H
