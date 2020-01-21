#ifndef VITEMDELEGATE_H
#define VITEMDELEGATE_H

#include <QStyledItemDelegate>

class vItemDelegate : public QStyledItemDelegate
{
public:
    vItemDelegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // VITEMDELEGATE_H
