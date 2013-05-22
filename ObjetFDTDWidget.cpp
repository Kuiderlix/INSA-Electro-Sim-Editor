#include "ObjetFDTDWidget.h"

ObjetFDTDWidget::ObjetFDTDWidget(Data *data, QWidget *parent) :
    ToolBoxWidget(data,parent)
{


    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    formCageExci = new FormCageExcitation(data->getCageExcitation());

    FormSurfacePrelevement * formSurfacePrel = new FormSurfacePrelevement(new surfacePrelevement());
    connect(formSurfacePrel,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newSurfacePrelCreated(elementBase*)));
    connect(formSurfacePrel,SIGNAL(elementValide(elementBase*)),formSurfacePrel,SLOT(reset()));
    FormSonde * formSonde = new FormSonde(new sonde());
    connect(formSonde,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newSondeCreated(elementBase*)));
    connect(formSonde,SIGNAL(elementValide(elementBase*)),formSonde,SLOT(reset()));

    layout->addWidget(formCageExci);
    layout->addWidget(formSurfacePrel);
    layout->addWidget(formSonde);



    QHBoxLayout * layoutAvance = new QHBoxLayout;
    layoutAvance->addWidget(new QLabel("Cartographies Temporelles"));
    QPushButton * boutonAvance = new QPushButton("+");
    layoutAvance->addWidget(boutonAvance);
    this->connect(boutonAvance, SIGNAL(clicked()), this, SLOT(openCartoTempoWindows()));

    QWidget * widgetAvance = new QWidget();

    widgetAvance->setLayout(layoutAvance);


    layout->addWidget(widgetAvance);

    setLayout(layout);
}

void ObjetFDTDWidget::init()
{
    formCageExci->setCageExcitation(data->getCageExcitation());
}

void ObjetFDTDWidget::openCartoTempoWindows()
{
    FormCartographieTemporelle * win = new FormCartographieTemporelle(new cartographieTemporelle());
    connect(win,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newCartoTempoCreated(elementBase*)));
    connect(win,SIGNAL(elementValide(elementBase*)),win,SLOT(reset()));
    win->show();
}
