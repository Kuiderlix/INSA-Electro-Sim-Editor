#include "FormExcitation.h"

FormExcitation::FormExcitation(Excitation *excitation, QWidget *parent) :
    QWidget(parent)
{
    this->excitation=excitation;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Excitation");

    QFormLayout * layout = new QFormLayout;

    QDoubleSpinBox * amplitudeWidget = new QDoubleSpinBox();
    layout->addRow("Amplitude Vo:",amplitudeWidget);
    connect(amplitudeWidget,SIGNAL(valueChanged(double)),excitation,SLOT(SetAmplitudeV0(double)));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);
}
