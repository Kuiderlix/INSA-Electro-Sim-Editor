#include "TableViewSurfacePrelev.h"

TableViewSurfacePrelev::TableViewSurfacePrelev(blocSurfacePrelevement *bloc, QWidget *parent) :
    TableView(parent)
{
    this->setModel(new TableModelSurfacePrelev(bloc));
    this->setItemDelegateForColumn(TableModelSurfacePrelev::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelSurfacePrelev::ArriereDroit,new CoordonneeDelegate());

    this->setItemDelegateForColumn(TableModelSurfacePrelev::TypeSurface,new ComboxDecaleeDelegate(QStringList() << "Huygens" << "Surface_de_prelevement_DG" << "Kirchhoff",1));
    this->setItemDelegateForColumn(TableModelSurfacePrelev::insideOutside,new ComboxDecaleeDelegate(QStringList() << "Inside" << "Outside",1));
    this->setItemDelegateForColumn(TableModelSurfacePrelev::nbFace,new ComboxDecaleeDelegate(QStringList() << "5 Faces" << "6 Faces",5));
}

void TableViewSurfacePrelev::addNewMetallisation()
{
    qDebug() << "test";
    FormSurfacePrelevement * form = new FormSurfacePrelevement(new surfacePrelevement,FormSurfacePrelevement::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}
