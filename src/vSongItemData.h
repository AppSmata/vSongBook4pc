#ifndef VSONGITEMDATA_H
#define VSONGITEMDATA_H

#include <QMetaType>

typedef struct {
    QString title;
    QString detail;
    QString content;
} vSongItemData;

Q_DECLARE_METATYPE(vSongItemData)

#endif // VSONGITEMDATA_H
