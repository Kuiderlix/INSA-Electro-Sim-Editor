#ifndef PARAMAVANCEWIDGET_H
#define PARAMAVANCEWIDGET_H

#include <QtWidgets>
#include "FormFormatStockage.h"
#include "FormExcitation.h"
#include "FormEchantillonage.h"
#include "FormPML.h"
#include "ToolBoxWidget.h"

/**
 * @brief Cette classe représente un widget qui se trouve dans la toolbox.
 * Il agit en faite comme un conteneur des autres formulaire de la meme catégorie.
 */
class ParamAvanceWidget : public ToolBoxWidget
{
    Q_OBJECT
public:
    explicit ParamAvanceWidget(Data* data,QWidget *parent = 0);

    void init();
    
signals:
    
public slots:

private:
    FormFormatStockage * formFormat;
    FormExcitation * formExci;
    FormEchantillonage *formEchanti;
    FormPML * formPml;
    
};

#endif // PARAMAVANCEWIDGET_H
