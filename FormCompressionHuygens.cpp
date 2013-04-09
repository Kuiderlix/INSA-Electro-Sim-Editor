#include "FormCompressionHuygens.h"

FormCompressionHuygens::FormCompressionHuygens(compressionHuygens *compreHuy, QWidget *parent) :
    QWidget(parent)
{
    this->compreHuy=compreHuy;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Compression Huygens");


    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutCompLong = new QHBoxLayout;
    layoutCompLong->addWidget(new QLabel("Compression Longueur:"));
    QSpinBox * compLongWidget = new QSpinBox();
    layoutCompLong->addWidget(compLongWidget);
    layout->addLayout(layoutCompLong);


    QHBoxLayout * layoutCompLarg = new QHBoxLayout;
    layoutCompLarg->addWidget(new QLabel("Compression Largeur:"));
    QSpinBox * compLargWidget = new QSpinBox();
    layoutCompLarg->addWidget(compLargWidget);
    layout->addLayout(layoutCompLarg);


    QHBoxLayout * layoutCompHaut = new QHBoxLayout;
    layoutCompHaut->addWidget(new QLabel("Compression Hauteur:"));
    QSpinBox * compHautWidget = new QSpinBox();
    layoutCompHaut->addWidget(compHautWidget);
    layout->addLayout(layoutCompHaut);


    QHBoxLayout * layoutFacteurMulti = new QHBoxLayout;
    layoutFacteurMulti->addWidget(new QLabel("Facteur Multiplicatif:"));
    QSpinBox * facteurMultiWidget = new QSpinBox();
    layoutFacteurMulti->addWidget(facteurMultiWidget);
    layout->addLayout(layoutFacteurMulti);


    layout->addWidget(new QPushButton("Valider"));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);


}
