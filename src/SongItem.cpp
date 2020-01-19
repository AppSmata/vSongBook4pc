/*
    SongItem.cpp

    A container for items of data supplied by the simple tree model.
*/

#include "SongItem.h"

#include <QStringList>

//! [0]
SongItem::SongItem(const QVector<QVariant>& data, SongItem* parent)
{
    parentItem = parent;
    itemData = data;
}
//! [0]

//! [1]
SongItem::~SongItem()
{
    qDeleteAll(childItems);
}
//! [1]

//! [2]
SongItem* SongItem::child(int number)
{
    return childItems.value(number);
}
//! [2]

//! [3]
int SongItem::childCount() const
{
    return childItems.count();
}
//! [3]

//! [4]
int SongItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<SongItem*>(this));

    return 0;
}
//! [4]

//! [5]
int SongItem::columnCount() const
{
    return itemData.count();
}
//! [5]

//! [6]
QVariant SongItem::data(int column) const
{
    return itemData.value(column);
}
//! [6]

//! [7]
bool SongItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        SongItem* item = new SongItem(data, this);
        childItems.insert(position, item);
    }

    return true;
}
//! [7]

//! [8]
bool SongItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    foreach(SongItem * child, childItems)
        child->insertColumns(position, columns);

    return true;
}
//! [8]

//! [9]
SongItem* SongItem::parent()
{
    return parentItem;
}
//! [9]

//! [10]
bool SongItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}
//! [10]

bool SongItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    foreach(SongItem * child, childItems)
        child->removeColumns(position, columns);

    return true;
}

//! [11]
bool SongItem::setData(int column, const QVariant& value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}
//! [11]
