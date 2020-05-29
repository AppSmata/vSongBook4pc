#include <src\tabs\TabView.h>
#include <src\tabs\TabBar.h>


TabView::TabView(QWidget *parent) :
    QTabWidget(parent)
{
    // Set custom tabbar
    setTabBar(new TabBar);
}


int TabView::tabAt(const QPoint &pos)
{
    return tabBar()->tabAt(pos);
}
