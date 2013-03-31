#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "visualisation3d.h"
#include "TableMetallisation.h"
/*
  Classe qui sert a affiché la fenêtre principale de l'application
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

    void construireMenu();

    void construireDockToolBox();
    void construireDockListeObjet();
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Visualisation3D * visualisation;
};

#endif // MAINWINDOW_H
