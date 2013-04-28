#include "CalculChampsLointainWidget.h"

CalculChampsLointainWidget::CalculChampsLointainWidget(QWidget *parent) :
    QWidget(parent)
{


    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormCompressionHuygens * formHuy = new FormCompressionHuygens(new compressionHuygens());
    FormCalculDirective * formCal = new FormCalculDirective(new calculDirectivite());
    FormChampLointain * formChLo = new FormChampLointain(new champLointain());

    layout->addWidget(formHuy);
    layout->addWidget(formCal);
    layout->addWidget(formChLo);

    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}
