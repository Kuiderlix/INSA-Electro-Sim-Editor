#include "TableMetallisation.h"

TableMetallisation::TableMetallisation(blocMetallisation *bloc, QWidget *parent) :
    QTableWidget(parent)
{
    listeMetallisation = bloc;
    this->setColumnCount(3);
    this->setRowCount(10);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setHorizontalHeaderLabels(QStringList() << "conductivité" << "coordonnees" << "coordonnees");
    setEditTriggers(QAbstractItemView::NoEditTriggers);


}
