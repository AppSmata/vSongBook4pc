#include "AppAbout.h"
#include "ui_AppAbout.h"
#include "sqlitedb.h"
#include "Application.h"

AppAbout::AppAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppAbout)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QString sqlite_version, sqlcipher_version;
    DBBrowserDB::getSqliteVersion(sqlite_version, sqlcipher_version);
    
	/*if(sqlcipher_version.isNull())
        sqlite_version = tr("SQLite Version ") + sqlite_version;
    else
        sqlite_version = tr("SQLCipher Version ") + sqlcipher_version + tr(" (based on SQLite %1)").arg(sqlite_version);

    ui->label_version->setText(tr("Version ") + Application::versionString() + "\n\n" +
                               tr("Built for ") + QSysInfo::buildAbi() + ", running on " + QSysInfo::currentCpuArchitecture() + "\n\n" +
                               tr("Qt Version ") + QT_VERSION_STR + "\n\n" +
                               sqlite_version
                               );*/

}

AppAbout::~AppAbout()
{
    delete ui;
}
