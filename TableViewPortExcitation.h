#ifndef TABLEVIEWPORTEXCITATION_H
#define TABLEVIEWPORTEXCITATION_H

#include "TableView.h"
#include "blocPortExcitation.h"
#include "TableModelPortExcitation.h"
#include "CoordonneeDelegate.h"
#include "ComboxDecaleeDelegate.h"
#include "FormPortExcitation.h"

class TableViewPortExcitation : public TableView
{
    Q_OBJECT
public:
    explicit TableViewPortExcitation(blocPortExcitation *bloc,QWidget *parent = 0);
    
signals:
    
public slots:
    void addNewMetallisation();
    
};

#endif // TABLEVIEWPORTEXCITATION_H
