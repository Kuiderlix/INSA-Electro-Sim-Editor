#ifndef CALCULCHAMPSLOINTAINWIDGET_H
#define CALCULCHAMPSLOINTAINWIDGET_H

#include <QtWidgets>
#include "FormCompressionHuygens.h"
#include "FormCalculDirective.h"
#include "FormChampLointain.h"
#include "Data.h"

/**
 *
 * @brief Cette classe représente le formulaire pour modifier un ChampsLointain
 */
class CalculChampsLointainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalculChampsLointainWidget(Data* data,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CALCULCHAMPSLOINTAINWIDGET_H
