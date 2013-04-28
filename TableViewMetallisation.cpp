#include "TableViewMetallisation.h"

TableViewMetallisation::TableViewMetallisation(blocMetallisation *blocMetal, QWidget *parent) :
    TableView(parent)
{
    MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
    proxyModel->setSourceModel(new TableModelMetallisation(blocMetal));
    this->setModel(proxyModel);
    this->setItemDelegateForColumn(TableModelMetallisation::Coord1,new CoordonneeDelegate());
    this->setItemDelegateForColumn(TableModelMetallisation::Coord2,new CoordonneeDelegate());
}



/**
 * @brief TableViewMetallisation::addNewMetallisation
 *Créer un nouvel objet metallisation et ouvre la fenetre d'edition de l'objet
 */
void TableViewMetallisation::addNewMetallisation()
{
    FormMetallisation * form = new FormMetallisation(new metallisation,FormMetallisation::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),((TableModel*)this->model()),SLOT(addElement(elementBase*)));
    connect(form,SIGNAL(elementValidee(elementBase*)),form,SLOT(accept()));
    form->exec();
}

