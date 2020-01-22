#ifndef VSONGEDIT_H
#define VSONGEDIT_H

#include "sqlitedb.h"
#include <QDialog>

class RemoteDatabase;

namespace Ui {
class vSongEdit;
}

class vSongEdit : public QDialog
{
    Q_OBJECT

public:
    explicit vSongEdit(QWidget *parent = nullptr, bool newSong = false);
    ~vSongEdit();

private:
    Ui::vSongEdit *ui;

    DBBrowserDB db;
    RemoteDatabase* m_remoteDb;

private slots:
    bool GetSettings();
    void ReloadSettings();
    bool PopulateSongbooks();
    void LoadSong();
    void SaveNewSong();
    void SaveChanges();
    void on_actionSave_triggered();
    void on_actionDelete_triggered();
    void on_actionClear_triggered();
};

#endif // VSONGEDIT_H
