#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setWindowTitle("Visualisation et de description de structures géométriques");

    
    return a.exec();
}
