#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QKeySequence>

class QAction;
class QTranslator;

class vSongHome;

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);
    ~Application() override;

    bool dontShowHome() const { return m_dontShowHome; }

    vSongHome* homeWindow() { return m_HomeWindow; }

    static QString versionString();

protected:
    bool event(QEvent* event) override;

private:
    bool m_dontShowHome;
    vSongHome* m_HomeWindow;
    QTranslator* m_translatorQt;
    QTranslator* m_translatorApp;
};

void addShortcutsTooltip(QAction* action, const QList<QKeySequence>& extraKeys = QList<QKeySequence>());

#endif
