#include "FormMetallisation.h"

FormMetallisation::FormMetallisation(metallisation* metal,int mode, QWidget *parent) :
    FormElementBase(metal,mode,parent)
{
    this->metal=metal;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * groupGeo = new QGroupBox("Métallisation");

    QFormLayout * layout = new QFormLayout;

    lineEditConductivite = new QDoubleSpinBox();
    lineEditConductivite->setValue(metal->GetConductivite());
    layout->addRow("Conductivité:",lineEditConductivite);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}


void FormMetallisation::valider()
{
    FormElementBase::valider();
    metal->SetConductivite(lineEditConductivite->value());
    emit elementValide(metal);
}

void FormMetallisation::reset()
{
    FormElementBase::reset();

    lineEditConductivite->setValue(0);
    this->metal=new metallisation();
    setElement(this->metal);

}
