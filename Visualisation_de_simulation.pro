#-------------------------------------------------
#
# Project created by QtCreator 2013-02-12T16:05:44
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Visualisation_de_simulation
TEMPLATE = app

LIBS += -L/usr/local/bar/libs -lGLU

SOURCES += main.cpp\
        mainwindow.cpp \
    myglwidget.cpp \
    visualisation3d.cpp \
    cube.cpp \
    formulaire.cpp \
    zonecentrale.cpp \
    point.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    visualisation3d.h \
    cube.h \
    formulaire.h \
    zonecentrale.h \
    point.h
