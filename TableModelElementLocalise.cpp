#include "TableModelElementLocalise.h"


TableModelElementLocalise::TableModelElementLocalise(BlocElementBase *bloc, QObject *parent) :
    TableModel(bloc,parent)
{
    this->bloc = (blocElementLocalise*)bloc;
    initHeaders(QStringList() << "Type" << "Valeur" << "Direction" << "Avant Gauche" << "Arrière Droit");

}

QVariant TableModelElementLocalise::data(const QModelIndex &index, int role) const
{

    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
         if (index.column() == Type)
        {
            return QVariant(bloc->GetElementLocalise(index.row())->GetType());
        }
        else if (index.column() == Valeur)
        {
             return QVariant(bloc->GetElementLocalise(index.row())->GetValeur()).toDouble();
        }
        else if (index.column() == Direction)
        {
             return QVariant(bloc->GetElementLocalise(index.row())->GetDirection());
        }
        else if (index.column() == AvantGauche)
        {
            QVariant var;
            var.setValue(bloc->GetElementLocalise(index.row())->GetAvantGauche());
            return var;
        }
        else if (index.column() == ArriereDroit)
        {
            QVariant var;
            var.setValue(bloc->GetElementLocalise(index.row())->GetArriereDroit());
            return var;
        }
        break;
    }

    return QVariant();
}

int TableModelElementLocalise::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 5;
}

bool TableModelElementLocalise::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        elementLocalise * elem = bloc->GetElementLocalise(index.row());

        if (index.column() == Type)
        {
            elem->SetType(value.toInt());
        }
        else if (index.column() == Valeur)
        {
            elem->SetValeur(value.toFloat());
        }
        else if (index.column() == Direction)
        {
            elem->SetDirection(value.toInt());
        }
        else if (index.column() == AvantGauche)
        {
            coordonnee c = value.value<coordonnee>();
            elem->SetAvantGauche(c);
        }
        else if (index.column() == ArriereDroit)
        {
            coordonnee c = value.value<coordonnee>();
            elem->SetArriereDroit(c);
        }

        bloc->setElement(index.row(),elem);
        emit dataChanged(index, index);
        return true;
        break;
    }

    return false;
}

