#ifndef VSONGBOOKS_H
#define VSONGBOOKS_H

#include <QDialog>

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
    void on_LstBooks_clicked(const QModelIndex &index);

    void on_TxtSearch_textChanged(const QString &arg1);

    void on_BtnSave_clicked();

    void on_BtnDelete_clicked();

    void on_BtnUpdate_clicked();

private:
    Ui::vSongBooks *ui;
};

#endif // VSONGBOOKS_H
