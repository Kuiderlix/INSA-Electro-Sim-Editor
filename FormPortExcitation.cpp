#include "FormPortExcitation.h"

FormPortExcitation::FormPortExcitation(portExcitation *port, QWidget *parent) :
    FormElementBase(port,parent)
{
    this->port=port;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * groupGeo = new QGroupBox("Port Excitation");

    QVBoxLayout * layout = new QVBoxLayout;


    QHBoxLayout * layoutPortActif = new QHBoxLayout;
    layoutPortActif->addWidget(new QLabel("Port Actif:"));
    portActifWidget = new QCheckBox();
    layoutPortActif->addWidget(portActifWidget);
    layout->addLayout(layoutPortActif);


    QHBoxLayout * layoutPortInfinitesimal = new QHBoxLayout;
    layoutPortInfinitesimal->addWidget(new QLabel("Port Infinitesimal:"));
    portInfinitesimalWidget = new QCheckBox();
    layoutPortInfinitesimal->addWidget(portInfinitesimalWidget);
    layout->addLayout(layoutPortInfinitesimal);


    QHBoxLayout * layoutTypePort = new QHBoxLayout;
    layoutTypePort->addWidget(new QLabel("Type Port:"));
    typePortWidget = new QComboBox();
    typePortWidget->addItems(QStringList() << "Magnétique" << "Electrique");
    layoutTypePort->addWidget(typePortWidget);
    layout->addLayout(layoutTypePort);


    QHBoxLayout * layoutDirection = new QHBoxLayout;
    layoutDirection->addWidget(new QLabel("Direction:"));
    directionWidget = new QComboBox();
    directionWidget->addItems(QStringList() << "x" << "y" << "z");
    layoutDirection->addWidget(directionWidget);
    layout->addLayout(layoutDirection);


    QHBoxLayout * layoutImpedance = new QHBoxLayout;
    layoutImpedance->addWidget(new QLabel("Impédance:"));
    impedanceWidget = new QDoubleSpinBox();
    layoutImpedance->addWidget(impedanceWidget);
    layout->addLayout(layoutImpedance);



    QHBoxLayout * layoutTypeSource = new QHBoxLayout;
    layoutTypeSource->addWidget(new QLabel("Type Source:"));
    typeSourceWidget = new QComboBox();
    typeSourceWidget->addItems(QStringList() << "Tension" << "Courant");
    layoutTypeSource->addWidget(typeSourceWidget);
    layout->addLayout(layoutTypeSource);


    QHBoxLayout * layoutPonderationAmplitude = new QHBoxLayout;
    layoutPonderationAmplitude->addWidget(new QLabel("Ponderation Amplitude:"));
    ponderationAmplitudeWidget = new QDoubleSpinBox();
    layoutPonderationAmplitude->addWidget(ponderationAmplitudeWidget);
    layout->addLayout(layoutPonderationAmplitude);


    QHBoxLayout * layoutPonderationPhase = new QHBoxLayout;
    layoutPonderationPhase->addWidget(new QLabel("Ponderation Phase:"));
    ponderationPhaseWidget = new QDoubleSpinBox();
    layoutPonderationPhase->addWidget(ponderationPhaseWidget);
    layout->addLayout(layoutPonderationPhase);

    layout->addWidget(getWidgetElementBase());

    layout->setAlignment(Qt::AlignTop);

    groupGeo->setLayout(layout);

    layoutPrincipal->addWidget(groupGeo);

    setLayout(layoutPrincipal);

    init();

}

void FormPortExcitation::valider()
{
    FormElementBase::valider();
    port->SetPortActif(portActifWidget->isChecked());
    port->SetPortInfinitesimal(portInfinitesimalWidget->isChecked());
    port->SetTypePort(typePortWidget->currentIndex()+1);
    port->SetDirection(directionWidget->currentIndex()+1);
    port->SetImpedance(impedanceWidget->value());
    port->SetTypeSource(typeSourceWidget->currentIndex());
    port->SetPonderationAmplitude(ponderationAmplitudeWidget->value());
    port->SetPonderationPhase(ponderationPhaseWidget->value());
    emit elementValide(port);
}

void FormPortExcitation::reset()
{
    FormElementBase::reset();

    port = new portExcitation();
    setElement(port);

    init();
}

void FormPortExcitation::init()
{
    FormElementBase::init();

    portActifWidget->setChecked(port->IsPortActif());
    portInfinitesimalWidget->setChecked(port->IsPortInfinitesimal());
    typePortWidget->setCurrentIndex(port->GetTypePort()-1);
    directionWidget->setCurrentIndex(port->GetDirection()-1);
    impedanceWidget->setValue(port->GetImpedance());
    typeSourceWidget->setCurrentIndex(port->GetTypeSource());
    ponderationAmplitudeWidget->setValue(port->GetPonderationAmplitude());
    ponderationPhaseWidget->setValue(port->GetPonderationPhase());

}
