#ifndef COORDONNEEDELEGATE_H
#define COORDONNEEDELEGATE_H

#include <QItemDelegate>
#include "coordonnee.h"
#include <QLabel>

class CoordonneeDelegate : public QItemDelegate
{
public:
    CoordonneeDelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;



private:
};

#endif // COORDONNEEDELEGATE_H
