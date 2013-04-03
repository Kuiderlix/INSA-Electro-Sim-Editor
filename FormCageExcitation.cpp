#include "FormCageExcitation.h"



FormCageExcitation::FormCageExcitation(cageExcitation *cageExci, int mode, QWidget *parent) :
    FormElementBase(cageExci,mode,parent)
{
    this->cageExci=cageExci;
}
