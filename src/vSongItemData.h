#ifndef VSONGITEMDATA_H
#define VSONGITEMDATA_H

#include <QMetaType>

typedef struct { QString title; QString content; QString detail; } vSongItemData;

Q_DECLARE_METATYPE(vSongItemData)

#endif // VSONGITEMDATA_H
