#include "vSongBooks.h"
#include "ui_vSongBooks.h"

vSongBooks::vSongBooks(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongBooks)
{
    ui->setupUi(this);
}

vSongBooks::~vSongBooks()
{
    delete ui;
}
