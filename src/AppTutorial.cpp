#include "AppTutorial.h"
#include "ui_AppTutorial.h"

AppTutorial::AppTutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppTutorial)
{
    ui->setupUi(this);
}

AppTutorial::~AppTutorial()
{
    delete ui;
}
