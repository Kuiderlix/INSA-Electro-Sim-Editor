#ifndef FORMELEMENTLOCALISE_H
#define FORMELEMENTLOCALISE_H

#include <QWidget>
#include "FormElementBase.h"
#include "elementLocalise.h"

class FormElementLocalise : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormElementLocalise(elementLocalise * localise, int mode, QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();

private:
    elementLocalise * localise;
    
};

#endif // FORMELEMENTLOCALISE_H
