#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "coordonnee.h"

/**
 * @brief Cette classe permet de personnalisé le tri et le filtrage dans les listes
 */
class MySortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit MySortFilterProxyModel(QObject *parent = 0);

    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
    
signals:
    
public slots:

    void setFilterKeyColumn(int column);
    
};

#endif // MYSORTFILTERPROXYMODEL_H
