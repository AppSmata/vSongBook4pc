#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <QMetaType>

typedef enum {
    S_RED,
    S_BLUE,
    S_YELLOW,
} ItemStatus;

struct ItemData {
    QString image;
    QString title;
    QString content;
};

Q_DECLARE_METATYPE(ItemData)

#endif //ITEMDATA_H
