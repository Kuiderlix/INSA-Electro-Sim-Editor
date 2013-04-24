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

    TableViewMetallisation * vueMetal = new TableViewMetallisation(parser.getBlocMetallisations());
    TableViewParallelepipede * vueParal = new TableViewParallelepipede(parser.getBlocParallelepipede());
    TableViewSonde * vueSonde = new TableViewSonde(parser.getBlocSonde());
    TableViewElementLocalise * vueElemLocal = new TableViewElementLocalise(parser.getBlocElementLocalise());
    TableViewPortExcitation * vuePortExci = new TableViewPortExcitation(parser.getBlocPortExcitation());
    TableViewCartTempo * vueCartoTempo = new TableViewCartTempo(parser.getBlocCartoTempo());
    TableViewSurfacePrelev * vueSurfacePrelev = new TableViewSurfacePrelev(parser.getBlocSurfacePrelev());

    QTabWidget * tabWidget = new QTabWidget();
    tabWidget->addTab(vueMetal, "Métallisations");
    tabWidget->addTab(vueElemLocal, "Elements Localises");
    tabWidget->addTab(vueParal, "Parallelepipèdes");
    tabWidget->addTab(vuePortExci, "Ports Excitations");
    tabWidget->addTab(vueSonde, "Sondes");
    tabWidget->addTab(vueSurfacePrelev, "Surfaces Prelevements");
    tabWidget->addTab(vueCartoTempo, "Cartographies Temporelles");
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



    toolbox->addItem(new DescriptionGeoWidget(&parser), "Description Géométrique");
    toolbox->addItem(new ParamSimuWidget(), "Paramètres Simulation");
    toolbox->addItem(new ObjetFDTDWidget(), "Objets FDTD et DG-FDTD");
    toolbox->addItem(new CalculChampsLointainWidget(), "Calcul Champ Lointain");
    toolbox->addItem(new QPushButton("test"), "Paramètres Avancés");


    dockLayout->addWidget(new QPushButton("Générer"));
    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}

