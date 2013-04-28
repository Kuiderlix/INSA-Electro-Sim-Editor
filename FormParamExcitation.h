#ifndef FORMPARAMEXCITATION_H
#define FORMPARAMEXCITATION_H

#include <QtWidgets>
#include "ParamExcitations.h"

class FormParamExcitation : public QWidget
{
    Q_OBJECT
public:
    explicit FormParamExcitation(ParamExcitations *excit,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    ParamExcitations *excit;
    QWidget * formTypeSinus;
    
};

#endif // FORMEXCITATION_H
