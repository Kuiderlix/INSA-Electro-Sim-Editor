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
    connect(frequenceMaxWidget,SIGNAL(valueChanged(double)),excit,SLOT(SetFrequenceMax(double)));


    QComboBox * typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "Gaussienne" << "Gaussienne modulant un sinus");
    typeWidget->setCurrentIndex(excit->GetType());
    layout->addRow("Type:", typeWidget);
    connect(typeWidget,SIGNAL(currentIndexChanged(int)),excit,SLOT(SetType(int)));
    connect(typeWidget,SIGNAL(currentIndexChanged(int)),this,SLOT(afficheSinus(int)));

    formTypeSinus = new QWidget();
    formTypeSinus->setVisible(false);
    QFormLayout * layoutSinus = new QFormLayout;
    layoutSinus->setMargin(0);
    QDoubleSpinBox * freqSinusWidget = new QDoubleSpinBox();
    freqSinusWidget->setMaximum(9999.9);
    freqSinusWidget->setValue(excit->GetFrequenceSinus());
    layoutSinus->addRow("Frequence Sinus:", freqSinusWidget);
    connect(freqSinusWidget,SIGNAL(valueChanged(double)),excit,SLOT(SetFrequenceSinus(double)));

    formTypeSinus->setLayout(layoutSinus);

    layout->addRow(formTypeSinus);


    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}

void FormParamExcitation::afficheSinus(int i)
{
    if (i==1)
    {
        formTypeSinus->setVisible(true);
    }
    else
    {
        formTypeSinus->setVisible(false);
    }
}

