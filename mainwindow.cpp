#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    construireMenu();
    construireDockToolBox();
    construireDockListeObjet();
    visualisation = new Visualisation3D(this);
    setCentralWidget(visualisation);



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
    dock->setMinimumWidth(300);
    QVBoxLayout *dockLayout = new QVBoxLayout;

    QToolBox * toolbox = new QToolBox();
    toolbox->addItem(new QPushButton("test"), "Métallisation");
    toolbox->addItem(new QPushButton("test2"), "bouton2");
    toolbox->addItem(new QPushButton("test3"), "bouton3");
    toolbox->addItem(new QPushButton("test4"), "bouton4");

    dockLayout->addWidget(toolbox);

    dockToolbox->setLayout(dockLayout);
}

void MainWindow::construireDockListeObjet()
{
    QDockWidget *dock = new QDockWidget("Liste", this);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    QWidget *dockToolbox = new QWidget;
    dock->setWidget(dockToolbox);
    dock->setMinimumHeight(300);
    QHBoxLayout *dockLayout = new QHBoxLayout;

    QTabWidget * tabWidget = new QTabWidget();
    tabWidget->addTab(new QPushButton("test"), "Métallisation");
    tabWidget->addTab(new QPushButton("test2"), "bouton2");
    tabWidget->addTab(new QPushButton("test3"), "bouton3");
    tabWidget->addTab(new QPushButton("test4"), "bouton4");

    dockLayout->addWidget(tabWidget);

    dockToolbox->setLayout(dockLayout);
}

