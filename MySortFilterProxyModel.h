#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "coordonnee.h"

class MySortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit MySortFilterProxyModel(QObject *parent = 0);

    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    
signals:
    
public slots:
    
};

#endif // MYSORTFILTERPROXYMODEL_H
