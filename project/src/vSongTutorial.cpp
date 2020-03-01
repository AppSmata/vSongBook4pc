#include "vSongTutorial.h"
#include "ui_vSongTutorial.h"

vSongTutorial::vSongTutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vSongTutorial)
{
    ui->setupUi(this);
}

vSongTutorial::~vSongTutorial()
{
    delete ui;
}
