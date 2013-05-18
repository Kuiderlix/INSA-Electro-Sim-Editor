#include "ParamAvanceWidget.h"

ParamAvanceWidget::ParamAvanceWidget(Data *data, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormFormatStockage * formFormat = new FormFormatStockage(data->getFormatStockage());
    FormExcitation * formExci = new FormExcitation(data->getExcitation());
    FormEchantillonage *formEchanti = new FormEchantillonage(data->getBlocEchantillonnage());
    FormPML * formPml = new FormPML(data->getPML());

    layout->addWidget(formExci);
    layout->addWidget(formFormat);
    layout->addWidget(formPml);
    layout->addWidget(formEchanti);

    setLayout(layout);
}
