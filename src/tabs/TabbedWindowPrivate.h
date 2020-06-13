#ifndef TABBEDWINDOWPRIVATE_H
#define TABBEDWINDOWPRIVATE_H

#include <src\tabs\TabbedWindow.h>

class TabView;

/*
 * Private implementation of the TabbedWindow class (PIMPL pattern)
 *
 *See tabbedwindow.h for more documentation
 */
class TabbedWindowPrivate : public QObject
{
    Q_OBJECT

public:
    // Constructor accepts the pointer of the public implementation
    TabbedWindowPrivate(TabbedWindow* q_ptr);

    int addView(QWidget* view, const QString &title);
    int insertView(const QPoint &pos, QWidget *page, const QString &text);
    void removeView(int index);
    void setCurrentView(int index);
    QWidget* currentView();

private:
    TabbedWindow *q_ptr;
    TabView* tabs;
};

#endif // TABBEDWINDOWPRIVATE_H
