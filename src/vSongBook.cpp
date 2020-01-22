#include <QFile>
#include <QFileOpenEvent>
#include <QTranslator>
#include <QTextCodec>
#include <QLibraryInfo>
#include <QLocale>
#include <QDebug>
#include <QAction>

#include "vSongBook.h"
#include "vSongHome.h"
#include "Settings.h"
#include "version.h"

#include "sqlite.h"
#include "RunSql.h"
#include "sqlitetablemodel.h"

vSongBook::vSongBook(int& argc, char** argv) :
    QApplication(argc, argv)
{
    // Set organisation and application names
    setOrganizationName("AppSmata Solutions");
    setApplicationName("vSongBook");

    // Set character encoding to UTF8
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    // Load translations
    bool ok;
    QString name = Settings::getValue("General", "language").toString();

    // First of all try to load the application translation file.
    m_translatorApp = new QTranslator(this);
    ok = m_translatorApp->load("sqlb_" + name,
                               QCoreApplication::applicationDirPath() + "/translations");
    // If failed then try to load .qm file from resources
    if (ok == false) {
        ok = m_translatorApp->load("sqlb_" + name, ":/translations");
    }

    if (ok == true) {
        Settings::setValue("General", "language", name);
        installTranslator(m_translatorApp);

        // The application translation file has been found and loaded.
        // And now try to load a Qt translation file.
        // Search path:
        // 1) standard Qt translations directory;
        // 2) the application translations directory.
        m_translatorQt = new QTranslator(this);

        ok = m_translatorQt->load("qt_" + name,
                                  QLibraryInfo::location(QLibraryInfo::TranslationsPath));
        if (ok == false)
            ok = m_translatorQt->load("qt_" + name, "translations");
        if (ok == true)
            installTranslator(m_translatorQt);
    } else {
        // Set the correct locale so that the program won't erroneously detect
        // a language change when the user toggles settings for the first time.
        // (it also prevents the program from always looking for a translation on launch)
        Settings::setValue("General", "language", "en_US");

        // Don't install a translator for Qt texts if no translator for DB4S texts could be loaded
        m_translatorQt = nullptr;
    }

    // On Windows, add the plugins subdirectory to the list of library directories. We need this
    // for Qt to search for more image format plugins.
#ifdef Q_WS_WIN
    QApplication::addLibraryPath(QApplication::applicationDirPath() + "/plugins");
#endif

    // Work around a bug in QNetworkAccessManager which sporadically causes high pings for Wifi connections
    // See https://bugreports.qt.io/browse/QTBUG-40332
    qputenv("QT_BEARER_POLL_TIMEOUT", QByteArray::number(INT_MAX));

    // Parse command line
    QString fileToOpen;
    QString tableToBrowse;
    QStringList sqlToExecute;
    bool readOnly = false;
    m_dontShowHome = false;
    for(int i=1;i<arguments().size();i++)
    {
        // Check next command line argument
        if(arguments().at(i) == "-h" || arguments().at(i) == "--help")
        {
            // Help
            qWarning() << qPrintable(tr("Usage: %1 [options] [db]\n").arg(argv[0]));
            qWarning() << qPrintable(tr("Possible command line arguments:"));
            qWarning() << qPrintable(tr("  -h, --help\t\tShow command line options"));
            qWarning() << qPrintable(tr("  -q, --quit\t\tExit application after running scripts"));
            qWarning() << qPrintable(tr("  -s, --sql [file]\tExecute this SQL file after opening the DB"));
            qWarning() << qPrintable(tr("  -t, --table [table]\tBrowse this table after opening the DB"));
            qWarning() << qPrintable(tr("  -R, --read-only\tOpen database in read-only mode"));
            qWarning() << qPrintable(tr("  -o, --option [group/setting=value]\tRun application with this setting temporarily set to value"));
            qWarning() << qPrintable(tr("  -O, --save-option [group/setting=value]\tRun application saving this value for this setting"));
            qWarning() << qPrintable(tr("  -v, --version\t\tDisplay the current version"));
            qWarning() << qPrintable(tr("  [file]\t\tOpen this SQLite database"));
            m_dontShowHome = true;
        } else if(arguments().at(i) == "-v" || arguments().at(i) == "--version") {
            qWarning() << qPrintable(tr("This is vSongBook version %1.").arg(versionString()));
            m_dontShowHome = true;
        } else if(arguments().at(i) == "-s" || arguments().at(i) == "--sql") {
            // Run SQL file: If file exists add it to list of scripts to execute
            if(++i >= arguments().size())
                qWarning() << qPrintable(tr("The -s/--sql option requires an argument"));
            else if(!QFile::exists(arguments().at(i)))
                qWarning() << qPrintable(tr("The file %1 does not exist").arg(arguments().at(i)));
            else
                sqlToExecute.append(arguments().at(i));
        } else if(arguments().at(i) == "-t" || arguments().at(i) == "--table") {
            if(++i >= arguments().size())
                qWarning() << qPrintable(tr("The -t/--table option requires an argument"));
            else
                tableToBrowse = arguments().at(i);
        } else if(arguments().at(i) == "-q" || arguments().at(i) == "--quit") {
            m_dontShowHome = true;
        } else if(arguments().at(i) == "-R" || arguments().at(i) == "--read-only") {
            readOnly = true;
        } else if(arguments().at(i) == "-o" || arguments().at(i) == "--option" ||
                  arguments().at(i) == "-O" || arguments().at(i) == "--save-option") {
            const QString optionWarning = tr("The -o/--option and -O/--save-option options require an argument in the form group/setting=value");
            bool saveToDisk = arguments().at(i) == "-O" || arguments().at(i) == "--save-option";
            if(++i >= arguments().size())
                qWarning() << qPrintable(optionWarning);
            else {
                QStringList option = arguments().at(i).split("=");
                if (option.size() != 2)
                    qWarning() << qPrintable(optionWarning);
                else {
                    QStringList setting = option.at(0).split("/");
                    if (setting.size() != 2)
                        qWarning() << qPrintable(optionWarning);
                    else {
                        QVariant value;
                        // Split string lists. This assumes they are always named "*list"
                        if (setting.at(1).endsWith("list", Qt::CaseInsensitive))
                            value = option.at(1).split(",");
                        else
                            value = option.at(1);
                        Settings::setValue(setting.at(0).toStdString(), setting.at(1).toStdString(), value, !saveToDisk);
                    }
                }
            }
        } else {
            // Other: Check if it's a valid file name
            if(QFile::exists(arguments().at(i)))
                fileToOpen = arguments().at(i);
            else
                qWarning() << qPrintable(tr("Invalid option/non-existant file: %1").arg(arguments().at(i)));
        }
    }

    // Show main window
    m_HomeWindow = new vSongHome();
    m_HomeWindow->showMaximized();
    connect(this, &vSongBook::lastWindowClosed, this, &vSongBook::quit);

    // Open database if one was specified
    if(fileToOpen.size())
    {
        /*if(m_HomeWindow->fileOpen(fileToOpen, false, readOnly))
        {
            // If database could be opened run the SQL scripts
            for(const QString& f : sqlToExecute)
            {
                QFile file(f);
                if(file.open(QIODevice::ReadOnly))
                {
                    m_HomeWindow->getDb().executeMultiSQL(file.readAll(), false, true);
                    file.close();
                }
            }
            if(!sqlToExecute.isEmpty())
                m_HomeWindow->refresh();

            // Jump to table if the -t/--table parameter was set
            if(!tableToBrowse.isEmpty())
                m_HomeWindow->switchToBrowseDataTab(sqlb::ObjectIdentifier("main", tableToBrowse.toStdString()));
        }*/
    }
}

