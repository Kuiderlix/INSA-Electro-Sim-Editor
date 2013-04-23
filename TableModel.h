#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include "BlocElementBase.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(BlocElementBase *bloc , QObject *parent = 0);


    int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    void initHeaders(QStringList l);
    
signals:

public slots:
    void addElement(elementBase *element);
    void removeElement(int i);

private:
    BlocElementBase * listeElement;
    QStringList headers;
    
};

#endif // TABLEMODEL_H
