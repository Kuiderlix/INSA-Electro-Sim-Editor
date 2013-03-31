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
    point.cpp \
    parser.cpp \
    SurfacePrelevement.cpp \
    CageExcitation.cpp \
    anayseTemporelle.cpp \
    blocAmplitude.cpp \
    blocCartographieTemporelle.cpp \
    blocConfiguration.cpp \
    blocEchantillonnage.cpp \
    blocElementLocalise.cpp \
    blocMetallisation.cpp \
    blocParallelepipede.cpp \
    blocPortExcitation.cpp \
    blocSonde.cpp \
    blocSurfacePrelevement.cpp \
    cageExcitation.cpp \
    calculDirectivite.cpp \
    cartographieTemporelle.cpp \
    champLointain.cpp \
    compressionHuygens.cpp \
    coordonnee.cpp \
    elementBase.cpp \
    elementLocalise.cpp \
    excitations.cpp \
    formatStockage.cpp \
    metallisation.cpp \
    parallelepipede.cpp \
    paroi.cpp \
    pml.cpp \
    portExcitation.cpp \
    sonde.cpp \
    surfacePrelevement.cpp \
    volumeCalcul.cpp \
    TableMetallisation.cpp \
    FormMetallisation.cpp \
    FormCoordonnees.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    visualisation3d.h \
    cube.h \
    formulaire.h \
    zonecentrale.h \
    point.h \
    constants.h \
    structures.h \
    CageExcitation.h \
    parser.h \
    anayseTemporelle.h \
    blocAmplitude.h \
    blocCartographieTemporelle.h \
    blocConfiguration.h \
    blocEchantillonnage.h \
    blocElementLocalise.h \
    blocMetallisation.h \
    blocParallelepipede.h \
    blocPortExcitation.h \
    blocSonde.h \
    blocSurfacePrelevement.h \
    cageExcitation.h \
    calculDirectivite.h \
    cartographieTemporelle.h \
    champLointain.h \
    compressionHuygens.h \
    coordonnee.h \
    elementBase.h \
    elementLocalise.h \
    excitations.h \
    formatStockage.h \
    metallisation.h \
    parallelepipede.h \
    paroi.h \
    pml.h \
    portExcitation.h \
    sonde.h \
    surfacePrelevement.h \
    volumeCalcul.h \
    TableMetallisation.h \
    FormMetallisation.h \
    FormCoordonnees.h

OTHER_FILES += \
    DATA1.ana \
    DATA1.avc \
    DATA1.dsc \
    DATA1.ptr \
    README.md \
    Visualisation_de_simulation.pro.user
