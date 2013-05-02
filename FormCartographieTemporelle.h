#ifndef FORMCARTOGRAPHIETEMPORELLE_H
#define FORMCARTOGRAPHIETEMPORELLE_H

#include "FormElementBase.h"
#include "cartographieTemporelle.h"

class FormCartographieTemporelle : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormCartographieTemporelle(cartographieTemporelle * carto, int mode, QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();
    void reset();


private:

    void init();

    cartographieTemporelle * carto;

    QCheckBox * champsEWidget;
    QCheckBox * champsHWidget;
    QSpinBox * iterationDebutWidget;
    QSpinBox * iterationFinWidget;
    QSpinBox * intervalleWidget;
    
};

#endif // FORMCARTOGRAPHIETEMPORELLE_H
