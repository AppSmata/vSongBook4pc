#ifndef ASPREFERENCE_H
#define ASPREFERENCE_H

#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QStandardItemModel>

class AsPreference : public QStyledItemDelegate
{
	Q_OBJECT
signals:

public:
	explicit AsPreference(QObject* parent = nullptr);

	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const Q_DECL_OVERRIDE;
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const Q_DECL_OVERRIDE;

	~AsPreference();
};

#endif
