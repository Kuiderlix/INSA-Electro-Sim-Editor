#include "TableModelSurfacePrelev.h"

TableModelSurfacePrelev::TableModelSurfacePrelev(BlocElementBase *bloc,QObject *parent) :
    TableModel(bloc,parent)
{
    this->bloc = (blocSurfacePrelevement*)bloc;
    initHeaders(QStringList() << "Type Surface" << "Nom Fichier" << "Inside/Outside" << "Nombre Faces" << "Compression Longueur" << "Compression Largeur" << "Compression Hauteur" << "Avant Gauche" << "Arrière Droit");

}

Qt::ItemFlags TableModelSurfacePrelev::flags(const QModelIndex &index) const
{
    int row = index.row();
    int column = index.column();
    if (this->index(row,TypeSurface).data().toInt() == 2)
    {
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
    }
    else
    {
        if (column>=2 && column <=6)
        {
            return Qt::ItemIsSelectable;
        }
        else
        {
            return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
        }
    }
}

QVariant TableModelSurfacePrelev::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        surfacePrelevement * surface = bloc->GetSurface(index.row());
        if (index.column() == TypeSurface)
        {
            return QVariant(surface->GetTypeSurface());
        }
        else if (index.column() == nomFichier)
        {
            return QVariant(surface->GetNomFichier().c_str());
        }
        else if (index.column() == insideOutside)
        {
            return QVariant(surface->GetInsideOutside());
        }
        else if (index.column() == nbFace)
        {
            return QVariant(surface->GetNbFaces());
        }
        else if (index.column() == compressionLongueur)
        {
            return QVariant(surface->GetCompressionLongueur());
        }
        else if (index.column() == compressionLargeur)
        {
            return QVariant(surface->GetCompressionLargeur());
        }
        else if (index.column() == compressionHauteur)
        {
            return QVariant(surface->GetCompressionHauteur());
        }
        else if (index.column() == AvantGauche)
        {
            QVariant var;
            var.setValue(surface->GetAvantGauche());
            return var;
        }
        else if (index.column() == ArriereDroit)
        {
            QVariant var;
            var.setValue(surface->GetArriereDroit());
            return var;
        }
        break;
    }

    return QVariant();
}

int TableModelSurfacePrelev::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 9;
}

bool TableModelSurfacePrelev::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= bloc->getNbElement())
    {
        return false;
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        surfacePrelevement * elem = bloc->GetSurface(index.row());


       if (index.column() == TypeSurface)
       {
            elem->SetTypeSurface(value.toInt());
       }
       else if (index.column() == nomFichier)
       {
           elem->SetNomFichier(value.toString().toStdString());
       }
       else if (index.column() == insideOutside)
       {
           elem->SetInsideOutside(value.toInt());
       }
       else if (index.column() == nbFace)
       {
           elem->SetNbFaces(value.toInt());
       }
       else if (index.column() == compressionHauteur)
       {
           elem->SetCompressionHauteur(value.toInt());
       }
       else if (index.column() == compressionLargeur)
       {
           elem->SetCompressionLargeur(value.toInt());
       }
       else if (index.column() == compressionLongueur)
       {
           elem->SetCompressionLongueur(value.toInt());
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
