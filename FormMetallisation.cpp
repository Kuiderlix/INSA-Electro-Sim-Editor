#include "FormMetallisation.h"

FormMetallisation::FormMetallisation(metallisation* metal,int mode, QWidget *parent) :
    FormElementBase(metal,mode,parent)
{
    this->metal=metal;

    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutConduc = new QHBoxLayout;

    layoutConduc->addWidget(new QLabel("Conductivité:"));
    QDoubleSpinBox * lineEditConductivite = new QDoubleSpinBox();
    layoutConduc->addWidget(lineEditConductivite);

    layout->addLayout(layoutConduc);

    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);



}
