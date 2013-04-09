#include "FormAnalyseTempo.h"

FormAnalyseTempo::FormAnalyseTempo(analyseTemporelle *anaTempo, QWidget *parent) : QWidget(parent)
{
    this->anaTempo=anaTempo;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Volume Calcul");

    QVBoxLayout * layout = new QVBoxLayout;


    QHBoxLayout * layoutPeriode = new QHBoxLayout;
    layoutPeriode->addWidget(new QLabel("Période:"));
    QDoubleSpinBox * periodeWidget = new QDoubleSpinBox();
    periodeWidget->setMaximum(9999.9);
    periodeWidget->setValue(anaTempo->GetPeriode());
    layoutPeriode->addWidget(periodeWidget);
    layout->addLayout(layoutPeriode);

    QHBoxLayout * layoutTemps = new QHBoxLayout;
    layoutTemps->addWidget(new QLabel("Temps:"));
    QDoubleSpinBox * tempsWidget = new QDoubleSpinBox();
    tempsWidget->setMaximum(9999.9);
    tempsWidget->setValue(anaTempo->GetTemps());
    layoutTemps->addWidget(tempsWidget);
    layout->addLayout(layoutTemps);


    layout->addWidget(new QPushButton("Valider"));


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);
}
