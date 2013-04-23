#include "TableViewParallelepipede.h"

TableViewParallelepipede::TableViewParallelepipede(blocParallelepipede *blocParal, QWidget *parent) :
    TableView(parent)
{
    this->setModel(new TableModelParallelepipede(blocParal));
    this->setItemDelegateForColumn(3,new CoordonneeDelegate());
    this->setItemDelegateForColumn(4,new CoordonneeDelegate());
}

void TableViewParallelepipede::addNewMetallisation()
{
    FormParallelepipede * form = new FormParallelepipede(new parallelepipede,FormParallelepipede::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    form->exec();
}
