#include "ObjetFDTDWidget.h"

ObjetFDTDWidget::ObjetFDTDWidget(QWidget *parent) :
    QWidget(parent)
{


    QVBoxLayout * layout = new QVBoxLayout;

    FormCageExcitation * formCageExci = new FormCageExcitation(new cageExcitation(), FormCageExcitation::NOUVEAU);
    FormSurfacePrelevement * formSurfacePrel = new FormSurfacePrelevement(new surfacePrelevement(), FormSurfacePrelevement::NOUVEAU);

    layout->addWidget(formCageExci);
    layout->addWidget(formSurfacePrel);

    setLayout(layout);
}
