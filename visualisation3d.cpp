#include "visualisation3d.h"


Visualisation3D::Visualisation3D(QWidget *parent)
    : MyGLWidget(parent)
{
    setFocusPolicy(Qt::ClickFocus);
    setCursor(QCursor(Qt::OpenHandCursor));
}

void Visualisation3D::initializeGL()
{
    zoom = -10.0;
    rotateX=0.0;
    rotateY=0.0;

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
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
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    gluLookAt(0,0,15,0,0,0,1,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Visualisation3D::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // efface la surface pour refaire le rendu
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f); // méthode de translation (x,y,z)
    gluLookAt(0,0,zoom,0,0,0,1,0,0); // gestion de la caméra
    glRotatef(depart.y-pointActuel.y, 1.0, 0, 0); // rotation en x avec la souris
    glRotatef(pointActuel.x-depart.x, 0, 1.0, 0);  //rotation en y avec la souris
    glRotatef(rotateX, 1.0, 0, 0); // rotation en x avec le clavier
    glRotatef(rotateY, 0, 1.0, 0);  //rotation en y avec le clavier

    for (vector<Cube*>::iterator it = tabCubes.begin(); it!=tabCubes.end(); ++it) {
        (*it)->dessineCube();
    }
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
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;

    if (event->orientation() == Qt::Horizontal) {
     zoom-=numSteps;
    } else {
     zoom+=numSteps;
    }
    event->accept();
}


void Visualisation3D::ajoutCube(Cube * c)
{
    tabCubes.push_back(c);
}

