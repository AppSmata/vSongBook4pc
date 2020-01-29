#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QStandardItemModel>

class AsDelegate : public QStyledItemDelegate
{
    Q_OBJECT
signals:

public:
    explicit AsDelegate(QObject* parent = nullptr, QString fontFamily = "Trebuchet MS", int fontSize = 25);
    ~AsDelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif ITEMDELEGATE_H
