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
#include "FormNouveau.h"
#include "FormOuvrir.h"
#include "FormSettings.h"

/**
 * @brief The MainWindow class
 * Cette classe représente la fenêtre principale du logiciel.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    /**
     * Construit les éléments du menu
     * @brief construireMenu
     */
    void construireMenu();
    /**
     * Construit la scene3D et renvoi le widget créé
     * @brief construireScene3D
     * @return le widget
     */
    QWidget * construireScene3D();
    /**
     * Cronstruit et initialise la barre d'outil
     * @brief construireToolBar
     */
    void construireToolBar();
    /**
     * Construit les tableaux de données. L'initialisation des tableaux est aussi faite dans cette fonction.
     * @brief construireTableaux
     * @return
     */
    QWidget * construireTableaux();
    /**
     * Construit la toolbox
     * @brief construireDockToolBox
     */
    void construireDockToolBox();


    void init();
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
     * Cette fonction est appelé dès que l'on change l'onglet courant ( et donc le tableau a affiché).
     * Elle modifie les champs du filtre dans le Widget FilterWidget
     * @brief changeFilter
     */
    void changeFilter();

    /**
     * @brief initialise l'interface graphique avec des données vierges
     */
    void nouvelleSimulation();

    /**
     * @brief Charge les fichiers de configuration et initialise l'interface graphique
     */
    void ouvrirSimulation();

    /**
     * @brief Ouvre la fenetre des paramètres du logiciel
     */
    void ouvreParametres();

    void ecrire();

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

    Data * data;
    Parser parser;

    Visualisation3D * visualisation;

    DescriptionGeoWidget * descGeo;
    ParamSimuWidget* paramSimu;
    ObjetFDTDWidget* objFDTD;
    CalculChampsLointainWidget* calculChWidget;
    ParamAvanceWidget* paramAvcWidget;


    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionGenerer;
    QAction *actionZoom11;
    QAction *actionParametre;
};

#endif // MAINWINDOW_H
