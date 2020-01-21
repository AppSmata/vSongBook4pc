#ifndef VITEMDATA_H
#define VITEMDATA_H

#include <QMetaType>

typedef struct { QString image; QString title; QString content; } vItemData;

Q_DECLARE_METATYPE(vItemData)

#endif // VITEMDATA_H
