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

void TableViewSonde::addNewMetallisation()
{
    FormSonde * form = new FormSonde(new sonde,FormSonde::NOUVEAU);
    connect(form,SIGNAL(elementValide(elementBase*)),((TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValide(elementBase*)),form,SLOT(accept()));
    form->exec();
}
