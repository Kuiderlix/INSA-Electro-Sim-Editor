#include "FormCalculDirective.h"

FormCalculDirective::FormCalculDirective(calculDirectivite *calDir, QWidget *parent) :
    QWidget(parent)
{
    this->calDir=calDir;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Calcul Directive");

    QFormLayout * layout = new QFormLayout;

    calculHWidget = new QCheckBox();
    layout->addRow("Calcul:",calculHWidget);
    connect(calculHWidget,SIGNAL(clicked(bool)),calDir,SLOT(SetCalcul(bool)));

    pasThetaWidget = new QSpinBox();
    pasThetaWidget->setMaximum(9999);
    pasThetaWidget->setValue(calDir->GetPasTheta());
    layout->addRow("pasTheta:",pasThetaWidget);
    connect(pasThetaWidget,SIGNAL(valueChanged(int)),calDir,SLOT(SetPasTheta(int)));

    pasPhiWidget = new QSpinBox();
    pasPhiWidget->setMaximum(9999);
    pasPhiWidget->setValue(calDir->GetPasPhi());
    layout->addRow("pasPhi:",pasPhiWidget);
    connect(pasPhiWidget,SIGNAL(valueChanged(int)),calDir,SLOT(SetPasPhi(int)));

    layout->setAlignment(Qt::AlignTop);
    group->setLayout(layout);
    layoutPrincipal->addWidget(group);
    setLayout(layoutPrincipal);

    init();

}

void FormCalculDirective::init()
{
    calculHWidget->setChecked(calDir->IsCalcul());
    connect(calculHWidget,SIGNAL(clicked(bool)),calDir,SLOT(SetCalcul(bool)));
    pasThetaWidget->setValue(calDir->GetPasTheta());
    connect(pasThetaWidget,SIGNAL(valueChanged(int)),calDir,SLOT(SetPasTheta(int)));
    pasPhiWidget->setValue(calDir->GetPasPhi());
    connect(pasPhiWidget,SIGNAL(valueChanged(int)),calDir,SLOT(SetPasPhi(int)));
}
