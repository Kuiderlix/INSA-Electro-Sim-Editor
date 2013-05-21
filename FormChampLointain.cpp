#include "FormChampLointain.h"

FormChampLointain::FormChampLointain(champLointain *champ, QWidget *parent) :
    QWidget(parent)
{
    this->champ=champ;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Calcul Champs Lointain");


    QFormLayout * layout = new QFormLayout;

    origineRepereWidget = new FormCoordonnees(champ->GetOrigineRepere());
    layout->addRow("Origine Repère:",origineRepereWidget);
    connect(origineRepereWidget,SIGNAL(coordonneeChanged(coordonnee)),champ,SLOT(SetOrigineRepere(coordonnee)));

    frequenceMinWidget = new QDoubleSpinBox();
    layout->addRow("Fréquence Min:",frequenceMinWidget);
    connect(frequenceMinWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetFrequenceMin(double)));

    frequenceMaxWidget = new QDoubleSpinBox();
    layout->addRow("Fréquence Max:",frequenceMaxWidget);
    connect(frequenceMaxWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetFrequenceMax(double)));

    frequencePasWidget = new QDoubleSpinBox();
    layout->addRow("Pas Fréquence:",frequencePasWidget);
    connect(frequencePasWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetPasFrequence(double)));

    calculImageWidget = new QCheckBox();
    layout->addRow("Calcul Image:",calculImageWidget);
    connect(calculImageWidget,SIGNAL(clicked(bool)),champ,SLOT(SetCalculImage(bool)));

    hauteurPlanMasseWidget = new QSpinBox();
    layout->addRow("Hauteur plan masse:",hauteurPlanMasseWidget);
    connect(hauteurPlanMasseWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetHauteurPlanMasse(int)));

    pasDiscrTetaWidget = new QSpinBox();
    layout->addRow("Pas Discr Teta:",pasDiscrTetaWidget);
    connect(pasDiscrTetaWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetPasDiscrTeta(int)));

    pasDiscrPhiWidget = new QSpinBox();
    layout->addRow("Pas Discr Phi:",pasDiscrPhiWidget);
    connect(pasDiscrPhiWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetPasDiscrPhi(int)));


    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

}

void FormChampLointain::init()
{
    origineRepereWidget->setCoordonnee(champ->GetOrigineRepere());
    connect(origineRepereWidget,SIGNAL(coordonneeChanged(coordonnee)),champ,SLOT(SetOrigineRepere(coordonnee)));

    frequenceMinWidget->setValue(champ->GetFrequenceMin());
    connect(frequenceMinWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetFrequenceMin(double)));

    frequenceMaxWidget->setValue(champ->GetFrequenceMax());
    connect(frequenceMaxWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetFrequenceMax(double)));

    frequencePasWidget->setValue(champ->GetPasFrequence());
    connect(frequencePasWidget,SIGNAL(valueChanged(double)),champ,SLOT(SetPasFrequence(double)));

    calculImageWidget->setChecked(champ->IsCalculImage());
    connect(calculImageWidget,SIGNAL(clicked(bool)),champ,SLOT(SetCalculImage(bool)));

    hauteurPlanMasseWidget->setValue(champ->GetHauteurPlanMasse());
    connect(hauteurPlanMasseWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetHauteurPlanMasse(int)));

    pasDiscrPhiWidget->setValue(champ->GetPasDiscrPhi());
    connect(pasDiscrTetaWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetPasDiscrTeta(int)));

    pasDiscrTetaWidget->setValue(champ->GetPasDiscrTeta());
    connect(pasDiscrPhiWidget,SIGNAL(valueChanged(int)),champ,SLOT(SetPasDiscrPhi(int)));
}
