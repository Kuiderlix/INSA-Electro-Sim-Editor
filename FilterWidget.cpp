#include "FilterWidget.h"

FilterWidget::FilterWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout * layoutFilter = new QHBoxLayout();
    layoutFilter->setMargin(0);
    colonneFilter = new QComboBox();
    colonneFilter->addItems(QStringList() << "Conductivité" << "Arrière Gauche" << "Avant Droit");

    connect(colonneFilter,SIGNAL(currentIndexChanged(int)), this, SIGNAL(columnChanged(int)));

    filterEdit = new QLineEdit();
    connect(filterEdit,SIGNAL(textChanged(QString)), this, SIGNAL(filterChanged(QString)));

    layoutFilter->addWidget(new QLabel("Filtre:"));
    layoutFilter->addWidget(colonneFilter);
    layoutFilter->addWidget(filterEdit);

    this->setLayout(layoutFilter);
}

void FilterWidget::setListCombox(QStringList l)
{
    listCombox=l;
    colonneFilter->clear();
    colonneFilter->addItems(listCombox);
    filterEdit->clear();
}

void FilterWidget::setCurrentModel(TableModel * t)
{
    currentModel=t;
    setListCombox(currentModel->getHeaders());
}

void FilterWidget::clear()
{
    colonneFilter->clear();
    filterEdit->clear();
}
