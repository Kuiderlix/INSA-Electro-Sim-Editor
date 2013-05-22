#ifndef FORMCALCULDIRECTIVE_H
#define FORMCALCULDIRECTIVE_H

#include <QtWidgets>
#include "calculDirectivite.h"

/**
 * @brief Formulaire permettant de modifier l'objet calculDirectivite
 */
class FormCalculDirective : public QWidget
{
public:
    FormCalculDirective(calculDirectivite * calDir, QWidget * parent=0);

    void setCaculDirective(calculDirectivite * c)
    {
        calDir=c;
        init();
    }

    void init();


private:
    calculDirectivite * calDir;

    QCheckBox * calculHWidget;
    QSpinBox * pasThetaWidget;
    QSpinBox * pasPhiWidget;
};

#endif // FORMCALCULDIRECTIVE_H
