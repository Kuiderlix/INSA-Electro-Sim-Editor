#include "ParamSimuWidget.h"

ParamSimuWidget::ParamSimuWidget(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout * layout = new QVBoxLayout;

    FormPortExcitation * formPortExci = new FormPortExcitation(new portExcitation(), FormPortExcitation::NOUVEAU);

    layout->addWidget(formPortExci);

    setLayout(layout);
}
