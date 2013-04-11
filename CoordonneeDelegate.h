#ifndef COORDONNEEDELEGATE_H
#define COORDONNEEDELEGATE_H

#include <QStyledItemDelegate>
#include "coordonnee.h"
#include <QLabel>
#include <QLineEdit>
#include "FormCoordonnees.h"

class CoordonneeDelegate : public QStyledItemDelegate
{
public:
    CoordonneeDelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

     QWidget * createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
     void setEditorData ( QWidget * editor, const QModelIndex & index ) const;
     void setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
     void updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const;

private:
};

#endif // COORDONNEEDELEGATE_H
