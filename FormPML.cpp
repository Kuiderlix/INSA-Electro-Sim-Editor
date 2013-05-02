#include "FormPML.h"

FormPML::FormPML(pml *m_pml, QWidget *parent) :
    QWidget(parent)
{
    this->m_pml=m_pml;
    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("PML");

    QFormLayout * layout = new QFormLayout;

    QSpinBox * epaisseurCoucheWidget = new QSpinBox();
    layout->addRow("Epaisseur Couche:",epaisseurCoucheWidget);
    connect(epaisseurCoucheWidget,SIGNAL(valueChanged(int)),m_pml,SLOT(SetEpaisseurCouche(int)));

    QSpinBox * ordreVariationWidget = new QSpinBox();
    layout->addRow("Ordre variation:",ordreVariationWidget);
    connect(ordreVariationWidget,SIGNAL(valueChanged(int)),m_pml,SLOT(SetOrdreVariation(int)));

    QDoubleSpinBox * sigmaMaxWidget = new QDoubleSpinBox();
    layout->addRow("Sigma Max:",sigmaMaxWidget);
    connect(sigmaMaxWidget,SIGNAL(valueChanged(double)),m_pml,SLOT(SetSigmaMax(double)));

    QDoubleSpinBox * kMaxWidget = new QDoubleSpinBox();
    layout->addRow("k Max:",kMaxWidget);
    connect(kMaxWidget,SIGNAL(valueChanged(double)),m_pml,SLOT(SetKMax(double)));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);
}
