TEMPLATE = app

QT += core gui network widgets printsupport concurrent xml

TARGET = vSongBook

CONFIG += debug_and_release
CONFIG += qt
CONFIG += warn_on

QMAKE_CXXFLAGS += -std=c++11

# create a unittest option
CONFIG(unittest) {
  QT += testlib

  HEADERS += tests/testsqlobjects.h tests/TestImport.h tests/TestRegex.h tests/TestRowCache.h
  SOURCES += tests/testsqlobjects.cpp tests/TestImport.cpp tests/TestRegex.cpp tests/TestRowCache.cpp
} else {
  SOURCES += main.cpp
}

HEADERS += \
    DbStructureModel.h \
    SongModel.h \
    SongItem.h \
    sqlitedb.h \
    AboutDialog.h \
    Settings.h \
    ExportDataDialog.h \
    ImportCsvDialog.h \
    sql/sqlitetypes.h \
    csvparser.h \
    ExtendedTableWidget.h \
    sqlitetablemodel.h \
    RowCache.h \
    RowLoader.h \
    FilterTableHeader.h \
    vAppSplash.h \
    vSongBooklist.h \
    vSongEditor.h \
    vSongHome.h \
    AsItem.h \
    AsDelegate.h \
    vSongOnline.h \
    vSongPreferences.h \
    vSongPresent.h \
    vSongTutorial.h \
    version.h \
    VacuumDialog.h \
    vSongBook.h \
    sqlite.h \
    CipherDialog.h \
    ExportSqlDialog.h \
    FileDialog.h \
    FilterLineEdit.h \
    RemoteDatabase.h \
    ForeignKeyEditorDelegate.h \
    PlotDock.h \
    RemoteModel.h \
    RemotePushDialog.h \
    FileExtensionManager.h \
    CondFormatManager.h \
    Data.h \
    CipherSettings.h \
    DotenvFormat.h \
    Palette.h \
    CondFormat.h \
    sql/Query.h \
    RunSql.h \
    sql/ObjectIdentifier.h \
    ProxyDialog.h \
    IconCache.h \
    SelectItemsPopup.h \
    sql/parser/ParserDriver.h \
    sql/parser/sqlite3_lexer.h \
    sql/parser/sqlite3_location.h \
    sql/parser/sqlite3_parser.hpp

SOURCES += \
    DbStructureModel.cpp \
    SongModel.cpp \
    SongItem.cpp \
    sqlitedb.cpp \
    Settings.cpp \
    AboutDialog.cpp \
    ExportDataDialog.cpp \
    ImportCsvDialog.cpp \
    sql/sqlitetypes.cpp \
    csvparser.cpp \
    ExtendedTableWidget.cpp \
    sqlitetablemodel.cpp \
    RowLoader.cpp \
    FilterTableHeader.cpp \
    VacuumDialog.cpp \
    vAppSplash.cpp \
    vSongBook.cpp \
    CipherDialog.cpp \
    ExportSqlDialog.cpp \
    FileDialog.cpp \
    FilterLineEdit.cpp \
    RemoteDatabase.cpp \
    ForeignKeyEditorDelegate.cpp \
    PlotDock.cpp \
    RemoteModel.cpp \
    RemotePushDialog.cpp \
    FileExtensionManager.cpp \
    CondFormatManager.cpp \
    Data.cpp \
    CipherSettings.cpp \
    DotenvFormat.cpp \
    Palette.cpp \
    CondFormat.cpp \
    sql/Query.cpp \
    RunSql.cpp \
    sql/ObjectIdentifier.cpp \
    ProxyDialog.cpp \
    IconCache.cpp \
    SelectItemsPopup.cpp \
    sql/parser/ParserDriver.cpp \
    sql/parser/sqlite3_lexer.cpp \
    sql/parser/sqlite3_parser.cpp \
    vSongBooklist.cpp \
    vSongEditor.cpp \
    vSongHome.cpp \
    AsDelegate.cpp \
    vSongOnline.cpp \
    vSongPreferences.cpp \
    vSongPresent.cpp \
    vSongTutorial.cpp

RESOURCES += icons/icons.qrc \
             images/images.qrc \
             translations/flags/flags.qrc \
             translations/translations.qrc \
             certs/CaCerts.qrc \
             qstyle/style.qrc \
             qdarkstyle/style.qrc

FORMS += \
    AboutDialog.ui \
    ExportDataDialog.ui \
    ImportCsvDialog.ui \
    VacuumDialog.ui \
    CipherDialog.ui \
    ExportSqlDialog.ui \
    PlotDock.ui \
    RemotePushDialog.ui \
    FileExtensionManager.ui \
    CondFormatManager.ui \
    ProxyDialog.ui \
    SelectItemsPopup.ui \
    vAppSplash.ui \
    vSongBooklist.ui \
    vSongEditor.ui \
    vSongHome.ui \
    vSongOnline.ui \
    vSongPreferences.ui \
    vSongPresent.ui \
    vSongTutorial.ui

