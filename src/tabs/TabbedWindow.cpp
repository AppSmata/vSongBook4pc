#include <src\tabs\TabbedWindow.h>
#include <src\tabs\TabbedWindowPrivate.h>
#include <src\tabs\TabView.h>

#include <QMenuBar>

TabbedWindow::TabbedWindow(QWidget *parent) :
    QMainWindow(parent),
    thiswnd(new TabbedWindowPrivate(this))
{
    QIcon icon;
    icon.addFile(QStringLiteral(":/icons/app_icon"), QSize(), QIcon::Normal, QIcon::Off);
    this->setWindowIcon(icon);
}


TabbedWindow::~TabbedWindow()
{
    delete thiswnd;
}


QWidget* TabbedWindow::currentView()
{
    return thiswnd->currentView();
}


QWidget* TabbedWindowPrivate::currentView()
{
    return tabs->currentWidget();
}


void TabbedWindow::setCurrentView(int index)
{
    thiswnd->setCurrentView(index);
}


int TabbedWindow::insertView(const QPoint &pos, QWidget *page,
                            const QString &text)
{
    return thiswnd->insertView(pos, page, text);
}


int TabbedWindow::addView(QWidget *view, const QString &title)
{
    return thiswnd->addView(view, title);
}


void TabbedWindow::removeView(int index)
{
    thiswnd->removeView(index);
}

TabbedWindowPrivate::TabbedWindowPrivate(TabbedWindow* q_ptr)
{
    QFont font1;
    font1.setFamily(QStringLiteral("Trebuchet MS"));
    font1.setPointSize(12);
    font1.setBold(false);
    font1.setWeight(50);

    // Create tab widget
    tabs = new TabView();
    tabs->setDocumentMode(true);
    tabs->setTabShape(QTabWidget::Triangular);
    //tabs->setTabsClosable(true);
    tabs->setMovable(true);
    tabs->setFont(font1);

    // Set up main window
    this->q_ptr = q_ptr;
    this->q_ptr->setCentralWidget(tabs);
}


void TabbedWindowPrivate::setCurrentView(int index)
{
    tabs->setCurrentIndex(index);
}


int TabbedWindowPrivate::insertView(const QPoint &pos, QWidget *page,
                                    const QString &text)
{
    // Get tab's index at the given global postition
    int index = tabs->tabAt(tabs->mapFromGlobal(pos));

    // Insert new tab
    return tabs->insertTab(index, page, text);
}


int TabbedWindowPrivate::addView(QWidget *view, const QString &title)
{
    return tabs->addTab(view, title);
}


void TabbedWindowPrivate::removeView(int index)
{
    tabs->removeTab(index);
}

