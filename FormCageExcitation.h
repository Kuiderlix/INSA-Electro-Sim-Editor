#ifndef FORMCAGEEXCITATION_H
#define FORMCAGEEXCITATION_H

#include "FormElementBase.h"
#include "cageExcitation.h"

class FormCageExcitation : public FormElementBase
{
public:
    explicit FormCageExcitation(cageExcitation * cageExci, int mode, QWidget *parent = 0);

signals:

public slots:


private:
    cageExcitation * cageExci;
    QWidget *formFace1, *formFaceDif1, *formType4;
};

#endif // FORMCAGEEXCITATION_H
