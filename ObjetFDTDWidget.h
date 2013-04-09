#ifndef OBJETFDTDWIDGET_H
#define OBJETFDTDWIDGET_H

#include <QWidget>
#include "FormSurfacePrelevement.h"
#include "FormCageExcitation.h"
#include "FormSonde.h"
#include "FormCartographieTemporelle.h"

class ObjetFDTDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ObjetFDTDWidget(QWidget *parent = 0);
    
signals:
    
public slots:

    void openCartoTempoWindows();
    
};

#endif // OBJETFDTDWIDGET_H
