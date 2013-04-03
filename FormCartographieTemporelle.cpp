#include "FormCartographieTemporelle.h"

FormCartographieTemporelle::FormCartographieTemporelle(cartographieTemporelle *carto, int mode, QWidget *parent) :
    FormElementBase(carto,mode,parent)
{
    this->carto=carto;



    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutChampsE = new QHBoxLayout;
    layoutChampsE->addWidget(new QLabel("ChampsE:"));
    QCheckBox * champsEWidget = new QCheckBox();
    layoutChampsE->addWidget(champsEWidget);
    layout->addLayout(layoutChampsE);


    QHBoxLayout * layoutChampsH = new QHBoxLayout;
    layoutChampsH->addWidget(new QLabel("ChampsH:"));
    QCheckBox * champsHWidget = new QCheckBox();
    layoutChampsH->addWidget(champsHWidget);
    layout->addLayout(layoutChampsH);


    QHBoxLayout * layoutIterationDebut = new QHBoxLayout;
    layoutIterationDebut->addWidget(new QLabel("Itération Début:"));
    QSpinBox * iterationDebutWidget = new QSpinBox();
    layoutIterationDebut->addWidget(iterationDebutWidget);
    layout->addLayout(layoutIterationDebut);


    QHBoxLayout * layoutIterationFin = new QHBoxLayout;
    layoutIterationFin->addWidget(new QLabel("Itération Fin:"));
    QSpinBox * iterationFinWidget = new QSpinBox();
    layoutIterationFin->addWidget(iterationFinWidget);
    layout->addLayout(layoutIterationFin);


    QHBoxLayout * layoutIntervalle = new QHBoxLayout;
    layoutIntervalle->addWidget(new QLabel("Intervalle:"));
    QSpinBox * intervalleWidget = new QSpinBox();
    layoutIntervalle->addWidget(intervalleWidget);
    layout->addLayout(layoutIntervalle);


    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);


}
