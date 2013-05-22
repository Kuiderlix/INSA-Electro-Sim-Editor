#include "FormSettings.h"

FormSettings::FormSettings(QWidget *parent) :
    QDialog(parent)
{

    settings = new QSettings("INSAProj", "EditSimuIETR");

    QVBoxLayout * layout = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Paramètres");

    QVBoxLayout *layoutGroup = new QVBoxLayout();

    QFormLayout * layoutForm = new QFormLayout();

    QHBoxLayout * layoutEmpl = new QHBoxLayout;
    champsPathSimu = new QLineEdit(settings->value("PathSimu",QCoreApplication::applicationDirPath()).toString());
    layoutEmpl->addWidget(champsPathSimu);
    QPushButton * changerBouton = new QPushButton("Chercher ...");
    connect(changerBouton,SIGNAL(clicked()),this,SLOT(ouvreDialogDossier()));
    layoutEmpl->addWidget(changerBouton);
    layoutForm->addRow("Emplacement des simulations: ", layoutEmpl);

    layoutGroup->addLayout(layoutForm);

    QHBoxLayout * layoutBouton = new QHBoxLayout;
    appliquerBouton = new QPushButton("Appliquer");
    appliquerBouton->setDefault(true);
    connect(appliquerBouton,SIGNAL(clicked()),this,SLOT(appliquer()));
    layoutBouton->addWidget(appliquerBouton);

    annulerBouton = new QPushButton("Annuler");
    connect(annulerBouton,SIGNAL(clicked()),this,SLOT(reject()));
    layoutBouton->addWidget(annulerBouton);


    OKBouton = new QPushButton("OK");
    connect(OKBouton,SIGNAL(clicked()),this,SLOT(appliquer()));
    connect(OKBouton,SIGNAL(clicked()),this,SLOT(reject()));
    layoutBouton->addWidget(OKBouton);

    layoutGroup->addLayout(layoutBouton);

    group->setLayout(layoutGroup);

    layout->addWidget(group);

    setMinimumWidth(500);

    setLayout(layout);
}

void FormSettings::ouvreDialogDossier()
{
    champsPathSimu->setText(QFileDialog::getExistingDirectory(this,"",settings->value("PathSimu",QCoreApplication::applicationDirPath()).toString()));
}

void FormSettings::appliquer()
{
    settings->setValue("PathSimu",champsPathSimu->text());
}
