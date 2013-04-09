#include "FormParoi.h"

FormParoi::FormParoi(paroi *m_paroi, QWidget *parent) :
    QWidget(parent)
{

    this->m_paroi=m_paroi;
    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Paroi");

    QVBoxLayout * layout = new QVBoxLayout;



    QHBoxLayout * layoutInferieur = new QHBoxLayout;
    layoutInferieur->addWidget(new QLabel("Inferieur:"));
    QComboBox * inferieurWidget = new QComboBox();
    inferieurWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    inferieurWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layoutInferieur->addWidget(inferieurWidget);
    layout->addLayout(layoutInferieur);


    QHBoxLayout * layoutSuperieur = new QHBoxLayout;
    layoutSuperieur->addWidget(new QLabel("Superieur:"));
    QComboBox * superieurWidget = new QComboBox();
    superieurWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    superieurWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layoutSuperieur->addWidget(superieurWidget);
    layout->addLayout(layoutSuperieur);


    QHBoxLayout * layoutAxeX = new QHBoxLayout;
    layoutAxeX->addWidget(new QLabel("Axe X:"));
    QComboBox * axeXWidget = new QComboBox();
    axeXWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    axeXWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layoutAxeX->addWidget(axeXWidget);
    layout->addLayout(layoutAxeX);


    QHBoxLayout * layoutAxeY = new QHBoxLayout;
    layoutAxeY->addWidget(new QLabel("Axe Y:"));
    QComboBox * axeYWidget = new QComboBox();
    axeYWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    axeYWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layoutAxeY->addWidget(axeYWidget);
    layout->addLayout(layoutAxeY);


    layout->addWidget(new QPushButton("Valider"));


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);
}
