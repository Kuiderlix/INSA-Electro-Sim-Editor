#include "CalculChampsLointainWidget.h"

CalculChampsLointainWidget::CalculChampsLointainWidget(Data *data, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormCompressionHuygens * formHuy = new FormCompressionHuygens(data->getCompressionHuygens());
    FormCalculDirective * formCal = new FormCalculDirective(data->getCalculDirective());
    FormChampLointain * formChLo = new FormChampLointain(data->getChampLointain());

    layout->addWidget(formHuy);
    layout->addWidget(formCal);
    layout->addWidget(formChLo);

    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}
