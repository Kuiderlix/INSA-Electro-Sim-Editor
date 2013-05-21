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

    /**
     * @brief Initialise les entetes du tableau
     * @param l la liste des entetes
     */
    void initHeaders(const QStringList l);

    /**
     * @brief Retourne la liste des entetes du tableau
     * @return
     */
    QStringList getHeaders() const {return headers;}

    /**
     * @brief Retourne un élément contenu dans le tableau au rang row
     * @param row
     * @return l'élément à l'indice row
     */
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
    /**
     * @brief La liste des éléments du tableau
     */
    BlocElementBase * listeElement;
    /**
     * @brief La liste des entetes du tableau
     */
    QStringList headers;
    
};

#endif // TABLEMODEL_H
