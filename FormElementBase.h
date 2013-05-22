#ifndef FORMELEMENTBASE_H
#define FORMELEMENTBASE_H

#include <QtWidgets>
#include "FormCoordonnees.h"
#include "elementBase.h"
#include "ColorPicker.h"

/**
 * @brief Cette classe sert de base aux formulaires qui modifie des objets elementBase
 */
class FormElementBase : public QDialog
{
    Q_OBJECT
public:
    explicit FormElementBase(elementBase * element,QWidget *parent = 0);


    /**
     * @brief Cette fonction retourne les champs qui sont communs à tous les elementBase.
     *  C'est à dire: le formulaire pour modifier les coordonnees ainsi que le bouton de validation
     * @return Un widget qui contient un formulaire et un bouton valider
     */
    QWidget * getWidgetElementBase();

signals:

    /**
     * @brief Ce signal est émis quand le bouton valider est pressé. Cela signifie que l'elementBase a bien était modifié.
     */
    void elementValide(elementBase *);
public slots:

    /**
     * @brief Cette fonction est appelé quand le bouton valider est pressé.
     * Elle met à jour les données de l'elementBase et émet le signal elementValide(elementBase *).
     */
    virtual void valider();

    void changeCouleur(QColor);


protected:
    FormCoordonnees * formCoord1, *formCoord2;

    /**
     * @brief Place des valeurs par défaut dans le formulaire
     */
    virtual void reset();
    /**
     * @brief Initialise le formulaire avec les données de l'objet elementBase
     */
    virtual void init();
    /**
     * @brief Modifie l'elementBase que contient le formulaire
     */
    void setElement(elementBase *);
    QPushButton * boutonValider;

    ColorPicker * couleurPick;

private:
    elementBase * element;
    
};

#endif // FORMELEMENTBASE_H
