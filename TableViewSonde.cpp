#include "TableViewSonde.h"

TableViewSonde::TableViewSonde(blocSonde *bloc, QWidget *parent) :
    TableView(parent)
{
    this->setModel(new TableModelSonde(bloc));
    this->setItemDelegateForColumn(TableModelSonde::ArriereDroit,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelSonde::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelSonde::PointAppli,new CoordonneeDelegate());
}

void TableViewSonde::addNewMetallisation()
{
    FormSonde * form = new FormSonde(new sonde,FormSonde::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}
