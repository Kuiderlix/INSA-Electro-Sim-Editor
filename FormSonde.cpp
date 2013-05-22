#include "FormSonde.h"

FormSonde::FormSonde(sonde *m_sonde, QWidget *parent) :
    FormElementBase(m_sonde,parent)
{

    this->m_sonde=m_sonde;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Sonde");

    QVBoxLayout * layout = new QVBoxLayout;

    QHBoxLayout * layoutActifE = new QHBoxLayout;

    eXWidget = new QCheckBox("ex");
    eYWidget = new QCheckBox("ey");
    eZWidget = new QCheckBox("ez");

    layoutActifE->addWidget(eXWidget);
    layoutActifE->addWidget(eYWidget);
    layoutActifE->addWidget(eZWidget);
    layout->addLayout(layoutActifE);


    QHBoxLayout * layoutActifH = new QHBoxLayout;
    hXWidget = new QCheckBox("hx");
    hYWidget = new QCheckBox("hy");
    hZWidget = new QCheckBox("hz");

    layoutActifH->addWidget(hXWidget);
    layoutActifH->addWidget(hYWidget);
    layoutActifH->addWidget(hZWidget);
    layout->addLayout(layoutActifH);

    formPtAppli = new FormCoordonnees();
    layout->addWidget(formPtAppli);


    valCentreWidget = new QCheckBox("Valeur au centre");
    layout->addWidget(valCentreWidget);

    layout->addWidget(getWidgetElementBase());
    layout->setAlignment(Qt::AlignTop);
    group->setLayout(layout);
    layoutPrincipal->addWidget(group);
    setLayout(layoutPrincipal);

    init();
}
void FormSonde::valider()
{
    FormElementBase::valider();

    m_sonde->SetEx(eXWidget->isChecked());
    m_sonde->SetEy(eYWidget->isChecked());
    m_sonde->SetEz(eZWidget->isChecked());

    m_sonde->SetHx(hXWidget->isChecked());
    m_sonde->SetHy(hYWidget->isChecked());
    m_sonde->SetHz(hZWidget->isChecked());

    m_sonde->SetValeurAuCentre(valCentreWidget->isChecked());

    m_sonde->SetPointApplication(formPtAppli->getCoord());

    emit elementValide(m_sonde);
}

void FormSonde::reset()
{
    FormElementBase::reset();
    this->m_sonde = new sonde();
    setElement(m_sonde);
    init();
}

void FormSonde::init()
{
    FormElementBase::init();
    eXWidget->setChecked(m_sonde->IsEx());
    eYWidget->setChecked(m_sonde->IsEy());
    eZWidget->setChecked(m_sonde->IsEz());

    hXWidget->setChecked(m_sonde->IsHx());
    hYWidget->setChecked(m_sonde->IsHy());
    hZWidget->setChecked(m_sonde->IsHz());

    formPtAppli->setCoordonnee(m_sonde->GetPointApplication());

    valCentreWidget->setChecked(m_sonde->IsValeurAuCentre());
}
