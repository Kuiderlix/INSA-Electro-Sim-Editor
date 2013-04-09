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
    QComboBox * typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "Résistance" << "Capacité" << "Self");
    layoutType->addWidget(typeWidget);
    layout->addLayout(layoutType);


    QHBoxLayout * layoutValeur = new QHBoxLayout;
    layoutValeur->addWidget(new QLabel("Valeur:"));
    QDoubleSpinBox * valeurWidget = new QDoubleSpinBox();
    layoutValeur->addWidget(valeurWidget);
    layout->addLayout(layoutValeur);



    QHBoxLayout * layoutDirection = new QHBoxLayout;
    layoutDirection->addWidget(new QLabel("Direction:"));
    QComboBox * directionWidget = new QComboBox();
    directionWidget->addItems(QStringList() << "x" << "y" << "z");
    layoutDirection->addWidget(directionWidget);
    layout->addLayout(layoutDirection);


    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}
