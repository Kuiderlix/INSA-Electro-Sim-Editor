#ifndef FORMANALYSETEMPO_H
#define FORMANALYSETEMPO_H

#include <QtWidgets>
#include "analyseTemporelle.h"

class FormAnalyseTempo : public QWidget
{
public:
    FormAnalyseTempo(analyseTemporelle * anaTempo, QWidget * parent=0);


private:
    analyseTemporelle * anaTempo;
};

#endif // FORMANALYSETEMPO_H
