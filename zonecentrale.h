#ifndef ZONECENTRAL_H
#define ZONECENTRAL_H

#include <QtWidgets>
#include "visualisation3d.h"
#include "formulaire.h"
/*
  Cette classe est le Widget qui est placé au centre de la fenêtre principale.
  Il contient les différents Widgets comme le rendu 3D et le formulaire.
*/
class ZoneCentrale : public QWidget
{
    Q_OBJECT
public:
    explicit ZoneCentrale(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    Visualisation3D* visualisation;
    Formulaire* formulaire;
    QHBoxLayout * layoutPrincipale;
    
};

#endif // ZONECENTRAL_H
