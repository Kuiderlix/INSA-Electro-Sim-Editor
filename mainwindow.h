#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "visualisation3d.h"
/*
  Classe qui sert a affiché la fenêtre principale de l'application
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

    void construitMenu();
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Visualisation3D *zoneCentrale;
};

#endif // MAINWINDOW_H
