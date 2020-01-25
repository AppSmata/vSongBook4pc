#ifndef VSONGBOOKS_H
#define VSONGBOOKS_H

#include <QDialog>
#include <QModelIndex>

class QStandardItemModel;

namespace Ui {
class vSongBooks;
}

class vSongBooks : public QDialog
{
    Q_OBJECT

public:
    explicit vSongBooks(QWidget *parent = nullptr);
    ~vSongBooks();

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
    Ui::vSongBooks *ui;
    QStandardItemModel* bookModel;
};

#endif // VSONGBOOKS_H
