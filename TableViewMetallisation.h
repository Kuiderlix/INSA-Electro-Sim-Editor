#ifndef TABLEVIEWMETALLISATION_H
#define TABLEVIEWMETALLISATION_H

#include <QTableView>
#include "TableMetallisationModel.h"
#include "CoordonneeDelegate.h"
#include "blocMetallisation.h"
#include "FormMetallisation.h"

class TableViewMetallisation : public QTableView
{
    Q_OBJECT
public:
    explicit TableViewMetallisation(blocMetallisation *blocMetal, QWidget *parent = 0);
    
     void contextMenuEvent ( QContextMenuEvent * e );

signals:
    
public slots:
    void addNewMetallisation();
    void editMetallisation();
    void deleteMetallisation();


private:

    TableMetallisationModel* tableMeta;
    
};

#endif // TABLEVIEWMETALLISATION_H
