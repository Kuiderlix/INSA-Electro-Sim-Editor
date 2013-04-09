#include "CalculChampsLointainWidget.h"

CalculChampsLointainWidget::CalculChampsLointainWidget(QWidget *parent) :
    QWidget(parent)
{


    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormCompressionHuygens * formHuy = new FormCompressionHuygens(new compressionHuygens());

    layout->addWidget(formHuy);

    setLayout(layout);
}
