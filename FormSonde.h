#ifndef FORMSONDE_H
#define FORMSONDE_H

#include "FormElementBase.h"
#include "sonde.h"

class FormSonde : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormSonde(sonde * m_sonde ,QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();
    void reset();

private:

    void init();

    sonde * m_sonde;

    QCheckBox * eXWidget;
    QCheckBox * eYWidget;
    QCheckBox * eZWidget;

    QCheckBox * hXWidget;
    QCheckBox * hYWidget;
    QCheckBox * hZWidget;

    FormCoordonnees * formPtAppli;

    QCheckBox * valCentreWidget;
    
};

#endif // FORMSONDE_H
