#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <QtWidgets>
#include <QObject>
#include "cube.h"
#include "point.h"

class Formulaire : public QWidget
{
    Q_OBJECT
public:
    explicit Formulaire(QWidget *parent = 0);
    
signals:
    void cubeSent(Cube *);
public slots:
    void sendCube();

private:
    QVBoxLayout * layoutPrincipale;
    QLineEdit * xEditLine, *yEditLine,*zEditLine;
    
};

#endif // FORMULAIRE_H
