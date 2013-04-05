/* 
 * File:   main.cpp
 * Author: camille
 *
 * Created on February 26, 2013, 4:47 PM
 */

#include <cstdlib>
#include <stdio.h>
#include "parser.h"

#include "mainwindow.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {    
    parse();

    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow fenetre;
    fenetre.showMaximized();

    return app.exec();
}

