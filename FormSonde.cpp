#include "FormSonde.h"

FormSonde::FormSonde(sonde *m_sonde, int mode, QWidget *parent) :
    FormElementBase(m_sonde,mode,parent)
{

    this->m_sonde=m_sonde;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Sonde");

    QVBoxLayout * layout = new QVBoxLayout;



    QHBoxLayout * layoutActifE = new QHBoxLayout;
    QCheckBox * eXWidget = new QCheckBox("ex");
    QCheckBox * eYWidget = new QCheckBox("ey");
    QCheckBox * eZWidget = new QCheckBox("ez");

    layoutActifE->addWidget(eXWidget);
    layoutActifE->addWidget(eYWidget);
    layoutActifE->addWidget(eZWidget);
    layout->addLayout(layoutActifE);


    QHBoxLayout * layoutActifH = new QHBoxLayout;
    QCheckBox * hXWidget = new QCheckBox("hx");
    QCheckBox * hYWidget = new QCheckBox("hy");
    QCheckBox * hZWidget = new QCheckBox("hz");

    layoutActifH->addWidget(hXWidget);
    layoutActifH->addWidget(hYWidget);
    layoutActifH->addWidget(hZWidget);
    layout->addLayout(layoutActifH);

    layout->addWidget(new FormCoordonnees(m_sonde->GetPointApplication()));

    layout->addWidget(new QCheckBox("Valeur au centre"));

    layout->addWidget(getWidgetElementBase());
    layout->setAlignment(Qt::AlignTop);
    group->setLayout(layout);
    layoutPrincipal->addWidget(group);
    setLayout(layoutPrincipal);
}

