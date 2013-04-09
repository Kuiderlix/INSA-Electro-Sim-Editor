#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    parser.parse();

    construireMenu();
    construireDockToolBox();
    QVBoxLayout * layout = new QVBoxLayout();
    visualisation = new Visualisation3D(this);
    layout->addWidget(visualisation);

    QWidget *tables = new QWidget;
    QHBoxLayout *layoutTable = new QHBoxLayout;
    TableMetallisation* tableMeta = new TableMetallisation(parser.getBlocMetallisations());
    QTabWidget * tabWidget = new QTabWidget();
    tabWidget->addTab(tableMeta, "Métallisations");
    tabWidget->addTab(new QPushButton("test2"), "Elements Localises");
    tabWidget->addTab(new QPushButton("test3"), "Parallelepipèdes");
    tabWidget->addTab(new QPushButton("test4"), "Ports Excitations");
    tabWidget->addTab(new QPushButton("test4"), "Sondes");
    tabWidget->addTab(new QPushButton("test4"), "Surfaces Prelevements");
    tabWidget->addTab(new QPushButton("test4"), "Cartographies Temporelles");
    layoutTable->addWidget(tabWidget);
    tables->setLayout(layoutTable);
    layout->addWidget(tables);

    QWidget *central = new QWidget();
    central->setLayout(layout);

    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    
}


void MainWindow::construireMenu()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QAction *actionNouveau = new QAction("&Nouveau", this);
    QAction *actionOuvrir = new QAction("&Ouvrir", this);
    QAction *actionEnregistrer = new QAction("&Enregistrer", this);
    QAction *actionEnregistrerSous = new QAction("&Enregistrer sous ...", this);
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionEnregistrer);
    menuFichier->addAction(actionEnregistrerSous);
    menuFichier->addAction(actionQuitter);

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
}

void MainWindow::construireDockToolBox()
{
    QDockWidget *dock = new QDockWidget("ToolBox", this);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    QWidget *dockToolbox = new QWidget;
    dock->setWidget(dockToolbox);
    QVBoxLayout *dockLayout = new QVBoxLayout;

    QToolBox * toolbox = new QToolBox();
    toolbox->setMinimumWidth(300);



    toolbox->addItem(new DescriptionGeoWidget(&parser), "Description Géométrie");
    toolbox->addItem(new ParamSimuWidget(), "Paramètres Simulation");
    toolbox->addItem(new ObjetFDTDWidget(), "Objets FDTD et DG-FDTD");
    toolbox->addItem(new QPushButton("test"), "Calcul Champ Lointain");
    toolbox->addItem(new QPushButton("test"), "Paramètres Avancés");
    /*
    toolbox->addItem(new FormMetallisation(new metallisation(),FormMetallisation::NOUVEAU), "Métallisation");
    toolbox->addItem(new FormElementLocalise(new elementLocalise(), FormElementLocalise::NOUVEAU), "Element localise");
    toolbox->addItem(new FormParallelepipede(new parallelepipede(), FormParallelepipede::NOUVEAU), "Parallelepipede");
    toolbox->addItem(new FormPortExcitation(new portExcitation(), FormPortExcitation::NOUVEAU), "Port Excitation");
    toolbox->addItem(new FormCageExcitation(new cageExcitation(), FormCageExcitation::NOUVEAU), "Cage Excitation");
    toolbox->addItem(new FormCartographieTemporelle(new cartographieTemporelle(), FormCartographieTemporelle::NOUVEAU), "Cartographie Temporelle");
    toolbox->addItem(new FormSurfacePrelevement(new surfacePrelevement(), FormSurfacePrelevement::NOUVEAU), "Surface Prelevement");
*/

    dockLayout->addWidget(new QPushButton("Générer"));
    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}

