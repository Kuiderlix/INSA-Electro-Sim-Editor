#include "TableModel.h"

TableModel::TableModel(BlocElementBase *bloc, QObject *parent) :
    QAbstractTableModel(parent)
{
    listeElement=bloc;
}


Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : listeElement->getNbElement();
}
void TableModel::addElement(elementBase *element)
{
    const int count = listeElement->getNbElement();
    beginInsertRows(QModelIndex(), count, count);
    listeElement->addElement(element);
    endInsertRows();
}

void TableModel::removeElement(int i)
{
    beginRemoveRows(QModelIndex(),i,i);
    listeElement->removeElement(i);
    endRemoveRows();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return headers.at(section);
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

void TableModel::initHeaders(const QStringList l)
{
    headers=l;
}

