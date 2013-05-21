#include "DescriptionGeoWidget.h"

DescriptionGeoWidget::DescriptionGeoWidget(Data *data, QWidget *parent) :
    ToolBoxWidget(data,parent)
{

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormMetallisation * formMetal = new FormMetallisation(new metallisation(), FormMetallisation::NOUVEAU);
    connect(formMetal,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newMetalCreated(elementBase*)));
    connect(formMetal,SIGNAL(elementValide(elementBase*)),formMetal,SLOT(reset()));
    FormParallelepipede * formPara = new FormParallelepipede(new parallelepipede(), FormParallelepipede::NOUVEAU);
    connect(formPara,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newParaCreated(elementBase*)));
    connect(formPara,SIGNAL(elementValide(elementBase*)),formPara,SLOT(reset()));

    formVolCal = new FormVolumeCalcul(data->getVolumeCalcul());

    formParoi = new FormParoi(data->getParoi());

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

    init();
}

void DescriptionGeoWidget::openElementLocaliseWindows()
{
    FormElementLocalise * win = new FormElementLocalise(new elementLocalise(), FormElementLocalise::NOUVEAU);
    connect(win,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newElemLocCreated(elementBase*)));
    connect(win,SIGNAL(elementValide(elementBase*)),win,SLOT(reset()));
    connect(win,SIGNAL(elementValide(elementBase*)),win,SLOT(accept()));
    win->exec();
}


void DescriptionGeoWidget::init()
{
    formVolCal->setVolumeCalcul(data->getVolumeCalcul());
    formParoi->setParoi(data->getParoi());
}
