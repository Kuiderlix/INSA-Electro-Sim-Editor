#include "TableModelCartoTempo.h"

TableModelCartoTempo::TableModelCartoTempo(BlocElementBase *bloc, QObject *parent) :
    TableModel(bloc,parent)
{
    this->bloc = (blocCartographieTemporelle*)bloc;
    initHeaders(QStringList() << "champ E" << "champ H" << "Iteration Debut" << "Iteration Fin" << "Intervalle" << "Avant Gauche" << "Arrière Droit");
    for (int i=0;i<15;i++)
    {
        cartographieTemporelle *metal = new cartographieTemporelle();
        bloc->addElement(metal);
    }
}

QVariant TableModelCartoTempo::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
         if (index.column() == champE)
        {
            return QVariant(bloc->GetCarto(index.row())->IsChampE());
        }
        else if (index.column() == champH)
        {
             return QVariant(bloc->GetCarto(index.row())->IsChampH());
        }
        else if (index.column() == iterationDebut)
        {
          return QVariant(bloc->GetCarto(index.row())->GetIterationDebut());
        }
        else if (index.column() == iterationFin)
        {
          return QVariant(bloc->GetCarto(index.row())->GetIterationDebut());
        }
        else if (index.column() == intervalle)
        {
          return QVariant(bloc->GetCarto(index.row())->GetIntervalle());
        }
        else if (index.column() == AvantGauche)
        {
            QVariant var;
            var.setValue(bloc->GetCarto(index.row())->GetAvantGauche());
            return var;
        }
        else if (index.column() == ArriereDroit)
        {
            QVariant var;
            var.setValue(bloc->GetCarto(index.row())->GetArriereDroit());
            return var;
        }
        break;
    }

    return QVariant();
}

int TableModelCartoTempo::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 7;
}

bool TableModelCartoTempo::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        cartographieTemporelle * elem = bloc->GetCarto(index.row());

        if (index.column() == champE)
        {
            elem->SetChampE(value.toBool());
        }
        else if (index.column() == champH)
        {
            elem->SetChampH(value.toBool());
        }
        else if (index.column() == iterationDebut)
        {
            elem->SetIterationDebut(value.toInt());
        }
        else if (index.column() == iterationFin)
        {
            elem->SetIterationFin(value.toInt());
        }
        else if (index.column() == intervalle)
        {
            elem->SetIntervalle(value.toInt());
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
