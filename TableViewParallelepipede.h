#ifndef TABLEVIEWPARALLELEPIPEDE_H
#define TABLEVIEWPARALLELEPIPEDE_H

#include "TableView.h"
#include "TableModelParallelepipede.h"
#include "CoordonneeDelegate.h"
#include "blocParallelepipede.h"
#include "FormParallelepipede.h"


class TableViewParallelepipede : public TableView
{
    Q_OBJECT
public:
    explicit TableViewParallelepipede(blocParallelepipede *blocParal, QWidget *parent = 0);
    
signals:

public slots:
    void addNewElement();
    
};

#endif // TABLEVIEWPARALLELEPIPEDE_H
