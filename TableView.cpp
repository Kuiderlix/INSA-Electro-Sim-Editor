#include "TableView.h"

TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);

}
void TableView::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu;
    menu.addAction("Nouveau...",this,SLOT(addNewMetallisation()));
    menu.addAction("Supprimer",this,SLOT(deleteMetallisation()));

    menu.exec(e->globalPos());
}

void TableView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        deleteMetallisation();
    }
}

/**
 * @brief TableViewMetallisation::selectedIndexes
 * Retourne la liste des lignes séléctionnés et trié sur le numéro de ligne
 * @return
 */
QModelIndexList TableView::selectedIndexes() const
{
    QModelIndexList list = this->QTableView::selectedIndexes();
    QModelIndexList::Iterator it = list.begin();
    int row = -1;
    for (;it!=list.end();)
    {
        if (row == (*it).row())
        {
            it = list.erase(it);
        }
        else
        {
            row = (*it).row();
            it++;
        }
    }
    qSort(list.begin(),list.end());
    return list;
}

void TableView::addNewMetallisation()
{
}


/**
 * @brief TableViewMetallisation::deleteMetallisation
 *Supprime les éléments séléctionnés
 */
void TableView::deleteMetallisation()
{
    QModelIndexList list = this->selectedIndexes();
    QModelIndexList::Iterator it = list.begin();
    for (int i=0;it!=list.end();it++,i++)
    {
        table->removeElement((*it).row()-i);
    }
}
