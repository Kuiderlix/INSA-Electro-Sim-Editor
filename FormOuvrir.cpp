#include "FormOuvrir.h"

FormOuvrir::FormOuvrir(QWidget *parent) :
    QDialog(parent)
{
    num=0;
    setWindowIcon(QIcon("icon/ouvrir.png"));
    setWindowTitle("Ouvrir une simulation");


    QSettings settings("INSAProj", "EditSimuIETR");
    QVBoxLayout * layout = new QVBoxLayout();

    QGroupBox * group = new QGroupBox("Ouvrir une simulation");

    QVBoxLayout *layoutGroup = new QVBoxLayout();

    layoutGroup->addWidget(new QLabel(settings.value("PathSimu",QCoreApplication::applicationDirPath()).toString()));

    QFormLayout * layoutForm = new QFormLayout();
    nbrSimu = new QSpinBox();
    connect(nbrSimu,SIGNAL(valueChanged(int)),this,SLOT(setNum(int)));
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

void FormOuvrir::testFichierExistant(int n)
{
    QSettings settings("INSAProj", "EditSimuIETR");
    QString nomFichier, path;
    path = settings.value("PathSimu",QCoreApplication::applicationDirPath()).toString();
    nomFichier = path + "/DATA"+QString::number(n)+".dsc";
    if (!QFile::exists(nomFichier))
    {
        labelFichierExist->setText("Attention: Cette simulation n'existe pas !");
    }
    else
    {
        labelFichierExist->setText("");
    }
}

void FormOuvrir::setNum(int i)
{
    num=i;
}
