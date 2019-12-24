#include "vSongEditor.h"
#include "ui_vSongEditor.h"

vSongEditor::vSongEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vSongEditor)
{
    ui->setupUi(this);
}

vSongEditor::~vSongEditor()
{
    delete ui;
}
