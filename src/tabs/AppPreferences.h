#ifndef APPPREFERENCES_H
#define APPPREFERENCES_H

#include <sqlitedb.h>
#include <QMainWindow>

class RemoteDatabase;
namespace Ui {
class AppPreferences;
}

class AppPreferences : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppPreferences(QWidget* parent = nullptr);
    ~AppPreferences();

private:
    Ui::AppPreferences* ui;

    DBBrowserDB db;
    RemoteDatabase* m_remoteDb;

private slots:
    

};

#endif // APPPREFERENCES_H
