#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    data = new Data(&parser);

    layout = new QVBoxLayout();


    QSplitter * splitter = new QSplitter();
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(construireScene3D());
    splitter->addWidget(construireTableaux());

    layout->addWidget(splitter);

    construireDockToolBox();

    construireMenu();
    construireToolBar();

    QWidget *central = new QWidget();
    central->setLayout(layout);

    setCentralWidget(central);
    currentModel = (MySortFilterProxyModel*)((TableView*)tabWidget->currentWidget())->model();
    connect(filterWidget,SIGNAL(columnChanged(int)), currentModel,SLOT(setFilterKeyColumn(int)));
    connect(filterWidget,SIGNAL(filterChanged(QString)), currentModel,SLOT(setFilterRegExp(QString)));
    connect(tabWidget,SIGNAL(currentChanged(int)), this, SLOT(changeFilter()));


    init();
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

void MainWindow::nouvelleSimulation()
{
    FormNouveau * win = new FormNouveau(this);
    int result = win->exec();

    if (result == QDialog::Accepted)
    {
        delete data;
        data=new Data();
        init();
    }
    delete win;
}

void MainWindow::ouvrirSimulation()
{
    FormOuvrir * win = new FormOuvrir(this);
    int result = win->exec();
    if (result == QDialog::Accepted)
    {
        delete data;
        parser.setNumFichier(win->getNum());
        data=new Data(&parser);
        init();
    }
    delete win;
}


void MainWindow::construireMenu()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    actionNouveau = new QAction(QIcon("icon/nouveau.png"),"&Nouveau", this);
    actionNouveau->setShortcuts(QKeySequence::New);
    connect(actionNouveau,SIGNAL(triggered()),this,SLOT(nouvelleSimulation()));
    actionOuvrir = new QAction(QIcon("icon/ouvrir.png"),"&Ouvrir", this);
    actionOuvrir->setShortcuts(QKeySequence::Open);
    connect(actionOuvrir,SIGNAL(triggered()),this,SLOT(ouvrirSimulation()));
    QAction *actionQuitter = new QAction(QIcon("icon/quitter.png"),"&Quitter", this);
    actionQuitter->setShortcuts(QKeySequence::Quit);
    connect(actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionQuitter);

    QMenu *menuSimulation = menuBar()->addMenu("&Simulation");
    actionGenerer = new QAction(QIcon("icon/generer.png"),"&Générer", this);
    menuSimulation->addAction(actionGenerer);


    QMenu *menuScene3D = menuBar()->addMenu("&Scene 3D");
    actionZoom11 = new QAction(QIcon("icon/initScene.png"),"&Zoom 1:1", this);
    connect(actionZoom11,SIGNAL(triggered()),visualisation,SLOT(startToZoom11()));
    menuScene3D->addAction(actionZoom11);

}

QWidget *MainWindow::construireScene3D()
{
    visualisation = new Visualisation3D(data->getVolumeCalcul(),this);
    visualisation->ajoutListElement(data->getBlocParallelepipede());
    visualisation->ajoutListElement(data->getBlocMetallisations());
    visualisation->ajoutListElement(data->getBlocCartoTempo());
    visualisation->ajoutListElement(data->getBlocElementLocalise());
    visualisation->ajoutListElement(data->getBlocSurfacePrelev());
    visualisation->ajoutListElement(data->getBlocSonde());
    visualisation->ajoutListElement(data->getBlocPortExcitation());

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

    return visuaWidget;

}

