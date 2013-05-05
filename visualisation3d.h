#ifndef VISUALISATION3D_H
#define VISUALISATION3D_H

#include "myglwidget.h"
#include <GL/glu.h>
#include "cube.h"
#include "elementBase.h"
#include "point.h"
#include <vector>
#include "volumeCalcul.h"
#include <QList>

using namespace std;

/*
  Cette classe affiche le rendu 3D de la scene
*/
class Visualisation3D : public MyGLWidget
{
    Q_OBJECT
public:
    explicit Visualisation3D(volumeCalcul * volume,QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent(QKeyEvent *keyEvent); // gestion des touches préssées
    /*
       Méthodes de gestion de la souris
    */
    void mousePressEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );

    void wheelEvent ( QWheelEvent * event );

    void dessineVolumeCalcul();

    Point coordonneeToPoint(coordonnee);

    void ajoutListElement(QList<elementBase*>*);

    void setXRotation(int angle);
    void setYRotation(int angle);

    void normalizeAngle(int *angle);


signals:
    void zoomChanged(int);


public slots:

        void setZoom(int z);


private:

    volumeCalcul * volume;
    QList<QList<elementBase*>* > listElement;

    int zoom;
    int xRot;
    int yRot;

    int xMov;
    int yMov;

    QPoint lastPos;

};

#endif // VISUALISATION3D_H
