#ifndef CALCULCHAMPSLOINTAINWIDGET_H
#define CALCULCHAMPSLOINTAINWIDGET_H

#include <QtWidgets>
#include "FormCompressionHuygens.h"
#include "FormCalculDirective.h"
#include "FormChampLointain.h"
#include "parser.h"

class CalculChampsLointainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalculChampsLointainWidget(Parser* parser,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CALCULCHAMPSLOINTAINWIDGET_H
