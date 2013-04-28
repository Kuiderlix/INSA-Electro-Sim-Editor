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

void TableViewParallelepipede::addNewMetallisation()
{
    FormParallelepipede * form = new FormParallelepipede(new parallelepipede,FormParallelepipede::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}
