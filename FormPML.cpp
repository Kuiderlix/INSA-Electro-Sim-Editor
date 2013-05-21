#include "FormPML.h"

FormPML::FormPML(pml *m_pml, QWidget *parent) :
    QWidget(parent)
{
    this->m_pml=m_pml;
    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("PML");

    QFormLayout * layout = new QFormLayout;

    epaisseurCoucheWidget = new QSpinBox();
    layout->addRow("Epaisseur Couche:",epaisseurCoucheWidget);
    connect(epaisseurCoucheWidget,SIGNAL(valueChanged(int)),m_pml,SLOT(SetEpaisseurCouche(int)));

    ordreVariationWidget = new QSpinBox();
    layout->addRow("Ordre variation:",ordreVariationWidget);
    connect(ordreVariationWidget,SIGNAL(valueChanged(int)),m_pml,SLOT(SetOrdreVariation(int)));

    sigmaMaxWidget = new QDoubleSpinBox();
    layout->addRow("Sigma Max:",sigmaMaxWidget);
    connect(sigmaMaxWidget,SIGNAL(valueChanged(double)),m_pml,SLOT(SetSigmaMax(double)));

    kMaxWidget = new QDoubleSpinBox();
    layout->addRow("k Max:",kMaxWidget);
    connect(kMaxWidget,SIGNAL(valueChanged(double)),m_pml,SLOT(SetKMax(double)));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

    init();
}

void FormPML::init()
{
    epaisseurCoucheWidget->setValue(m_pml->GetEpaisseurCouche());
    connect(epaisseurCoucheWidget,SIGNAL(valueChanged(int)),m_pml,SLOT(SetEpaisseurCouche(int)));
    ordreVariationWidget->setValue(m_pml->GetOrdreVariation());
    connect(ordreVariationWidget,SIGNAL(valueChanged(int)),m_pml,SLOT(SetOrdreVariation(int)));
    sigmaMaxWidget->setValue(m_pml->GetSigmaMax());
    connect(sigmaMaxWidget,SIGNAL(valueChanged(double)),m_pml,SLOT(SetSigmaMax(double)));
    kMaxWidget->setValue(m_pml->GetKMax());
    connect(kMaxWidget,SIGNAL(valueChanged(double)),m_pml,SLOT(SetKMax(double)));
}
