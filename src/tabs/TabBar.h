#ifndef VIEWBAR_H
#define VIEWBAR_H

#include <QTabBar>

class GhostWindow;

class TabbedWindow;

/*
 * Re-implemented the standard QTabBar widget but adds new methods to allow
 * Drag&Drop operations outside the tab bar's window, like creating a new
 * window with a dragged view, move a view into a different window or close the
 * current window if no more tabs are available
 */
class TabBar : public QTabBar
{
    Q_OBJECT

public:
    TabBar(QWidget *parent = 0);
    ~TabBar();

    // If the left mouse button if pressed over a tab show the ghost window
    // and starts the Drag&Drop operation
    void mousePressEvent(QMouseEvent *);

    // Update the ghost window's position during mouse move
    void mouseMoveEvent(QMouseEvent *);

    // Drops the current dragged view and creates a new window if no tab bar
    // under the event's screen position otherwise move the dragged view into
    // the tab bar under the mouse event's position.
    // Finishing by destroying the ghost windows widget and closing the current
    // window if no tabs left.
    void mouseReleaseEvent(QMouseEvent *);

protected:
    // Creates a new window fetching geometry information from the given
    // GhostWindow instance and moving the view at the index referenced by
    // GhostWindow::index() into the newly created window
    void createNewWindow(GhostWindow*);

    // Move the view at the index referenced by the GhostWindow::index()
    // attribute into the given tabbed windows and at the given current
    // position.
    void moveToWindow(TabbedWindow*, const QPoint&, GhostWindow*);

    // If no tabs are left in the current tab bar closes the widget's window.
    //
    // See QTabBar::tabRemoved
    void tabRemoved(int index);

private:
    GhostWindow *m_ghost;
};

#endif // VIEWBAR_H
