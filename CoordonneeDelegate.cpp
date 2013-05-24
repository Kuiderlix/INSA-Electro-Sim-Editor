#include "CoordonneeDelegate.h"
#include <QApplication>
#include <QPainter>
#include <QDebug>
CoordonneeDelegate::CoordonneeDelegate()
{
}

void CoordonneeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    coordonnee coord = index.data().value<coordonnee>();
    QTextOption o;
    o.setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
    painter->drawText(option.rect, coord.toQString(), o);
    painter->restore();
}

QWidget *CoordonneeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    FormCoordonnees *formCoord = new FormCoordonnees(coordonnee(),parent);
    formCoord->setAutoFillBackground(true);
    formCoord->layout()->setMargin(0);
    return formCoord;
}

void CoordonneeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    FormCoordonnees *form = qobject_cast<FormCoordonnees *>(editor);
    if (form)
    {
        coordonnee coord = index.data().value<coordonnee>();
        form->setCoordonnee(coord);
    }
}

void CoordonneeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    FormCoordonnees *form = qobject_cast<FormCoordonnees *>(editor);
    if (editor)
    {
        QVariant var;
        var.setValue(form->getCoord());
        model->setData(index, var);
    }
}

void CoordonneeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    QRect rect;
    rect = option.rect;
    rect.setWidth(200);
    editor->setGeometry(rect);
}
