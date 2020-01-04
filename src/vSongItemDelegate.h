#ifndef VSONGITEMDELEGATE_H
#define VSONGITEMDELEGATE_H

#include <QStyledItemDelegate>

class vSongItemDelegate : public QStyledItemDelegate
{
public:
    vSongItemDelegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // VSONGITEMDELEGATE_H
