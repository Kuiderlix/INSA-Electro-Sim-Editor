#include "TableViewSurfacePrelev.h"

TableViewSurfacePrelev::TableViewSurfacePrelev(blocSurfacePrelevement *bloc, QWidget *parent) :
    TableView(parent)
{
    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelSurfacePrelev(bloc));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelSurfacePrelev::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelSurfacePrelev::ArriereDroit,new CoordonneeDelegate());

    this->setItemDelegateForColumn(TableModelSurfacePrelev::TypeSurface,new ComboxDecaleeDelegate(QStringList() << "Huygens" << "Surface_de_prelevement_DG" << "Kirchhoff",1));
    this->setItemDelegateForColumn(TableModelSurfacePrelev::insideOutside,new ComboxDecaleeDelegate(QStringList() << "Inside" << "Outside",1));
    this->setItemDelegateForColumn(TableModelSurfacePrelev::nbFace,new ComboxDecaleeDelegate(QStringList() << "5 Faces" << "6 Faces",5));
}

void TableViewSurfacePrelev::addNewElement()
{
    FormSurfacePrelevement * form = new FormSurfacePrelevement(new surfacePrelevement);
    connect(form,SIGNAL(elementValide(elementBase*)),((TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValide(elementBase*)),form,SLOT(accept()));
    form->exec();
}
