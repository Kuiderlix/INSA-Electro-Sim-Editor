#include "FormPortExcitation.h"

FormPortExcitation::FormPortExcitation(portExcitation *port, int mode, QWidget *parent) :
    FormElementBase(port,mode,parent)
{
    this->port=port;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->setMargin(0);
    QGroupBox * groupGeo = new QGroupBox("Port Excitation");

    QVBoxLayout * layout = new QVBoxLayout;


    QHBoxLayout * layoutPortActif = new QHBoxLayout;
    layoutPortActif->addWidget(new QLabel("Port Actif:"));
    QCheckBox * portActifWidget = new QCheckBox();
    layoutPortActif->addWidget(portActifWidget);
    layout->addLayout(layoutPortActif);


    QHBoxLayout * layoutPortInfinitesimal = new QHBoxLayout;
    layoutPortInfinitesimal->addWidget(new QLabel("Port Infinitesimal:"));
    QCheckBox * portInfinitesimalWidget = new QCheckBox();
    layoutPortInfinitesimal->addWidget(portInfinitesimalWidget);
    layout->addLayout(layoutPortInfinitesimal);


    QHBoxLayout * layoutTypePort = new QHBoxLayout;
    layoutTypePort->addWidget(new QLabel("Type Port:"));
    QComboBox * typePortWidget = new QComboBox();
    typePortWidget->addItems(QStringList() << "Magnétique" << "Electrique");
    layoutTypePort->addWidget(typePortWidget);
    layout->addLayout(layoutTypePort);


    QHBoxLayout * layoutDirection = new QHBoxLayout;
    layoutDirection->addWidget(new QLabel("Direction:"));
    QComboBox * directionWidget = new QComboBox();
    directionWidget->addItems(QStringList() << "x" << "y" << "z");
    layoutDirection->addWidget(directionWidget);
    layout->addLayout(layoutDirection);


    QHBoxLayout * layoutImpedance = new QHBoxLayout;
    layoutImpedance->addWidget(new QLabel("Impédance:"));
    QDoubleSpinBox * impedanceWidget = new QDoubleSpinBox();
    layoutImpedance->addWidget(impedanceWidget);
    layout->addLayout(layoutImpedance);



    QHBoxLayout * layoutTypeSource = new QHBoxLayout;
    layoutTypeSource->addWidget(new QLabel("Type Source:"));
    QComboBox * typeSourceWidget = new QComboBox();
    typeSourceWidget->addItems(QStringList() << "Tension" << "Courant");
    layoutTypeSource->addWidget(typeSourceWidget);
    layout->addLayout(layoutTypeSource);


    QHBoxLayout * layoutPonderationAmplitude = new QHBoxLayout;
    layoutPonderationAmplitude->addWidget(new QLabel("Ponderation Amplitude:"));
    QDoubleSpinBox * ponderationAmplitudeWidget = new QDoubleSpinBox();
    layoutPonderationAmplitude->addWidget(ponderationAmplitudeWidget);
    layout->addLayout(layoutPonderationAmplitude);


    QHBoxLayout * layoutPonderationPhase = new QHBoxLayout;
    layoutPonderationPhase->addWidget(new QLabel("Ponderation Phase:"));
    QDoubleSpinBox * ponderationPhaseWidget = new QDoubleSpinBox();
    layoutPonderationPhase->addWidget(ponderationPhaseWidget);
    layout->addLayout(layoutPonderationPhase);

    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

}
