#include "FormMetallisation.h"

FormMetallisation::FormMetallisation(metallisation* metal,int mode, QWidget *parent) :
    FormElementBase(metal,mode,parent)
{
    this->metal=metal;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * groupGeo = new QGroupBox("Métallisation");

    QFormLayout * layout = new QFormLayout;

    lineEditConductivite = new QDoubleSpinBox();
    layout->addRow("Conductivité:",lineEditConductivite);

    layout->addRow(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    init();

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

    this->metal=new metallisation();
    setElement(this->metal);

    init();
}

void FormMetallisation::init()
{
    FormElementBase::init();
    lineEditConductivite->setValue(metal->GetConductivite());
}
