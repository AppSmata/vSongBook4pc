#include <AsPreference.h>
#include <AsPref.h>

#include <QPainter>
#include <QStyledItemDelegate>
#include <QStyle>
#include <QEvent>
#include <QDebug>

AsPreference::AsPreference(QObject* parent) : QStyledItemDelegate(parent) { }

AsPreference::~AsPreference() { }

void AsPreference::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	if (index.isValid()) {
		painter->save();
		QVariant var = index.data(Qt::UserRole + 1);
		AsPref pref = var.value<AsPref>();

		// pref Rectangular area
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

		painter->setPen(QPen(QColor("#EEEEEE")));
		painter->setBrush(QColor("#EEEEEE"));
		painter->drawPath(path);

		QRectF iconRect, prefText1, prefText2;

		prefText1 = QRect(5, rect.top(), rect.width() - 10, pref.size);
		prefText2 = QRect(prefText1.left(), prefText1.bottom() + 5, rect.width() - 10 - iconRect.width(), pref.size);

		painter->setPen(QPen(QColor(Qt::black)));
		painter->setFont(QFont("Trebuchet MS", 10, QFont::Bold));
		painter->drawText(prefText1, pref.title);

		painter->setPen(QPen(Qt::black));
		painter->setFont(QFont("Trebuchet MS", 10, 0));
		painter->drawText(prefText2, pref.description);

		painter->restore();
	}
}

QSize AsPreference::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	Q_UNUSED(index)
		return QSize(option.rect.width(), 50);
}
