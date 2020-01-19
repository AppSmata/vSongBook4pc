#ifndef VSONGPREFS_H
#define VSONGPREFS_H

#include <QDialog>

namespace Ui {
class vSongPrefs;
}

class vSongPrefs : public QDialog
{
    Q_OBJECT

public:
    explicit vSongPrefs(QWidget *parent = nullptr);
    ~vSongPrefs();

private:
    Ui::vSongPrefs*ui;
};

#endif VSONGPREFS_H
