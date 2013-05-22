#ifndef FORMELEMENTLOCALISE_H
#define FORMELEMENTLOCALISE_H

#include <QWidget>
#include "FormElementBase.h"
#include "elementLocalise.h"

/**
 * @brief Formulaire permettant d'ajouter un nouvelle objet elementLocalise dans la scène 3D
 */
class FormElementLocalise : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormElementLocalise(elementLocalise * localise, QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();
    void reset();

private:

    void init();

    elementLocalise * localise;

    QComboBox * typeWidget;
    QDoubleSpinBox * valeurWidget;
    QComboBox * directionWidget;
    
};

#endif // FORMELEMENTLOCALISE_H
