#include "DescriptionGeoWidget.h"

DescriptionGeoWidget::DescriptionGeoWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;

    FormMetallisation * formMetal = new FormMetallisation(new metallisation(), FormMetallisation::NOUVEAU);
    FormParallelepipede * formPara = new FormParallelepipede(new parallelepipede(), FormParallelepipede::NOUVEAU);

    FormVolumeCalcul * formVolCal = new FormVolumeCalcul(new volumeCalcul);

    FormParoi * formParoi = new FormParoi(new paroi());

    layout->addWidget(formVolCal);
    layout->addWidget(formParoi);
    layout->addWidget(formMetal);
    layout->addWidget(formPara);

    QHBoxLayout * layoutAvance = new QHBoxLayout;
    layoutAvance->setMargin(0);
    layoutAvance->addWidget(new QLabel("Element Localisé"));
    layoutAvance->addWidget(new QPushButton("+"));

    QWidget * widgetAvance = new QWidget();

    widgetAvance->setLayout(layoutAvance);


    layout->addWidget(widgetAvance);


    setLayout(layout);
}
