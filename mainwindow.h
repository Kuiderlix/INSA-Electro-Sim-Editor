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

    void construireDockToolBox();
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void changeFilter();

private:
    TableViewMetallisation * vueMetal;
    TableViewParallelepipede * vueParal;
    TableViewElementLocalise * vueElemLocal;
    MySortFilterProxyModel * currentModel;
    FilterWidget * filterWidget;
    QTabWidget * tabWidget;
    Parser parser;
    Visualisation3D * visualisation;
};

#endif // MAINWINDOW_H
