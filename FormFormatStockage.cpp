#include "FormFormatStockage.h"

FormFormatStockage::FormFormatStockage(formatStockage *format, QWidget *parent) :
    QWidget(parent)
{
    this->format=format;

    QVBoxLayout * layoutPrincipal = new QVBoxLayout();
    QGroupBox * group = new QGroupBox("Format de stockage");

    QFormLayout * layout = new QFormLayout;

    QComboBox * formatWidget = new QComboBox();
    formatWidget->addItems(QStringList() << "binaire" << "texte");
    layout->addRow("Format:", formatWidget);
    connect(formatWidget,SIGNAL(currentIndexChanged(int)),format,SLOT(SetFormat(int)));

    QComboBox * formatFichierPrelevementWidget = new QComboBox();
    formatFichierPrelevementWidget->addItems(QStringList() << "texte" << "binaire");
    layout->addRow("Format fichier prelevement:", formatFichierPrelevementWidget);
    connect(formatFichierPrelevementWidget,SIGNAL(currentIndexChanged(int)),format,SLOT(SetFormatFichierPrelevement(int)));

    layout->setAlignment(Qt::AlignTop);

    group->setLayout(layout);

    layoutPrincipal->addWidget(group);

    setLayout(layoutPrincipal);
}
