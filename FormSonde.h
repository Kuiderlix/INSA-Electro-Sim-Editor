#ifndef FORMSONDE_H
#define FORMSONDE_H

#include "FormElementBase.h"
#include "sonde.h"

class FormSonde : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormSonde(sonde * m_sonde, int mode ,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    sonde * m_sonde;
    
};

#endif // FORMSONDE_H
