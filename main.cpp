#include <QtGui>
#include "mainwindow.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    parse();
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.setWindowTitle("Visualisation et description de structures géométriques");

    
    return a.exec();
}
