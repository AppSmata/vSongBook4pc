#include "vSongPrefs.h"
#include "ui_vSongPrefs.h"
#include "sqlitedb.h"
#include "vSongBook.h"

vSongPrefs::vSongPrefs(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::vSongPrefs)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

vSongPrefs::~vSongPrefs()
{
    delete ui;
}
