#include "FormOuvrir.h"

FormOuvrir::FormOuvrir(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout * layout = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Ouvrir une simulation");

    QVBoxLayout *layoutGroup = new QVBoxLayout();

    QFormLayout * layoutForm = new QFormLayout();
    nbrSimu = new QSpinBox();
    connect(nbrSimu,SIGNAL(valueChanged(int)),this,SLOT(setNum(int)));
    layoutForm->addRow("N°", nbrSimu);

    layoutGroup->addLayout(layoutForm);

    QHBoxLayout * layoutBouton = new QHBoxLayout;
    validerBouton = new QPushButton("Valider");
    validerBouton->setDefault(true);
    connect(validerBouton,SIGNAL(clicked()),this,SLOT(accept()));
    layoutBouton->addWidget(validerBouton);

    annulerBouton = new QPushButton("Annuler");
    connect(annulerBouton,SIGNAL(clicked()),this,SLOT(reject()));
    layoutBouton->addWidget(annulerBouton);

    layoutGroup->addLayout(layoutBouton);

    group->setLayout(layoutGroup);

    layout->addWidget(group);

    setLayout(layout);
}

void FormOuvrir::setNum(int i)
{
    num=i;
}
