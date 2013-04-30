#include "FormParallelepipede.h"

FormParallelepipede::FormParallelepipede(parallelepipede *paralle, int mode, QWidget *parent) :
    FormElementBase(paralle,mode,parent)
{
    this->paralle=paralle;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Parallélépipède");


    QFormLayout * layout = new QFormLayout;


    permitRelativeWidget = new QDoubleSpinBox();
    permitRelativeWidget->setValue(paralle->GetPermitRelative());
    layout->addRow("PermitRelative:", permitRelativeWidget);


    permeRelativeWidget = new QDoubleSpinBox();
    permeRelativeWidget->setValue(paralle->GetPermeRelative());
    layout->addRow("PermeRelative:",permeRelativeWidget);


    conductiviteWidget = new QDoubleSpinBox();
    conductiviteWidget->setValue(paralle->GetConductivite());
    layout->addRow("Conductivité:",conductiviteWidget);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

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
    permitRelativeWidget->setValue(0);
    permeRelativeWidget->setValue(0);
    conductiviteWidget->setValue(0);
    this->paralle = new parallelepipede();
    setElement(this->paralle);
}

