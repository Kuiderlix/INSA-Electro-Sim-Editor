#include "MySortFilterProxyModel.h"

MySortFilterProxyModel::MySortFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

bool MySortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left);
    QVariant rightData = sourceModel()->data(right);

    if (leftData.type()==QVariant::UserType)
    {
        coordonnee leftCoord = leftData.value<coordonnee>();
        coordonnee rightCoord = rightData.value<coordonnee>();
        return QString::localeAwareCompare(leftCoord.toQString(), rightCoord.toQString()) < 0;
    }
    else
    {
        return this->QSortFilterProxyModel::lessThan(left,right);
    }
}

void MySortFilterProxyModel::setFilterKeyColumn(int column)
{
    QSortFilterProxyModel::setFilterKeyColumn(column);
}

bool MySortFilterProxyModel::filterAcceptsRow(int sourceRow,
        const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, filterKeyColumn(), sourceParent);

    if (index.data().type()==QVariant::UserType)
    {
        coordonnee coord = index.data().value<coordonnee>();
        return coord.toQString().contains(filterRegExp());
    }
    else
    {
        return QSortFilterProxyModel::filterAcceptsRow(sourceRow,sourceParent);
    }
}
