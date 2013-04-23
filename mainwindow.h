#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "parser.h"
#include "visualisation3d.h"
#include "TableViewMetallisation.h"
#include "TableViewParallelepipede.h"
#include "TableViewSonde.h"
#include "TableViewElementLocalise.h"
#include "TableViewPortExcitation.h"
#include "DescriptionGeoWidget.h"
#include "ParamSimuWidget.h"
#include "ObjetFDTDWidget.h"
#include "CalculChampsLointainWidget.h"

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
    Parser parser;
    Visualisation3D * visualisation;
};

#endif // MAINWINDOW_H
