#include "ParamAvanceWidget.h"

ParamAvanceWidget::ParamAvanceWidget(Data *data, QWidget *parent) :
    ToolBoxWidget(data,parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    formFormat = new FormFormatStockage(data->getFormatStockage());
    formExci = new FormExcitation(data->getExcitation());
    formEchanti = new FormEchantillonage(data->getBlocEchantillonnage());
    formPml = new FormPML(data->getPML());

    layout->addWidget(formExci);
    layout->addWidget(formFormat);
    layout->addWidget(formPml);
    layout->addWidget(formEchanti);

    setLayout(layout);

    init();
}

void ParamAvanceWidget::init()
{
    formFormat->setFormatStockage(data->getFormatStockage());
    formExci->setExcitation(data->getExcitation());
    formEchanti->setEchantillonnage(data->getBlocEchantillonnage());
    formPml->setPML(data->getPML());
}
