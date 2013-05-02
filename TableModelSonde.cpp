#include "TableModelSonde.h"

TableModelSonde::TableModelSonde(BlocElementBase *bloc, QObject *parent) :
    TableModel(bloc,parent)
{
    this->bloc = (blocSonde*)bloc;
    initHeaders(QStringList() << "EX" << "EY" << "EZ" << "HX" << "HY" << "HZ" << "Point d'Application" << "Valeur au Centre" << "Avant Gauche" << "Arrière Droit");

}

QVariant TableModelSonde::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == ex)
        {
            return QVariant(bloc->GetSonde(index.row())->IsEx());
        }
        else if (index.column() == ey)
        {
            return QVariant(bloc->GetSonde(index.row())->IsEy());
        }
        else if (index.column() == ez)
        {
            return QVariant(bloc->GetSonde(index.row())->IsEz());
        }
        else if (index.column() == hx)
        {
            return QVariant(bloc->GetSonde(index.row())->IsHx());
        }
        else if (index.column() == hy)
        {
            return QVariant(bloc->GetSonde(index.row())->IsHy());
        }
        else if (index.column() == hz)
        {
            return QVariant(bloc->GetSonde(index.row())->IsHz());
        }
        else if (index.column() == PointAppli)
        {
            QVariant var;
            var.setValue(bloc->GetSonde(index.row())->GetPointApplication());
            return var;
        }
        else if (index.column() == ValCentre)
        {
            return QVariant(bloc->GetSonde(index.row())->IsValeurAuCentre());
        }
        else if (index.column() == AvantGauche)
        {
            QVariant var;
            var.setValue(bloc->GetSonde(index.row())->GetAvantGauche());
            return var;
        }
        else if (index.column() == ArriereDroit)
        {
            QVariant var;
            var.setValue(bloc->GetSonde(index.row())->GetArriereDroit());
            return var;
        }
        break;
    }

    return QVariant();
}

int TableModelSonde::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 10;
}

bool TableModelSonde::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        sonde * elem = bloc->GetSonde(index.row());

        if (index.column() == ex)
        {
            elem->SetEx(value.toBool());
        }
        else if (index.column() == ey)
        {
            elem->SetEy(value.toBool());
        }
        else if (index.column() == ez)
        {
            elem->SetEz(value.toBool());
        }
        else if (index.column() == hx)
        {
            elem->SetHx(value.toBool());
        }
        else if (index.column() == hy)
        {
            elem->SetHy(value.toBool());
        }
        else if (index.column() == hz)
        {
            elem->SetHz(value.toBool());
        }
        else if (index.column() == PointAppli)
        {
            coordonnee c = value.value<coordonnee>();
            elem->SetPointApplication(c.GetX(),c.GetY(),c.GetZ());
        }
        else if (index.column() == ValCentre)
        {
            elem->SetValeurAuCentre(value.toBool());
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
