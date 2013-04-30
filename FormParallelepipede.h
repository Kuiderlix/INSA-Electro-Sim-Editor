#ifndef FORMPARALLELEPIPEDE_H
#define FORMPARALLELEPIPEDE_H

#include "FormElementBase.h"
#include "parallelepipede.h"

class FormParallelepipede : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormParallelepipede(parallelepipede * paralle, int mode, QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();

    void reset();


private:
    parallelepipede * paralle;
    QDoubleSpinBox * permitRelativeWidget;
    QDoubleSpinBox * permeRelativeWidget;
    QDoubleSpinBox * conductiviteWidget;
    
};

#endif // FORMPARALLELEPIPEDE_H
