#include "FormExcitation.h"

FormExcitation::FormExcitation(excitations *excit, QWidget *parent) :
    QWidget(parent)
{
    this->excit=excit;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Paramètres Excitations");

    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutFrequenceMax = new QHBoxLayout;
    layoutFrequenceMax->addWidget(new QLabel("Frequence Max:"));
    QDoubleSpinBox * frequenceMaxWidget = new QDoubleSpinBox();
    frequenceMaxWidget->setMaximum(9999.9);
    frequenceMaxWidget->setValue(excit->GetFrequenceMax());
    layoutFrequenceMax->addWidget(frequenceMaxWidget);
    layout->addLayout(layoutFrequenceMax);

    QHBoxLayout * layoutType = new QHBoxLayout;
    layoutType->addWidget(new QLabel("Type:"));
    QComboBox * typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "Gaussienne" << "Gaussienne modulant un sinus");
    typeWidget->setCurrentIndex(excit->GetType());
    layoutType->addWidget(typeWidget);
    layout->addLayout(layoutType);



    QHBoxLayout * layoutFreqSinus = new QHBoxLayout;
    layoutFreqSinus->addWidget(new QLabel("Frequence Sinus:"));
    QDoubleSpinBox * freqSinusWidget = new QDoubleSpinBox();
    freqSinusWidget->setMaximum(9999.9);
    freqSinusWidget->setValue(excit->GetFrequenceSinus());
    layoutFreqSinus->addWidget(freqSinusWidget);
    layout->addLayout(layoutFreqSinus);

    layout->addWidget(new QPushButton("Valider"));

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}
