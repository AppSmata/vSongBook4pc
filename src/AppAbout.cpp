#include "AppAbout.h"
#include "ui_AppAbout.h"

AppAbout::AppAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppAbout)
{
    ui->setupUi(this);

}

AppAbout::~AppAbout()
{
    delete ui;
}
