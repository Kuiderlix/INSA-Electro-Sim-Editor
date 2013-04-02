#include "FormMetallisation.h"

FormMetallisation::FormMetallisation(metallisation* metal,int mode, QWidget *parent) :
    QWidget(parent)
{
    this->mode=mode;
    this->metal=metal;

    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutConduc = new QHBoxLayout;

    layoutConduc->addWidget(new QLabel("Conductivité:"));
    QDoubleSpinBox * lineEditConductivite = new QDoubleSpinBox();
    layoutConduc->addWidget(lineEditConductivite);

    layout->addLayout(layoutConduc);

    layout->addWidget(new QLabel("Coordonnees Avant Gauche:"));
    coordonnee coord = metal->GetAvantGauche();
    FormCoordonnees * formCoord1 = new FormCoordonnees(&coord);
    layout->addWidget(formCoord1);

    layout->addWidget(new QLabel("Coordonnees Arrière Droit:"));
    coordonnee coord2 = metal->GetArriereDroit();
    FormCoordonnees * formCoord2 = new FormCoordonnees(&coord2);
    layout->addWidget(formCoord2);

    layout->addWidget(new QPushButton("Valider"));

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);



}
