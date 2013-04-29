#include "FormSonde.h"

FormSonde::FormSonde(sonde *m_sonde, int mode, QWidget *parent) :
    FormElementBase(m_sonde,mode,parent)
{

    this->m_sonde=m_sonde;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Sonde");

    QVBoxLayout * layout = new QVBoxLayout;



    QHBoxLayout * layoutActifE = new QHBoxLayout;

    eXWidget = new QCheckBox("ex");
    eXWidget->setChecked(m_sonde->IsEx());

    eYWidget = new QCheckBox("ey");
    eYWidget->setChecked(m_sonde->IsEy());

    eZWidget = new QCheckBox("ez");
    eZWidget->setChecked(m_sonde->IsEz());

    layoutActifE->addWidget(eXWidget);
    layoutActifE->addWidget(eYWidget);
    layoutActifE->addWidget(eZWidget);
    layout->addLayout(layoutActifE);


    QHBoxLayout * layoutActifH = new QHBoxLayout;
    hXWidget = new QCheckBox("hx");
    hXWidget->setChecked(m_sonde->IsHx());

    hYWidget = new QCheckBox("hy");
    hYWidget->setChecked(m_sonde->IsHy());

    hZWidget = new QCheckBox("hz");
    hZWidget->setChecked(m_sonde->IsHz());

    layoutActifH->addWidget(hXWidget);
    layoutActifH->addWidget(hYWidget);
    layoutActifH->addWidget(hZWidget);
    layout->addLayout(layoutActifH);

    formPtAppli = new FormCoordonnees(m_sonde->GetPointApplication());
    layout->addWidget(formPtAppli);


    valCentreWidget = new QCheckBox("Valeur au centre");
    valCentreWidget->setChecked(m_sonde->IsValeurAuCentre());
    layout->addWidget(valCentreWidget);

    layout->addWidget(getWidgetElementBase());
    layout->setAlignment(Qt::AlignTop);
    group->setLayout(layout);
    layoutPrincipal->addWidget(group);
    setLayout(layoutPrincipal);
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
