#include "DescriptionGeoWidget.h"

DescriptionGeoWidget::DescriptionGeoWidget(Parser *parser, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormMetallisation * formMetal = new FormMetallisation(new metallisation(), FormMetallisation::NOUVEAU);
    FormParallelepipede * formPara = new FormParallelepipede(new parallelepipede(), FormParallelepipede::NOUVEAU);

    FormVolumeCalcul * formVolCal = new FormVolumeCalcul(parser->getVolumeCalcul());

    FormParoi * formParoi = new FormParoi(new paroi());

    layout->addWidget(formVolCal);
    layout->addWidget(formParoi);
    layout->addWidget(formMetal);
    layout->addWidget(formPara);

    QHBoxLayout * layoutAvance = new QHBoxLayout;
    layoutAvance->addWidget(new QLabel("Element Localisé"));
    QPushButton * boutonAvance = new QPushButton("+");
    layoutAvance->addWidget(boutonAvance);
    this->connect(boutonAvance, SIGNAL(clicked()), this, SLOT(openElementLocaliseWindows()));

    QWidget * widgetAvance = new QWidget();

    widgetAvance->setLayout(layoutAvance);


    layout->addWidget(widgetAvance);


    setLayout(layout);
}

void DescriptionGeoWidget::openElementLocaliseWindows()
{
    FormElementLocalise * win = new FormElementLocalise(new elementLocalise(), FormElementLocalise::NOUVEAU);
    win->show();
}
