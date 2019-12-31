#ifndef SONGITEM_H
#define SONGITEM_H

#include <QList>
#include <QVariant>
#include <QVector>

//! [0]
class SongItem
{
public:
    explicit SongItem(const QVector<QVariant>& data, SongItem* parent = 0);
    ~SongItem();

    SongItem* child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    SongItem* parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant& value);

private:
    QList<SongItem*> childItems;
    QVector<QVariant> itemData;
    SongItem* parentItem;
};
//! [0]

#endif // SONGITEM_H
