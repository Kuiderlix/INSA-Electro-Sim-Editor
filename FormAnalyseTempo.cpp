#include "FormAnalyseTempo.h"

FormAnalyseTempo::FormAnalyseTempo(analyseTemporelle *anaTempo, QWidget *parent) : QWidget(parent)
{
    this->anaTempo=anaTempo;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Analyse Temporelle");

    QFormLayout * layout = new QFormLayout;


    QDoubleSpinBox * periodeWidget = new QDoubleSpinBox();
    periodeWidget->setMaximum(9999.9);
    periodeWidget->setValue(anaTempo->GetPeriode());
    layout->addRow("Période:",periodeWidget);
    connect(periodeWidget,SIGNAL(valueChanged(double)),anaTempo,SLOT(SetPeriode(double)));

    QDoubleSpinBox * tempsWidget = new QDoubleSpinBox();
    tempsWidget->setMaximum(9999.9);
    tempsWidget->setValue(anaTempo->GetTemps());
    layout->addRow("Temps:",tempsWidget);
    connect(tempsWidget,SIGNAL(valueChanged(double)),anaTempo,SLOT(SetTemps(double)));


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);
}
