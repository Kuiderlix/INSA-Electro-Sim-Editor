#ifndef FORMEXCITATION_H
#define FORMEXCITATION_H

#include <QtWidgets>
#include "Excitation.h"

class FormExcitation : public QWidget
{
    Q_OBJECT
public:
    explicit FormExcitation(Excitation * excitation,QWidget *parent = 0);

    void setExcitation(Excitation * e)
    {
        excitation=e;
        init();
    }

    void init();
    
signals:
    
public slots:

private:
    Excitation * excitation;

    QDoubleSpinBox * amplitudeWidget;
    
};

#endif // FORMEXCITATION_H
