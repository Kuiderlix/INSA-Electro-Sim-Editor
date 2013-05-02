#ifndef OBJETFDTDWIDGET_H
#define OBJETFDTDWIDGET_H

#include <QWidget>
#include "FormSurfacePrelevement.h"
#include "FormCageExcitation.h"
#include "FormSonde.h"
#include "FormCartographieTemporelle.h"
#include "parser.h"

class ObjetFDTDWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ObjetFDTDWidget(Parser* parser,QWidget *parent = 0);
    
signals:

    void newSondeCreated(elementBase*);
    void newSurfacePrelCreated(elementBase*);
    void newCageExcitationCreated(elementBase*);
    void newCartoTempoCreated(elementBase*);
    
public slots:

    void openCartoTempoWindows();
    
};

#endif // OBJETFDTDWIDGET_H
