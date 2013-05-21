#ifndef FORMPML_H
#define FORMPML_H

#include <QtWidgets>
#include "pml.h"

class FormPML : public QWidget
{
    Q_OBJECT
public:
    explicit FormPML(pml* m_pml,QWidget *parent = 0);

    void setPML(pml * p)
    {
        m_pml=p;
        init();
    }

    void init();
    
signals:
    
public slots:


private:
    pml* m_pml;

    QSpinBox * epaisseurCoucheWidget;
    QSpinBox * ordreVariationWidget;
    QDoubleSpinBox * sigmaMaxWidget;
    QDoubleSpinBox * kMaxWidget;
    
};

#endif // FORMPML_H
