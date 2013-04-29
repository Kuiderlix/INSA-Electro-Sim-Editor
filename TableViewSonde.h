#ifndef TABLEVIEWSONDE_H
#define TABLEVIEWSONDE_H

#include "TableView.h"
#include "blocSonde.h"
#include "FormSonde.h"
#include "CoordonneeDelegate.h"
#include "TableModelSonde.h"

class TableViewSonde : public TableView
{
    Q_OBJECT
public:
    explicit TableViewSonde(blocSonde *bloc, QWidget *parent = 0);


public slots:
    void addNewElement();
};

#endif // TABLEVIEWSONDE_H
