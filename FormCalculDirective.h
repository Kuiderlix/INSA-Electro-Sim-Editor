#ifndef FORMCALCULDIRECTIVE_H
#define FORMCALCULDIRECTIVE_H

#include <QtWidgets>
#include "calculDirectivite.h"

/**
 * Formulaire permettant de modifier l'objet calculDirectivite
 * @brief The FormCalculDirective class
 */
class FormCalculDirective : public QWidget
{
public:
    FormCalculDirective(calculDirectivite * calDir, QWidget * parent=0);


private:
    calculDirectivite * calDir;
};

#endif // FORMCALCULDIRECTIVE_H
