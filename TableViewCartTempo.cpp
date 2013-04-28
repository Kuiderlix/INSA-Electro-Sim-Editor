#include "TableViewCartTempo.h"

TableViewCartTempo::TableViewCartTempo(blocCartographieTemporelle *bloc,QWidget *parent) :
    TableView(parent)
{
    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelCartoTempo(bloc));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelCartoTempo::AvantGauche,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelCartoTempo::ArriereDroit,new CoordonneeDelegate());
    this->resizeColumnToContents(TableModelCartoTempo::AvantGauche);
}

void TableViewCartTempo::addNewMetallisation()
{
    FormCartographieTemporelle * form = new FormCartographieTemporelle(new cartographieTemporelle,FormCartographieTemporelle::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}