TRANSLATIONS += \
    translations/sqlb_ar_SA.ts \
    translations/sqlb_cs.ts \
    translations/sqlb_zh.ts \
    translations/sqlb_zh_TW.ts \
    translations/sqlb_de.ts \
    translations/sqlb_es_ES.ts \
    translations/sqlb_fr.ts \
    translations/sqlb_ru.ts \
    translations/sqlb_pl.ts \
    translations/sqlb_pt_BR.ts \
    translations/sqlb_en_GB.ts \
    translations/sqlb_ko_KR.ts \
    translations/sqlb_tr.ts \
    translations/sqlb_uk_UA.ts \
    translations/sqlb_it.ts

# SQLite / SQLCipher switch pieces
CONFIG(sqlcipher) {
    QMAKE_CXXFLAGS += -DENABLE_SQLCIPHER
    LIBS += -lsqlcipher

    # Add the paths for Homebrew installed SQLCipher
    macx {
        INCLUDEPATH += /usr/local/opt/sqlcipher/include
        LIBS += -L/usr/local/opt/sqlcipher/lib
    }
} else {
    LIBS += -lsqlite3

    # Add the paths for Homebrew installed SQLite
    macx {
        INCLUDEPATH += /usr/local/opt/sqlite/include
        LIBS += -L/usr/local/opt/sqlite/lib
    }
}

LIBPATH_QHEXEDIT=$$OUT_PWD/../libs/qhexedit
LIBPATH_QCUSTOMPLOT=$$OUT_PWD/../libs/qcustomplot-source
LIBPATH_JSON=$$OUT_PWD/../libs/json
unix {
    LIBS += -ldl
}
os2 {
    RC_FILE = os2app.rc
}
win32 {
    TARGET = "vSongBook"
    RC_FILE = winapp.rc
    INCLUDEPATH += $$PWD
    CONFIG(debug,debug|release) {
        LIBPATH_QHEXEDIT = $$LIBPATH_QHEXEDIT/debug
        LIBPATH_QCUSTOMPLOT = $$LIBPATH_QCUSTOMPLOT/debug
        LIBPATH_JSON = $$LIBPATH_JSON/debug
    }
    CONFIG(release,debug|release) {
        LIBPATH_QHEXEDIT = $$LIBPATH_QHEXEDIT/release
        LIBPATH_QCUSTOMPLOT = $$LIBPATH_QCUSTOMPLOT/release
        LIBPATH_JSON = $$LIBPATH_JSON/release
    }
    QMAKE_CXXFLAGS += -DCHECKNEWVERSION

    # Added SQLite installation path variables, matching our setup guide
    LIBS += -L$$PWD/../../../dev/SQLite/ -lsqlite3
    INCLUDEPATH += $$PWD/../../../dev/SQLite
    DEPENDPATH += $$PWD/../../../dev/SQLite
}
macx {
    TARGET = "vSongBook"
    RC_FILE = macapp.icns
    QT += macextras opengl
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -framework Carbon
    QMAKE_INFO_PLIST = app.plist
    QMAKE_CXXFLAGS += -DCHECKNEWVERSION
}

CONFIG(all_warnings) {
    QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion
    QMAKE_CXXFLAGS += -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast
}

UI_DIR = .ui
INCLUDEPATH += $$PWD/../libs/qhexedit/src $$PWD/../libs/qcustomplot-source $$PWD/../libs/json $$PWD/..
LIBS += -L$$LIBPATH_QHEXEDIT -L$$LIBPATH_QCUSTOMPLOT -lqhexedit -lqcustomplot
DEPENDPATH += $$PWD/../libs/qhexedit $$PWD/../libs/qcustomplot-source $$PWD/../libs/json

unix {
    # Below, the user can specify where all generated file can be placed
    # through a set of variables, being them:
    #
    # PREFIX        -> the root directory where the files will be placed
    # BINDIR        -> where executables accessible by the user resides
    # DATADIR       -> where data files and resources should be placed
    #
    # The values of each variable changes between supported platforms and are describe as follow

    # Default configuration for package vSongBook.
    # The default prefix is /usr/local
    !defined(PREFIX, var):        PREFIX = /usr/local
    !defined(BINDIR, var):        BINDIR = $$PREFIX/bin
    !defined(DATADIR, var):       DATADIR = $$PREFIX/share

    # The executable
    target.path = $$BINDIR
    INSTALLS += target

    # Icon
    icon.path = $$DATADIR/icons/hicolor/256x256/apps/
    icon.files = icons/vSongBook.png
    INSTALLS += icon

    # Desktop metadata
    desktop.path = $$DATADIR/applications/
    desktop.files = ../distri/vSongBook.desktop
    INSTALLS += desktop
    appdata.path = $$DATADIR/appdata/
    appdata.files = ../distri/vSongBook.desktop.appdata.xml
    INSTALLS += appdata
}

# Rules for creating/updating {ts|qm}-files
include(i18n.pri)
