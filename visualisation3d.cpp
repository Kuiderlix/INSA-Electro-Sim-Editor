#include "visualisation3d.h"


Visualisation3D::Visualisation3D(volumeCalcul *volume, QWidget *parent)
    : MyGLWidget(parent)
{
    this->volume=volume;

    setFocusPolicy(Qt::ClickFocus);
    setCursor(QCursor(Qt::OpenHandCursor));
    qsrand(458);
}

void Visualisation3D::initializeGL()
{
    zoom = 0;
    rotateX=0.0;
    rotateY=0.0;

    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Visualisation3D::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 10000.0f);
    gluLookAt(0,0,100,0,0,0,1,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Visualisation3D::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);  // efface la surface pour refaire le rendu
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTranslatef(0.0f,0.0f, 0.0f); // méthode de translation (x,y,z)
    int ratioZoom = (volume->GetHauteur()*1.5) / 100;
    gluLookAt(0,(volume->GetHauteur()*1.5)-(zoom*ratioZoom),0,0,0,0,1,0,0); // gestion de la caméra
    glRotatef(depart.y-pointActuel.y, 1.0, 0, 0); // rotation en x avec la souris
    glRotatef(pointActuel.x-depart.x, 0, 0, 1.0);  //rotation en y avec la souris
    glRotatef(rotateX, 1.0, 0, 0); // rotation en x avec le clavier
    glRotatef(rotateY, 0, 0, 1.0);  //rotation en y avec le clavier


    glColor3ub(0,0,0);// couleur noir
    dessineVolumeCalcul();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    QList<QList<elementBase*>* >::Iterator it = listElement.begin();
    for (;it!=listElement.end();it++)
    {
        QList<elementBase*>* list = *it;
        QList<elementBase*>::Iterator it_l = list->begin();
        for(;it_l!=list->end();it_l++)
        {
            elementBase * elem = (elementBase*) *it_l;
            glColor4ub(elem->getCouleur().red(), elem->getCouleur().green(), elem->getCouleur().blue(),elem->getCouleur().alpha());
            Cube::drawCube(coordonneeToPoint(elem->GetArriereDroit()),coordonneeToPoint(elem->GetAvantGauche()));
        }
    }

    glDisable(GL_BLEND);

}

void Visualisation3D::keyPressEvent(QKeyEvent *keyEvent)
{
    MyGLWidget::keyPressEvent(keyEvent);

    switch (keyEvent->key())
    {
    case Qt::Key_Up:
        rotateX+=10;
        break;
    case Qt::Key_Down:
        rotateX-=10;
        break;
    case Qt::Key_Left:
        rotateY-=10;
        break;
    case Qt::Key_Right:
        rotateY+=10;
        break;
    case Qt::Key_C:
        //setCursor(QCursor(Qt::SizeAllCursor));
        break;
    default:
        setCursor(QCursor(Qt::OpenHandCursor));
    }

}

void Visualisation3D::mousePressEvent( QMouseEvent * event )
{
    setCursor(QCursor(Qt::ClosedHandCursor)); // change le curseur qui on clique dessus
    depart.x=ecartPrecedent.x+event->pos().x();
    depart.y=ecartPrecedent.y+event->pos().y();
    pointActuel.x=event->pos().x();
    pointActuel.y=event->pos().y();
}
void Visualisation3D::mouseMoveEvent( QMouseEvent * event )
{
    pointActuel.x=event->pos().x();
    pointActuel.y=event->pos().y();
}

void Visualisation3D::mouseReleaseEvent( QMouseEvent * event )
{
    setCursor(QCursor(Qt::OpenHandCursor)); // remet le curseur dans on état d'origine quand on relache le clic
    ecartPrecedent.x=depart.x-pointActuel.x;
    ecartPrecedent.y=depart.y-pointActuel.y;
}

void Visualisation3D::wheelEvent(QWheelEvent * event) // gestion de la molette de la souris
{

    zoom += event->delta() / 12;

    if (zoom < -100)
        zoom = -100;
    if (zoom > 100)
        zoom = 100;

    event->accept();
    emit zoomChanged(zoom);
}

void Visualisation3D::dessineVolumeCalcul()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    Cube::drawCube(Point(-volume->GetLargeur()/2,-volume->GetLongueur()/2,-volume->GetHauteur()/2),Point(volume->GetLargeur()/2,volume->GetLongueur()/2,volume->GetHauteur()/2));
}
/**
 * @brief Visualisation3D::coordonneeToPoint
 * Tranforme une coordonnee en un Point
 * @param c la coordonnee a transformé
 * @return le Point transformé
 */
Point Visualisation3D::coordonneeToPoint(coordonnee c)
{
    double ratioX = volume->GetLargeur() / volume->GetNombreX();
    double ratioY = volume->GetLongueur() / volume->GetNombreY();
    double ratioZ = volume->GetHauteur() / volume->GetNombreZ();

    Point point;

    point.x=(c.GetX()*ratioX)-(volume->GetLargeur()/2);
    point.y=(c.GetY()*ratioY)-(volume->GetLongueur()/2);
    point.z=(c.GetZ()*ratioZ)-(volume->GetHauteur()/2);

    return point;
}

void Visualisation3D::ajoutListElement(QList<elementBase *> *l)
{
    listElement.push_back(l);
}

void Visualisation3D::setZoom(int z)
{
    zoom = z;
}

