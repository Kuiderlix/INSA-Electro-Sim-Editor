#include "CalculChampsLointainWidget.h"

CalculChampsLointainWidget::CalculChampsLointainWidget(QWidget *parent) :
    QWidget(parent)
{


    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormCompressionHuygens * formHuy = new FormCompressionHuygens(new compressionHuygens());
    FormCalculDirective * formCal = new FormCalculDirective(new calculDirectivite());

    layout->addWidget(formHuy);
    layout->addWidget(formCal);

    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}
