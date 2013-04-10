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

    QSpinBox * compLargWidget = new QSpinBox();
    layout->addRow("Compression Largeur:",compLargWidget);


    QSpinBox * compHautWidget = new QSpinBox();
    layout->addRow("Compression Hauteur:",compHautWidget);


    QSpinBox * facteurMultiWidget = new QSpinBox();
    layout->addRow("Facteur Multiplicatif:",facteurMultiWidget);


    layout->addRow(new QPushButton("Valider"));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);


}
