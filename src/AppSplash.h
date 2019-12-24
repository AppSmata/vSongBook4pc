#ifndef APPSPLASH_H
#define APPSPLASH_H

#include <QMainWindow>

namespace Ui {
class AppSplash;
}

class AppSplash : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppSplash(QWidget *parent = nullptr);
    ~AppSplash();

private:
    Ui::AppSplash *ui;
};

#endif // APPSPLASH_H
