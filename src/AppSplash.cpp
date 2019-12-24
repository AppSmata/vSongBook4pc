#include "AppSplash.h"
#include "ui_AppSplash.h"

AppSplash::AppSplash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppSplash)
{
    ui->setupUi(this);
}

AppSplash::~AppSplash()
{
    delete ui;
}
