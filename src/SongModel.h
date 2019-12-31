#ifndef SONGMODEL_H
#define SONGMODEL_H

#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QColor>
#include <QSet>

class SongModel : public QStringListModel
{
public:
    SongModel(QObject* parent = 0);
    SongModel(const QStringList& strings, QObject* parent = 0);
    Qt::ItemFlags flags(const QModelIndex& index) const;
    QVariant data(const QModelIndex& index, int role) const;
    bool setData(const QModelIndex& index, const QVariant& value,
        int role);

private:
    QSet<QPersistentModelIndex> checkedItems;

};

#endif // CUSTOMLISTMODEL_H