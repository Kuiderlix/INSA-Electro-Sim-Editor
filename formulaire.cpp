#include "formulaire.h"

Formulaire::Formulaire(QWidget *parent) :
    QWidget(parent)
{
    layoutPrincipale = new QVBoxLayout();
    QGroupBox* conteneurPrincipale = new QGroupBox("Formulaire");

    QVBoxLayout *layoutGroupBox = new QVBoxLayout();

    layoutGroupBox->addWidget(new QLineEdit());
    layoutGroupBox->addWidget(new QPushButton("Ajouter"));
    layoutGroupBox->setAlignment(Qt::AlignTop);

    conteneurPrincipale->setLayout(layoutGroupBox);

    layoutPrincipale->addWidget(conteneurPrincipale);


    this->setLayout(layoutPrincipale);
}
