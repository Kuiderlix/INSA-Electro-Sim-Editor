#include "ComboxDecaleeDelegate.h"

ComboxDecaleeDelegate::ComboxDecaleeDelegate(QStringList list, QObject *parent) :
    QStyledItemDelegate(parent)
{
    this->list = list;
}

void ComboxDecaleeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    int type = index.data().value<int>() - 1;
    QTextOption o;
    o.setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
    painter->drawText(option.rect, list.at(type), o);
    painter->restore();
}

QWidget *ComboxDecaleeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox * typeWidget = new QComboBox(parent);
    typeWidget->addItems(list);
    typeWidget->setAutoFillBackground(true);

    return typeWidget;
}

void ComboxDecaleeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *form = qobject_cast<QComboBox *>(editor);
    if (form)
    {
        int type = index.data().value<int>();
        form->setCurrentIndex (type-1);
    }
}

void ComboxDecaleeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *form = qobject_cast<QComboBox *>(editor);
    if (editor)
    {
        QVariant var;
        var.setValue<int>(form->currentIndex() + 1);
        model->setData(index, var);
    }
}

void ComboxDecaleeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
