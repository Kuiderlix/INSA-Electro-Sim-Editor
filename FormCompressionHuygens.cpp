#include "FormCompressionHuygens.h"

FormCompressionHuygens::FormCompressionHuygens(compressionHuygens *compreHuy, QWidget *parent) :
    QWidget(parent)
{
    this->compreHuy=compreHuy;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Compression Huygens");


    QFormLayout * layout = new QFormLayout;

    QSpinBox * compLongWidget = new QSpinBox();
    layout->addRow("Compression Longueur:",compLongWidget);
    connect(compLongWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionLongueur(int)));

    QSpinBox * compLargWidget = new QSpinBox();
    layout->addRow("Compression Largeur:",compLargWidget);
    connect(compLargWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionLargeur(int)));


    QSpinBox * compHautWidget = new QSpinBox();
    layout->addRow("Compression Hauteur:",compHautWidget);
    connect(compHautWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetCompressionHauteur(int)));


    QSpinBox * facteurMultiWidget = new QSpinBox();
    layout->addRow("Facteur Multiplicatif:",facteurMultiWidget);
    connect(facteurMultiWidget,SIGNAL(valueChanged(int)),compreHuy,SLOT(SetFacteurMultiplicatif(int)));



    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);


}
