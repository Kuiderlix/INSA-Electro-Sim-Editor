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
    formCoord1 = new FormCoordonnees(metal->GetAvantGauche());
    layout->addWidget(formCoord1);

    layout->addWidget(new QLabel("Coordonnees Arrière Droit:"));
    formCoord2 = new FormCoordonnees(metal->GetArriereDroit());
    layout->addWidget(formCoord2);

    boutonValider = new QPushButton("Valider");
    layout->addWidget(boutonValider);

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);



}
