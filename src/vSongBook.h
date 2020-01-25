#ifndef VSONGBOOK_H
#define VSONGBOOK_H

#include <QApplication>
#include <QFile>
#include <QKeySequence>

class QAction;
class QTranslator;

class vSongHome;
class vSongView;

class vSongBook : public QApplication
{
    Q_OBJECT

public:
    explicit vSongBook(int& argc, char** argv);
    ~vSongBook() override;

    bool dontShowHome() const { return m_dontShowHome; }

    vSongHome* homeWindow() { return m_HomeWindow; }
    static QString ReplaceList(QString text);
    static QString ReplaceView(QString text);
    static void SetOption(QString title, QString content);
    static bool isTrue(int value);
    static QString booltoInt(bool value);
    static int setCmbValue(std::vector<QString> values, QString value);
    static QString versionString();

protected:
    bool event(QEvent* event) override;

private:
    bool m_dontShowHome;
    vSongHome* m_HomeWindow;
    vSongView* m_ViewWindow;
    QTranslator* m_translatorQt;
    QTranslator* m_translatorApp;
};

void addShortcutsTooltip(QAction* action, const QList<QKeySequence>& extraKeys = QList<QKeySequence>());

#endif
