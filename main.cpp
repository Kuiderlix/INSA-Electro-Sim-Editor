/* 
 * File:   main.cpp
 * Author: camille
 *
 * Created on February 26, 2013, 4:47 PM
 */

#include <cstdlib>
#include <stdio.h>

#include "mainwindow.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {    

    QApplication app(argc, argv);
    app.setStyle(QStyleFactory::create("fusion"));
    MainWindow fenetre;
    fenetre.showMaximized();

    return app.exec();
}

