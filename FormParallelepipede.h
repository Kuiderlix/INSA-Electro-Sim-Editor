#ifndef FORMPARALLELEPIPEDE_H
#define FORMPARALLELEPIPEDE_H

#include "FormElementBase.h"
#include "parallelepipede.h"

/**
 * @brief Formulaire permettant d'ajouter un nouvelle objet parallelepipede dans la scène 3D
 */
class FormParallelepipede : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormParallelepipede(parallelepipede * paralle, QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();

    void reset();


private:

    void init();

    parallelepipede * paralle;
    QDoubleSpinBox * permitRelativeWidget;
    QDoubleSpinBox * permeRelativeWidget;
    QDoubleSpinBox * conductiviteWidget;
    
};

#endif // FORMPARALLELEPIPEDE_H
