#include "CoordonneeDelegate.h"
#include <QApplication>
#include <QPainter>
CoordonneeDelegate::CoordonneeDelegate()
{
}

void CoordonneeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    coordonnee coord = index.data().value<coordonnee>();

    painter->drawText(option.rect.topLeft(),"coord");
}
