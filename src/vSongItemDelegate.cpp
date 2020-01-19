#include <QPainter>
#include <QDebug>
#include "vSongItemDelegate.h"
#include "vSongItemData.h"

vSongItemDelegate::vSongItemDelegate(QObject* parent) :
    QStyledItemDelegate(parent)
{

}

void vSongItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    if (index.isValid()) {
        painter->save();
        QVariant var = index.data(Qt::UserRole + 1);
        vSongItemData song = var.value<vSongItemData>();

        // item Rectangular area
        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width() - 1);
        rect.setHeight(option.rect.height() - 1);

        QPainterPath path;
        path.moveTo(rect.topRight());
        path.lineTo(rect.topLeft());
        path.quadTo(rect.topLeft(), rect.topLeft());
        path.lineTo(rect.bottomLeft());
        path.quadTo(rect.bottomLeft(), rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.quadTo(rect.bottomRight(), rect.bottomRight());
        path.lineTo(rect.topRight());
        path.quadTo(rect.topRight(), rect.topRight());

        // Change background color when hovering or selecting
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            //painter->setPen(QPen(QColor("#FF7C00")));
            painter->setPen(QPen(QColor("#FF4500")));
            painter->setBrush(QColor("#FF4500"));
            painter->drawPath(path);
        }
        if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(QColor("#FF7C00")));
            painter->setBrush(QColor("#FF7C00"));
            painter->drawPath(path);
        }

        // Draw picture, text, number location area
        QRectF iconRect = QRect(rect.left() + 5, rect.top() + 5, 40, 40);
        QRectF songText1 = QRect(iconRect.right() + 5, iconRect.top(), rect.width() - 10 - iconRect.width(), 20);
        QRectF songNbRect = QRect(songText1.left(), songText1.bottom() + 5, rect.width() - 10 - iconRect.width(), 20);

        painter->drawImage(iconRect, QImage("res/icon.png"));

        painter->setPen(QPen(QColor(Qt::black)));
        painter->setFont(QFont("Trebuchen MS", 12, 75));
        painter->drawText(songText1, song.title);

        painter->setPen(QPen(Qt::black));
        painter->setFont(QFont("Trebuchen MS", 12, 0));
        painter->drawText(songNbRect, song.content);

        painter->restore();
    }
}

QSize vSongItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index)
        return QSize(option.rect.width(), 50);
}
