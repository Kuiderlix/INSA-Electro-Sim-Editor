#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include "BlocElementBase.h"

/**
 * @brief Cette classe sert de model de base pour les éléments des tableaux.
 */
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(BlocElementBase *bloc , QObject *parent = 0);


    int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    void initHeaders(const QStringList l);

    QStringList getHeaders() const {return headers;}

    elementBase * getElement(int row);
    
signals:

public slots:
    /**
     * @brief ajout un élément à la fin du tableau
     * @param element l'élément a ajouté
     */
    void addElement(elementBase *element);
    /**
     * @brief supprime un élément du tableau
     * @param i le numéro dans le tableau de l'élément à supprimé
     */
    void removeElement(int i);

private:
    BlocElementBase * listeElement;
    QStringList headers;
    
};

#endif // TABLEMODEL_H
