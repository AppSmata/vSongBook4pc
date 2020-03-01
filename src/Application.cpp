#include <QFile>
#include <QFileOpenEvent>
#include <QTranslator>
#include <QTextCodec>
#include <QLibraryInfo>
#include <QLocale>
#include <QDebug>
#include <QAction>

#include "Application.h"
#include "AppMain.h"
#include "Settings.h"
#include "version.h"

Application::Application(int& argc, char** argv) :
    QApplication(argc, argv)
{
    // Set organisation and application names
    setOrganizationName("Appsmata Solutions");
    setApplicationName("vSongBook");
	setApplicationVersion(APP_VERSION);

    // Set character encoding to UTF8
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    // Load translations
    bool ok;
    QString name = Settings::getValue("General", "language").toString();

    // First of all try to load the application translation file.
    m_translatorApp = new QTranslator(this);
    ok = m_translatorApp->load("sqlb_" + name,  QCoreApplication::applicationDirPath() + "/translations");
    // If failed then try to load .qm file from resources
    if (ok == false) {
        ok = m_translatorApp->load("sqlb_" + name, ":/translations");
    }

    if (ok == true) {
        Settings::setValue("General", "language", name);
        installTranslator(m_translatorApp);

        m_translatorQt = new QTranslator(this);

        ok = m_translatorQt->load("qt_" + name, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
        if (ok == false)
            ok = m_translatorQt->load("qt_" + name, "translations");
        if (ok == true)
            installTranslator(m_translatorQt);
    } else {
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
    m_dontShowMainWindow = false;
    
    // Show main window
    m_homepage = new AppMain();
    m_homepage->showMaximized();

    this->thread();

    connect(this, &Application::lastWindowClosed, this, &Application::quit);

}

Application::~Application()
{
    delete m_homepage;
}

bool Application::event(QEvent* event)
{
    switch(event->type())
    {
    case QEvent::FileOpen:
        //m_mainWindow->fileOpen(static_cast<QFileOpenEvent*>(event)->file());
        return true;
    default:
        return QApplication::event(event);
    }
}

QString Application::versionString()
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
