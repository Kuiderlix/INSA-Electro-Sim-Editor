#ifndef FORMPORTEXCITATION_H
#define FORMPORTEXCITATION_H

#include "FormElementBase.h"
#include "portExcitation.h"

class FormPortExcitation : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormPortExcitation(portExcitation * port,int mode,QWidget *parent = 0);
    
signals:
    
public slots:


private:
    portExcitation * port;
    
};

#endif // FORMPORTEXCITATION_H