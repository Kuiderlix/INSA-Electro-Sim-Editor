#ifndef DESCRIPTIONGEOWIDGET_H
#define DESCRIPTIONGEOWIDGET_H

#include <QWidget>
#include "FormParallelepipede.h"
#include "FormMetallisation.h"
#include "FormVolumeCalcul.h"
#include "FormParoi.h"
#include "parser.h"

class DescriptionGeoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DescriptionGeoWidget(Parser * parser, QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DESCRIPTIONGEOWIDGET_H
