#include "FormParamExcitation.h"

FormParamExcitation::FormParamExcitation(ParamExcitations *excit, QWidget *parent) :
    QWidget(parent)
{
    this->excit=excit;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Paramètres Excitations");

    QFormLayout * layout = new QFormLayout;

    QDoubleSpinBox * frequenceMaxWidget = new QDoubleSpinBox();
    frequenceMaxWidget->setMaximum(9999.9);
    frequenceMaxWidget->setValue(excit->GetFrequenceMax());
    layout->addRow("Frequence Max:", frequenceMaxWidget);


    QComboBox * typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "Gaussienne" << "Gaussienne modulant un sinus");
    typeWidget->setCurrentIndex(excit->GetType());
    layout->addRow("Type:", typeWidget);



    QDoubleSpinBox * freqSinusWidget = new QDoubleSpinBox();
    freqSinusWidget->setMaximum(9999.9);
    freqSinusWidget->setValue(excit->GetFrequenceSinus());
    layout->addRow("Frequence Sinus:", freqSinusWidget);


    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}
