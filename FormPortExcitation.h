#ifndef FORMPORTEXCITATION_H
#define FORMPORTEXCITATION_H

#include "FormElementBase.h"
#include "portExcitation.h"

/**
 * @brief Formulaire permettant d'ajouter un nouvelle objet portExcitation dans la scène 3D
 */
class FormPortExcitation : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormPortExcitation(portExcitation * port,QWidget *parent = 0);
    
signals:
    
public slots:
    void valider();
    void reset();


private:

    void init();

    portExcitation * port;

    QCheckBox * portActifWidget;
    QCheckBox * portInfinitesimalWidget;
    QComboBox * typePortWidget;
    QComboBox * directionWidget;
    QDoubleSpinBox * impedanceWidget;
    QComboBox * typeSourceWidget;
    QDoubleSpinBox * ponderationAmplitudeWidget;
    QDoubleSpinBox * ponderationPhaseWidget;
    
};

#endif // FORMPORTEXCITATION_H
