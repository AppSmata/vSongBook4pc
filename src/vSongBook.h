#ifndef VSONGBOOK_H
#define VSONGBOOK_H

#include <QApplication>
#include <QKeySequence>
#include <QFile>

class QAction;
class vSongHome;
class QTranslator;

class vSongBook : public QApplication
{
    Q_OBJECT

public:
    explicit vSongBook(int& argc, char** argv);
    ~vSongBook() override;

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
