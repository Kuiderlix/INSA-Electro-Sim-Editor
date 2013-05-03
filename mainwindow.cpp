#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    parser.parse();
    layout = new QVBoxLayout();

    construireMenu();

    construireScene3D();

    construireTableaux();

    construireDockToolBox();

    construireToolBar();

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

    QMenu *menuSimulation = menuBar()->addMenu("&Simulation");
    QAction *actionGenerer = new QAction("&Générer", this);
    menuSimulation->addAction(actionGenerer);


    QMenu *menuScene3D = menuBar()->addMenu("&Scene 3D");
    QAction *actionZoom11 = new QAction("&Zoom 1:1", this);
    menuScene3D->addAction(actionZoom11);

}

void MainWindow::construireScene3D()
{
    visualisation = new Visualisation3D(parser.getVolumeCalcul(),this);
    visualisation->ajoutListElement(parser.getBlocParallelepipede()->getListElementPointer());
    visualisation->ajoutListElement(parser.getBlocMetallisations()->getListElementPointer());
    visualisation->ajoutListElement(parser.getBlocCartoTempo()->getListElementPointer());
    visualisation->ajoutListElement(parser.getBlocElementLocalise()->getListElementPointer());
    visualisation->ajoutListElement(parser.getBlocSurfacePrelev()->getListElementPointer());
    visualisation->ajoutListElement(parser.getBlocSonde()->getListElementPointer());
    visualisation->ajoutListElement(parser.getBlocPortExcitation()->getListElementPointer());

    QWidget * visuaWidget = new QWidget();
    QHBoxLayout * layoutVisua = new QHBoxLayout;

    layoutVisua->addWidget(visualisation);

    QSlider * sliderZoom = new QSlider();
    sliderZoom->setMinimum(-100);
    sliderZoom->setMaximum(100);
    sliderZoom->setValue(0);
    sliderZoom->setOrientation(Qt::Vertical);

    connect(sliderZoom,SIGNAL(valueChanged(int)),visualisation,SLOT(setZoom(int)));
    connect(visualisation,SIGNAL(zoomChanged(int)),sliderZoom,SLOT(setValue(int)));

    layoutVisua->addWidget(sliderZoom);
    visuaWidget->setLayout(layoutVisua);
    layout->addWidget(visuaWidget);
}

void MainWindow::construireToolBar()
{
    QToolBar * toolbar = this->addToolBar("ToolBar");

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
    connect(descGeo,SIGNAL(newParaCreated(elementBase*)),vueParal,SLOT(addElement(elementBase*)));
    connect(descGeo,SIGNAL(newElemLocCreated(elementBase*)),vueElemLocal,SLOT(addElement(elementBase*)));

    ParamSimuWidget* paramSimu = new ParamSimuWidget(&parser);
    connect(paramSimu,SIGNAL(newPortExcitationCreated(elementBase*)),vuePortExci,SLOT(addElement(elementBase*)));

    ObjetFDTDWidget* objFDTD = new ObjetFDTDWidget(&parser);
    connect(objFDTD,SIGNAL(newSondeCreated(elementBase*)),vueSonde,SLOT(addElement(elementBase*)));
    connect(objFDTD,SIGNAL(newSurfacePrelCreated(elementBase*)),vueSurfacePrelev,SLOT(addElement(elementBase*)));
    connect(objFDTD,SIGNAL(newCartoTempoCreated(elementBase*)),vueCartoTempo,SLOT(addElement(elementBase*)));

    toolbox->addItem(descGeo, "Description Géométrique");
    toolbox->addItem(paramSimu, "Paramètres Simulation");
    toolbox->addItem(objFDTD, "Objets FDTD et DG-FDTD");
    toolbox->addItem(new CalculChampsLointainWidget(&parser), "Calcul Champ Lointain");
    toolbox->addItem(new ParamAvanceWidget(&parser), "Paramètres Avancés");


    dockLayout->addWidget(new QPushButton("Générer"));
    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}


void MainWindow::construireTableaux()
{
    QWidget *tables = new QWidget;
    QHBoxLayout *layoutTable = new QHBoxLayout;

    vueMetal = new TableViewMetallisation(parser.getBlocMetallisations());
    vueParal = new TableViewParallelepipede(parser.getBlocParallelepipede());
    vueSonde = new TableViewSonde(parser.getBlocSonde());
    vueElemLocal = new TableViewElementLocalise(parser.getBlocElementLocalise());
    vuePortExci = new TableViewPortExcitation(parser.getBlocPortExcitation());
    vueCartoTempo = new TableViewCartTempo(parser.getBlocCartoTempo());
    vueSurfacePrelev = new TableViewSurfacePrelev(parser.getBlocSurfacePrelev());

    tabWidget = new QTabWidget();
    tabWidget->addTab(vueMetal, "Métallisations");
    tabWidget->addTab(vueParal, "Parallelepipèdes");
    tabWidget->addTab(vueElemLocal, "Elements Localises");
    tabWidget->addTab(vuePortExci, "Ports Excitations");
    tabWidget->addTab(vueSurfacePrelev, "Surfaces Prelevements");
    tabWidget->addTab(vueSonde, "Sondes");
    tabWidget->addTab(vueCartoTempo, "Cartographies Temporelles");
    layoutTable->addWidget(tabWidget);
    tables->setLayout(layoutTable);
    layout->addWidget(tables);


    filterWidget = new FilterWidget;

    layout->addWidget(filterWidget);
}
