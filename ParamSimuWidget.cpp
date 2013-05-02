#include "ParamSimuWidget.h"

ParamSimuWidget::ParamSimuWidget(Parser *parser, QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormPortExcitation * formPortExci = new FormPortExcitation(new portExcitation(), FormPortExcitation::NOUVEAU);
    connect(formPortExci,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newPortExcitationCreated(elementBase*)));
    connect(formPortExci,SIGNAL(elementValide(elementBase*)),formPortExci,SLOT(reset()));

    FormAnalyseTempo * formAnaTempo = new FormAnalyseTempo(parser->getAnalyseTempo());

    FormParamExcitation * formParamExci = new FormParamExcitation(parser->getParamExcitations());

    layout->addWidget(formParamExci);
    layout->addWidget(formAnaTempo);
    layout->addWidget(formPortExci);

    setLayout(layout);
}
