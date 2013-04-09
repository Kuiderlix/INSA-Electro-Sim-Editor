#include "ObjetFDTDWidget.h"

ObjetFDTDWidget::ObjetFDTDWidget(QWidget *parent) :
    QWidget(parent)
{


    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormCageExcitation * formCageExci = new FormCageExcitation(new cageExcitation(), FormCageExcitation::NOUVEAU);
    FormSurfacePrelevement * formSurfacePrel = new FormSurfacePrelevement(new surfacePrelevement(), FormSurfacePrelevement::NOUVEAU);
    FormSonde * formSonde = new FormSonde(new sonde(), FormSonde::NOUVEAU);

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

void ObjetFDTDWidget::openCartoTempoWindows()
{
    FormCartographieTemporelle * win = new FormCartographieTemporelle(new cartographieTemporelle(), FormCartographieTemporelle::NOUVEAU);
    win->show();
}
