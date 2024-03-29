#ifndef TABLEVIEWSURFACEPRELEV_H
#define TABLEVIEWSURFACEPRELEV_H


#include "TableView.h"
#include "blocSurfacePrelevement.h"
#include "FormSurfacePrelevement.h"
#include "CoordonneeDelegate.h"
#include "TableModelSurfacePrelev.h"
#include "ComboxDecaleeDelegate.h"

class TableViewSurfacePrelev : public TableView
{
    Q_OBJECT
public:
    explicit TableViewSurfacePrelev(blocSurfacePrelevement *bloc, QWidget *parent = 0);

public slots:
    void addNewElement();
};

#endif // TABLEVIEWSURFACEPRELEV_H
