#ifndef TABLEMETALLISATION_H
#define TABLEMETALLISATION_H

#include "blocMetallisation.h"
#include "TableModel.h"

class TableModelMetallisation : public TableModel
{
    Q_OBJECT
    enum Columns { Conductivite = 0, Coord1 = 1, Coord2 = 2};
public:
    explicit TableModelMetallisation(BlocElementBase *bloc , QObject *parent = 0);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:

private:

    blocMetallisation * listeMetal;
    
};

#endif // TABLEMETALLISATION_H
