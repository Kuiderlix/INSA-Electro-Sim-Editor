#ifndef FORMCOORDONNEES_H
#define FORMCOORDONNEES_H

#include <QtWidgets>
#include "coordonnee.h"

/**
 * @brief Cette classe fournit un widget pour modifier l'objet coordonnee
 */
class FormCoordonnees : public QWidget
{
    Q_OBJECT
public:
    explicit FormCoordonnees(QWidget *parent = 0);
    explicit FormCoordonnees(coordonnee coord,QWidget *parent = 0);

    void setCoordonnee(coordonnee c);

    coordonnee getCoord();
    
signals:
    void coordonneeChanged(coordonnee);
    
public slots:

    void changeX(int);
    void changeY(int);
    void changeZ(int);


private:

    void init();

    coordonnee  coord;

    QSpinBox * champsX;
    QSpinBox * champsY;
    QSpinBox * champsZ;
    
};

#endif // FORMCOORDONNEES_H
