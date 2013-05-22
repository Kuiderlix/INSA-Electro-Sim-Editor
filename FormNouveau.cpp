#include "FormNouveau.h"

FormNouveau::FormNouveau(QWidget *parent) :
    QDialog(parent)
{
    QSettings settings("INSAProj", "EditSimuIETR");

    QVBoxLayout * layout = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Nouvelle simulation");

    QVBoxLayout *layoutGroup = new QVBoxLayout();


    layoutGroup->addWidget(new QLabel(settings.value("PathSimu",QCoreApplication::applicationDirPath()).toString()));

    QFormLayout * layoutForm = new QFormLayout();
    nbrSimu = new QSpinBox();
    connect(nbrSimu,SIGNAL(valueChanged(int)),this,SLOT(testFichierExistant(int)));
    layoutForm->addRow("N°", nbrSimu);

    layoutGroup->addLayout(layoutForm);

    QHBoxLayout *layoutLabel = new QHBoxLayout();
    labelFichierExist = new QLabel("");
    layoutLabel->addWidget(labelFichierExist);
    layoutGroup->addLayout(layoutLabel);

    QHBoxLayout * layoutBouton = new QHBoxLayout;
    validerBouton = new QPushButton("Valider");
    validerBouton->setDefault(true);
    connect(validerBouton,SIGNAL(clicked()),this,SLOT(accept()));
    layoutBouton->addWidget(validerBouton);

    annulerBouton = new QPushButton("Annuler");
    connect(annulerBouton,SIGNAL(clicked()),this,SLOT(reject()));
    layoutBouton->addWidget(annulerBouton);

    layoutGroup->addLayout(layoutBouton);

    group->setLayout(layoutGroup);

    layout->addWidget(group);


    setLayout(layout);

    testFichierExistant(nbrSimu->value());
}

void FormNouveau::testFichierExistant(int n)
{
    QSettings settings("INSAProj", "EditSimuIETR");
    QString nomFichier, path;
    path = settings.value("PathSimu",QCoreApplication::applicationDirPath()).toString();
    nomFichier = path + "/DATA"+QString::number(n)+".dsc";
    if (QFile::exists(nomFichier))
    {
        labelFichierExist->setText("Attention: Une simulation porte déjà ce numéro !");
    }
    else
    {
        labelFichierExist->setText("");
    }
}
