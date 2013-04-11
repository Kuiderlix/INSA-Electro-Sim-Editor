#include "TableMetallisation.h"

TableMetallisation::TableMetallisation(blocMetallisation *bloc, QWidget *parent) :
    QAbstractTableModel(parent)
{
    listeMetallisation = bloc;

    for (int i=0;i<15;i++)
    {
        metallisation *metal = new metallisation();
        listeMetallisation->addMetallisation(metal);
    }

}
Qt::ItemFlags TableMetallisation::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable;
}

int TableMetallisation::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : listeMetallisation->GetNbMetallisation();
}

int TableMetallisation::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;
}

QVariant TableMetallisation::data(const QModelIndex &index, int role) const
{

    if (!index.isValid() || index.row() < 0 || index.row() >= listeMetallisation->GetNbMetallisation())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == Conductivite)
        {
            return listeMetallisation->GetMetallisation(index.row())->GetConductivite();
        }
        else if (index.column() == Coord1)
        {
            QVariant var;
            var.setValue(listeMetallisation->GetMetallisation(index.row())->GetArriereDroit());
            return var;
        }
        else if (index.column() == Coord2)
        {
            QVariant var;
            var.setValue(listeMetallisation->GetMetallisation(index.row())->GetAvantGauche());
            return var;
        }
        break;
    }

    return QVariant();
}

QVariant TableMetallisation::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        {
            switch (section)
            {
            case Conductivite:
                return trUtf8("Conductivité");
                break;
            case Coord1:
                return trUtf8("Arrière Droit");
                break;
            case Coord2:
                return trUtf8("Avant Gauche");
                break;
            }
        }

        return QAbstractTableModel::headerData(section, orientation, role);
}
