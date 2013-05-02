#ifndef PARAMAVANCEWIDGET_H
#define PARAMAVANCEWIDGET_H

#include <QtWidgets>
#include "FormFormatStockage.h"
#include "FormExcitation.h"
#include "FormEchantillonage.h"
#include "FormPML.h"
#include "parser.h"

class ParamAvanceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ParamAvanceWidget(Parser* parser,QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PARAMAVANCEWIDGET_H
