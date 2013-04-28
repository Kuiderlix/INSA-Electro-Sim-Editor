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

    QDoubleSpinBox * frequenceMinWidget = new QDoubleSpinBox();
    layout->addRow("Fréquence Min:",frequenceMinWidget);

    QDoubleSpinBox * frequenceMaxWidget = new QDoubleSpinBox();
    layout->addRow("Fréquence Max:",frequenceMaxWidget);

    QDoubleSpinBox * frequencePasWidget = new QDoubleSpinBox();
    layout->addRow("Pas Fréquence:",frequencePasWidget);

    QCheckBox * calculImageWidget = new QCheckBox();
    layout->addRow("Calcul Image:",calculImageWidget);

    QSpinBox * hauteurPlanMasseWidget = new QSpinBox();
    layout->addRow("Hauteur plan masse:",hauteurPlanMasseWidget);

    QSpinBox * pasDiscrTetaWidget = new QSpinBox();
    layout->addRow("Pas Discr Teta:",pasDiscrTetaWidget);

    QSpinBox * pasDiscrPhiWidget = new QSpinBox();
    layout->addRow("Pas Discr Phi:",pasDiscrPhiWidget);


    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

}
