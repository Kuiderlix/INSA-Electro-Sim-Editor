#ifndef PARAMSIMUWIDGET_H
#define PARAMSIMUWIDGET_H

#include <QWidget>
#include "FormPortExcitation.h"
#include "FormAnalyseTempo.h"
#include "FormParamExcitation.h"
#include "parser.h"

class ParamSimuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ParamSimuWidget(Parser* parser, QWidget *parent = 0);
    
signals:
    
    void newPortExcitationCreated(elementBase*);

public slots:

    
};

#endif // PARAMSIMUWIDGET_H
