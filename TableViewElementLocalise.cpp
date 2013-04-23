#include "TableViewElementLocalise.h"

TableViewElementLocalise::TableViewElementLocalise(blocElementLocalise *bloc, QWidget *parent) :
    TableView(parent)
{
    this->setModel(new TableModelElementLocalise(bloc));

    this->setItemDelegateForColumn(TableModelElementLocalise::Type,new ComboxDecaleeDelegate(QStringList() << "Résistance" << "Capacité" << "Self"));
    this->setItemDelegateForColumn(TableModelElementLocalise::Direction,new ComboxDecaleeDelegate(QStringList() << "x" << "y" << "z"));
    this->setItemDelegateForColumn(TableModelElementLocalise::ArriereDroit,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelElementLocalise::AvantGauche,new CoordonneeDelegate());
}

void TableViewElementLocalise::addNewMetallisation()
{
    FormElementLocalise * form = new FormElementLocalise(new elementLocalise,FormElementLocalise::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}
