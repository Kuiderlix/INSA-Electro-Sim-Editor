#ifndef TABLEVIEWCARTTEMPO_H
#define TABLEVIEWCARTTEMPO_H

#include "TableView.h"
#include "blocCartographieTemporelle.h"
#include "TableModelCartoTempo.h"
#include "CoordonneeDelegate.h"
#include "FormCartographieTemporelle.h"

class TableViewCartTempo : public TableView
{
    Q_OBJECT
public:
    explicit TableViewCartTempo(blocCartographieTemporelle *bloc,QWidget *parent = 0);
    
signals:
    
public slots:
    void addNewMetallisation();
    
};

#endif // TABLEVIEWCARTTEMPO_H
