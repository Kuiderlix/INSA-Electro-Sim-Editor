#include "ParamSimuWidget.h"

ParamSimuWidget::ParamSimuWidget(Data *data, QWidget *parent) :
    ToolBoxWidget(data,parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormPortExcitation * formPortExci = new FormPortExcitation(new portExcitation());
    connect(formPortExci,SIGNAL(elementValide(elementBase*)),this,SIGNAL(newPortExcitationCreated(elementBase*)));
    connect(formPortExci,SIGNAL(elementValide(elementBase*)),formPortExci,SLOT(reset()));

    formAnaTempo = new FormAnalyseTempo(data->getAnalyseTempo());

    formParamExci = new FormParamExcitation(data->getParamExcitations());

    layout->addWidget(formParamExci);
    layout->addWidget(formAnaTempo);
    layout->addWidget(formPortExci);

    setLayout(layout);

    init();
}

void ParamSimuWidget::init()
{
    formAnaTempo->setAnalyseTempo(data->getAnalyseTempo());
    formParamExci->setParamExcit(data->getParamExcitations());
}
