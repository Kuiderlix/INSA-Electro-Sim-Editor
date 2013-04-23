#include "TableMetallisationModel.h"

TableMetallisationModel::TableMetallisationModel(BlocElementBase *bloc, QWidget *parent) :
    TableModel(bloc,parent)
{
    listeMetal = (blocMetallisation*)bloc;
    for (int i=0;i<15;i++)
    {
        metallisation *metal = new metallisation();
        listeMetal->addElement(metal);
    }

}


int TableMetallisationModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;
}

QVariant TableMetallisationModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid() || index.row() < 0 || index.row() >= listeMetal->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == Conductivite)
        {
            QVariant var(listeMetal->GetMetallisation(index.row())->GetConductivite());
            return var;
        }
        else if (index.column() == Coord1)
        {
            QVariant var;
            var.setValue(listeMetal->GetMetallisation(index.row())->GetArriereDroit());
            return var;
        }
        else if (index.column() == Coord2)
        {
            QVariant var;
            var.setValue(listeMetal->GetMetallisation(index.row())->GetAvantGauche());
            return var;
        }
        break;
    }

    return QVariant();
}

QVariant TableMetallisationModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool TableMetallisationModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= listeMetal->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == Conductivite)
        {
            metallisation * met = listeMetal->GetMetallisation(index.row());
            met->SetConductivite(value.toFloat());
            listeMetal->setElement(index.row(),met);
        }
        else if (index.column() == Coord1)
        {
            metallisation * met = listeMetal->GetMetallisation(index.row());
            coordonnee c = value.value<coordonnee>();
            met->SetArriereDroit(c);
            listeMetal->setElement(index.row(),met);
        }
        else if (index.column() == Coord2)
        {
            metallisation * met = listeMetal->GetMetallisation(index.row());
            coordonnee c = value.value<coordonnee>();
            met->SetAvantGauche(c);
            listeMetal->setElement(index.row(),met);
        }
        emit dataChanged(index, index);
        return true;
        break;
    }

    return false;
}


