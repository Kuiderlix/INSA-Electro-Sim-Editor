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

    QDoubleSpinBox * tempsWidget = new QDoubleSpinBox();
    tempsWidget->setMaximum(9999.9);
    tempsWidget->setValue(anaTempo->GetTemps());
    layout->addRow("Temps:",tempsWidget);


    layout->addRow(new QPushButton("Valider"));


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);
}
