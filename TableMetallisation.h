#ifndef TABLEMETALLISATION_H
#define TABLEMETALLISATION_H

#include <QtWidgets>
#include "blocMetallisation.h"

class TableMetallisation : public QAbstractTableModel
{
    Q_OBJECT
    enum Columns { Conductivite = 0, Coord1 = 1, Coord2 = 2};
public:
    explicit TableMetallisation(blocMetallisation * bloc , QWidget *parent = 0);
    int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:
    
public slots:
private:
    blocMetallisation* listeMetallisation;
    
};

#endif // TABLEMETALLISATION_H
