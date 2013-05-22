#include "FormParallelepipede.h"

FormParallelepipede::FormParallelepipede(parallelepipede *paralle, QWidget *parent) :
    FormElementBase(paralle,parent)
{
    this->paralle=paralle;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Parallélépipède");


    QFormLayout * layout = new QFormLayout;


    permitRelativeWidget = new QDoubleSpinBox();
    layout->addRow("PermitRelative:", permitRelativeWidget);


    permeRelativeWidget = new QDoubleSpinBox();
    layout->addRow("PermeRelative:",permeRelativeWidget);


    conductiviteWidget = new QDoubleSpinBox();
    layout->addRow("Conductivité:",conductiviteWidget);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);
    init();

}

void FormParallelepipede::valider()
{
    FormElementBase::valider();
    paralle->SetConductivite(conductiviteWidget->value());
    paralle->SetPermitRelative(permitRelativeWidget->value());
    paralle->SetPermeRelative(permeRelativeWidget->value());
    emit elementValide(paralle);
}

void FormParallelepipede::reset()
{
    FormElementBase::reset();
    this->paralle = new parallelepipede();
    setElement(this->paralle);
    init();
}

void FormParallelepipede::init()
{
    FormElementBase::init();
    permitRelativeWidget->setValue(paralle->GetPermitRelative());
    permeRelativeWidget->setValue(paralle->GetPermeRelative());
    conductiviteWidget->setValue(paralle->GetConductivite());
}

