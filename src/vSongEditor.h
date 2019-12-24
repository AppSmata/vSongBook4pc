#ifndef VSONGEDITOR_H
#define VSONGEDITOR_H

#include <QMainWindow>

namespace Ui {
class vSongEditor;
}

class vSongEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit vSongEditor(QWidget *parent = nullptr);
    ~vSongEditor();

private:
    Ui::vSongEditor *ui;
};

#endif // VSONGEDITOR_H
