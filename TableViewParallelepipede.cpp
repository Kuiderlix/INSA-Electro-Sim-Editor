#include "TableViewParallelepipede.h"

TableViewParallelepipede::TableViewParallelepipede(blocParallelepipede *blocParal, QWidget *parent) :
    TableView(parent)
{
    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelParallelepipede(blocParal));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelParallelepipede::Coord1,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelParallelepipede::Coord2,new CoordonneeDelegate());
}

void TableViewParallelepipede::addNewElement()
{
    FormParallelepipede * form = new FormParallelepipede(new parallelepipede);
    connect(form,SIGNAL(elementValide(elementBase*)),((TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValide(elementBase*)),form,SLOT(accept()));
    form->exec();
}
