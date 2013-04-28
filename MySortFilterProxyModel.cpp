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
