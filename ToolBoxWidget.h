#ifndef TOOLBOXWIDGET_H
#define TOOLBOXWIDGET_H

#include <QWidget>
#include "Data.h"

class ToolBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBoxWidget(Data *data,QWidget *parent = 0);

    void setData(Data * data)
    {
        this->data = data;
        init();
    }

    virtual void init()=0;
    
signals:
    
public slots:

protected:
    Data *data;
    
};

#endif // TOOLBOXWIDGET_H
