#ifndef FORMMETALLISATION_H
#define FORMMETALLISATION_H

#include <QtWidgets>
#include "metallisation.h"
#include "FormCoordonnees.h"

class FormMetallisation : public QWidget
{
    Q_OBJECT
public:
    explicit FormMetallisation(metallisation* metal,int mode,QWidget *parent = 0);
    
signals:
    
public slots:

public:
    static const int NOUVEAU = 0;
    static const int MODIFIER = 1;

private:
    int mode;

    metallisation * metal;

    QPushButton * boutonValider;
    FormCoordonnees * formCoord1;
    FormCoordonnees * formCoord2;
    
};

#endif // FORMMETALLISATION_H
