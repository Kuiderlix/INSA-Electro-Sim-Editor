#include "FormParoi.h"

FormParoi::FormParoi(paroi *m_paroi, QWidget *parent) :
    QWidget(parent)
{

    this->m_paroi=m_paroi;
    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Paroi");

    QFormLayout * layout = new QFormLayout;


    inferieurWidget = new QComboBox();
    inferieurWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    layout->addRow("Inférieur:",inferieurWidget);
    connect(inferieurWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiInferieure(int)));

    superieurWidget = new QComboBox();
    superieurWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    layout->addRow("Superieur:",superieurWidget);
    connect(superieurWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiSuperieure(int)));

    axeXWidget = new QComboBox();
    axeXWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    layout->addRow("Axe X:",axeXWidget);
    connect(axeXWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiX(int)));

    axeYWidget = new QComboBox();
    axeYWidget->addItems(QStringList() << "MUR" << "PEC" << "FLOQUET" << "PML" << "PMC");
    layout->addRow("Axe Y:",axeYWidget);
    connect(axeYWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiY(int)));

    layout->setAlignment(Qt::AlignTop);
    groupGeo->setLayout(layout);
    layoutPrincipal->addWidget(groupGeo);
    setLayout(layoutPrincipal);

    init();
}

void FormParoi::init()
{
    inferieurWidget->setCurrentIndex(m_paroi->GetParoiInferieure());
    connect(inferieurWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiInferieure(int)));

    superieurWidget->setCurrentIndex(m_paroi->GetParoiSuperieure());
    connect(superieurWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiSuperieure(int)));

    axeXWidget->setCurrentIndex(m_paroi->GetParoiX());
    connect(axeXWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiX(int)));

    axeYWidget->setCurrentIndex(m_paroi->GetParoiY());
    connect(axeYWidget,SIGNAL(currentIndexChanged(int)),m_paroi,SLOT(SetParoiY(int)));
}
