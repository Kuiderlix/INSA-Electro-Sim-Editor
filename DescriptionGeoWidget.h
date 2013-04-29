#ifndef DESCRIPTIONGEOWIDGET_H
#define DESCRIPTIONGEOWIDGET_H

#include <QWidget>
#include "FormParallelepipede.h"
#include "FormMetallisation.h"
#include "FormVolumeCalcul.h"
#include "FormElementLocalise.h"
#include "FormParoi.h"
#include "parser.h"

class DescriptionGeoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DescriptionGeoWidget(Parser * parser, QWidget *parent = 0);
    
signals:

    void newMetalCreated(elementBase*);
    void newParaCreated(elementBase*);
    void newElemLocCreated(elementBase*);
    
public slots:

    void openElementLocaliseWindows();
    
};

#endif // DESCRIPTIONGEOWIDGET_H
