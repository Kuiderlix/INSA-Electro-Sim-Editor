#include "ComboxDecaleeDelegate.h"

ComboxDecaleeDelegate::ComboxDecaleeDelegate(QStringList list,int decalage, QObject *parent) :
    QStyledItemDelegate(parent)
{
    this->list = list;
    this->decalage=decalage;
}

void ComboxDecaleeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    int type = index.data().value<int>() - decalage;
    if (type<0)
        type=0;
    else if (type>list.count())
        type=list.count()-1;

    QStyleOptionViewItemV4 opt = option;
    initStyleOption(&opt,index);
    QTextOption o;
    o.setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
    painter->setFont(option.font);
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
        if (type<0)
            type=0;
        else if (type>list.count())
            type=list.count()-1;
        form->setCurrentIndex (type-1);
    }
}

void ComboxDecaleeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *form = qobject_cast<QComboBox *>(editor);
    if (editor)
    {
        QVariant var;
        var.setValue<int>(form->currentIndex() + decalage);
        model->setData(index, var);
    }
}

void ComboxDecaleeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
