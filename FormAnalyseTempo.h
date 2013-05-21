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

    void setAnalyseTempo(analyseTemporelle * temp)
    {
        this->anaTempo=temp;
        init();
    }

    void init();

private:
    analyseTemporelle * anaTempo;

    QDoubleSpinBox * periodeWidget;
    QDoubleSpinBox * tempsWidget;
};

#endif // FORMANALYSETEMPO_H
