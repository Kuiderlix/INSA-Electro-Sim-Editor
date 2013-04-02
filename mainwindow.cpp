#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    construireMenu();
    construireDockToolBox();
    QVBoxLayout * layout = new QVBoxLayout();
    visualisation = new Visualisation3D(this);
    layout->addWidget(visualisation);

    QWidget *tables = new QWidget;
    QHBoxLayout *layoutTable = new QHBoxLayout;
    TableMetallisation* tableMeta = new TableMetallisation();
    QTabWidget * tabWidget = new QTabWidget();
    tabWidget->addTab(tableMeta, "Métallisation");
    tabWidget->addTab(new QPushButton("test2"), "bouton2");
    tabWidget->addTab(new QPushButton("test3"), "bouton3");
    tabWidget->addTab(new QPushButton("test4"), "bouton4");
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
    dock->setMaximumWidth(300);
    QVBoxLayout *dockLayout = new QVBoxLayout;

    QToolBox * toolbox = new QToolBox();
    toolbox->addItem(new FormMetallisation(new metallisation(),FormMetallisation::NOUVEAU), "Métallisation");
    toolbox->addItem(new QPushButton("test2"), "bouton2");
    toolbox->addItem(new QPushButton("test3"), "bouton3");
    toolbox->addItem(new QPushButton("test4"), "bouton4");


    dockLayout->addWidget(new QPushButton("Générer"));
    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}

