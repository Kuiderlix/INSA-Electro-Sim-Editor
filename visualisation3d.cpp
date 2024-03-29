#include "visualisation3d.h"


Visualisation3D::Visualisation3D(volumeCalcul *volume, QWidget *parent)
    : MyGLWidget(parent)
{
    this->volume=volume;

    setFocusPolicy(Qt::ClickFocus);
    setCursor(QCursor(Qt::OpenHandCursor));
    qsrand(458);


    couleurVolume = QColor("black");


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(reInit()));
    connect(this, SIGNAL(stopTimer()), timer, SLOT(stop()));
}

void Visualisation3D::initializeGL()
{
    init();

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

    glTranslatef(xMov,yMov, 0.0f); // méthode de translation (x,y,z)

    int ratioZoom = (volume->GetHauteur()*1.5) / 100;
    if (ratioZoom < 1)
        ratioZoom=1;
    gluLookAt(0,(volume->GetHauteur()*1.5)-(zoom*ratioZoom),0,0,0,0,1,0,0); // gestion de la caméra

    glRotated(-xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 0.0, 1.0);


    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    dessineVolumeCalcul();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    dessineScene();
    dessineCageExcitation();


    glDisable(GL_BLEND);
}

void Visualisation3D::keyPressEvent(QKeyEvent *keyEvent)
{
    MyGLWidget::keyPressEvent(keyEvent);


    switch (keyEvent->key())
    {
    case Qt::Key_Up:
        setXRotation(xRot - 80);
        break;
    case Qt::Key_Down:
        setXRotation(xRot + 80);
        break;
    case Qt::Key_Left:
        setYRotation(yRot - 80);
        break;
    case Qt::Key_Right:
        setYRotation(yRot + 80);
        break;
    }
    emit stopTimer();

}

void Visualisation3D::mousePressEvent( QMouseEvent * event )
{
    setCursor(QCursor(Qt::ClosedHandCursor)); // change le curseur qui on clique dessus
    lastPos = event->pos();
    emit stopTimer();
}
void Visualisation3D::mouseMoveEvent( QMouseEvent * event )
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        int ratioZoom = qAbs(8 + (-zoom/14));
        xMov = xMov - ratioZoom * dy;
        yMov = yMov - ratioZoom * dx;
        updateGL();
    }
    lastPos = event->pos();
}

void Visualisation3D::mouseReleaseEvent( QMouseEvent * event )
{
    Q_UNUSED(event)
    setCursor(QCursor(Qt::OpenHandCursor)); // remet le curseur dans on état d'origine quand on relache le clic
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

void Visualisation3D::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        updateGL();
    }
}

void Visualisation3D::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot) {
        yRot = angle;
        updateGL();
    }
}


void Visualisation3D::dessineVolumeCalcul()
{
    qglColor(couleurVolume);
    Cube::drawCube(Point(-volume->GetLargeur()/2,-volume->GetLongueur()/2,-volume->GetHauteur()/2),Point(volume->GetLargeur()/2,volume->GetLongueur()/2,volume->GetHauteur()/2));
}

void Visualisation3D::dessineScene()
{
    it = listElement.begin();
    for (;it!=listElement.end();it++)
    {
        list = (*it)->getListElementPointer();
        it_l = list->begin();
        for(;it_l!=list->end();it_l++)
        {
            elementBase * elem = (elementBase*) *it_l;
            qglColor(elem->getCouleur());
            Cube::drawCube(coordonneeToPoint(elem->GetArriereDroit()),coordonneeToPoint(elem->GetAvantGauche()));
        }
    }
}

void Visualisation3D::dessineCageExcitation()
{
    if (cageExcit->isCreate())
    {
        qglColor(cageExcit->getCouleur());
        Cube::drawCube(coordonneeToPoint(cageExcit->GetArriereDroit()),coordonneeToPoint(cageExcit->GetAvantGauche()));
    }

}

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

void Visualisation3D::ajoutListElement(BlocElementBase *l)
{
    listElement.push_back(l);
}

void Visualisation3D::setZoom(int z)
{
    zoom = z;
}

void Visualisation3D::init()
{
    zoom = 0;
    xRot=0;
    yRot=0;

    xMov=0;
    yMov=0;
}

void Visualisation3D::reInit()
{

    toZero(&zoom,5);
    emit zoomChanged(zoom);
    toZeroAngle(&xRot,80);
    toZeroAngle(&yRot,80);
    toZero(&xMov,80);
    toZero(&yMov,80);


    updateGL();

    if (!zoom && !xRot && !yRot && !xMov && !yMov)
        emit stopTimer();
}

void Visualisation3D::startToZoom11()
{
    timer->start(10);
}

void Visualisation3D::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

void Visualisation3D::toZero(int *var, int step)
{
    if (*var > 0)
    {
        *var -= step;
        if (*var < 0)
            *var = 0;
    }
    else if (*var < 0)
    {
        *var += step;
        if (*var > 0)
            *var = 0;
    }
}

void Visualisation3D::toZeroAngle(int *angle, int step)
{
    if (*angle >= 360*8)
    {
        *angle += step;
        if (*angle > 360 * 16)
            *angle = 0;
    }
    else if (*angle < 360*8)
    {
        *angle -= step;
        if (*angle < 0)
            *angle = 0;
    }
}
