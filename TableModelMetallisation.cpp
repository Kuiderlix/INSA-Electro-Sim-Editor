#include "TableModelMetallisation.h"

TableModelMetallisation::TableModelMetallisation(BlocElementBase *bloc, QObject *parent) :
    TableModel(bloc,parent)
{
    listeMetal = (blocMetallisation*)bloc;
    initHeaders(QStringList() << "Conductivité" << "Avant Gauche" << "Arrière Droit");

}


int TableModelMetallisation::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;
}

QVariant TableModelMetallisation::data(const QModelIndex &index, int role) const
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
            return var.toDouble();
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

bool TableModelMetallisation::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= listeMetal->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        metallisation * met = listeMetal->GetMetallisation(index.row());
        if (index.column() == Conductivite)
        {
            met->SetConductivite(value.toFloat());
        }
        else if (index.column() == Coord1)
        {
            coordonnee c = value.value<coordonnee>();
            met->SetArriereDroit(c);
        }
        else if (index.column() == Coord2)
        {
            coordonnee c = value.value<coordonnee>();
            met->SetAvantGauche(c);
        }
        listeMetal->setElement(index.row(),met);
        emit dataChanged(index, index);
        return true;
        break;
    }

    return false;
}


