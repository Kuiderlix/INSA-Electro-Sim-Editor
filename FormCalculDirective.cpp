#include "FormCalculDirective.h"

FormCalculDirective::FormCalculDirective(calculDirectivite *calDir, QWidget *parent) :
    QWidget(parent)
{
    this->calDir=calDir;



    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Calcul Directive");

    QFormLayout * layout = new QFormLayout;

    QCheckBox * calculHWidget = new QCheckBox();
    layout->addRow("Calcul:",calculHWidget);

    QDoubleSpinBox * pasThetaWidget = new QDoubleSpinBox();
    pasThetaWidget->setMaximum(9999.9);
    pasThetaWidget->setValue(calDir->GetPasTheta());
    layout->addRow("pasTheta:",pasThetaWidget);

    QDoubleSpinBox * pasPhiWidget = new QDoubleSpinBox();
    pasPhiWidget->setMaximum(9999.9);
    pasPhiWidget->setValue(calDir->GetPasPhi());
    layout->addRow("pasPhi:",pasPhiWidget);


    layout->addRow(new QPushButton("Valider"));


    layout->setAlignment(Qt::AlignTop);
    group->setLayout(layout);
    layoutPrincipal->addWidget(group);
    setLayout(layoutPrincipal);

}
