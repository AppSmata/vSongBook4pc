#include "vSongView.h"
#include "ui_vSongView.h"

vSongView::vSongView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongView)
{
    ui->setupUi(this);
}

vSongView::~vSongView()
{
    delete ui;
}
