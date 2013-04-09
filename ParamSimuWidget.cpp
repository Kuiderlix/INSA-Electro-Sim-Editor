#include "ParamSimuWidget.h"

ParamSimuWidget::ParamSimuWidget(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin(0);

    FormPortExcitation * formPortExci = new FormPortExcitation(new portExcitation(), FormPortExcitation::NOUVEAU);

    FormAnalyseTempo * formAnaTempo = new FormAnalyseTempo(new analyseTemporelle());

    FormExcitation * formExci = new FormExcitation(new excitations());

    layout->addWidget(formExci);
    layout->addWidget(formAnaTempo);
    layout->addWidget(formPortExci);

    setLayout(layout);
}
