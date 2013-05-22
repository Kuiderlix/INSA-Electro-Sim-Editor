#include "TableViewSonde.h"

TableViewSonde::TableViewSonde(blocSonde *bloc, QWidget *parent) :
    TableView(parent)
{
    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelSonde(bloc));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelSonde::ArriereDroit,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelSonde::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelSonde::PointAppli,new CoordonneeDelegate());
}

void TableViewSonde::addNewElement()
{
    FormSonde * form = new FormSonde(new sonde);
    connect(form,SIGNAL(elementValide(elementBase*)),((TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValide(elementBase*)),form,SLOT(accept()));
    form->exec();
}
