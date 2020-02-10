#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QKeySequence>

class QAction;
class QTranslator;

class MainWindow;
class vSongHome;

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    ~Application() override;

    bool dontShowMainWindow() const { return m_dontShowMainWindow; }

    MainWindow* mainWindow() { return m_mainWindow; }
	vSongHome* homepage() { return m_homepage; }

    static QString versionString();

protected:
    bool event(QEvent* event) override;

private:
    bool m_dontShowMainWindow;
    MainWindow* m_mainWindow;
	vSongHome* m_homepage;
    QTranslator* m_translatorQt;
    QTranslator* m_translatorApp;
};

void addShortcutsTooltip(QAction* action, const QList<QKeySequence>& extraKeys = QList<QKeySequence>());

#endif
