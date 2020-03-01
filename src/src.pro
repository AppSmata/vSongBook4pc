TEMPLATE = app

QT += core gui network widgets printsupport concurrent xml

TARGET = vSongBook

CONFIG += debug_and_release
CONFIG += qt
CONFIG += warn_on

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    AppAbout.h \
    AppEditor.h \
    Application.h \
    AppMain.h \
    AppOnline.h \
    AppPreferences.h \
    AppPresent.h \
    AppSongbooks.h \
    AppTutorial.h \
    Settings.h

SOURCES += \
    AppAbout.cpp \
    AppEditor.cpp \
    Application.cpp \
    AppMain.cpp \
    AppOnline.cpp \
    AppPreferences.cpp \
    AppPresent.cpp \
    AppSongbooks.cpp \
    AppTutorial.cpp \
    main.cpp \
    Settings.cpp

RESOURCES += icons/icons.qrc \
             translations/flags/flags.qrc \
             qdarkstyle/style.qrc

FORMS += \
    AppAbout.ui \
    AppEditor.ui \
    AppMain.ui \
    AppOnline.ui \
    AppPreferences.ui \
    AppPresent.ui \
    AppSongbooks.ui \
    AppTutorial.ui

TRANSLATIONS += \
    translations/sqlb_de.ts \
    translations/sqlb_es_ES.ts \
    translations/sqlb_en_GB.ts \
    translations/sqlb_fr.ts

LIBPATH_QCUSTOMPLOT=$$OUT_PWD/../libs/qcustomplot-source

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
        LIBPATH_QCUSTOMPLOT = $$LIBPATH_QCUSTOMPLOT/debug
    }
    CONFIG(release,debug|release) {
        LIBPATH_QCUSTOMPLOT = $$LIBPATH_QCUSTOMPLOT/release
    }
    QMAKE_CXXFLAGS += -DCHECKNEWVERSION

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
INCLUDEPATH += $$PWD/../libs/qcustomplot-source $$PWD/..
LIBS += -L$$LIBPATH_QCUSTOMPLOT -lqcustomplot
DEPENDPATH += $$PWD/../libs/qcustomplot-source

unix {
    # Below, the user can specify where all generated file can be placed
    # through a set of variables, being them:
    #
    # PREFIX        -> the root directory where the files will be placed
    # BINDIR        -> where executables accessible by the user resides
    # DATADIR       -> where data files and resources should be placed
    #
    # The values of each variable changes between supported platforms and are describe as follow

    # Default configuration for package AppBook.
    # The default prefix is /usr/local
    !defined(PREFIX, var):        PREFIX = /usr/local
    !defined(BINDIR, var):        BINDIR = $$PREFIX/bin
    !defined(DATADIR, var):       DATADIR = $$PREFIX/share

    # The executable
    target.path = $$BINDIR
    INSTALLS += target

    # Icon
    icon.path = $$DATADIR/icons/hicolor/256x256/apps/
    icon.files = icons/AppBook.png
    INSTALLS += icon

    # Desktop metadata
    desktop.path = $$DATADIR/applications/
    desktop.files = ../distri/vsongbook.desktop
    INSTALLS += desktop
    appdata.path = $$DATADIR/appdata/
    appdata.files = ../distri/vsongbook.desktop.appdata.xml
    INSTALLS += appdata
}

# Rules for creating/updating {ts|qm}-files
include(i18n.pri)
