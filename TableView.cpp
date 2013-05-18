#include "TableView.h"

TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setSortingEnabled(true);



}
void TableView::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu;
    menu.addAction("Nouveau...",this,SLOT(addNewElement()));
    menu.addAction("Supprimer",this,SLOT(deleteElement()));
    menu.addAction("Editer couleur",this,SLOT(editColor()));

    menu.exec(e->globalPos());
}

void TableView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        deleteElement();
    }
}

/**
 * @brief TableView::selectedIndexes
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

void TableView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QTableView::selectionChanged(selected,deselected);


    //on change la couleur des éléments selectionnés
    QModelIndexList list = selected.indexes();
    QModelIndexList::Iterator it = list.begin();
    for (int i=0;it!=list.end();it++,i++)
    {
        elementBase * elem = getSourceModel()->getElement((*it).row());
        elem->invertColor();
    }

    // on restaure la couleur original des éléments désélectionnés
    list = deselected.indexes();
    it = list.begin();
    for (int i=0;it!=list.end();it++,i++)
    {
        elementBase * elem = getSourceModel()->getElement((*it).row());
        elem->invertColor();
    }
}

TableModel *TableView::getSourceModel()
{
    return (TableModel*)((MySortFilterProxyModel*)this->model())->sourceModel();
}

void TableView::addElement(elementBase * e)
{
    getSourceModel()->addElement(e);
}

void TableView::addNewElement()
{
}


/**
 * @brief TableView::deleteMetallisation
 *Supprime les éléments séléctionnés
 */
void TableView::deleteElement()
{
    QModelIndexList list = this->selectedIndexes();
    QModelIndexList::Iterator it = list.begin();
    for (int i=0;it!=list.end();it++,i++)
    {
        getSourceModel()->removeElement((*it).row()-i);
    }
}

void TableView::editColor()
{
    QModelIndexList list = this->selectedIndexes();
    QModelIndexList::Iterator it = list.begin();

    elementBase* elemPrem = this->getSourceModel()->getElement((*it).row());
    QColorDialog dial(elemPrem->getInvertColor(),this);

    dial.setOptions(QColorDialog::ShowAlphaChannel);

    int res = dial.exec();

    if (res==QDialog::Accepted)
    {
        QColor newCouleur = dial.selectedColor();
        for (;it!=list.end();it++)
        {
            this->getSourceModel()->getElement((*it).row())->setCouleur(newCouleur);
            this->getSourceModel()->getElement((*it).row())->invertColor();
        }
    }
}
