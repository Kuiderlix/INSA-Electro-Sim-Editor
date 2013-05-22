#include "TableViewPortExcitation.h"

TableViewPortExcitation::TableViewPortExcitation(blocPortExcitation *bloc,QWidget *parent) :
    TableView(parent)
{
    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelPortExcitation(bloc));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelPortExcitation::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelPortExcitation::ArriereDroit,new CoordonneeDelegate());

    this->setItemDelegateForColumn(TableModelPortExcitation::type,new ComboxDecaleeDelegate(QStringList() << "Magnétique" << "Electrique"));
    this->setItemDelegateForColumn(TableModelPortExcitation::direction,new ComboxDecaleeDelegate(QStringList() << "x" << "y" << "z"));
    this->setItemDelegateForColumn(TableModelPortExcitation::typeSource,new ComboxDecaleeDelegate(QStringList() << "Tension" << "Courant"));
}

void TableViewPortExcitation::addNewElement()
{
    FormPortExcitation * form = new FormPortExcitation(new portExcitation);
    connect(form,SIGNAL(elementValide(elementBase*)),((TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValide(elementBase*)),form,SLOT(accept()));
    form->exec();
}
