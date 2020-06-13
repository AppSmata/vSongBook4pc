#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QKeySequence>

#include <src\tabs\TabbedWindow.h>

class QAction;
class QTranslator;

class TabbedWindow;
class AppHome;

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    ~Application() override;

    bool dontShowMainWindow() const { return m_dontShowMainWindow; }

    TabbedWindow* mainhometab() { return m_tab; }

    static QString versionString();

protected:
    bool event(QEvent* event) override;

private:
    bool m_dontShowMainWindow;
    TabbedWindow* m_tab;
    QTranslator* m_translatorQt;
    QTranslator* m_translatorApp;
};

void addShortcutsTooltip(QAction* action, const QList<QKeySequence>& extraKeys = QList<QKeySequence>());

#endif
