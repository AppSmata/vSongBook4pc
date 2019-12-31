#include "vSongBook.h"
#include <QFile>

void setStyle(const QString& qssFile)
{
    QFile qss(qssFile);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

int main( int argc, char ** argv )
{
    // Create application object. All the initialisation stuff happens in there
    vSongBook a(argc, argv);

    setStyle("res/style.qss");

    // Run application
    return a.exec();
}
