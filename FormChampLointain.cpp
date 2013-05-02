#include "FormChampLointain.h"

FormChampLointain::FormChampLointain(champLointain *champ, QWidget *parent) :
    QWidget(parent)
{
    this->champ=champ;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Calcul Champs Lointain");


    QFormLayout * layout = new QFormLayout;

    FormCoordonnees * origineRepereWidget = new FormCoordonnees(champ->GetOrigineRepere());
    layout->addRow("Origine Repère:",origineRepereWidget);
    connect(origineRepereWidget,SIGNAL(coordonneeChanged(coordonnee)),champ,SLOT(SetOrigineRepere(coordonnee)));

    QDoubleSpinBox * frequenceMinWidget = new QDoubleSpinBox();
    layout->addRow("Fréquence Min:",frequenceMinWidget);
    connect(frequenceMinWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetFrequenceMin(double)));

    QDoubleSpinBox * frequenceMaxWidget = new QDoubleSpinBox();
    layout->addRow("Fréquence Max:",frequenceMaxWidget);
    connect(frequenceMaxWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetFrequenceMax(double)));

    QDoubleSpinBox * frequencePasWidget = new QDoubleSpinBox();
    layout->addRow("Pas Fréquence:",frequencePasWidget);
    connect(frequencePasWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetPasFrequence(double)));

    QCheckBox * calculImageWidget = new QCheckBox();
    layout->addRow("Calcul Image:",calculImageWidget);
    connect(calculImageWidget,SIGNAL(clicked(bool)),champ,SLOT(SetCalculImage(bool)));

    QSpinBox * hauteurPlanMasseWidget = new QSpinBox();
    layout->addRow("Hauteur plan masse:",hauteurPlanMasseWidget);
    connect(hauteurPlanMasseWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetHauteurPlanMasse(int)));

    QSpinBox * pasDiscrTetaWidget = new QSpinBox();
    layout->addRow("Pas Discr Teta:",pasDiscrTetaWidget);
    connect(pasDiscrTetaWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetPasDiscrTeta(int)));

    QSpinBox * pasDiscrPhiWidget = new QSpinBox();
    layout->addRow("Pas Discr Phi:",pasDiscrPhiWidget);
    connect(pasDiscrPhiWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetPasDiscrPhi(int)));


    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

}
