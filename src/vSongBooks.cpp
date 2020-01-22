#include "vSongBooks.h"
#include "ui_vSongBooks.h"

vSongBooks::vSongBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vSongBooks)
{
    ui->setupUi(this);
}

vSongBooks::~vSongBooks()
{
    delete ui;
}

void vSongBooks::on_LstBooks_clicked(const QModelIndex &index)
{

}

void vSongBooks::on_TxtSearch_textChanged(const QString &arg1)
{

}

void vSongBooks::on_BtnSave_clicked()
{

}

void vSongBooks::on_BtnDelete_clicked()
{

}

void vSongBooks::on_BtnUpdate_clicked()
{

}
