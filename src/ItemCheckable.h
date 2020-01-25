#ifndef ITEMCHECKABLE_H
#define ITEMCHECKABLE_H

#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QColor>
#include <QSet>

class ItemCheckable : public QStringListModel
{
public:
    ItemCheckable(QObject* parent = 0);
    ItemCheckable(const QStringList& strings, QObject* parent = 0);
    Qt::ItemFlags flags(const QModelIndex& index) const;
    QVariant data(const QModelIndex& index, int role) const;
    bool setData(const QModelIndex& index, const QVariant& value,
        int role);
    void save();
private:
    QSet<QPersistentModelIndex> checkedItems;
};

#endif // ITEMCHECKABLE_H