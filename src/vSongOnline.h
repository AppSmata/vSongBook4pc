#ifndef VSONGONLINE_H
#define VSONGONLINE_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "AsDelegate.h"

namespace Ui {
class vSongOnline;
}

class vSongOnline : public QDialog
{
    Q_OBJECT

public:
    explicit vSongOnline(QWidget *parent = nullptr);
    ~vSongOnline();

private slots:
    void onBooksResult(QNetworkReply* reply);
    void onSongsResult(QNetworkReply* reply);
    void createListView();
    void LoadBooks();
    void LoadSongs();
    void progressManager(qint64 ist, qint64 max);
    void showProgress(bool show);

    void on_LstBooks_clicked(const QModelIndex &index);
    void on_BtnProceed_clicked();
    void on_BtnCancel_clicked();

private:
    Ui::vSongOnline *ui;
    QNetworkAccessManager* qnam;
    QNetworkRequest request;
    QStandardItemModel* bookModel;
};

#endif VSONGONLINE_H
