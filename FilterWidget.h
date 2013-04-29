#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QtWidgets>
#include "TableModel.h"
#include "FormCoordonnees.h"

class FilterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FilterWidget(QWidget *parent = 0);
    
signals:
    void columnChanged(int);
    void filterChanged(QString);

public slots:
    void setListCombox(QStringList);
    void setCurrentModel(TableModel*);
    void clear();

private:
    QStringList listCombox;
    QComboBox * colonneFilter;
    QLineEdit* filterEdit;
    TableModel * currentModel;

    
};

#endif // FILTERWIDGET_H
