#include "FormElementLocalise.h"

FormElementLocalise::FormElementLocalise(elementLocalise *localise, int mode, QWidget *parent) :
    FormElementBase(localise,mode,parent)
{
    this->localise=localise;


    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutType = new QHBoxLayout;
    layoutType->addWidget(new QLabel("Type:"));
    QComboBox * typeWidget = new QComboBox();
    typeWidget->addItems(QStringList() << "1" << "2" << "3");
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
    directionWidget->addItems(QStringList() << "1" << "2" << "3");
    layoutDirection->addWidget(directionWidget);
    layout->addLayout(layoutDirection);


    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);



}
