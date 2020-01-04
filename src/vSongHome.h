#ifndef VSONGHOME_H
#define VSONGHOME_H

#include "sqlitedb.h"
#include <SongModel.h>

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
    void reloadSettings();
    bool PopulateSongbooks();
    void PopulateSonglists(QString setbook, QString searchstr, bool searchall);

    void on_TxtSearch_textChanged(const QString &arg1);
};

#endif // VSONGHOME_H
