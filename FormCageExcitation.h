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

    void manageFormulaire(int val);
    void actualiseFormulaire(int);

private:
    cageExcitation * cageExci;
    QSpinBox * nbFacesWidget;
    QComboBox * typeWidget;
    QWidget *formFace1, *formFaceDif1, *formType4;
};

#endif // FORMCAGEEXCITATION_H
