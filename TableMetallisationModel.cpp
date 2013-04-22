#include "TableMetallisationModel.h"

TableMetallisationModel::TableMetallisationModel(blocMetallisation *bloc, QWidget *parent) :
    QAbstractTableModel(parent)
{
    listeMetallisation = bloc;

    for (int i=0;i<15;i++)
    {
        metallisation *metal = new metallisation();
        listeMetallisation->addMetallisation(metal);
    }

}
Qt::ItemFlags TableMetallisationModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

int TableMetallisationModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : listeMetallisation->GetNbMetallisation();
}

int TableMetallisationModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;
}

QVariant TableMetallisationModel::data(const QModelIndex &index, int role) const
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
            QVariant var(listeMetallisation->GetMetallisation(index.row())->GetConductivite());
            return var;
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
    if (!index.isValid() || index.row() < 0 || index.row() >= listeMetallisation->GetNbMetallisation())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == Conductivite)
        {
            metallisation * met = listeMetallisation->GetMetallisation(index.row());
            met->SetConductivite(value.toFloat());
            listeMetallisation->setMetallisation(index.row(),met);
        }
        else if (index.column() == Coord1)
        {
            metallisation * met = listeMetallisation->GetMetallisation(index.row());
            coordonnee c = value.value<coordonnee>();
            met->SetArriereDroit(c);
            listeMetallisation->setMetallisation(index.row(),met);
        }
        else if (index.column() == Coord2)
        {
            metallisation * met = listeMetallisation->GetMetallisation(index.row());
            coordonnee c = value.value<coordonnee>();
            met->SetAvantGauche(c);
            listeMetallisation->setMetallisation(index.row(),met);
        }
        emit dataChanged(index, index);
        return true;
        break;
    }

    return false;
}

void TableMetallisationModel::addElement(metallisation *element)
{
    const int count = listeMetallisation->GetNbMetallisation();
    beginInsertRows(QModelIndex(), count, count);
    listeMetallisation->addMetallisation(element);
    endInsertRows();
    qDebug() << "ajout : " << listeMetallisation->GetNbMetallisation();
}

void TableMetallisationModel::removeElement(int i)
{
    beginRemoveRows(QModelIndex(),i,i);
    listeMetallisation->removeMetallisation(i);
    endRemoveRows();

}
