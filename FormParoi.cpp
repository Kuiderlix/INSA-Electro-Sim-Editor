#include "FormParoi.h"

FormParoi::FormParoi(paroi *m_paroi, QWidget *parent) :
    QWidget(parent)
{

    this->m_paroi=m_paroi;
    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Paroi");

    QFormLayout * layout = new QFormLayout;


    QComboBox * inferieurWidget = new QComboBox();
    inferieurWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    inferieurWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layout->addRow("Inférieur:",inferieurWidget);

    QComboBox * superieurWidget = new QComboBox();
    superieurWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    superieurWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layout->addRow("Superieur:",superieurWidget);

    QComboBox * axeXWidget = new QComboBox();
    axeXWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    axeXWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layout->addRow("Axe X:",axeXWidget);

    QComboBox * axeYWidget = new QComboBox();
    axeYWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    axeYWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    layout->addRow("Axe Y:",axeYWidget);


    layout->addRow(new QPushButton("Valider"));


    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);
}
