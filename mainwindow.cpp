#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    parser.parse();

    construireMenu();
    QVBoxLayout * layout = new QVBoxLayout();
    visualisation = new Visualisation3D(this);
    layout->addWidget(visualisation);


    QWidget *tables = new QWidget;
    QHBoxLayout *layoutTable = new QHBoxLayout;

    vueMetal = new TableViewMetallisation(parser.getBlocMetallisations());
    TableViewParallelepipede * vueParal = new TableViewParallelepipede(parser.getBlocParallelepipede());
    TableViewSonde * vueSonde = new TableViewSonde(parser.getBlocSonde());
    TableViewElementLocalise * vueElemLocal = new TableViewElementLocalise(parser.getBlocElementLocalise());
    TableViewPortExcitation * vuePortExci = new TableViewPortExcitation(parser.getBlocPortExcitation());
    TableViewCartTempo * vueCartoTempo = new TableViewCartTempo(parser.getBlocCartoTempo());
    TableViewSurfacePrelev * vueSurfacePrelev = new TableViewSurfacePrelev(parser.getBlocSurfacePrelev());

    tabWidget = new QTabWidget();
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


    filterWidget = new FilterWidget;

    layout->addWidget(filterWidget);



    construireDockToolBox();

    QWidget *central = new QWidget();
    central->setLayout(layout);

    setCentralWidget(central);
    currentModel = (MySortFilterProxyModel*)((TableView*)tabWidget->currentWidget())->model();
    connect(filterWidget,SIGNAL(columnChanged(int)), currentModel,SLOT(setFilterKeyColumn(int)));
    connect(filterWidget,SIGNAL(filterChanged(QString)), currentModel,SLOT(setFilterRegExp(QString)));
    connect(tabWidget,SIGNAL(currentChanged(int)), this, SLOT(changeFilter()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::changeFilter()
{
    disconnect(filterWidget,SIGNAL(columnChanged(int)), currentModel,SLOT(setFilterKeyColumn(int)));
    disconnect(filterWidget,SIGNAL(filterChanged(QString)), currentModel,SLOT(setFilterRegExp(QString)));
    currentModel = (MySortFilterProxyModel*)((TableView*)tabWidget->currentWidget())->model();
    connect(filterWidget,SIGNAL(columnChanged(int)), currentModel,SLOT(setFilterKeyColumn(int)));
    connect(filterWidget,SIGNAL(filterChanged(QString)), currentModel,SLOT(setFilterRegExp(QString)));

    TableModel* table = (TableModel*)currentModel->sourceModel();

    filterWidget->setCurrentModel(table);
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

    DescriptionGeoWidget * descGeo = new DescriptionGeoWidget(&parser);
    connect(descGeo,SIGNAL(newMetalCreated(elementBase*)),vueMetal,SLOT(addElement(elementBase*)));

    toolbox->addItem(descGeo, "Description Géométrique");
    toolbox->addItem(new ParamSimuWidget(), "Paramètres Simulation");
    toolbox->addItem(new ObjetFDTDWidget(), "Objets FDTD et DG-FDTD");
    toolbox->addItem(new CalculChampsLointainWidget(), "Calcul Champ Lointain");
    toolbox->addItem(new ParamAvanceWidget(), "Paramètres Avancés");


    dockLayout->addWidget(new QPushButton("Générer"));
    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}

