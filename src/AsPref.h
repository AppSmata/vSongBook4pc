#ifndef PREFITEM_H
#define PREFITEM_H

#include <QMetaType>

typedef enum {
    S_ENABLED,
    S_DISABLED,
} PrefStatus;

struct AsPref {
    QString type;
    QString title;
    QString description;
    QString value;
    QString options;
    int size;
};

Q_DECLARE_METATYPE(AsPref)

#endif
#pragma once
