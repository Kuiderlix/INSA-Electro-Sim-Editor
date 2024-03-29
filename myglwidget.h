#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>
/**
@brief Cette classe sert de base à la classe qui affiche le rendu en 3D avec OpenGL
*/
class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    virtual void initializeGL() = 0;
    virtual void resizeGL(int width, int height) = 0;
    virtual void paintGL() = 0;
    virtual QSize	sizeHint () const;

public slots:
    virtual void timeOutSlot();

private:
    QTimer *t_Timer;
    int framesPerSecond;

};


#endif // MYGLWIDGET_H
