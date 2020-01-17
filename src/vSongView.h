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

private slots:
    void on_actionClose_triggered();
    void on_BtnClose_clicked();
    void on_actionLeft_triggered();
    void on_actionRight_triggered();
    void on_actionBigger_triggered();
    void on_actionSmaller_triggered();
    void on_actionFont_triggered();
    void on_actionBold_triggered();
    void on_actionTheme_triggered();
    void on_actionChorus_triggered();
    void on_actionUp_triggered();
    void on_actionDown_triggered();
    void on_BtnDown_clicked();
    void on_BtnUp_clicked();

private:
    Ui::vSongView *ui;
};

#endif // VSONGVIEW_H
