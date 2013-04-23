#ifndef TABLEMODELPORTEXCITATION_H
#define TABLEMODELPORTEXCITATION_H

#include "TableModel.h"
#include "blocPortExcitation.h"

class TableModelPortExcitation : public TableModel
{
public:

    enum Columns {portActif=0, portInfinitesimal=1, type = 2, direction = 3, impedance = 4, typeSource=5,
                  ponderationAmplitude = 6, ponderationPhase = 7, AvantGauche = 8, ArriereDroit = 9};

    explicit TableModelPortExcitation(BlocElementBase *bloc , QObject *parent = 0);


    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:

    blocPortExcitation * bloc;
};

#endif // TABLEMODELPORTEXCITATION_H
