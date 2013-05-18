#ifndef FORMANALYSETEMPO_H
#define FORMANALYSETEMPO_H

#include <QtWidgets>
#include "analyseTemporelle.h"

/**
 * Formulaire de modification de l'objet analyseTemporelle
 * @brief The FormAnalyseTempo class
 */
class FormAnalyseTempo : public QWidget
{
public:
    FormAnalyseTempo(analyseTemporelle * anaTempo, QWidget * parent=0);


private:
    analyseTemporelle * anaTempo;
};

#endif // FORMANALYSETEMPO_H
