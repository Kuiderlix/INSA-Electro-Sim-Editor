#ifndef TYPEELEMLOCALDELEGATE_H
#define TYPEELEMLOCALDELEGATE_H

#include <QStyledItemDelegate>
#include <QtWidgets>

class ComboxDecaleeDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ComboxDecaleeDelegate(QStringList list, int decalage=0, QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

     QWidget * createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
     void setEditorData ( QWidget * editor, const QModelIndex & index ) const;
     void setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
     void updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const;

signals:
    
public slots:


private:
     QStringList list;
     int decalage;
    
};

#endif // TYPEELEMLOCALDELEGATE_H
