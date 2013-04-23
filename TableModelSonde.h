#ifndef TABLEMODELSONDE_H
#define TABLEMODELSONDE_H

#include "TableModel.h"
#include "blocSonde.h"

class TableModelSonde : public TableModel
{
    Q_OBJECT
public:
    enum Columns {ex=0, ey=1, ez = 2, hx = 3, hy = 4, hz=5,
                  PointAppli = 6, ValCentre = 7, AvantGauche = 8, ArriereDroit = 9};
    TableModelSonde(BlocElementBase* bloc, QObject *parent = 0);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    
signals:
    
public slots:
private:
    blocSonde* bloc;
    
};

#endif // TABLEMODELSONDE_H
