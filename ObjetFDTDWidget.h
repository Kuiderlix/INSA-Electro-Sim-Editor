#ifndef OBJETFDTDWIDGET_H
#define OBJETFDTDWIDGET_H

#include <QWidget>
#include "FormSurfacePrelevement.h"
#include "FormCageExcitation.h"
#include "FormSonde.h"
#include "FormCartographieTemporelle.h"
#include "ToolBoxWidget.h"

class ObjetFDTDWidget : public ToolBoxWidget
{
    Q_OBJECT
public:
    explicit ObjetFDTDWidget(Data* data,QWidget *parent = 0);

    void init();
    
signals:

    void newSondeCreated(elementBase*);
    void newSurfacePrelCreated(elementBase*);
    void newCartoTempoCreated(elementBase*);
    
public slots:

    void openCartoTempoWindows();

private:
    FormCageExcitation * formCageExci;
    
};

#endif // OBJETFDTDWIDGET_H
