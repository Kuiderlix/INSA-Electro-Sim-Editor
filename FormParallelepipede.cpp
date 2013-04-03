#include "FormParallelepipede.h"

FormParallelepipede::FormParallelepipede(parallelepipede *paralle, int mode, QWidget *parent) :
    FormElementBase(paralle,mode,parent)
{
    this->paralle=paralle;


    QVBoxLayout * layout = new QVBoxLayout;


    QHBoxLayout * layoutPermitRelative = new QHBoxLayout;
    layoutPermitRelative->addWidget(new QLabel("PermitRelative:"));
    QDoubleSpinBox * permitRelativeWidget = new QDoubleSpinBox();
    layoutPermitRelative->addWidget(permitRelativeWidget);
    layout->addLayout(layoutPermitRelative);


    QHBoxLayout * layoutPermeRelative = new QHBoxLayout;
    layoutPermeRelative->addWidget(new QLabel("PermeRelative:"));
    QDoubleSpinBox * permeRelativeWidget = new QDoubleSpinBox();
    layoutPermeRelative->addWidget(permeRelativeWidget);
    layout->addLayout(layoutPermeRelative);


    QHBoxLayout * layoutConduc = new QHBoxLayout;
    layoutConduc->addWidget(new QLabel("Conductivité:"));
    QDoubleSpinBox * conductiviteWidget = new QDoubleSpinBox();
    layoutConduc->addWidget(conductiviteWidget);
    layout->addLayout(layoutConduc);

    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);




}
