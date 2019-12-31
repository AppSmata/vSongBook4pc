#include "SongModel.h"

SongModel::SongModel(QObject* parent) : QStringListModel(parent) { }

SongModel::SongModel(const QStringList& strings, QObject* parent) :
    QStringListModel(strings, parent) {

}

Qt::ItemFlags SongModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags defaultFlags = QStringListModel::flags(index);
    if (index.isValid()) {
        return defaultFlags | Qt::ItemIsSelectable;
    }
    return defaultFlags;
}

QVariant SongModel::data(const QModelIndex& index,
    int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::CheckStateRole)
        return checkedItems.contains(index) ?
        Qt::Checked : Qt::Unchecked;

    else if (role == Qt::BackgroundColorRole)
        return checkedItems.contains(index) ?
        QColor("#FF2500") : QColor("#FFFFFF");

    return QStringListModel::data(index, role);
}

bool SongModel::setData(const QModelIndex& index,
    const QVariant& value, int role) {

    if (!index.isValid() || role != Qt::CheckStateRole)
        return false;

    if (value == Qt::Checked)
        checkedItems.insert(index);
    else
        checkedItems.remove(index);

    emit dataChanged(index, index);
    return true;
}
