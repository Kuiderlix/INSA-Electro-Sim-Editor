#include "TableMetallisation.h"

TableMetallisation::TableMetallisation(QWidget *parent) :
    QTableWidget(parent)
{

    this->setColumnCount(3);
    this->setRowCount(10);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setHorizontalHeaderLabels(QStringList() << "conductivité" << "coordonnees" << "coordonnees");
}
