#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QtWidgets>
#include "TableModel.h"
#include "FormCoordonnees.h"

/**
 * Ce widget est un formulaire qui permet de filtrer le tableau courant en
 * fonction de sa colonne et d'une expression régulière
 * @brief The FilterWidget class
 */
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
