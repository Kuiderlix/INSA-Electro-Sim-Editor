#ifndef FORMELEMENTBASE_H
#define FORMELEMENTBASE_H

#include <QtWidgets>
#include "FormCoordonnees.h"
#include "elementBase.h"

class FormElementBase : public QDialog
{
    Q_OBJECT
public:
    explicit FormElementBase(elementBase * element,int mode,QWidget *parent = 0);


    QWidget * getWidgetElementBase();

signals:

    void elementValide(elementBase *);
public slots:

    virtual void valider();


public:
    static const int NOUVEAU = 0;
    static const int MODIFIER = 1;


protected:
    FormCoordonnees * formCoord1, *formCoord2;

    virtual void reset();
    void setElement(elementBase *);

private:
    int mode;
    QPushButton * boutonValider;
    elementBase * element;
    
};

#endif // FORMELEMENTBASE_H
