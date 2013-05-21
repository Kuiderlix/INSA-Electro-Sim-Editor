#include "FormAnalyseTempo.h"

FormAnalyseTempo::FormAnalyseTempo(analyseTemporelle *anaTempo, QWidget *parent) : QWidget(parent)
{
    this->anaTempo=anaTempo;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Analyse Temporelle");

    QFormLayout * layout = new QFormLayout;

    periodeWidget = new QDoubleSpinBox();
    periodeWidget->setMaximum(INT_MAX);
    layout->addRow("Période:",periodeWidget);
    connect(periodeWidget,SIGNAL(valueChanged(double)),anaTempo,SLOT(SetPeriode(double)));

    tempsWidget = new QDoubleSpinBox();
    tempsWidget->setMaximum(INT_MAX);
    layout->addRow("Temps:",tempsWidget);
    connect(tempsWidget,SIGNAL(valueChanged(double)),anaTempo,SLOT(SetTemps(double)));


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);

    init();
}

void FormAnalyseTempo::init()
{
    periodeWidget->setValue(anaTempo->GetPeriode());
    connect(periodeWidget,SIGNAL(valueChanged(double)),anaTempo,SLOT(SetPeriode(double)));

    tempsWidget->setValue(anaTempo->GetTemps());
    connect(tempsWidget,SIGNAL(valueChanged(double)),anaTempo,SLOT(SetTemps(double)));
}
