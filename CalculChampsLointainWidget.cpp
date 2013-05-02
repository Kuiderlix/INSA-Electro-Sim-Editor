#include "CalculChampsLointainWidget.h"

CalculChampsLointainWidget::CalculChampsLointainWidget(Parser *parser, QWidget *parent) :
    QWidget(parent)
{


    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormCompressionHuygens * formHuy = new FormCompressionHuygens(parser->getCompressionHuygens());
    FormCalculDirective * formCal = new FormCalculDirective(parser->getCalculDirective());
    FormChampLointain * formChLo = new FormChampLointain(parser->getChampLointain());

    layout->addWidget(formHuy);
    layout->addWidget(formCal);
    layout->addWidget(formChLo);

    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}
