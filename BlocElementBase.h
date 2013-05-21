#ifndef BLOCELEMENTBASE_H
#define BLOCELEMENTBASE_H

#include "blocConfiguration.h"
#include "elementBase.h"
#include <QColor>
/**
 * @brief Représente une liste d'elementBase.
 */
class BlocElementBase : public blocConfiguration
{
public:
    BlocElementBase();

    /**
     * @brief Retourne le nombre d'élément dans la liste
     * @return
     */
    int getNbElement() const {
        return listElement.size();
    }

    /**
     * @brief Remplace l'élément à l'indice i par elem
     * @param i l'indice
     * @param elem le nouveau élément
     */
    void setElement(int i, elementBase* elem){
        if(i> listElement.size())return;
        listElement[i] = elem;
    }

    /**
     * @brief Supprime l'élément elem du tableau
     * @param elem l'élément à supprimé
     */
    void removeElement(elementBase * elem)
    {
        listElement.removeOne(elem);
    }

    /**
     * @brief Supprime l'élément à l'indice i
     * @param i
     */
    void removeElement(int i)
    {
        listElement.removeAt(i);
    }

    /**
     * @brief Ajoute l'élément elem à la fin de la liste
     * @param elem
     */
    void addElement(elementBase* elem){
        listElement.push_back(elem);
    }
    /**
     * @brief Retourne un elementBase contenu à l'indice i
     * @param i
     * @return
     */
    elementBase * getElement(int i)
    {
        return listElement.at(i);
    }

    /**
     * @brief Retourne un pointeur sur la liste des éléments
     * @return
     */
    QList<elementBase*>* getListElementPointer()
    {
        return &listElement;
    }

protected:
    QList<elementBase*> listElement;

};

#endif // BLOCELEMENTBASE_H
