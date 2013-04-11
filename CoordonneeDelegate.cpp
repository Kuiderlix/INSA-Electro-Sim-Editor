#include "CoordonneeDelegate.h"
#include <QApplication>
#include <QPainter>
#include <QDebug>
CoordonneeDelegate::CoordonneeDelegate()
{
}

void CoordonneeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QStyleOptionViewItem myOption = option;

    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    coordonnee coord = index.data().value<coordonnee>();

    myOption.displayAlignment = Qt::AlignLeft| Qt::AlignVCenter;

    painter->save();
    drawDisplay(painter, myOption, myOption.rect, coord.toQString());
    drawFocus(painter, myOption, myOption.rect);
    painter->restore();

}
