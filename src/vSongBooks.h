#ifndef VSONGBOOKS_H
#define VSONGBOOKS_H

#include <QMainWindow>

namespace Ui {
class vSongBooks;
}

class vSongBooks : public QMainWindow
{
    Q_OBJECT

public:
    explicit vSongBooks(QWidget *parent = nullptr);
    ~vSongBooks();

private:
    Ui::vSongBooks *ui;
};

#endif // VSONGBOOKS_H
