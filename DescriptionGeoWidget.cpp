#include "DescriptionGeoWidget.h"

DescriptionGeoWidget::DescriptionGeoWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;

    FormMetallisation * formMetal = new FormMetallisation(new metallisation(), FormMetallisation::NOUVEAU);
    FormParallelepipede * formPara = new FormParallelepipede(new parallelepipede(), FormParallelepipede::NOUVEAU);

    layout->addWidget(formMetal);
    layout->addWidget(formPara);

    setLayout(layout);
}
