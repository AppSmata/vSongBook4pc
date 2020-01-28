#ifndef VSONGBOOKLIST_H
#define VSONGBOOKLIST_H

#include <QDialog>
#include <QModelIndex>

class QStandardItemModel;

namespace Ui {
class vSongBooklist;
}

class vSongBooklist : public QDialog
{
    Q_OBJECT

public:
    explicit vSongBooklist(QWidget *parent = nullptr);
    ~vSongBooklist();

private slots:
    void LoadBook();
    void GetUpdates();
    void LoadBooklist(QString searchstr);
    void SaveNewBook();
    void SaveChanges();
    void DeleteBook();

    void on_LstBooks_clicked(const QModelIndex &index);
    void on_TxtSearch_textChanged(const QString &arg1);

    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionDelete_triggered();
    void on_actionRefresh_triggered();
    void on_actionUpdate_triggered();

private:
    Ui::vSongBooklist*ui;
    QStandardItemModel* bookModel;
};

#endif // VSONGBOOKLIST_H
