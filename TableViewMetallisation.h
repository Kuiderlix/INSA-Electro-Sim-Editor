#ifndef TABLEVIEWMETALLISATION_H
#define TABLEVIEWMETALLISATION_H

#include <QTableView>
#include "TableView.h"
#include "TableMetallisationModel.h"
#include "CoordonneeDelegate.h"
#include "blocMetallisation.h"
#include "FormMetallisation.h"

class TableViewMetallisation : public TableView
{
    Q_OBJECT
public:
    explicit TableViewMetallisation(blocMetallisation *blocMetal, QWidget *parent = 0);



signals:
    
public slots:
    void addNewMetallisation();


private:

};

#endif // TABLEVIEWMETALLISATION_H