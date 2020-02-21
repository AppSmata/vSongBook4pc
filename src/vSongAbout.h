#ifndef VSONGABOUT_H
#define VSONGABOUT_H

#include <QDialog>

namespace Ui {
class vSongAbout;
}

class vSongAbout : public QDialog
{
    Q_OBJECT

public:
    explicit vSongAbout(QWidget *parent = nullptr);
    ~vSongAbout();

private:
    Ui::vSongAbout *ui;
};

#endif // VSONGABOUT_H
