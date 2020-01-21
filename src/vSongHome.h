#ifndef VSONGHOME_H
#define VSONGHOME_H

#include "sqlitedb.h"

#include <memory>
#include <QMainWindow>
#include <QModelIndex>
#include <QListView>
#include <QDialog>
#include <QDialogButtonBox>
#include <QListView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>

class RemoteDatabase;
class QStandardItemModel;

namespace Ui {
class vSongHome;
}

class vSongHome : public QMainWindow
{
    Q_OBJECT

public:
    explicit vSongHome(QWidget *parent = nullptr);
    ~vSongHome();

    DBBrowserDB& getDb() { return db; }
    RemoteDatabase& getRemote() { return *m_remoteDb; }

private:
    Ui::vSongHome* ui;

    QStandardItemModel *songModel;

    DBBrowserDB db;
    RemoteDatabase* m_remoteDb;

    void init();


public slots:

private slots:
    bool GetSettings();
    void ReloadControls();
    void ReloadSettings();

    void SongLast();
    void SongNext();
    void FontSmaller();
    void FontBigger();
    void FontBold();
    void OpenSettings();

    bool PopulateSongbooks();
    void openPresentation();
    void PopulateSonglists(QString setbook, QString searchstr, bool searchall);

    void on_TxtSearch_textChanged(const QString &searchstr);
    void on_LstResults_clicked(const QModelIndex& selected);
    void OpenSongPreview(const QModelIndex& selected);

    void on_CmbSongbooks_currentIndexChanged(int index);
    void on_LstResults_activated(const QModelIndex &index);
    void on_LstResults_doubleClicked(const QModelIndex &index);

    void on_actionPresent_triggered();
    void on_actionSave_triggered();
    void on_actionPresent_Song_triggered();
    void on_actionBold_Text_triggered();
    void on_actionChange_Font_triggered();
    void on_actionSmaller_Font_triggered();
    void on_actionBigger_Font_triggered();
    void on_actionNext_Song_triggered();
    void on_actionPrevious_Song_triggered();
    void on_actionCheck_Updates_triggered();
    void on_actionContribute_triggered();
    void on_actionDonate_triggered();
    void on_actionUpdate_Songbooks_triggered();
    void on_actionManage_Songbooks_triggered();
    void on_actionEdit_Songbook_triggered();
    void on_actionNew_Songbook_triggered();
    void on_actionDelete_Song_triggered();
    void on_actionEdit_Song_triggered();
    void on_actionNew_Song_triggered();
    void on_actionManage_Settings_triggered();
    void on_actionReset_Settings_triggered();
    void on_actionHow_it_Works_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionBold_triggered();
    void on_actionSmaller_triggered();
    void on_actionBigger_triggered();
    void on_actionNext_triggered();
    void on_actionPrevious_triggered();
    void on_actionCancel_triggered();
    void on_actionDelete_triggered();
    void on_actionPreferences_triggered();
    void on_TxtSearch_returnPressed();
};

#endif // VSONGHOME_H
