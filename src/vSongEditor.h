#ifndef VSONGEDITOR_H
#define VSONGEDITOR_H

#include "sqlitedb.h"
#include <QDialog>

class RemoteDatabase;

namespace Ui {
class vSongEditor;
}

class vSongEditor : public QDialog
{
    Q_OBJECT

public:
    explicit vSongEditor(QWidget *parent = nullptr, bool newSong = false);
    ~vSongEditor();

private:
    Ui::vSongEditor*ui;

    DBBrowserDB db;
    RemoteDatabase* m_remoteDb;

private slots:
    void ShowFeedback(bool show);
    void DeleteSong();
    void ReloadSettings();
    bool PopulateSongbooks();
    void LoadSong();
    void SaveChanges();
    void ShowExtraFields();
    void on_actionSave_triggered();
    void on_actionDelete_triggered();
    void on_actionClear_triggered();
    void on_actionExtra_triggered();
    void on_BtnFeedback_clicked();
};

#endif // VSONGEDITOR_H
