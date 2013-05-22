#ifndef FORMCHAMPLOINTAIN_H
#define FORMCHAMPLOINTAIN_H

#include <QtWidgets>
#include "champLointain.h"
#include "FormCoordonnees.h"

/**
 * @brief Cette classe fournit un formulaire pour modifier l'objet champLointain
 */
class FormChampLointain : public QWidget
{
    Q_OBJECT
public:
    explicit FormChampLointain(champLointain * champ, QWidget *parent = 0);

    void setChampLointain(champLointain * c)
    {
        champ=c;
        init();
    }

    void init();
    
signals:
    
public slots:
private:
    champLointain * champ;

    FormCoordonnees * origineRepereWidget;
    QDoubleSpinBox * frequenceMinWidget;
    QDoubleSpinBox * frequenceMaxWidget;
    QDoubleSpinBox * frequencePasWidget;
    QCheckBox * calculImageWidget;
    QSpinBox * hauteurPlanMasseWidget;
    QSpinBox * pasDiscrTetaWidget;
    QSpinBox * pasDiscrPhiWidget;
    
};

#endif // FORMCHAMPLOINTAIN_H
