#include "ParamAvanceWidget.h"

ParamAvanceWidget::ParamAvanceWidget(Parser *parser, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormFormatStockage * formFormat = new FormFormatStockage(parser->getFormatStockage());
    FormExcitation * formExci = new FormExcitation(parser->getExcitation());
    FormEchantillonage *formEchanti = new FormEchantillonage(parser->getBlocEchantillonnage());
    FormPML * formPml = new FormPML(parser->getPML());

    layout->addWidget(formExci);
    layout->addWidget(formFormat);
    layout->addWidget(formPml);
    layout->addWidget(formEchanti);

    setLayout(layout);
}
