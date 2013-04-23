#include "TableModelParallelepipede.h"

TableModelParallelepipede::TableModelParallelepipede(BlocElementBase *bloc , QObject *parent)
    :TableModel(bloc,parent)
{
    this->bloc = (blocParallelepipede*)bloc;
    initHeaders(QStringList() << "PermitRelative" << "PermeRelative" << "Conductivité" << "Avant Gauche" << "Arrière Droit");
    for (int i=0;i<15;i++)
    {
        parallelepipede *metal = new parallelepipede();
        bloc->addElement(metal);
    }
}

QVariant TableModelParallelepipede::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == PermitRelative)
        {
            QVariant var(bloc->getParallelepipede(index.row())->GetPermitRelative());
            return var;
        }
        else if (index.column() == PermeRelative)
        {
            QVariant var(bloc->getParallelepipede(index.row())->GetPermeRelative());
            return var;
        }
        else if (index.column() == Conductivite)
        {
            QVariant var(bloc->getParallelepipede(index.row())->GetConductivite());
            return var;
        }
        else if (index.column() == Coord1)
        {
            QVariant var;
            var.setValue(bloc->getParallelepipede(index.row())->GetArriereDroit());
            return var;
        }
        else if (index.column() == Coord2)
        {
            QVariant var;
            var.setValue(bloc->getParallelepipede(index.row())->GetAvantGauche());
            return var;
        }
        break;
    }

    return QVariant();
}

int TableModelParallelepipede::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 5;
}

bool TableModelParallelepipede::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        parallelepipede * elem = bloc->getParallelepipede(index.row());
        if (index.column() == PermitRelative)
        {
            elem->SetPermitRelative(value.toFloat());
        }
        else if (index.column() == PermeRelative)
        {
            elem->SetPermeRelative(value.toFloat());
        }
        else if (index.column() == Conductivite)
        {
            elem->SetConductivite(value.toFloat());
        }
        else if (index.column() == Coord1)
        {
            coordonnee c = value.value<coordonnee>();
            elem->SetArriereDroit(c);
        }
        else if (index.column() == Coord2)
        {
            coordonnee c = value.value<coordonnee>();
            elem->SetAvantGauche(c);
        }
        bloc->setElement(index.row(),elem);
        emit dataChanged(index, index);
        return true;
        break;
    }

    return false;
}

