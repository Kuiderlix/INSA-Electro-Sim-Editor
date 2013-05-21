#ifndef FORMPARAMEXCITATION_H
#define FORMPARAMEXCITATION_H

#include <QtWidgets>
#include "ParamExcitations.h"

class FormParamExcitation : public QWidget
{
    Q_OBJECT
public:
    explicit FormParamExcitation(ParamExcitations *excit,QWidget *parent = 0);

    void setParamExcit(ParamExcitations* ex)
    {
        excit=ex;
        init();
    }

    void init();
    
signals:
    
public slots:

    void afficheSinus(int);

private:
    ParamExcitations *excit;
    QWidget * formTypeSinus;

    QDoubleSpinBox * frequenceMaxWidget;
    QComboBox * typeWidget;
    QDoubleSpinBox * freqSinusWidget;
    
};

#endif // FORMEXCITATION_H
