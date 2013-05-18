#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include <QHeaderView>
#include <QDebug>
#include <QColorDialog>
#include "elementBase.h"
#include "TableModel.h"
#include "MySortFilterProxyModel.h"

/**
 * Cette classe sert de vue de base pour les tableaux de données.
 * @brief The TableView class
 */
class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);

    void contextMenuEvent ( QContextMenuEvent * e );
    void keyPressEvent(QKeyEvent * event);

    QModelIndexList selectedIndexes() const;

    virtual void selectionChanged(const QItemSelection &selected,const QItemSelection &deselected);

    TableModel * getSourceModel();

signals:
    
public slots:
    /**
     * Ajoute un élément au tableau de données
     * @brief addElement
     */
    void addElement(elementBase* e);
    /**
     * Fonction virtual qui est appelé quand l'utilisateur veut ajouter un nouveau élément avec le menu contextuel du tableau.
     * Par défaut, cette fonction ne fait rien.
     * @brief addNewElement
     */
    virtual void addNewElement();
    /**
     * Supprime un élément du tableau
     * @brief deleteElement
     */
    void deleteElement();

    /**
     * Ouvre la fenetre de dialogue pour changer de couleur les éléments séléctionnés.
     * @brief editColor
     */
    void editColor();


protected:

    
};

#endif // TABLEVIEW_H
