#ifndef TABLEMODELCARTOTEMPO_H
#define TABLEMODELCARTOTEMPO_H

#include "TableModel.h"
#include "blocCartographieTemporelle.h"


class TableModelCartoTempo : public TableModel
{
public:
    enum Columns {champE=0, champH=1, iterationDebut = 2, iterationFin = 3, intervalle=4, AvantGauche = 5, ArriereDroit = 6};

    explicit TableModelCartoTempo(BlocElementBase *bloc , QObject *parent = 0);


    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:

    blocCartographieTemporelle * bloc;
};

#endif // TABLEMODELCARTOTEMPO_H
