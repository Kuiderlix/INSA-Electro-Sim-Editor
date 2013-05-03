#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMenu>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include <QHeaderView>
#include <QDebug>
#include <QColorDialog>
#include "elementBase.h"
#include "TableModel.h"
#include "MySortFilterProxyModel.h"

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);

    void contextMenuEvent ( QContextMenuEvent * e );
    void keyPressEvent(QKeyEvent * event);

    QModelIndexList selectedIndexes() const;

    TableModel * getSourceModel();

signals:
    
public slots:
    void addElement(elementBase*);
    void addNewElement();
    void deleteElement();

    void editColor();


protected:

    
};

#endif // TABLEVIEW_H
