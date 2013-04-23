#ifndef TABLEMODELELEMENTLOCALISE_H
#define TABLEMODELELEMENTLOCALISE_H

#include "TableModel.h"
#include "blocElementLocalise.h"

class TableModelElementLocalise : public TableModel
{
    Q_OBJECT
public:
    enum Columns { Type = 0, Valeur = 1, Direction = 2, AvantGauche = 3, ArriereDroit = 4};

    explicit TableModelElementLocalise(BlocElementBase *bloc , QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:

    blocElementLocalise * bloc;
};

#endif // TABLEMODELELEMENTLOCALISE_H
