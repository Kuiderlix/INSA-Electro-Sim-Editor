#ifndef FORMCAGEEXCITATION_H
#define FORMCAGEEXCITATION_H

#include "FormElementBase.h"
#include "cageExcitation.h"

/**
 * @brief Formulaire permettant d'ajouter un objet cageExcitation
 */
class FormCageExcitation : public FormElementBase
{
    Q_OBJECT
public:
    explicit FormCageExcitation(cageExcitation * cageExci, QWidget *parent = 0);

    void setCageExcitation(cageExcitation * c)
    {
        setElement(c);
        cageExci=c;
        init();
    }

signals:

public slots:
    void valider();

    void manageFormulaire(int val);
    void actualiseFormulaire(int);

    void changeCreate(bool);

    void changeBackgroundRed();
    void changeBackgroundNormal(QWidget * w);


private:
    void init();


    cageExcitation * cageExci;

    QGroupBox * group;
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
