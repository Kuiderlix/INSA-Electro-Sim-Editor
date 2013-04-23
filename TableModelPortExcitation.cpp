#include "TableModelPortExcitation.h"

TableModelPortExcitation::TableModelPortExcitation(BlocElementBase *bloc , QObject *parent) :
    TableModel(bloc,parent)
{
    this->bloc = (blocPortExcitation*)bloc;
    initHeaders(QStringList() << "Port Actif" << "Port Infinitesimal" << "Type" << "Direction" << "Impédance" << "Type Source" << "Ponderation Amplitude" << "Ponderation Phase" << "Avant Gauche" << "Arrière Droit");
    for (int i=0;i<15;i++)
    {
        portExcitation *metal = new portExcitation();
        bloc->addElement(metal);
    }
}

QVariant TableModelPortExcitation::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == portActif)
        {
            return QVariant(bloc->GetPortExcitation(index.row())->IsPortActif());
        }
        else if (index.column() == portInfinitesimal)
        {
             return QVariant(bloc->GetPortExcitation(index.row())->IsPortInfinitesimal());
        }
        else if (index.column() == type)
        {
             return QVariant(bloc->GetPortExcitation(index.row())->GetTypePort());
        }
        else if (index.column() == direction)
        {
          return QVariant(bloc->GetPortExcitation(index.row())->GetDirection());
        }
        else if (index.column() == impedance)
        {
          return QVariant(bloc->GetPortExcitation(index.row())->GetImpedance());
        }
        else if (index.column() == typeSource)
        {
          return QVariant(bloc->GetPortExcitation(index.row())->GetTypeSource());
        }
        else if (index.column() == ponderationAmplitude)
        {
        return QVariant(bloc->GetPortExcitation(index.row())->GetPonderationAmplitude());
        }
        else if (index.column() == ponderationPhase)
        {
        return QVariant(bloc->GetPortExcitation(index.row())->GetPonderationPhase());
        }
        else if (index.column() == AvantGauche)
        {
            QVariant var;
            var.setValue(bloc->GetPortExcitation(index.row())->GetAvantGauche());
            return var;
        }
        else if (index.column() == ArriereDroit)
        {
            QVariant var;
            var.setValue(bloc->GetPortExcitation(index.row())->GetArriereDroit());
            return var;
        }
        break;
    }

    return QVariant();
}

int TableModelPortExcitation::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 10;
}

bool TableModelPortExcitation::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        portExcitation * elem = bloc->GetPortExcitation(index.row());


       if (index.column() == portActif)
       {
            elem->SetPortActif(value.toBool());
       }
       else if (index.column() == portInfinitesimal)
       {
           elem->SetPortInfinitesimal(value.toBool());
       }
       else if (index.column() == type)
       {
           elem->SetTypePort(value.toInt());
       }
       else if (index.column() == direction)
       {
           elem->SetDirection(value.toInt());
       }
       else if (index.column() == impedance)
       {
           elem->SetImpedance(value.toFloat());
       }
       else if (index.column() == typeSource)
       {
           elem->SetTypeSource(value.toInt());
       }
       else if (index.column() == ponderationAmplitude)
       {
           elem->SetPonderationAmplitude(value.toFloat());
       }
       else if (index.column() == ponderationPhase)
       {
           elem->SetPonderationPhase(value.toFloat());
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
