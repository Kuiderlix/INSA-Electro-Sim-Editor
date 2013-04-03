#ifndef FORMELEMENTBASE_H
#define FORMELEMENTBASE_H

#include <QtWidgets>
#include "FormCoordonnees.h"
#include "elementBase.h"

class FormElementBase : public QWidget
{
    Q_OBJECT
public:
    explicit FormElementBase(elementBase * element,int mode,QWidget *parent = 0);


    QWidget * getWidgetElementBase();
    
signals:
    
public slots:


public:
    static const int NOUVEAU = 0;
    static const int MODIFIER = 1;

private:
    int mode;
    QPushButton * boutonValider;
    elementBase * element;
    FormCoordonnees * formCoord1, *formCoord2;
    
};

#endif // FORMELEMENTBASE_H
