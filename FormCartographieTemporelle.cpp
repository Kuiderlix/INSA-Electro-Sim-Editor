#include "FormCartographieTemporelle.h"

FormCartographieTemporelle::FormCartographieTemporelle(cartographieTemporelle *carto, QWidget *parent) :
    FormElementBase(carto,parent)
{
    this->carto=carto;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Cartographie Temporelle");


    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutChampsE = new QHBoxLayout;
    layoutChampsE->addWidget(new QLabel("ChampsE:"));
    champsEWidget = new QCheckBox();
    layoutChampsE->addWidget(champsEWidget);
    layout->addLayout(layoutChampsE);


    QHBoxLayout * layoutChampsH = new QHBoxLayout;
    layoutChampsH->addWidget(new QLabel("ChampsH:"));
    champsHWidget = new QCheckBox();
    layoutChampsH->addWidget(champsHWidget);
    layout->addLayout(layoutChampsH);


    QHBoxLayout * layoutIterationDebut = new QHBoxLayout;
    layoutIterationDebut->addWidget(new QLabel("Itération Début:"));
    iterationDebutWidget = new QSpinBox();
    layoutIterationDebut->addWidget(iterationDebutWidget);
    layout->addLayout(layoutIterationDebut);


    QHBoxLayout * layoutIterationFin = new QHBoxLayout;
    layoutIterationFin->addWidget(new QLabel("Itération Fin:"));
    iterationFinWidget = new QSpinBox();
    layoutIterationFin->addWidget(iterationFinWidget);
    layout->addLayout(layoutIterationFin);


    QHBoxLayout * layoutIntervalle = new QHBoxLayout;
    layoutIntervalle->addWidget(new QLabel("Intervalle:"));
    intervalleWidget = new QSpinBox();
    layoutIntervalle->addWidget(intervalleWidget);
    layout->addLayout(layoutIntervalle);


    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    init();
}

void FormCartographieTemporelle::valider()
{
    FormElementBase::valider();
    carto->SetChampE(champsEWidget->isChecked());
    carto->SetChampH(champsHWidget->isChecked());
    carto->SetIterationDebut(iterationDebutWidget->value());
    carto->SetIterationFin(iterationFinWidget->value());
    carto->SetIntervalle(intervalleWidget->value());
    emit elementValide(carto);
}

void FormCartographieTemporelle::reset()
{
    FormElementBase::reset();
    carto = new cartographieTemporelle();
    setElement(carto);
    init();
}

void FormCartographieTemporelle::init()
{
    FormElementBase::init();
    champsEWidget->setChecked(carto->IsChampE());
    champsHWidget->setChecked(carto->IsChampH());
    iterationDebutWidget->setValue(carto->GetIterationDebut());
    iterationFinWidget->setValue(carto->GetIterationFin());
    intervalleWidget->setValue(carto->GetIntervalle());
}
