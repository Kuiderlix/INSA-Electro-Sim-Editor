#include "FormExcitation.h"

FormExcitation::FormExcitation(Excitation *excitation, QWidget *parent) :
    QWidget(parent)
{
    this->excitation=excitation;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Excitation");

    QFormLayout * layout = new QFormLayout;

    amplitudeWidget = new QDoubleSpinBox();
    layout->addRow("Amplitude Vo:",amplitudeWidget);
    connect(amplitudeWidget,SIGNAL(valueChanged(double)),excitation,SLOT(SetAmplitudeV0(double)));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

    init();
}

void FormExcitation::init()
{
    amplitudeWidget->setValue(excitation->GetAmplitudeV0());
    connect(amplitudeWidget,SIGNAL(valueChanged(double)),excitation,SLOT(SetAmplitudeV0(double)));
}
