#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "visualisation3d.h"
#include "TableMetallisation.h"
#include "FormMetallisation.h"
#include "FormElementLocalise.h"
/*
  Classe qui sert a affiché la fenêtre principale de l'application
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

    void construireMenu();

    void construireDockToolBox();
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Visualisation3D * visualisation;
};

#endif // MAINWINDOW_H
