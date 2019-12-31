#include <QPainter>
#include <QDebug>
#include "vSongItemDelegate.h"
#include "vSongItemData.h"

vSongItemDelegate::vSongItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

void vSongItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid()) {
        painter->save();
        QVariant var = index.data(Qt::UserRole+1);
        vSongItemData song = var.value<vSongItemData>();

        // item 矩形区域
        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width()-1);
        rect.setHeight(option.rect.height()-1);

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

        // 绘制图片，歌手，数量位置区域
        QRectF iconRect = QRect(rect.left() + 5, rect.top() + 25, 60, 60);
        QRectF text1Rect = QRect(iconRect.right() + 5, iconRect.top(), rect.width() - 10 - iconRect.width(), 20);
        QRectF text2Rect = QRect(text1Rect.left(), text1Rect.bottom() + 5, rect.width() - 10 - iconRect.width(), 20);
        QRectF text3Rect = QRect(text1Rect.left(), text2Rect.bottom() + 25, rect.width() - 10 - iconRect.width(), 20);

        // 鼠标悬停或者选中时改变背景色
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setPen(QPen(Qt::white));
            painter->setBrush(QColor("#FF7C00"));
            painter->drawPath(path);
        }
        if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(Qt::white));
            painter->setBrush(QColor("#FF2500"));
            painter->drawPath(path);
        }

        painter->drawImage(iconRect, QImage("res/icon.png"));

        painter->setPen(QPen(QColor("#FF4500")));
        painter->setFont(QFont("Trebuchet MS", 15, 1));
        painter->drawText(text1Rect, song.title);

        painter->setPen(QPen(Qt::black));
        painter->setFont(QFont("Trebuchet MS", 12));
        painter->drawText(text2Rect, song.content);

        painter->setPen(QPen(Qt::black));
        painter->drawText(text3Rect, song.detail);

        painter->restore();
    }
}

QSize vSongItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    return QSize(option.rect.width(), 50);
}