vSongBook::~vSongBook()
{
    delete m_HomeWindow;
}

bool vSongBook::isTrue(int value)
{
    if (value == 0) return false;
    else if (value == 1) return true;
}

QString vSongBook::booltoInt(bool value)
{
    if (value == true) return "1";
    else if (value == false) return "0";
}

int vSongBook::setCmbValue(std::vector<QString> values, QString value)
{
    int retvalue;
    for (int v = 0; v < values.size(); v++)
    {
        if (value == values[v]) retvalue = v;
    }
    return retvalue;
}

void vSongBook::SetOption(QString title, QString content)
{
    sqlite3* db;
    sqlite3_stmt* sqlqueryStmt;
    char* zErrMsg = NULL;
    int row, col, rc = sqlite3_open("Data/vSongBook.db", &db);

    uint timenow = QDateTime::currentSecsSinceEpoch();
    QString timeStr = QString::number(timenow);

    QString SqlQuery = "UPDATE settings SET content = '" + content + "', updated='" + timeStr + 
        "' WHERE title = '" + title + "'";

    QByteArray bar = SqlQuery.toLocal8Bit();
    char* sqlQuery = bar.data();

    rc = sqlite3_exec(db, sqlQuery, 0, 0, &zErrMsg);

    if (rc != SQLITE_OK) sqlite3_free(zErrMsg);
    sqlite3_close(db);
}

bool vSongBook::event(QEvent* event)
{
    switch(event->type())
    {
    case QEvent::FileOpen:
        //m_HomeWindow->fileOpen(static_cast<QFileOpenEvent*>(event)->file());
        return true;
    default:
        return QApplication::event(event);
    }
}

QString vSongBook::versionString()
{
    // Distinguish between high and low patch version numbers. High numbers as in x.y.99 indicate nightly builds or
    // beta releases. For these we want to include the build date. For the release versions we don't add the release
    // date in order to avoid confusion about what is more important, version number or build date, and about different
    // build dates for the same version. This also should help making release builds reproducible out of the box.
#if PATCH_VERSION >= 99
    return QString("%1 (%2)").arg(APP_VERSION, __DATE__);
#else
    return QString("%1").arg(APP_VERSION);
#endif
}

// Functions for documenting the shortcuts in the user interface using native names
static QString shortcutsTip(const QList<QKeySequence>& keys)
{
    QString tip;

    if (!keys.isEmpty()) {
        tip = " [";

        for (const auto& shortcut : keys)
            tip.append(shortcut.toString(QKeySequence::NativeText) + ", ");
        tip.chop(2);

        tip.append("]");
    }
    return tip;
}

void addShortcutsTooltip(QAction* action, const QList<QKeySequence>& extraKeys)
{
    if (!action->shortcuts().isEmpty() || !extraKeys.isEmpty())
        action->setToolTip(action->toolTip() + shortcutsTip(action->shortcuts() + extraKeys));
}
