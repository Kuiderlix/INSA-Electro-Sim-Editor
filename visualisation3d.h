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
#include "BlocElementBase.h"
#include "cageExcitation.h"

using namespace std;


/**
 * @brief Affiche et gère la scène 3D
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

    /**
     * @brief Desinne dans la scène le volume de calcul
     */
    void dessineVolumeCalcul();
    /**
     * @brief Dessine dans la scène tout les éléments du scénario
     */
    void dessineScene();
    /**
     * @brief Dessine la cage d'excitation du scénario de simulation s'elle existe.
     * La cage s'affiche par défault en transparence.
     */
    void dessineCageExcitation();

    /**
     * @brief Tranforme une coordonnee en un Point
     * @param c la coordonnee a transformée
     * @return le Point transformé
     */
    Point coordonneeToPoint(coordonnee);

    /**
     * @brief Ajoute une liste d'élément à la scène
     */
    void ajoutListElement(BlocElementBase*);

    void setXRotation(int angle);
    void setYRotation(int angle);

    void normalizeAngle(int *angle);

    /**
     * @brief Fait tendre la variable var vers 0 avec un pas de step à chaque appel.
     * Exemple: si var=50 et step = 1
     *  La fonction va décrémenté de 1 la variable à chaque appel
     * @param var
     * @param step
     */
    void toZero(int * var, int step);
    /**
     * @brief Meme fonction que toZero() mais appliqué à un angle
     * @param angle
     * @param step
     */
    void toZeroAngle(int * angle, int step);
    /**
     * @brief Initialise les variables de la scène (zoom, xRot, yMov, ...)
     */
    void init();


    void setVolumeCalcul(volumeCalcul * vol)
    {
        this->volume=vol;
    }

    void setCageExcitation(cageExcitation * c)
    {
        cageExcit=c;
    }

    /**
     * @brief Vide la scène
     */
    void clearScene()
    {
        listElement.clear();
    }



signals:
    /**
     * @brief Signal émis quand le zoom change
     */
    void zoomChanged(int);
    /**
     * @brief Signal émis quand le timer doit s'arreter.
     */
    void stopTimer();


public slots:

    /**
     * @brief Modifie le zoom sur la scène
     * @param z
     */
    void setZoom(int z);
    /**
     * @brief Cette fonction fait tendre progressivement (à chaque appel) les variables qui gèrent la scène dans le état initial
     */
    void reInit();
    /**
     * @brief Cette fonction démarre le timer qui permet de remettre la scène dans son état initial
     */
    void startToZoom11();


private:
    /**
     * @brief Le volume de calcul de la scène
     */
    volumeCalcul * volume;

    /**
     * @brief La cage d'excitation de la simulation
     */
    cageExcitation * cageExcit;

    /**
     * @brief Une liste de pointeur sur des listes d'éléments.
     *Ces éléments seront affichés dans la scène.
     */
    QList<BlocElementBase* > listElement;
    /**
     * @brief Variable qui gère le zoom sur la scène
     */
    int zoom;
    /**
     * @brief Variable qui gère la rotation en x de la scène
     */
    int xRot;
    /**
     * @brief Variable qui gère la rotation en y de la scène
     */
    int yRot;
    /**
     * @brief Variable qui gère le déplacement en x de la scène
     */
    int xMov;
    /**
     * @brief Variable qui gère le déplacement en y de la scène
     */
    int yMov;

    QPoint lastPos;

    /**
     * @brief Le timer qui sert à remettre la scène dans son état initial.
     * Ce timer appel la fonction reInit() toute les 10msecs.
     */
    QTimer *timer;

    /**
     * @brief La couleur du volume de calcul
     */
    QColor couleurVolume;

    QList<BlocElementBase* >::Iterator it;
    QList<elementBase*>* list;
    QList<elementBase*>::Iterator it_l;

};

#endif // VISUALISATION3D_H
