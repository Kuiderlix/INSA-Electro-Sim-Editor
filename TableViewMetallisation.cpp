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
    menu.addAction("Nouveau...",this,SLOT(addNewMetallisation()));
    menu.addAction("Editer...",this,SLOT(editMetallisation()));
    menu.addAction("Supprimer",this,SLOT(deleteMetallisation()));

    menu.exec(e->globalPos());
}

void TableViewMetallisation::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        deleteMetallisation();
    }
}

QModelIndexList TableViewMetallisation::selectedIndexes() const
{
    QModelIndexList list = this->QTableView::selectedIndexes();
    QModelIndexList::Iterator it = list.begin();
    for (;it!=list.end();it++)
    {
        //effacer les item en trop
    }
    return list;
}

void TableViewMetallisation::addNewMetallisation()
{
    FormMetallisation * form = new FormMetallisation(new metallisation,FormMetallisation::NOUVEAU);
    connect(form,SIGNAL(metallisationValider(metallisation*)),tableMeta,SLOT(addElement(metallisation*)));
    form->exec();
}

void TableViewMetallisation::editMetallisation()
{
    QModelIndexList list = this->selectedIndexes();
    for (int i=0;i<list.count()/tableMeta->columnCount();i++)
    {
        metallisation * metal = tableMeta->getMetallisations()->GetMetallisation(list.at(i*tableMeta->columnCount()).row());
        FormMetallisation * form = new FormMetallisation(metal,FormMetallisation::MODIFIER);
        form->show();
    }
}

void TableViewMetallisation::deleteMetallisation()
{
    QModelIndexList list = this->selectedIndexes();
    qDebug() << list.count();
    QModelIndexList::Iterator it = list.begin();
    for (;it!=list.end();it++)
    {
        tableMeta->removeElement((*it).row());
    }

}

