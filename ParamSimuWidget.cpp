#include "ParamSimuWidget.h"

ParamSimuWidget::ParamSimuWidget(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormPortExcitation * formPortExci = new FormPortExcitation(new portExcitation(), FormPortExcitation::NOUVEAU);

    FormAnalyseTempo * formAnaTempo = new FormAnalyseTempo(new analyseTemporelle());

    FormParamExcitation * formParamExci = new FormParamExcitation(new ParamExcitations());

    layout->addWidget(formParamExci);
    layout->addWidget(formAnaTempo);
    layout->addWidget(formPortExci);

    setLayout(layout);
}
