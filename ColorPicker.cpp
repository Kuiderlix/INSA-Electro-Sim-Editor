#include "ColorPicker.h"

ColorPicker::ColorPicker(QColor c, QWidget *parent) :
    QPushButton(parent)
{
    couleur=c;
    connect(this,SIGNAL(clicked()),this,SLOT(ouvreColorDialog()));
    setText("Change Couleur");
}

void ColorPicker::paintEvent(QPaintEvent * e)
{
    QPushButton::paintEvent(e);

    QPainter painter(this);
    QRect rect(e->rect());
    rect.setX(5);
    rect.setY(5);
    rect.setWidth(this->height()-10);
    rect.setHeight(this->height()-10);
    painter.fillRect(rect,couleur);

}

void ColorPicker::ouvreColorDialog()
{
    QColorDialog dial(couleur,this);

    dial.setOptions(QColorDialog::ShowAlphaChannel);

    int res = dial.exec();

    if (res==QDialog::Accepted)
    {
        couleur = dial.selectedColor();
        emit colorChanged(couleur);
    }
}
