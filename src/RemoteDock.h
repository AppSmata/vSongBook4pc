#ifndef REMOTEDOCK_H
#define REMOTEDOCK_H

#include <QDialog>

class RemoteDatabase;
class RemoteModel;
class vSongHome;

namespace Ui {
class RemoteDock;
}

class RemoteDock : public QDialog
{
    Q_OBJECT

public:
    explicit RemoteDock(vSongHome* parent);
    ~RemoteDock() override;

    void reloadSettings();
    void enableButtons();

public slots:
    void reject() override;

private slots:
    void setNewIdentity();
    void fetchDatabase(const QModelIndex& idx);
    void pushDatabase();
    void newDirectoryNode(const QModelIndex& parent);
    void switchToMainView();

private:
    Ui::RemoteDock* ui;

    vSongHome* homeWindow;

    RemoteDatabase& remoteDatabase;
    RemoteModel* remoteModel;
};

#endif
