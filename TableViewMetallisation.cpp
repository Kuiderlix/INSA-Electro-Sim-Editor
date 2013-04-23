#include "TableViewMetallisation.h"

TableViewMetallisation::TableViewMetallisation(blocMetallisation *blocMetal, QWidget *parent) :
    TableView(parent)
{
    table = new TableMetallisationModel(blocMetal);
    this->setModel(table);
    this->setItemDelegateForColumn(1,new CoordonneeDelegate());
    this->setItemDelegateForColumn(2,new CoordonneeDelegate());
}



/**
 * @brief TableViewMetallisation::addNewMetallisation
 *Créer un nouvel objet metallisation et ouvre la fenetre d'edition de l'objet
 */
void TableViewMetallisation::addNewMetallisation()
{
    FormMetallisation * form = new FormMetallisation(new metallisation,FormMetallisation::NOUVEAU);
    connect(form,SIGNAL(elementValidee(elementBase*)),table,SLOT(addElement(elementBase*)));
    form->exec();
}

