#ifndef FORMMETALLISATION_H
#define FORMMETALLISATION_H

#include <QtWidgets>
#include "metallisation.h"
#include "FormElementBase.h"

class FormMetallisation : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormMetallisation(metallisation* metal,QWidget *parent = 0);

    metallisation * getMetallisation();
    
signals:

    
public slots:

    void valider();
    void reset();

private:

    void init();


    QDoubleSpinBox * lineEditConductivite;
    metallisation * metal;
    
};

#endif // FORMMETALLISATION_H
