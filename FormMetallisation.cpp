#include "FormMetallisation.h"

FormMetallisation::FormMetallisation(metallisation* metal,int mode, QWidget *parent) :
    FormElementBase(metal,mode,parent)
{
    this->metal=metal;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * groupGeo = new QGroupBox("Métallisation");

    QFormLayout * layout = new QFormLayout;

    QDoubleSpinBox * lineEditConductivite = new QDoubleSpinBox();
    layout->addRow("Conductivité:",lineEditConductivite);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}
