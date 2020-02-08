#ifndef VSONGTUTORIAL_H
#define VSONGTUTORIAL_H

#include <QDialog>

namespace Ui {
class vSongTutorial;
}

class vSongTutorial : public QDialog
{
    Q_OBJECT

public:
    explicit vSongTutorial(QWidget *parent = nullptr);
    ~vSongTutorial();

private:
    Ui::vSongTutorial *ui;
};

#endif // VSONGTUTORIAL_H
