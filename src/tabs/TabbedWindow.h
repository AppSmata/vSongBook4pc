#ifndef TABBEDWINDOW_H
#define TABBEDWINDOW_H

#include <QMainWindow>

class TabbedWindowPrivate;

/*
 * Subclass of QMainWindow, contains a tab bar to manage a per-window list of
 * tabbed views and allows to add, insert or remove a view.
 *
 * Views can be standard QWidget instances or even instances of QMainWindow
 * with menu bar and tool bars as well.
 *
 * Thes features will be displayed automatically when the view's tab will be
 * activated and hidden when it'll be deactivated.
 */
class TabbedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabbedWindow(QWidget *parent = 0);
    ~TabbedWindow();

    // Add a new view
    int addView(QWidget* view, const QString &title);

    // Insert a view at the given global position
    // Returns -1 if the insert view operations fails otherwise returns the
    // view's index
    int insertView(const QPoint &pos, QWidget *page, const QString &text);

    // Remove the view at the given index
    void removeView(int index);

    // Set the view at the given index as the current view
    void setCurrentView(int index);

    // Returns the current view
    QWidget* currentView();

private:
    TabbedWindowPrivate* thiswnd;
};

#endif // TABBEDWINDOW_H
