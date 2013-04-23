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

/**
 * @brief TableViewMetallisation::selectedIndexes
 * Retourne la liste des lignes séléctionnés et trié sur le numéro de ligne
 * @return
 */
QModelIndexList TableViewMetallisation::selectedIndexes() const
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
/**
 * @brief TableViewMetallisation::addNewMetallisation
 *Créer un nouvel objet metallisation et ouvre la fenetre d'edition de l'objet
 */
void TableViewMetallisation::addNewMetallisation()
{
    FormMetallisation * form = new FormMetallisation(new metallisation,FormMetallisation::NOUVEAU);
    connect(form,SIGNAL(metallisationValider(metallisation*)),tableMeta,SLOT(addElement(metallisation*)));
    form->exec();
}

void TableViewMetallisation::editMetallisation()
{
    QModelIndexList list = this->selectedIndexes();
    metallisation * metal = tableMeta->getMetallisations()->GetMetallisation(list.at(0).row());
    FormMetallisation * form = new FormMetallisation(metal,FormMetallisation::MODIFIER);
    form->show();
}
/**
 * @brief TableViewMetallisation::deleteMetallisation
 *Supprime les éléments séléctionnés
 */
void TableViewMetallisation::deleteMetallisation()
{
    QModelIndexList list = this->selectedIndexes();
    QModelIndexList::Iterator it = list.begin();
    for (int i=0;it!=list.end();it++,i++)
    {
        tableMeta->removeElement((*it).row()-i);
    }
}

