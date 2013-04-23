#ifndef TABLEMODELPARALLELEPIPEDE_H
#define TABLEMODELPARALLELEPIPEDE_H

#include "TableModel.h"
#include "blocParallelepipede.h"

class TableModelParallelepipede : public TableModel
{
    Q_OBJECT
    enum Columns {PermitRelative=0, PermeRelative=1, Conductivite = 2, Coord1 = 3, Coord2 = 4};
public:
    TableModelParallelepipede(BlocElementBase *bloc , QObject *parent = 0);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:

private:

    blocParallelepipede * bloc;
};

#endif // TABLEMODELPARALLELEPIPEDE_H
