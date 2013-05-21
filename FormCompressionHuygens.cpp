#include "FormCompressionHuygens.h"

FormCompressionHuygens::FormCompressionHuygens(compressionHuygens *compreHuy, QWidget *parent) :
    QWidget(parent)
{
    this->compreHuy=compreHuy;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Compression Huygens");


    QFormLayout * layout = new QFormLayout;

    compLongWidget = new QSpinBox();
    layout->addRow("Compression Longueur:",compLongWidget);
    connect(compLongWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionLongueur(int)));

    compLargWidget = new QSpinBox();
    layout->addRow("Compression Largeur:",compLargWidget);
    connect(compLargWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionLargeur(int)));


    compHautWidget = new QSpinBox();
    layout->addRow("Compression Hauteur:",compHautWidget);
    connect(compHautWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionHauteur(int)));


    facteurMultiWidget = new QSpinBox();
    layout->addRow("Facteur Multiplicatif:",facteurMultiWidget);
    connect(facteurMultiWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetFacteurMultiplicatif(int)));



    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);

    init();


}

void FormCompressionHuygens::init()
{
    compLongWidget->setValue(compreHuy->GetCompressionLongueur());
    connect(compLongWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionLongueur(int)));

    compLargWidget->setValue(compreHuy->GetCompressionLargeur());
    connect(compLargWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionLargeur(int)));

    compHautWidget->setValue(compreHuy->GetCompressionHauteur());
    connect(compHautWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionHauteur(int)));

    facteurMultiWidget->setValue(compreHuy->GetFacteurMultiplicatif());
    connect(facteurMultiWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetFacteurMultiplicatif(int)));
}
