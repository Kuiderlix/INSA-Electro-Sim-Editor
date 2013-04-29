#ifndef TABLEVIEWELEMENTLOCALISE_H
#define TABLEVIEWELEMENTLOCALISE_H

#include "TableView.h"
#include "blocElementLocalise.h"
#include "TableModelElementLocalise.h"
#include "FormElementLocalise.h"
#include "CoordonneeDelegate.h"
#include "ComboxDecaleeDelegate.h"

class TableViewElementLocalise : public TableView
{
    Q_OBJECT
public:
    explicit TableViewElementLocalise(blocElementLocalise *bloc, QWidget *parent = 0);
    
signals:

public slots:
    void addNewElement();
    
};

#endif // TABLEVIEWELEMENTLOCALISE_H
