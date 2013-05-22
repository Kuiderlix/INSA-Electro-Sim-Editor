#include "TableViewElementLocalise.h"

TableViewElementLocalise::TableViewElementLocalise(blocElementLocalise *bloc, QWidget *parent) :
    TableView(parent)
{

    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelElementLocalise(bloc));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelElementLocalise::Type,new ComboxDecaleeDelegate(QStringList() << "Résistance" << "Capacité" << "Self",1));
    this->setItemDelegateForColumn(TableModelElementLocalise::Direction,new ComboxDecaleeDelegate(QStringList() << "x" << "y" << "z",1));
    this->setItemDelegateForColumn(TableModelElementLocalise::ArriereDroit,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelElementLocalise::AvantGauche,new CoordonneeDelegate());
}

void TableViewElementLocalise::addNewElement()
{
    FormElementLocalise * form = new FormElementLocalise(new elementLocalise);
    connect(form,SIGNAL(elementValide(elementBase*)),((TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValide(elementBase*)),form,SLOT(accept()));
    form->exec();
}
