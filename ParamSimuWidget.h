#ifndef PARAMSIMUWIDGET_H
#define PARAMSIMUWIDGET_H

#include <QWidget>
#include "FormPortExcitation.h"
#include "FormAnalyseTempo.h"
#include "FormParamExcitation.h"
#include "ToolBoxWidget.h"

/**
 * @brief Cette classe représente un widget qui se trouve dans la toolbox.
 * Il agit en faite comme un conteneur des autres formulaire de la meme catégorie.
 */
class ParamSimuWidget : public ToolBoxWidget
{
    Q_OBJECT
public:
    explicit ParamSimuWidget(Data* data, QWidget *parent = 0);


    void init();
    
signals:
    
    void newPortExcitationCreated(elementBase*);

public slots:


private:

    FormAnalyseTempo * formAnaTempo;
    FormParamExcitation * formParamExci;

    
};

#endif // PARAMSIMUWIDGET_H
