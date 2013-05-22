#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QPushButton>
#include <QColorDialog>
#include <QPainter>
#include <QPaintEvent>

class ColorPicker : public QPushButton
{
    Q_OBJECT
public:
    explicit ColorPicker(QColor c,QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

    void setColor(QColor c)
    {
        couleur=c;
    }
    
signals:

    void colorChanged(QColor);
    
public slots:
    void ouvreColorDialog();

private:
    QColor couleur;
    
};

#endif // COLORPICKER_H
