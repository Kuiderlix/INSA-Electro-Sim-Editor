#include "ParamAvanceWidget.h"

ParamAvanceWidget::ParamAvanceWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormFormatStockage * formFormat = new FormFormatStockage(new formatStockage());
    FormExcitation * formExci = new FormExcitation(new Excitation());
    FormEchantillonage *formEchanti = new FormEchantillonage(new blocEchantillonnage());
    FormPML * formPml = new FormPML(new pml());

    layout->addWidget(formExci);
    layout->addWidget(formFormat);
    layout->addWidget(formPml);
    layout->addWidget(formEchanti);

    setLayout(layout);
}
