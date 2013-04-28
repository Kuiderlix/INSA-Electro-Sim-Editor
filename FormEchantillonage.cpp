#include "FormEchantillonage.h"

FormEchantillonage::FormEchantillonage(blocEchantillonnage *echanti, QWidget *parent) :
    QWidget(parent)
{
    this->echanti=echanti;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Echantillonnage");

    QFormLayout * layout = new QFormLayout;

    QSpinBox * facteurWidget = new QSpinBox();
    layout->addRow("Facteur:",facteurWidget);

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);
}
