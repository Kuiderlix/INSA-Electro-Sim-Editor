#ifndef TABLEMETALLISATION_H
#define TABLEMETALLISATION_H

#include <QtWidgets>
#include "blocMetallisation.h"

class TableMetallisationModel : public QAbstractTableModel
{
    Q_OBJECT
    enum Columns { Conductivite = 0, Coord1 = 1, Coord2 = 2};
public:
    explicit TableMetallisationModel(blocMetallisation * bloc , QWidget *parent = 0);
    int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);


    blocMetallisation* getMetallisations()
    {
        return listeMetallisation;
    }

signals:
    
public slots:
    void addElement(metallisation *element);
    void removeElement(int i);
private:
    blocMetallisation* listeMetallisation;
    
};

#endif // TABLEMETALLISATION_H
