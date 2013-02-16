#ifndef VISUALISATION3D_H
#define VISUALISATION3D_H

#include "myglwidget.h"
#include "cube.h"

/*
  Cette classe affiche le rendu 3D de la scene
*/
class Visualisation3D : public MyGLWidget
{
    Q_OBJECT
    public:
        explicit Visualisation3D(QWidget *parent = 0);
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
    private:
        Cube* cube; // le cube a affiché
        double zoom;
        double rotateX, rotateY;
};

#endif // VISUALISATION3D_H
