#include "FormElementLocalise.h"

FormElementLocalise::FormElementLocalise(elementLocalise *localise, int mode, QWidget *parent) :
    FormElementBase(localise,mode,parent)
{
    this->localise=localise;


    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Element Localise");

    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutType = new QHBoxLayout;
    layoutType->addWidget(new QLabel("Type:"));
    typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "Résistance" << "Capacité" << "Self");
    layoutType->addWidget(typeWidget);
    layout->addLayout(layoutType);


    QHBoxLayout * layoutValeur = new QHBoxLayout;
    layoutValeur->addWidget(new QLabel("Valeur:"));
    valeurWidget = new QDoubleSpinBox();
    layoutValeur->addWidget(valeurWidget);
    layout->addLayout(layoutValeur);



    QHBoxLayout * layoutDirection = new QHBoxLayout;
    layoutDirection->addWidget(new QLabel("Direction:"));
    directionWidget = new QComboBox();
    directionWidget->addItems(QStringList() << "x" << "y" << "z");
    layoutDirection->addWidget(directionWidget);
    layout->addLayout(layoutDirection);


    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    init();

}

void FormElementLocalise::valider()
{
    FormElementBase::valider();
    localise->SetDirection(directionWidget->currentIndex()+1);
    localise->SetType(typeWidget->currentIndex()+1);
    localise->SetValeur(valeurWidget->value());
    emit elementValide(localise);
}

void FormElementLocalise::reset()
{
    FormElementBase::reset();
    this->localise = new elementLocalise();
    setElement(this->localise);
    init();
}

void FormElementLocalise::init()
{
    FormElementBase::init();
    typeWidget->setCurrentIndex(localise->GetType());
    directionWidget->setCurrentIndex(localise->GetDirection());
    valeurWidget->setValue(localise->GetValeur());
}
