#ifndef CALCULCHAMPSLOINTAINWIDGET_H
#define CALCULCHAMPSLOINTAINWIDGET_H

#include <QtWidgets>
#include "FormCompressionHuygens.h"
#include "FormCalculDirective.h"
#include "FormChampLointain.h"
#include "ToolBoxWidget.h"

/**
 *
 * @brief Cette classe représente le formulaire pour modifier un ChampsLointain
 */
class CalculChampsLointainWidget : public ToolBoxWidget
{
    Q_OBJECT
public:
    explicit CalculChampsLointainWidget(Data* data,QWidget *parent = 0);

    /**
     * @brief Cette fonction initialise les formulaires avec les données
     */
    void init();
    
signals:
    
public slots:
    

private:
    FormCompressionHuygens * formHuy;
    FormCalculDirective * formCal;
    FormChampLointain * formChLo;
};

#endif // CALCULCHAMPSLOINTAINWIDGET_H
