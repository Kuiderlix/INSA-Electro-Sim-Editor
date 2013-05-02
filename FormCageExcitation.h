#ifndef FORMCAGEEXCITATION_H
#define FORMCAGEEXCITATION_H

#include "FormElementBase.h"
#include "cageExcitation.h"

class FormCageExcitation : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormCageExcitation(cageExcitation * cageExci, int mode, QWidget *parent = 0);

signals:

public slots:
    void valider();
    void reset();

    void manageFormulaire(int val);
    void actualiseFormulaire(int);

private:

    void init();

    cageExcitation * cageExci;

    QSpinBox * nbFacesWidget;
    QComboBox * typeWidget;
    QWidget *formFace1, *formFaceDif1, *formType4;
    QComboBox * insideOutsideWidget;
    QComboBox * modeWidget;
    QSpinBox * hauteurWidget;
    QComboBox * sensPropaWidget;
    FormCoordonnees* pointRefWidget;
    QDoubleSpinBox * theta0Widget;
    QDoubleSpinBox * phi0Widget;
    QDoubleSpinBox * psi0Widget;
    QDoubleSpinBox * modulationAmplitudeWidget;
    QDoubleSpinBox * modulationPhaseWidget;
    QLineEdit * nomFichierWidget;
};

#endif // FORMCAGEEXCITATION_H