void MainWindow::construireToolBar()
{
    QToolBar * toolbar = this->addToolBar("ToolBar");

    toolbar->addAction(actionNouveau);
    toolbar->addAction(actionOuvrir);
    toolbar->addSeparator();
    toolbar->addAction(actionGenerer);
    toolbar->addSeparator();
    toolbar->addAction(actionZoom11);

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

    descGeo = new DescriptionGeoWidget(data);
    connect(descGeo,SIGNAL(newMetalCreated(elementBase*)),vueMetal,SLOT(addElement(elementBase*)));
    connect(descGeo,SIGNAL(newParaCreated(elementBase*)),vueParal,SLOT(addElement(elementBase*)));
    connect(descGeo,SIGNAL(newElemLocCreated(elementBase*)),vueElemLocal,SLOT(addElement(elementBase*)));

    paramSimu = new ParamSimuWidget(data);
    connect(paramSimu,SIGNAL(newPortExcitationCreated(elementBase*)),vuePortExci,SLOT(addElement(elementBase*)));

    objFDTD = new ObjetFDTDWidget(data);
    connect(objFDTD,SIGNAL(newSondeCreated(elementBase*)),vueSonde,SLOT(addElement(elementBase*)));
    connect(objFDTD,SIGNAL(newSurfacePrelCreated(elementBase*)),vueSurfacePrelev,SLOT(addElement(elementBase*)));
    connect(objFDTD,SIGNAL(newCartoTempoCreated(elementBase*)),vueCartoTempo,SLOT(addElement(elementBase*)));

    calculChWidget = new CalculChampsLointainWidget(data);
    paramAvcWidget = new ParamAvanceWidget(data);

    toolbox->addItem(descGeo, "Description Géométrique");
    toolbox->addItem(paramSimu, "Paramètres Simulation");
    toolbox->addItem(objFDTD, "Objets FDTD et DG-FDTD");
    toolbox->addItem(calculChWidget, "Calcul Champ Lointain");
    toolbox->addItem(paramAvcWidget, "Paramètres Avancés");


    dockLayout->addWidget(new QPushButton(QIcon("icon/generer.png"),"Générer"));
    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}

void MainWindow::init()
{
    //initialisation des données de la vue
    visualisation->clearScene();
    visualisation->init();
    visualisation->setVolumeCalcul(data->getVolumeCalcul());
    visualisation->ajoutListElement(data->getBlocParallelepipede());
    visualisation->ajoutListElement(data->getBlocMetallisations());
    visualisation->ajoutListElement(data->getBlocCartoTempo());
    visualisation->ajoutListElement(data->getBlocElementLocalise());
    visualisation->ajoutListElement(data->getBlocSurfacePrelev());
    visualisation->ajoutListElement(data->getBlocSonde());
    visualisation->ajoutListElement(data->getBlocPortExcitation());

    //initialisation des données des tableaux
    vueMetal->setSourceModel(new TableModelMetallisation(data->getBlocMetallisations()));
    vueParal->setSourceModel(new TableModelParallelepipede(data->getBlocParallelepipede()));
    vueSonde->setSourceModel(new TableModelSonde(data->getBlocSonde()));
    vueElemLocal->setSourceModel(new TableModelElementLocalise(data->getBlocElementLocalise()));
    vuePortExci->setSourceModel(new TableModelPortExcitation(data->getBlocPortExcitation()));
    vueCartoTempo->setSourceModel(new TableModelCartoTempo(data->getBlocCartoTempo()));
    vueSurfacePrelev->setSourceModel(new TableModelSurfacePrelev(data->getBlocSurfacePrelev()));

    //initialisation des formulaires de la toolbox
    descGeo->setData(data);
    paramSimu->setData(data);
    objFDTD->setData(data);
    calculChWidget->setData(data);
    paramAvcWidget->setData(data);
}


QWidget *MainWindow::construireTableaux()
{
    QWidget *tables = new QWidget;
    QVBoxLayout *layoutTable = new QVBoxLayout;

    vueMetal = new TableViewMetallisation(data->getBlocMetallisations());
    vueParal = new TableViewParallelepipede(data->getBlocParallelepipede());
    vueSonde = new TableViewSonde(data->getBlocSonde());
    vueElemLocal = new TableViewElementLocalise(data->getBlocElementLocalise());
    vuePortExci = new TableViewPortExcitation(data->getBlocPortExcitation());
    vueCartoTempo = new TableViewCartTempo(data->getBlocCartoTempo());
    vueSurfacePrelev = new TableViewSurfacePrelev(data->getBlocSurfacePrelev());

    tabWidget = new QTabWidget();
    tabWidget->addTab(vueMetal, "Métallisations");
    tabWidget->addTab(vueParal, "Parallelepipèdes");
    tabWidget->addTab(vueElemLocal, "Elements Localises");
    tabWidget->addTab(vuePortExci, "Ports Excitations");
    tabWidget->addTab(vueSurfacePrelev, "Surfaces Prelevements");
    tabWidget->addTab(vueSonde, "Sondes");
    tabWidget->addTab(vueCartoTempo, "Cartographies Temporelles");

    filterWidget = new FilterWidget;

    layoutTable->addWidget(tabWidget);
    layoutTable->addWidget(filterWidget);

    tables->setLayout(layoutTable);

    return tables;

}
