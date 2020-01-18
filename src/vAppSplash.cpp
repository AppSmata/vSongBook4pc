#include "vAppSplash.h"
#include "ui_vAppSplash.h"

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
