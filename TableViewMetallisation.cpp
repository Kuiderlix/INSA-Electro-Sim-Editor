#include "TableViewMetallisation.h"

TableViewMetallisation::TableViewMetallisation(blocMetallisation *blocMetal, QWidget *parent) :
    QTableView(parent)
{
    tableMeta = new TableMetallisationModel(blocMetal);
    this->setItemDelegateForColumn(1,new CoordonneeDelegate());
    this->setItemDelegateForColumn(2,new CoordonneeDelegate());
    this->setModel(tableMeta);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

void TableViewMetallisation::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu;
    menu.addAction("Editer");
    menu.addAction("Supprimer");

    menu.exec(e->globalPos());
}

