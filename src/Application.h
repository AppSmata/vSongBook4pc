#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QKeySequence>

class QAction;
class QTranslator;

class vSongHome;
class vSongPresent;

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    ~Application() override;

    bool dontShowMainWindow() const { return m_dontShowMainWindow; }

    vSongHome* mainWindow() { return m_mainWindow; }

    static QString versionString();

protected:
    bool event(QEvent* event) override;

private:
    bool m_dontShowMainWindow;
    vSongHome* m_mainWindow;
    vSongPresent* m_presentation;
    QTranslator* m_translatorQt;
    QTranslator* m_translatorApp;
};

void addShortcutsTooltip(QAction* action, const QList<QKeySequence>& extraKeys = QList<QKeySequence>());

#endif
