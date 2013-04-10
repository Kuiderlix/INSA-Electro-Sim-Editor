#include "FormParallelepipede.h"

FormParallelepipede::FormParallelepipede(parallelepipede *paralle, int mode, QWidget *parent) :
    FormElementBase(paralle,mode,parent)
{
    this->paralle=paralle;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Parallélépipède");


    QFormLayout * layout = new QFormLayout;


    QDoubleSpinBox * permitRelativeWidget = new QDoubleSpinBox();
    layout->addRow("PermitRelative:", permitRelativeWidget);


    QDoubleSpinBox * permeRelativeWidget = new QDoubleSpinBox();
    layout->addRow("PermeRelative:",permeRelativeWidget);


    QDoubleSpinBox * conductiviteWidget = new QDoubleSpinBox();
    layout->addRow("Conductivité:",conductiviteWidget);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}
