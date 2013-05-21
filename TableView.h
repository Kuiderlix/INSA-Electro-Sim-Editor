#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include <QHeaderView>
#include <QColorDialog>
#include "elementBase.h"
#include "TableModel.h"
#include "MySortFilterProxyModel.h"

/**
 * @brief Cette classe sert de vue de base pour les tableaux de données.
 * Elle affiche les données contenu dans son model sous forme de tableau.
 */
class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);

    /**
     * @brief affiche un menu contextuel
     */
    void contextMenuEvent ( QContextMenuEvent * e );
    /**
     * @brief Gère les entrées au clavier.
     * Cette fonction appelle simplement la fonction de suppression des éléments quand la touche SUPPR est enfoncée.
     */
    void keyPressEvent(QKeyEvent * event);

    /**
     * @brief Modifie la liste des éléments séléctionnés pour prendre en compte seulement les lignes.
     * @return la liste des éléments séléctionnés.
     */
    QModelIndexList selectedIndexes() const;

    /**
     * @brief Change la couleur des éléments séléctionnés.
     */
    virtual void selectionChanged(const QItemSelection &selected,const QItemSelection &deselected);

    /**
     * @brief Retourne le model associé.
     * @return le model TableModel associé à la vue.
     */
    TableModel * getSourceModel();

    void setSourceModel(TableModel * m)
    {
        MySortFilterProxyModel * proxyModel = new MySortFilterProxyModel(this);
        proxyModel->setSourceModel(m);
        this->setModel(proxyModel);
    }


signals:
    
public slots:

    /**
     * @brief Ajoute un élément au model
     * @param e l'élément a ajouté
     */
    void addElement(elementBase* e);

    /**
     * @brief Fonction virtual qui est appelé quand l'utilisateur veut ajouter un nouveau élément avec le menu contextuel du tableau.
     * Par défaut, cette fonction ne fait rien.
     */
    virtual void addNewElement();
    /**
     * @brief Supprime un élément du model
     */
    void deleteElement();

    /**
     * @brief Ouvre une fenetre de dialogue pour changer de couleur les éléments séléctionnés.
     * La couleur choisi sera appliquée à tous les éléments séléctionnés.
     */
    void editColor();


protected:

    
};

#endif // TABLEVIEW_H
