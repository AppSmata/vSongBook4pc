#include <src\ui\AppPreferences.h>
#include <ui_AppPreferences.h>

#include <AsBase.h>
#include <AsUtils.h>
#include <Application.h>

#include <sqlite.h>
#include <RunSql.h>
#include <sqlitetablemodel.h>

AppPreferences::AppPreferences(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppPreferences)
{
    ui->setupUi(this);
	
}

AppPreferences::~AppPreferences()
{
    delete ui;
}


