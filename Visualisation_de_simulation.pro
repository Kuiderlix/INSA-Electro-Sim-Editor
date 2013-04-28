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
    formatStockage.cpp \
    metallisation.cpp \
    parallelepipede.cpp \
    paroi.cpp \
    pml.cpp \
    portExcitation.cpp \
    sonde.cpp \
    surfacePrelevement.cpp \
    volumeCalcul.cpp \
    FormMetallisation.cpp \
    FormCoordonnees.cpp \
    FormElementLocalise.cpp \
    FormElementBase.cpp \
    FormParallelepipede.cpp \
    FormCartographieTemporelle.cpp \
    FormSurfacePrelevement.cpp \
    FormPortExcitation.cpp \
    FormCageExcitation.cpp \
    Ecriture.cpp \
    analyseTemporelle.cpp \
    DescriptionGeoWidget.cpp \
    ParamSimuWidget.cpp \
    ObjetFDTDWidget.cpp \
    FormVolumeCalcul.cpp \
    FormParoi.cpp \
    FormAnalyseTempo.cpp \
    CalculChampsLointainWidget.cpp \
    FormCompressionHuygens.cpp \
    FormSonde.cpp \
    FormCalculDirective.cpp \
    CoordonneeDelegate.cpp \
    TableViewMetallisation.cpp \
    BlocElementBase.cpp \
    TableModel.cpp \
    TableView.cpp \
    TableModelMetallisation.cpp \
    TableModelParallelepipede.cpp \
    TableViewParallelepipede.cpp \
    TableModelSonde.cpp \
    TableViewSonde.cpp \
    TableModelElementLocalise.cpp \
    TableViewElementLocalise.cpp \
    ComboxDecaleeDelegate.cpp \
    TableModelPortExcitation.cpp \
    TableViewPortExcitation.cpp \
    TableModelCartoTempo.cpp \
    TableViewCartTempo.cpp \
    TableModelSurfacePrelev.cpp \
    TableViewSurfacePrelev.cpp \
    FormChampLointain.cpp \
    ParamAvanceWidget.cpp \
    FormFormatStockage.cpp \
    ParamExcitations.cpp \
    FormParamExcitation.cpp \
    Excitation.cpp \
    FormExcitation.cpp \
    FormEchantillonage.cpp

HEADERS  += mainwindow.h \
    myglwidget.h \
    visualisation3d.h \
    cube.h \
    formulaire.h \
    zonecentrale.h \
    point.h \
    constants.h \
    structures.h \
    parser.h \
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
    formatStockage.h \
    metallisation.h \
    parallelepipede.h \
    paroi.h \
    pml.h \
    portExcitation.h \
    sonde.h \
    surfacePrelevement.h \
    volumeCalcul.h \
    FormMetallisation.h \
    FormCoordonnees.h \
    FormElementLocalise.h \
    FormElementBase.h \
    FormParallelepipede.h \
    FormParallelepipede.h \
    FormCartographieTemporelle.h \
    FormSurfacePrelevement.h \
    FormPortExcitation.h \
    FormCageExcitation.h \
    Ecriture.h \
    analyseTemporelle.h \
    DescriptionGeoWidget.h \
    ParamSimuWidget.h \
    ObjetFDTDWidget.h \
    FormVolumeCalcul.h \
    FormParoi.h \
    FormAnalyseTempo.h \
    CalculChampsLointainWidget.h \
    FormCompressionHuygens.h \
    FormSonde.h \
    FormCalculDirective.h \
    CoordonneeDelegate.h \
    TableViewMetallisation.h \
    BlocElementBase.h \
    TableModel.h \
    TableView.h \
    TableModelMetallisation.h \
    TableModelParallelepipede.h \
    TableViewParallelepipede.h \
    TableModelSonde.h \
    TableViewSonde.h \
    TableModelElementLocalise.h \
    TableViewElementLocalise.h \
    ComboxDecaleeDelegate.h \
    TableModelPortExcitation.h \
    TableViewPortExcitation.h \
    TableModelCartoTempo.h \
    TableViewCartTempo.h \
    TableModelSurfacePrelev.h \
    TableViewSurfacePrelev.h \
    FormChampLointain.h \
    ParamAvanceWidget.h \
    FormFormatStockage.h \
    ParamExcitations.h \
    FormParamExcitation.h \
    Excitation.h \
    FormExcitation.h \
    FormEchantillonage.h

OTHER_FILES += \
    DATA1.ana \
    DATA1.avc \
    DATA1.dsc \
    DATA1.ptr \
    README.md \
    Visualisation_de_simulation.pro.user
