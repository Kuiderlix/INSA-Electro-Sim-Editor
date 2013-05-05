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
#include "TableViewCartTempo.h"
#include "TableViewSurfacePrelev.h"
#include "DescriptionGeoWidget.h"
#include "ParamSimuWidget.h"
#include "ObjetFDTDWidget.h"
#include "ParamAvanceWidget.h"
#include "CalculChampsLointainWidget.h"
#include "FilterWidget.h"

/*
  Classe qui sert a affiché la fenêtre principale de l'application
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

    void construireMenu();
    QWidget * construireScene3D();
    void construireToolBar();
    QWidget * construireTableaux();
    void construireDockToolBox();
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void changeFilter();

private:

    QVBoxLayout * layout;

    TableViewMetallisation * vueMetal;
    TableViewParallelepipede * vueParal;
    TableViewElementLocalise * vueElemLocal;
    TableViewPortExcitation * vuePortExci;
    TableViewSonde * vueSonde;
    TableViewCartTempo * vueCartoTempo;
    TableViewSurfacePrelev * vueSurfacePrelev;

    MySortFilterProxyModel * currentModel;
    FilterWidget * filterWidget;
    QTabWidget * tabWidget;
    Parser parser;
    Visualisation3D * visualisation;


    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionGenerer;
    QAction *actionZoom11;
};

#endif // MAINWINDOW_H
