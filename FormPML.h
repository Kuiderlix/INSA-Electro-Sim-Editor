#ifndef FORMPML_H
#define FORMPML_H

#include <QtWidgets>
#include "pml.h"

class FormPML : public QWidget
{
    Q_OBJECT
public:
    explicit FormPML(pml* m_pml,QWidget *parent = 0);
    
signals:
    
public slots:


private:
    pml* m_pml;
    
};

#endif // FORMPML_H
