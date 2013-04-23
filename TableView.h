#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include "TableModel.h"

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);

    void contextMenuEvent ( QContextMenuEvent * e );
    void keyPressEvent(QKeyEvent * event);

    QModelIndexList selectedIndexes() const;

signals:
    
public slots:
    void addNewMetallisation();
    void deleteMetallisation();


protected:

    
};

#endif // TABLEVIEW_H
