#ifndef VSONGVIEW_H
#define VSONGVIEW_H

#include <QMainWindow>

namespace Ui {
class vSongView;
}

class vSongView : public QMainWindow
{
    Q_OBJECT

public:
    explicit vSongView(QWidget *parent = nullptr);
    ~vSongView();

private:
    Ui::vSongView *ui;
};

#endif // VSONGVIEW_H
