#include "TableViewPortExcitation.h"

TableViewPortExcitation::TableViewPortExcitation(blocPortExcitation *bloc,QWidget *parent) :
    TableView(parent)
{
    this->setModel(new TableModelPortExcitation(bloc));
    this->setItemDelegateForColumn(TableModelPortExcitation::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelPortExcitation::ArriereDroit,new CoordonneeDelegate());

    this->setItemDelegateForColumn(TableModelPortExcitation::type,new ComboxDecaleeDelegate(QStringList() << "Magnétique" << "Electrique"));
    this->setItemDelegateForColumn(TableModelPortExcitation::direction,new ComboxDecaleeDelegate(QStringList() << "x" << "y" << "z"));
    this->setItemDelegateForColumn(TableModelPortExcitation::typeSource,new ComboxDecaleeDelegate(QStringList() << "Tension" << "Courant"));
}

void TableViewPortExcitation::addNewMetallisation()
{
    FormPortExcitation * form = new FormPortExcitation(new portExcitation,FormPortExcitation::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}
