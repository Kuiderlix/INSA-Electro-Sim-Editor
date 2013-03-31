#ifndef FORMMETALLISATION_H
#define FORMMETALLISATION_H

#include <QtWidgets>
#include "metallisation.h"

class FormMetallisation : public QWidget
{
    Q_OBJECT
public:
    explicit FormMetallisation(int mode,QWidget *parent = 0);
    
signals:
    
public slots:


private:
    const int NOUVEAU = 0;
    const int MODIFIER = 1;

    int mode;

    metallisation * metal;
    
};

#endif // FORMMETALLISATION_H
