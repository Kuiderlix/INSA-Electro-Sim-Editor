#ifndef TABLEMODELSURFACEPRELEV_H
#define TABLEMODELSURFACEPRELEV_H

#include "TableModel.h"
#include "blocSurfacePrelevement.h"

class TableModelSurfacePrelev : public TableModel
{
    Q_OBJECT
public:
    enum Columns {TypeSurface=0, nomFichier=1, insideOutside = 2, nbFace = 3,compressionLongueur = 4, compressionLargeur=5, compressionHauteur=6, AvantGauche = 7, ArriereDroit = 8};

    explicit TableModelSurfacePrelev(BlocElementBase *bloc , QObject *parent = 0);


    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int	columnCount ( const QModelIndex & parent = QModelIndex()) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:

    blocSurfacePrelevement * bloc;
    
};

#endif // TABLEMODELSURFACEPRELEV_H
