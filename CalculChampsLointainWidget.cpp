#include "CalculChampsLointainWidget.h"

CalculChampsLointainWidget::CalculChampsLointainWidget(Data *data, QWidget *parent) :
    ToolBoxWidget(data,parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    formHuy = new FormCompressionHuygens(data->getCompressionHuygens());
    formCal = new FormCalculDirective(data->getCalculDirective());
    formChLo = new FormChampLointain(data->getChampLointain());

    layout->addWidget(formHuy);
    layout->addWidget(formCal);
    layout->addWidget(formChLo);

    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);

    init();
}

void CalculChampsLointainWidget::init()
{
    formHuy->setCompressHuy(data->getCompressionHuygens());
    formCal->setCaculDirective(data->getCalculDirective());
    formChLo->setChampLointain(data->getChampLointain());
}
