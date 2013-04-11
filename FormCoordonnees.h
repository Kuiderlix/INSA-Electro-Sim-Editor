#ifndef FORMCOORDONNEES_H
#define FORMCOORDONNEES_H

#include <QtWidgets>
#include "coordonnee.h"

class FormCoordonnees : public QWidget
{
    Q_OBJECT
public:
    explicit FormCoordonnees(coordonnee coord,QWidget *parent = 0);

    void setCoordonnee(coordonnee c);

    coordonnee getCoord();
    
signals:
    
public slots:

    void changeX(QString);
    void changeY(QString);
    void changeZ(QString);


private:
    coordonnee  coord;

    QSpinBox * champsX;
    QSpinBox * champsY;
    QSpinBox * champsZ;
    
};

#endif // FORMCOORDONNEES_H
