#ifndef FORMCOORDONNEES_H
#define FORMCOORDONNEES_H

#include <QtWidgets>
#include "coordonnee.h"

class FormCoordonnees : public QWidget
{
    Q_OBJECT
public:
    explicit FormCoordonnees(coordonnee coord,QWidget *parent = 0);
    
signals:
    
public slots:


private:
    coordonnee  coord;

    QSpinBox * champsX;
    QSpinBox * champsY;
    QSpinBox * champsZ;
    
};

#endif // FORMCOORDONNEES_H
