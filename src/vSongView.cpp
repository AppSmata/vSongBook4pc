#include "vSongView.h"
#include "ui_vSongView.h"

vSongView::vSongView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongView)
{
    ui->setupUi(this);
    ui->BtnClose->hide();
}

vSongView::~vSongView()
{
    delete ui;
}

void vSongView::on_actionClose_triggered()
{
    this->close();
}

void vSongView::on_BtnClose_clicked()
{
    this->close();
}

void vSongView::on_actionLeft_triggered()
{

}

void vSongView::on_actionRight_triggered()
{

}

void vSongView::on_actionBigger_triggered()
{

}

void vSongView::on_actionSmaller_triggered()
{

}

void vSongView::on_actionFont_triggered()
{

}

void vSongView::on_actionBold_triggered()
{

}

void vSongView::on_actionTheme_triggered()
{

}

void vSongView::on_actionChorus_triggered()
{

}

void vSongView::on_actionUp_triggered()
{

}

void vSongView::on_actionDown_triggered()
{

}


void vSongView::on_BtnDown_clicked()
{

}

void vSongView::on_BtnUp_clicked()
{

}
