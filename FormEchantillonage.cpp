#include "FormEchantillonage.h"

FormEchantillonage::FormEchantillonage(blocEchantillonnage *echanti, QWidget *parent) :
    QWidget(parent)
{
    this->echanti=echanti;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Echantillonnage");

    QFormLayout * layout = new QFormLayout;

    facteurWidget = new QSpinBox();
    layout->addRow("Facteur:",facteurWidget);
    connect(facteurWidget,SIGNAL(valueChanged(int)),echanti,SLOT(SetFacteurEchatillonnage(int)));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

    init();
}

void FormEchantillonage::init()
{
    facteurWidget->setValue(echanti->GetFacteurEchatillonnage());
    connect(facteurWidget,SIGNAL(valueChanged(int)),echanti,SLOT(SetFacteurEchatillonnage(int)));
}
