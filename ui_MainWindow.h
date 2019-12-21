/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ExtendedScintilla.h"
#include "TableBrowser.h"
#include "sqltextedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *fileNewAction;
    QAction *fileOpenAction;
    QAction *fileCloseAction;
    QAction *fileRevertAction;
    QAction *fileSaveAction;
    QAction *fileCompactAction;
    QAction *fileExitAction;
    QAction *fileImportSQLAction;
    QAction *fileImportCSVAction;
    QAction *fileExportSQLAction;
    QAction *fileExportCSVAction;
    QAction *editCreateTableAction;
    QAction *editDeleteObjectAction;
    QAction *editModifyObjectAction;
    QAction *editCreateIndexAction;
    QAction *viewPreferencesAction;
    QAction *viewDBToolbarAction;
    QAction *helpWhatsThisAction;
    QAction *helpAboutAction;
    QAction *actionRecent_y_opened;
    QAction *actionSqlOpenTab;
    QAction *actionExecuteSql;
    QAction *actionSqlOpenFile;
    QAction *actionSqlSaveFile;
    QAction *actionLoadExtension;
    QAction *actionSqlExecuteLine;
    QAction *actionExportCsvPopup;
    QAction *actionWiki;
    QAction *actionBug_report;
    QAction *actionFeature_Request;
    QAction *actionWebsite;
    QAction *actionDonatePatreon;
    QAction *actionSaveProject;
    QAction *actionOpenProject;
    QAction *fileAttachAction;
    QAction *actionEncryption;
    QAction *actionSqlSaveFileAs;
    QAction *actionSqlSaveFilePopup;
    QAction *actionEditBrowseTable;
    QAction *actionEditCopyCreateStatement;
    QAction *actionSqlCipherFaq;
    QAction *fileExportJsonAction;
    QAction *fileOpenReadOnlyAction;
    QAction *actionSqlResultsSave;
    QAction *actionSqlFind;
    QAction *actionSqlFindReplace;
    QAction *actionSqlResultsExportCsv;
    QAction *actionSqlResultsSaveAsView;
    QAction *viewProjectToolbarAction;
    QAction *viewExtraDBToolbarAction;
    QAction *fileOpenActionPopup;
    QAction *fileNewInMemoryDatabaseAction;
    QAction *actionDropQualifiedCheck;
    QAction *actionEnquoteNamesCheck;
    QAction *actionIntegrityCheck;
    QAction *actionForeignKeyCheck;
    QAction *actionQuickCheck;
    QAction *actionOptimize;
    QAction *actionSqlPrint;
    QAction *actionDbPrint;
    QAction *actionSqlToggleComment;
    QAction *actionSqlStop;
    QAction *actionSaveProjectAs;
    QAction *actionSaveAll;
    QAction *actionPopupSchemaDockBrowseTable;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *mainTab;
    QWidget *structure;
    QVBoxLayout *verticalLayout;
    QToolBar *dbToolbar;
    QTreeView *dbTreeWidget;
    QWidget *browser;
    QVBoxLayout *verticalLayout_2;
    TableBrowser *tableBrowser;
    QWidget *pragmas;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollareaPragmas;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QLabel *labelPragmaAutoVacuum;
    QComboBox *comboboxPragmaAutoVacuum;
    QLabel *labelPragmaAutomaticIndex;
    QCheckBox *checkboxPragmaAutomaticIndex;
    QLabel *labelPragmaCaseSensitiveLike;
    QCheckBox *checkboxPragmaCaseSensitiveLike;
    QLabel *labelPragmaCheckpointFullFsync;
    QCheckBox *checkboxPragmaCheckpointFullFsync;
    QLabel *labelPragmaForeignKeys;
    QCheckBox *checkboxPragmaForeignKeys;
    QLabel *labelPragmaFullFsync;
    QCheckBox *checkboxPragmaFullFsync;
    QLabel *labelPragmaIgnoreCheckConstraints;
    QCheckBox *checkboxPragmaIgnoreCheckConstraints;
    QLabel *labelPragmaJournalMode;
    QComboBox *comboboxPragmaJournalMode;
    QLabel *labelJournalSizeLimit;
    QSpinBox *spinPragmaJournalSizeLimit;
    QLabel *labelPragmaLockingMode;
    QComboBox *comboboxPragmaLockingMode;
    QLabel *labelPragmaMaxPageCount;
    QSpinBox *spinPragmaMaxPageCount;
    QLabel *labelPragmaPageSize;
    QComboBox *comboPragmaPageSize;
    QLabel *labelPragmaRecursiveTriggers;
    QCheckBox *checkboxPragmaRecursiveTriggers;
    QLabel *labelPragmaSecureDelete;
    QCheckBox *checkboxPragmaSecureDelete;
    QLabel *labelPragmaSynchronous;
    QComboBox *comboboxPragmaSynchronous;
    QLabel *labelPragmaTempStore;
    QComboBox *comboboxPragmaTempStore;
    QLabel *labelPragmaUserVersion;
    QSpinBox *spinPragmaUserVersion;
    QLabel *labelPragmaWalAutoCheckpoint;
    QSpinBox *spinPragmaWalAutoCheckpoint;
    QDialogButtonBox *buttonBoxPragmas;
    QWidget *query;
    QVBoxLayout *verticalLayout_3;
    QToolBar *toolbarSql;
    QTabWidget *tabSqlAreas;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *menuImport;
    QMenu *menuExport;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QMenu *menuTools;
    QStatusBar *statusbar;
    QToolBar *toolbarDB;
    QDockWidget *dockEdit;
    QWidget *dockWidgetContents_4;
    QDockWidget *dockLog;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelLogSubmittedBy;
    QComboBox *comboLogSubmittedBy;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonLogClear;
    QStackedWidget *stackLog;
    SqlTextEdit *editLogUser;
    SqlTextEdit *editLogApplication;
    ExtendedScintilla *editLogErrorLog;
    QDockWidget *dockPlot;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    QDockWidget *dockSchema;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_9;
    QTreeView *treeSchemaDock;
    QDockWidget *dockRemote;
    QWidget *dockWidgetContents_5;
    QToolBar *toolbarProject;
    QToolBar *toolbarExtraDB;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1037, 630);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/appicon"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        fileNewAction = new QAction(MainWindow);
        fileNewAction->setObjectName(QString::fromUtf8("fileNewAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/db_new"), QSize(), QIcon::Normal, QIcon::Off);
        fileNewAction->setIcon(icon1);
        fileNewAction->setMenuRole(QAction::NoRole);
        fileOpenAction = new QAction(MainWindow);
        fileOpenAction->setObjectName(QString::fromUtf8("fileOpenAction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/db_open"), QSize(), QIcon::Normal, QIcon::Off);
        fileOpenAction->setIcon(icon2);
        fileOpenAction->setMenuRole(QAction::NoRole);
        fileCloseAction = new QAction(MainWindow);
        fileCloseAction->setObjectName(QString::fromUtf8("fileCloseAction"));
        fileCloseAction->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/close"), QSize(), QIcon::Normal, QIcon::Off);
        fileCloseAction->setIcon(icon3);
        fileCloseAction->setMenuRole(QAction::NoRole);
        fileRevertAction = new QAction(MainWindow);
        fileRevertAction->setObjectName(QString::fromUtf8("fileRevertAction"));
        fileRevertAction->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/db_revert"), QSize(), QIcon::Normal, QIcon::Off);
        fileRevertAction->setIcon(icon4);
        fileRevertAction->setMenuRole(QAction::NoRole);
        fileSaveAction = new QAction(MainWindow);
        fileSaveAction->setObjectName(QString::fromUtf8("fileSaveAction"));
        fileSaveAction->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/db_save"), QSize(), QIcon::Normal, QIcon::Off);
        fileSaveAction->setIcon(icon5);
        fileSaveAction->setMenuRole(QAction::NoRole);
        fileCompactAction = new QAction(MainWindow);
        fileCompactAction->setObjectName(QString::fromUtf8("fileCompactAction"));
        fileCompactAction->setEnabled(false);
        fileCompactAction->setMenuRole(QAction::NoRole);
        fileExitAction = new QAction(MainWindow);
        fileExitAction->setObjectName(QString::fromUtf8("fileExitAction"));
        fileExitAction->setMenuRole(QAction::QuitRole);
        fileImportSQLAction = new QAction(MainWindow);
        fileImportSQLAction->setObjectName(QString::fromUtf8("fileImportSQLAction"));
        fileImportSQLAction->setMenuRole(QAction::NoRole);
        fileImportCSVAction = new QAction(MainWindow);
        fileImportCSVAction->setObjectName(QString::fromUtf8("fileImportCSVAction"));
        fileImportCSVAction->setMenuRole(QAction::NoRole);
        fileExportSQLAction = new QAction(MainWindow);
        fileExportSQLAction->setObjectName(QString::fromUtf8("fileExportSQLAction"));
        fileExportSQLAction->setMenuRole(QAction::NoRole);
        fileExportCSVAction = new QAction(MainWindow);
        fileExportCSVAction->setObjectName(QString::fromUtf8("fileExportCSVAction"));
        fileExportCSVAction->setMenuRole(QAction::NoRole);
        editCreateTableAction = new QAction(MainWindow);
        editCreateTableAction->setObjectName(QString::fromUtf8("editCreateTableAction"));
        editCreateTableAction->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/table_create"), QSize(), QIcon::Normal, QIcon::Off);
        editCreateTableAction->setIcon(icon6);
        editCreateTableAction->setMenuRole(QAction::NoRole);
        editDeleteObjectAction = new QAction(MainWindow);
        editDeleteObjectAction->setObjectName(QString::fromUtf8("editDeleteObjectAction"));
        editDeleteObjectAction->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/table_delete"), QSize(), QIcon::Normal, QIcon::Off);
        editDeleteObjectAction->setIcon(icon7);
        editDeleteObjectAction->setMenuRole(QAction::NoRole);
        editModifyObjectAction = new QAction(MainWindow);
        editModifyObjectAction->setObjectName(QString::fromUtf8("editModifyObjectAction"));
        editModifyObjectAction->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/table_modify"), QSize(), QIcon::Normal, QIcon::Off);
        editModifyObjectAction->setIcon(icon8);
        editModifyObjectAction->setMenuRole(QAction::NoRole);
        editCreateIndexAction = new QAction(MainWindow);
        editCreateIndexAction->setObjectName(QString::fromUtf8("editCreateIndexAction"));
        editCreateIndexAction->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/index_create"), QSize(), QIcon::Normal, QIcon::Off);
        editCreateIndexAction->setIcon(icon9);
        editCreateIndexAction->setMenuRole(QAction::NoRole);
        viewPreferencesAction = new QAction(MainWindow);
        viewPreferencesAction->setObjectName(QString::fromUtf8("viewPreferencesAction"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/settings"), QSize(), QIcon::Normal, QIcon::Off);
        viewPreferencesAction->setIcon(icon10);
        viewPreferencesAction->setMenuRole(QAction::PreferencesRole);
        viewDBToolbarAction = new QAction(MainWindow);
        viewDBToolbarAction->setObjectName(QString::fromUtf8("viewDBToolbarAction"));
        viewDBToolbarAction->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/toolbar"), QSize(), QIcon::Normal, QIcon::Off);
        viewDBToolbarAction->setIcon(icon11);
        viewDBToolbarAction->setMenuRole(QAction::NoRole);
        helpWhatsThisAction = new QAction(MainWindow);
        helpWhatsThisAction->setObjectName(QString::fromUtf8("helpWhatsThisAction"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/whatis"), QSize(), QIcon::Normal, QIcon::Off);
        helpWhatsThisAction->setIcon(icon12);
        helpWhatsThisAction->setMenuRole(QAction::NoRole);
        helpAboutAction = new QAction(MainWindow);
        helpAboutAction->setObjectName(QString::fromUtf8("helpAboutAction"));
        helpAboutAction->setMenuRole(QAction::AboutRole);
        actionRecent_y_opened = new QAction(MainWindow);
        actionRecent_y_opened->setObjectName(QString::fromUtf8("actionRecent_y_opened"));
        actionSqlOpenTab = new QAction(MainWindow);
        actionSqlOpenTab->setObjectName(QString::fromUtf8("actionSqlOpenTab"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/open_tab"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlOpenTab->setIcon(icon13);
        actionExecuteSql = new QAction(MainWindow);
        actionExecuteSql->setObjectName(QString::fromUtf8("actionExecuteSql"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/run"), QSize(), QIcon::Normal, QIcon::Off);
        actionExecuteSql->setIcon(icon14);
        actionSqlOpenFile = new QAction(MainWindow);
        actionSqlOpenFile->setObjectName(QString::fromUtf8("actionSqlOpenFile"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/document_open"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlOpenFile->setIcon(icon15);
        actionSqlSaveFile = new QAction(MainWindow);
        actionSqlSaveFile->setObjectName(QString::fromUtf8("actionSqlSaveFile"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/save_sql"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlSaveFile->setIcon(icon16);
        actionLoadExtension = new QAction(MainWindow);
        actionLoadExtension->setObjectName(QString::fromUtf8("actionLoadExtension"));
        actionLoadExtension->setEnabled(false);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/load_extension"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadExtension->setIcon(icon17);
        actionLoadExtension->setMenuRole(QAction::NoRole);
        actionSqlExecuteLine = new QAction(MainWindow);
        actionSqlExecuteLine->setObjectName(QString::fromUtf8("actionSqlExecuteLine"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/run_line"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlExecuteLine->setIcon(icon18);
        actionExportCsvPopup = new QAction(MainWindow);
        actionExportCsvPopup->setObjectName(QString::fromUtf8("actionExportCsvPopup"));
        actionExportCsvPopup->setEnabled(false);
        actionWiki = new QAction(MainWindow);
        actionWiki->setObjectName(QString::fromUtf8("actionWiki"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons/browser_open"), QSize(), QIcon::Normal, QIcon::Off);
        actionWiki->setIcon(icon19);
        actionWiki->setMenuRole(QAction::NoRole);
        actionBug_report = new QAction(MainWindow);
        actionBug_report->setObjectName(QString::fromUtf8("actionBug_report"));
        actionBug_report->setIcon(icon19);
        actionBug_report->setMenuRole(QAction::NoRole);
        actionFeature_Request = new QAction(MainWindow);
        actionFeature_Request->setObjectName(QString::fromUtf8("actionFeature_Request"));
        actionFeature_Request->setIcon(icon19);
        actionFeature_Request->setMenuRole(QAction::NoRole);
        actionWebsite = new QAction(MainWindow);
        actionWebsite->setObjectName(QString::fromUtf8("actionWebsite"));
        actionWebsite->setIcon(icon19);
        actionWebsite->setMenuRole(QAction::NoRole);
        actionDonatePatreon = new QAction(MainWindow);
        actionDonatePatreon->setObjectName(QString::fromUtf8("actionDonatePatreon"));
        actionDonatePatreon->setIcon(icon19);
        actionDonatePatreon->setMenuRole(QAction::NoRole);
        actionSaveProject = new QAction(MainWindow);
        actionSaveProject->setObjectName(QString::fromUtf8("actionSaveProject"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons/project_save"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveProject->setIcon(icon20);
        actionSaveProject->setMenuRole(QAction::NoRole);
        actionOpenProject = new QAction(MainWindow);
        actionOpenProject->setObjectName(QString::fromUtf8("actionOpenProject"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons/project_open"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenProject->setIcon(icon21);
        actionOpenProject->setMenuRole(QAction::NoRole);
        fileAttachAction = new QAction(MainWindow);
        fileAttachAction->setObjectName(QString::fromUtf8("fileAttachAction"));
        fileAttachAction->setEnabled(false);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons/db_attach"), QSize(), QIcon::Normal, QIcon::Off);
        fileAttachAction->setIcon(icon22);
        fileAttachAction->setMenuRole(QAction::NoRole);
        actionEncryption = new QAction(MainWindow);
        actionEncryption->setObjectName(QString::fromUtf8("actionEncryption"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons/encryption"), QSize(), QIcon::Normal, QIcon::Off);
        actionEncryption->setIcon(icon23);
        actionEncryption->setMenuRole(QAction::NoRole);
        actionSqlSaveFileAs = new QAction(MainWindow);
        actionSqlSaveFileAs->setObjectName(QString::fromUtf8("actionSqlSaveFileAs"));
        actionSqlSaveFileAs->setIcon(icon16);
        actionSqlSaveFilePopup = new QAction(MainWindow);
        actionSqlSaveFilePopup->setObjectName(QString::fromUtf8("actionSqlSaveFilePopup"));
        actionSqlSaveFilePopup->setIcon(icon16);
        actionEditBrowseTable = new QAction(MainWindow);
        actionEditBrowseTable->setObjectName(QString::fromUtf8("actionEditBrowseTable"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons/table"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditBrowseTable->setIcon(icon24);
        actionEditCopyCreateStatement = new QAction(MainWindow);
        actionEditCopyCreateStatement->setObjectName(QString::fromUtf8("actionEditCopyCreateStatement"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/icons/copy"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditCopyCreateStatement->setIcon(icon25);
        actionSqlCipherFaq = new QAction(MainWindow);
        actionSqlCipherFaq->setObjectName(QString::fromUtf8("actionSqlCipherFaq"));
        actionSqlCipherFaq->setIcon(icon19);
        fileExportJsonAction = new QAction(MainWindow);
        fileExportJsonAction->setObjectName(QString::fromUtf8("fileExportJsonAction"));
        fileExportJsonAction->setMenuRole(QAction::NoRole);
        fileOpenReadOnlyAction = new QAction(MainWindow);
        fileOpenReadOnlyAction->setObjectName(QString::fromUtf8("fileOpenReadOnlyAction"));
        fileOpenReadOnlyAction->setIcon(icon2);
        fileOpenReadOnlyAction->setMenuRole(QAction::NoRole);
        actionSqlResultsSave = new QAction(MainWindow);
        actionSqlResultsSave->setObjectName(QString::fromUtf8("actionSqlResultsSave"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/icons/save_table"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlResultsSave->setIcon(icon26);
        actionSqlFind = new QAction(MainWindow);
        actionSqlFind->setObjectName(QString::fromUtf8("actionSqlFind"));
        actionSqlFind->setCheckable(true);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/icons/find"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlFind->setIcon(icon27);
        actionSqlFind->setShortcutContext(Qt::WidgetShortcut);
        actionSqlFindReplace = new QAction(MainWindow);
        actionSqlFindReplace->setObjectName(QString::fromUtf8("actionSqlFindReplace"));
        actionSqlFindReplace->setCheckable(false);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/icons/text_replace"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlFindReplace->setIcon(icon28);
        actionSqlFindReplace->setShortcutContext(Qt::WidgetShortcut);
        actionSqlResultsExportCsv = new QAction(MainWindow);
        actionSqlResultsExportCsv->setObjectName(QString::fromUtf8("actionSqlResultsExportCsv"));
        actionSqlResultsSaveAsView = new QAction(MainWindow);
        actionSqlResultsSaveAsView->setObjectName(QString::fromUtf8("actionSqlResultsSaveAsView"));
        viewProjectToolbarAction = new QAction(MainWindow);
        viewProjectToolbarAction->setObjectName(QString::fromUtf8("viewProjectToolbarAction"));
        viewProjectToolbarAction->setCheckable(true);
        viewProjectToolbarAction->setChecked(false);
        viewProjectToolbarAction->setIcon(icon11);
        viewProjectToolbarAction->setMenuRole(QAction::NoRole);
        viewExtraDBToolbarAction = new QAction(MainWindow);
        viewExtraDBToolbarAction->setObjectName(QString::fromUtf8("viewExtraDBToolbarAction"));
        viewExtraDBToolbarAction->setCheckable(true);
        viewExtraDBToolbarAction->setIcon(icon11);
        fileOpenActionPopup = new QAction(MainWindow);
        fileOpenActionPopup->setObjectName(QString::fromUtf8("fileOpenActionPopup"));
        fileOpenActionPopup->setIcon(icon2);
        fileOpenActionPopup->setMenuRole(QAction::TextHeuristicRole);
        fileNewInMemoryDatabaseAction = new QAction(MainWindow);
        fileNewInMemoryDatabaseAction->setObjectName(QString::fromUtf8("fileNewInMemoryDatabaseAction"));
        actionDropQualifiedCheck = new QAction(MainWindow);
        actionDropQualifiedCheck->setObjectName(QString::fromUtf8("actionDropQualifiedCheck"));
        actionDropQualifiedCheck->setCheckable(true);
        actionEnquoteNamesCheck = new QAction(MainWindow);
        actionEnquoteNamesCheck->setObjectName(QString::fromUtf8("actionEnquoteNamesCheck"));
        actionEnquoteNamesCheck->setCheckable(true);
        actionIntegrityCheck = new QAction(MainWindow);
        actionIntegrityCheck->setObjectName(QString::fromUtf8("actionIntegrityCheck"));
        actionForeignKeyCheck = new QAction(MainWindow);
        actionForeignKeyCheck->setObjectName(QString::fromUtf8("actionForeignKeyCheck"));
        actionQuickCheck = new QAction(MainWindow);
        actionQuickCheck->setObjectName(QString::fromUtf8("actionQuickCheck"));
        actionOptimize = new QAction(MainWindow);
        actionOptimize->setObjectName(QString::fromUtf8("actionOptimize"));
        actionSqlPrint = new QAction(MainWindow);
        actionSqlPrint->setObjectName(QString::fromUtf8("actionSqlPrint"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/icons/print"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlPrint->setIcon(icon29);
        actionSqlPrint->setShortcutContext(Qt::WidgetShortcut);
        actionDbPrint = new QAction(MainWindow);
        actionDbPrint->setObjectName(QString::fromUtf8("actionDbPrint"));
        actionDbPrint->setEnabled(false);
        actionDbPrint->setIcon(icon29);
        actionDbPrint->setShortcutContext(Qt::WidgetShortcut);
        actionSqlToggleComment = new QAction(MainWindow);
        actionSqlToggleComment->setObjectName(QString::fromUtf8("actionSqlToggleComment"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/icons/comment_block"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlToggleComment->setIcon(icon30);
        actionSqlToggleComment->setShortcutContext(Qt::WidgetShortcut);
        actionSqlStop = new QAction(MainWindow);
        actionSqlStop->setObjectName(QString::fromUtf8("actionSqlStop"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/icons/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        actionSqlStop->setIcon(icon31);
        actionSaveProjectAs = new QAction(MainWindow);
        actionSaveProjectAs->setObjectName(QString::fromUtf8("actionSaveProjectAs"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/icons/project_save_as"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveProjectAs->setIcon(icon32);
        actionSaveAll = new QAction(MainWindow);
        actionSaveAll->setObjectName(QString::fromUtf8("actionSaveAll"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/icons/save_all"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAll->setIcon(icon33);
        actionPopupSchemaDockBrowseTable = new QAction(MainWindow);
        actionPopupSchemaDockBrowseTable->setObjectName(QString::fromUtf8("actionPopupSchemaDockBrowseTable"));
        actionPopupSchemaDockBrowseTable->setIcon(icon24);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(3, 3, 3, 3);
        mainTab = new QTabWidget(centralwidget);
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        mainTab->setMovable(true);
        mainTab->setTabBarAutoHide(true);
        structure = new QWidget();
        structure->setObjectName(QString::fromUtf8("structure"));
        verticalLayout = new QVBoxLayout(structure);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        dbToolbar = new QToolBar(structure);
        dbToolbar->setObjectName(QString::fromUtf8("dbToolbar"));
        dbToolbar->setWindowTitle(QString::fromUtf8("toolBar1"));
        dbToolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(dbToolbar);

        dbTreeWidget = new QTreeView(structure);
        dbTreeWidget->setObjectName(QString::fromUtf8("dbTreeWidget"));
        dbTreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        dbTreeWidget->setDragEnabled(true);
        dbTreeWidget->setDragDropMode(QAbstractItemView::DragDrop);
        dbTreeWidget->setAlternatingRowColors(true);
        dbTreeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        dbTreeWidget->setAnimated(true);

        verticalLayout->addWidget(dbTreeWidget);

        mainTab->addTab(structure, QString());
        browser = new QWidget();
        browser->setObjectName(QString::fromUtf8("browser"));
        verticalLayout_2 = new QVBoxLayout(browser);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        tableBrowser = new TableBrowser(browser);
        tableBrowser->setObjectName(QString::fromUtf8("tableBrowser"));

        verticalLayout_2->addWidget(tableBrowser);

        mainTab->addTab(browser, QString());
        pragmas = new QWidget();
        pragmas->setObjectName(QString::fromUtf8("pragmas"));
        verticalLayout_4 = new QVBoxLayout(pragmas);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        scrollareaPragmas = new QScrollArea(pragmas);
        scrollareaPragmas->setObjectName(QString::fromUtf8("scrollareaPragmas"));
        scrollareaPragmas->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 596, 526));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        labelPragmaAutoVacuum = new QLabel(scrollAreaWidgetContents);
        labelPragmaAutoVacuum->setObjectName(QString::fromUtf8("labelPragmaAutoVacuum"));
        labelPragmaAutoVacuum->setText(QString::fromUtf8("<html><head/><body><p>Auto Vacuum <a href=\"http://www.sqlite.org/pragma.html#pragma_auto_vacuum\"><img src=\":/icons/whatis\"/></a></p></body></html>"));
        labelPragmaAutoVacuum->setOpenExternalLinks(true);
        labelPragmaAutoVacuum->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPragmaAutoVacuum);

        comboboxPragmaAutoVacuum = new QComboBox(scrollAreaWidgetContents);
        comboboxPragmaAutoVacuum->addItem(QString::fromUtf8("None"));
        comboboxPragmaAutoVacuum->addItem(QString::fromUtf8("Full"));
        comboboxPragmaAutoVacuum->addItem(QString::fromUtf8("Incremental"));
        comboboxPragmaAutoVacuum->setObjectName(QString::fromUtf8("comboboxPragmaAutoVacuum"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboboxPragmaAutoVacuum);

        labelPragmaAutomaticIndex = new QLabel(scrollAreaWidgetContents);
        labelPragmaAutomaticIndex->setObjectName(QString::fromUtf8("labelPragmaAutomaticIndex"));
        labelPragmaAutomaticIndex->setText(QString::fromUtf8("<html><head/><body><p>Automatic Index <a href=\"http://www.sqlite.org/pragma.html#pragma_automatic_index\"><img src=\":/icons/whatis\"/></a></p></body></html>"));
        labelPragmaAutomaticIndex->setOpenExternalLinks(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPragmaAutomaticIndex);

        checkboxPragmaAutomaticIndex = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaAutomaticIndex->setObjectName(QString::fromUtf8("checkboxPragmaAutomaticIndex"));

        formLayout->setWidget(1, QFormLayout::FieldRole, checkboxPragmaAutomaticIndex);

        labelPragmaCaseSensitiveLike = new QLabel(scrollAreaWidgetContents);
        labelPragmaCaseSensitiveLike->setObjectName(QString::fromUtf8("labelPragmaCaseSensitiveLike"));
        labelPragmaCaseSensitiveLike->setText(QString::fromUtf8("<html><head/><body><p>Case Sensitive Like <a href=\"https://www.sqlite.org/pragma.html#pragma_case_sensitive_like\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaCaseSensitiveLike->setOpenExternalLinks(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPragmaCaseSensitiveLike);

        checkboxPragmaCaseSensitiveLike = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaCaseSensitiveLike->setObjectName(QString::fromUtf8("checkboxPragmaCaseSensitiveLike"));

        formLayout->setWidget(2, QFormLayout::FieldRole, checkboxPragmaCaseSensitiveLike);

        labelPragmaCheckpointFullFsync = new QLabel(scrollAreaWidgetContents);
        labelPragmaCheckpointFullFsync->setObjectName(QString::fromUtf8("labelPragmaCheckpointFullFsync"));
        labelPragmaCheckpointFullFsync->setText(QString::fromUtf8("<html><head/><body><p>Checkpoint Full FSYNC <a href=\"https://www.sqlite.org/pragma.html#pragma_checkpoint_fullfsync\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaCheckpointFullFsync->setOpenExternalLinks(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelPragmaCheckpointFullFsync);

        checkboxPragmaCheckpointFullFsync = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaCheckpointFullFsync->setObjectName(QString::fromUtf8("checkboxPragmaCheckpointFullFsync"));

        formLayout->setWidget(3, QFormLayout::FieldRole, checkboxPragmaCheckpointFullFsync);

        labelPragmaForeignKeys = new QLabel(scrollAreaWidgetContents);
        labelPragmaForeignKeys->setObjectName(QString::fromUtf8("labelPragmaForeignKeys"));
        labelPragmaForeignKeys->setText(QString::fromUtf8("<html><head/><body><p>Foreign Keys <a href=\"https://www.sqlite.org/pragma.html#pragma_foreign_keys\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaForeignKeys->setOpenExternalLinks(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelPragmaForeignKeys);

        checkboxPragmaForeignKeys = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaForeignKeys->setObjectName(QString::fromUtf8("checkboxPragmaForeignKeys"));

        formLayout->setWidget(4, QFormLayout::FieldRole, checkboxPragmaForeignKeys);

        labelPragmaFullFsync = new QLabel(scrollAreaWidgetContents);
        labelPragmaFullFsync->setObjectName(QString::fromUtf8("labelPragmaFullFsync"));
        labelPragmaFullFsync->setText(QString::fromUtf8("<html><head/><body><p>Full FSYNC <a href=\"https://www.sqlite.org/pragma.html#pragma_fullfsync\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaFullFsync->setOpenExternalLinks(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelPragmaFullFsync);

        checkboxPragmaFullFsync = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaFullFsync->setObjectName(QString::fromUtf8("checkboxPragmaFullFsync"));

        formLayout->setWidget(5, QFormLayout::FieldRole, checkboxPragmaFullFsync);

        labelPragmaIgnoreCheckConstraints = new QLabel(scrollAreaWidgetContents);
        labelPragmaIgnoreCheckConstraints->setObjectName(QString::fromUtf8("labelPragmaIgnoreCheckConstraints"));
        labelPragmaIgnoreCheckConstraints->setText(QString::fromUtf8("<html><head/><body><p>Ignore Check Constraints <a href=\"https://www.sqlite.org/pragma.html#pragma_ignore_check_constraints\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaIgnoreCheckConstraints->setOpenExternalLinks(true);

        formLayout->setWidget(6, QFormLayout::LabelRole, labelPragmaIgnoreCheckConstraints);

        checkboxPragmaIgnoreCheckConstraints = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaIgnoreCheckConstraints->setObjectName(QString::fromUtf8("checkboxPragmaIgnoreCheckConstraints"));

        formLayout->setWidget(6, QFormLayout::FieldRole, checkboxPragmaIgnoreCheckConstraints);

        labelPragmaJournalMode = new QLabel(scrollAreaWidgetContents);
        labelPragmaJournalMode->setObjectName(QString::fromUtf8("labelPragmaJournalMode"));
        labelPragmaJournalMode->setText(QString::fromUtf8("<html><head/><body><p>Journal Mode <a href=\"https://www.sqlite.org/pragma.html#pragma_journal_mode\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaJournalMode->setOpenExternalLinks(true);

        formLayout->setWidget(7, QFormLayout::LabelRole, labelPragmaJournalMode);

        comboboxPragmaJournalMode = new QComboBox(scrollAreaWidgetContents);
        comboboxPragmaJournalMode->addItem(QString::fromUtf8("Delete"));
        comboboxPragmaJournalMode->addItem(QString::fromUtf8("Truncate"));
        comboboxPragmaJournalMode->addItem(QString::fromUtf8("Persist"));
        comboboxPragmaJournalMode->addItem(QString::fromUtf8("Memory"));
        comboboxPragmaJournalMode->addItem(QString::fromUtf8("WAL"));
        comboboxPragmaJournalMode->addItem(QString::fromUtf8("Off"));
        comboboxPragmaJournalMode->setObjectName(QString::fromUtf8("comboboxPragmaJournalMode"));

        formLayout->setWidget(7, QFormLayout::FieldRole, comboboxPragmaJournalMode);

        labelJournalSizeLimit = new QLabel(scrollAreaWidgetContents);
        labelJournalSizeLimit->setObjectName(QString::fromUtf8("labelJournalSizeLimit"));
        labelJournalSizeLimit->setText(QString::fromUtf8("<html><head/><body><p>Journal Size Limit <a href=\"https://www.sqlite.org/pragma.html#pragma_journal_size_limit\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelJournalSizeLimit->setOpenExternalLinks(true);

        formLayout->setWidget(8, QFormLayout::LabelRole, labelJournalSizeLimit);

        spinPragmaJournalSizeLimit = new QSpinBox(scrollAreaWidgetContents);
        spinPragmaJournalSizeLimit->setObjectName(QString::fromUtf8("spinPragmaJournalSizeLimit"));
        spinPragmaJournalSizeLimit->setMinimum(-1);
        spinPragmaJournalSizeLimit->setMaximum(100000);

        formLayout->setWidget(8, QFormLayout::FieldRole, spinPragmaJournalSizeLimit);

        labelPragmaLockingMode = new QLabel(scrollAreaWidgetContents);
        labelPragmaLockingMode->setObjectName(QString::fromUtf8("labelPragmaLockingMode"));
        labelPragmaLockingMode->setText(QString::fromUtf8("<html><head/><body><p>Locking Mode <a href=\"https://www.sqlite.org/pragma.html#pragma_locking_mode\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaLockingMode->setOpenExternalLinks(true);

        formLayout->setWidget(9, QFormLayout::LabelRole, labelPragmaLockingMode);

        comboboxPragmaLockingMode = new QComboBox(scrollAreaWidgetContents);
        comboboxPragmaLockingMode->addItem(QString::fromUtf8("Normal"));
        comboboxPragmaLockingMode->addItem(QString::fromUtf8("Exclusive"));
        comboboxPragmaLockingMode->setObjectName(QString::fromUtf8("comboboxPragmaLockingMode"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboboxPragmaLockingMode);

        labelPragmaMaxPageCount = new QLabel(scrollAreaWidgetContents);
        labelPragmaMaxPageCount->setObjectName(QString::fromUtf8("labelPragmaMaxPageCount"));
        labelPragmaMaxPageCount->setText(QString::fromUtf8("<html><head/><body><p>Max Page Count <a href=\"https://www.sqlite.org/pragma.html#pragma_max_page_count\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaMaxPageCount->setOpenExternalLinks(true);

        formLayout->setWidget(10, QFormLayout::LabelRole, labelPragmaMaxPageCount);

        spinPragmaMaxPageCount = new QSpinBox(scrollAreaWidgetContents);
        spinPragmaMaxPageCount->setObjectName(QString::fromUtf8("spinPragmaMaxPageCount"));
        spinPragmaMaxPageCount->setMaximum(2000000000);

        formLayout->setWidget(10, QFormLayout::FieldRole, spinPragmaMaxPageCount);

        labelPragmaPageSize = new QLabel(scrollAreaWidgetContents);
        labelPragmaPageSize->setObjectName(QString::fromUtf8("labelPragmaPageSize"));
        labelPragmaPageSize->setText(QString::fromUtf8("<html><head/><body><p>Page Size <a href=\"https://www.sqlite.org/pragma.html#pragma_page_size\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaPageSize->setOpenExternalLinks(true);

        formLayout->setWidget(11, QFormLayout::LabelRole, labelPragmaPageSize);

        comboPragmaPageSize = new QComboBox(scrollAreaWidgetContents);
        comboPragmaPageSize->addItem(QString::fromUtf8("512"));
        comboPragmaPageSize->addItem(QString::fromUtf8("1024"));
        comboPragmaPageSize->addItem(QString::fromUtf8("2048"));
        comboPragmaPageSize->addItem(QString::fromUtf8("4096"));
        comboPragmaPageSize->addItem(QString::fromUtf8("8192"));
        comboPragmaPageSize->addItem(QString::fromUtf8("16384"));
        comboPragmaPageSize->addItem(QString::fromUtf8("32768"));
        comboPragmaPageSize->addItem(QString::fromUtf8("65536"));
        comboPragmaPageSize->setObjectName(QString::fromUtf8("comboPragmaPageSize"));

        formLayout->setWidget(11, QFormLayout::FieldRole, comboPragmaPageSize);

        labelPragmaRecursiveTriggers = new QLabel(scrollAreaWidgetContents);
        labelPragmaRecursiveTriggers->setObjectName(QString::fromUtf8("labelPragmaRecursiveTriggers"));
        labelPragmaRecursiveTriggers->setText(QString::fromUtf8("<html><head/><body><p>Recursive Triggers <a href=\"https://www.sqlite.org/pragma.html#pragma_recursive_triggers\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaRecursiveTriggers->setOpenExternalLinks(true);

        formLayout->setWidget(12, QFormLayout::LabelRole, labelPragmaRecursiveTriggers);

        checkboxPragmaRecursiveTriggers = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaRecursiveTriggers->setObjectName(QString::fromUtf8("checkboxPragmaRecursiveTriggers"));

        formLayout->setWidget(12, QFormLayout::FieldRole, checkboxPragmaRecursiveTriggers);

        labelPragmaSecureDelete = new QLabel(scrollAreaWidgetContents);
        labelPragmaSecureDelete->setObjectName(QString::fromUtf8("labelPragmaSecureDelete"));
        labelPragmaSecureDelete->setText(QString::fromUtf8("<html><head/><body><p>Secure Delete <a href=\"https://www.sqlite.org/pragma.html#pragma_secure_delete\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaSecureDelete->setOpenExternalLinks(true);

        formLayout->setWidget(13, QFormLayout::LabelRole, labelPragmaSecureDelete);

        checkboxPragmaSecureDelete = new QCheckBox(scrollAreaWidgetContents);
        checkboxPragmaSecureDelete->setObjectName(QString::fromUtf8("checkboxPragmaSecureDelete"));

        formLayout->setWidget(13, QFormLayout::FieldRole, checkboxPragmaSecureDelete);

        labelPragmaSynchronous = new QLabel(scrollAreaWidgetContents);
        labelPragmaSynchronous->setObjectName(QString::fromUtf8("labelPragmaSynchronous"));
        labelPragmaSynchronous->setText(QString::fromUtf8("<html><head/><body><p>Synchronous <a href=\"https://www.sqlite.org/pragma.html#pragma_synchronous\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaSynchronous->setOpenExternalLinks(true);

        formLayout->setWidget(14, QFormLayout::LabelRole, labelPragmaSynchronous);

        comboboxPragmaSynchronous = new QComboBox(scrollAreaWidgetContents);
        comboboxPragmaSynchronous->addItem(QString::fromUtf8("Off"));
        comboboxPragmaSynchronous->addItem(QString::fromUtf8("Normal"));
        comboboxPragmaSynchronous->addItem(QString::fromUtf8("Full"));
        comboboxPragmaSynchronous->setObjectName(QString::fromUtf8("comboboxPragmaSynchronous"));

        formLayout->setWidget(14, QFormLayout::FieldRole, comboboxPragmaSynchronous);

        labelPragmaTempStore = new QLabel(scrollAreaWidgetContents);
        labelPragmaTempStore->setObjectName(QString::fromUtf8("labelPragmaTempStore"));
        labelPragmaTempStore->setText(QString::fromUtf8("<html><head/><body><p>Temp Store <a href=\"https://www.sqlite.org/pragma.html#pragma_temp_store\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaTempStore->setOpenExternalLinks(true);

        formLayout->setWidget(15, QFormLayout::LabelRole, labelPragmaTempStore);

        comboboxPragmaTempStore = new QComboBox(scrollAreaWidgetContents);
        comboboxPragmaTempStore->addItem(QString::fromUtf8("Default"));
        comboboxPragmaTempStore->addItem(QString::fromUtf8("File"));
        comboboxPragmaTempStore->addItem(QString::fromUtf8("Memory"));
        comboboxPragmaTempStore->setObjectName(QString::fromUtf8("comboboxPragmaTempStore"));

        formLayout->setWidget(15, QFormLayout::FieldRole, comboboxPragmaTempStore);

        labelPragmaUserVersion = new QLabel(scrollAreaWidgetContents);
        labelPragmaUserVersion->setObjectName(QString::fromUtf8("labelPragmaUserVersion"));
        labelPragmaUserVersion->setText(QString::fromUtf8("<html><head/><body><p>User Version <a href=\"https://www.sqlite.org/pragma.html#pragma_user_version\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaUserVersion->setOpenExternalLinks(true);

        formLayout->setWidget(16, QFormLayout::LabelRole, labelPragmaUserVersion);

        spinPragmaUserVersion = new QSpinBox(scrollAreaWidgetContents);
        spinPragmaUserVersion->setObjectName(QString::fromUtf8("spinPragmaUserVersion"));
        spinPragmaUserVersion->setMaximum(2147483647);

        formLayout->setWidget(16, QFormLayout::FieldRole, spinPragmaUserVersion);

        labelPragmaWalAutoCheckpoint = new QLabel(scrollAreaWidgetContents);
        labelPragmaWalAutoCheckpoint->setObjectName(QString::fromUtf8("labelPragmaWalAutoCheckpoint"));
        labelPragmaWalAutoCheckpoint->setText(QString::fromUtf8("<html><head/><body><p>WAL Auto Checkpoint <a href=\"https://www.sqlite.org/pragma.html#pragma_wal_autocheckpoint\"><img src=\":/icons/whatis\"/></a></a></p></body></html>"));
        labelPragmaWalAutoCheckpoint->setOpenExternalLinks(true);

        formLayout->setWidget(17, QFormLayout::LabelRole, labelPragmaWalAutoCheckpoint);

        spinPragmaWalAutoCheckpoint = new QSpinBox(scrollAreaWidgetContents);
        spinPragmaWalAutoCheckpoint->setObjectName(QString::fromUtf8("spinPragmaWalAutoCheckpoint"));
        spinPragmaWalAutoCheckpoint->setMaximum(10000);

        formLayout->setWidget(17, QFormLayout::FieldRole, spinPragmaWalAutoCheckpoint);

        scrollareaPragmas->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollareaPragmas);

        buttonBoxPragmas = new QDialogButtonBox(pragmas);
        buttonBoxPragmas->setObjectName(QString::fromUtf8("buttonBoxPragmas"));
        buttonBoxPragmas->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBoxPragmas->setCenterButtons(false);

        verticalLayout_4->addWidget(buttonBoxPragmas);

        mainTab->addTab(pragmas, QString());
        query = new QWidget();
        query->setObjectName(QString::fromUtf8("query"));
        verticalLayout_3 = new QVBoxLayout(query);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        toolbarSql = new QToolBar(query);
        toolbarSql->setObjectName(QString::fromUtf8("toolbarSql"));

        verticalLayout_3->addWidget(toolbarSql);

        tabSqlAreas = new QTabWidget(query);
        tabSqlAreas->setObjectName(QString::fromUtf8("tabSqlAreas"));
        tabSqlAreas->setMovable(true);
        tabSqlAreas->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_3->addWidget(tabSqlAreas);

        mainTab->addTab(query, QString());

        verticalLayout_7->addWidget(mainTab);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1037, 22));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        menuImport = new QMenu(fileMenu);
        menuImport->setObjectName(QString::fromUtf8("menuImport"));
        menuExport = new QMenu(fileMenu);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        editMenu = new QMenu(menubar);
        editMenu->setObjectName(QString::fromUtf8("editMenu"));
        viewMenu = new QMenu(menubar);
        viewMenu->setObjectName(QString::fromUtf8("viewMenu"));
        helpMenu = new QMenu(menubar);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolbarDB = new QToolBar(MainWindow);
        toolbarDB->setObjectName(QString::fromUtf8("toolbarDB"));
        toolbarDB->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolbarDB);
        dockEdit = new QDockWidget(MainWindow);
        dockEdit->setObjectName(QString::fromUtf8("dockEdit"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        dockEdit->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockEdit);
        dockLog = new QDockWidget(MainWindow);
        dockLog->setObjectName(QString::fromUtf8("dockLog"));
        dockLog->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelLogSubmittedBy = new QLabel(dockWidgetContents);
        labelLogSubmittedBy->setObjectName(QString::fromUtf8("labelLogSubmittedBy"));
        labelLogSubmittedBy->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(labelLogSubmittedBy);

        comboLogSubmittedBy = new QComboBox(dockWidgetContents);
        comboLogSubmittedBy->addItem(QString());
        comboLogSubmittedBy->addItem(QString());
        comboLogSubmittedBy->addItem(QString());
        comboLogSubmittedBy->setObjectName(QString::fromUtf8("comboLogSubmittedBy"));
        comboLogSubmittedBy->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(comboLogSubmittedBy);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        buttonLogClear = new QPushButton(dockWidgetContents);
        buttonLogClear->setObjectName(QString::fromUtf8("buttonLogClear"));
        buttonLogClear->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(buttonLogClear);


        verticalLayout_5->addLayout(horizontalLayout_3);

        stackLog = new QStackedWidget(dockWidgetContents);
        stackLog->setObjectName(QString::fromUtf8("stackLog"));
        editLogUser = new SqlTextEdit();
        editLogUser->setObjectName(QString::fromUtf8("editLogUser"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(8);
        editLogUser->setFont(font);
        editLogUser->setReadOnly(true);
        stackLog->addWidget(editLogUser);
        editLogApplication = new SqlTextEdit();
        editLogApplication->setObjectName(QString::fromUtf8("editLogApplication"));
        editLogApplication->setFont(font);
        editLogApplication->setReadOnly(true);
        stackLog->addWidget(editLogApplication);
        editLogErrorLog = new ExtendedScintilla();
        editLogErrorLog->setObjectName(QString::fromUtf8("editLogErrorLog"));
        editLogErrorLog->setFont(font);
        editLogErrorLog->setReadOnly(true);
        stackLog->addWidget(editLogErrorLog);

        verticalLayout_5->addWidget(stackLog);

        dockLog->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockLog);
        dockPlot = new QDockWidget(MainWindow);
        dockPlot->setObjectName(QString::fromUtf8("dockPlot"));
        dockPlot->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        dockPlot->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockPlot);
        dockSchema = new QDockWidget(MainWindow);
        dockSchema->setObjectName(QString::fromUtf8("dockSchema"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_9 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        treeSchemaDock = new QTreeView(dockWidgetContents_3);
        treeSchemaDock->setObjectName(QString::fromUtf8("treeSchemaDock"));
        treeSchemaDock->setContextMenuPolicy(Qt::CustomContextMenu);
        treeSchemaDock->setDragEnabled(true);
        treeSchemaDock->setDragDropMode(QAbstractItemView::DragDrop);
        treeSchemaDock->setAlternatingRowColors(true);
        treeSchemaDock->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeSchemaDock->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeSchemaDock->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        treeSchemaDock->setAnimated(true);

        verticalLayout_9->addWidget(treeSchemaDock);

        dockSchema->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockSchema);
        dockRemote = new QDockWidget(MainWindow);
        dockRemote->setObjectName(QString::fromUtf8("dockRemote"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        dockRemote->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockRemote);
        toolbarProject = new QToolBar(MainWindow);
        toolbarProject->setObjectName(QString::fromUtf8("toolbarProject"));
        toolbarProject->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolbarProject);
        toolbarExtraDB = new QToolBar(MainWindow);
        toolbarExtraDB->setObjectName(QString::fromUtf8("toolbarExtraDB"));
        toolbarExtraDB->setEnabled(true);
        toolbarExtraDB->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolbarExtraDB);
#ifndef QT_NO_SHORTCUT
        labelPragmaAutoVacuum->setBuddy(comboboxPragmaAutoVacuum);
        labelPragmaAutomaticIndex->setBuddy(checkboxPragmaAutomaticIndex);
        labelPragmaCaseSensitiveLike->setBuddy(checkboxPragmaCaseSensitiveLike);
        labelPragmaCheckpointFullFsync->setBuddy(checkboxPragmaCheckpointFullFsync);
        labelPragmaForeignKeys->setBuddy(checkboxPragmaForeignKeys);
        labelPragmaFullFsync->setBuddy(checkboxPragmaFullFsync);
        labelPragmaIgnoreCheckConstraints->setBuddy(checkboxPragmaIgnoreCheckConstraints);
        labelPragmaJournalMode->setBuddy(comboboxPragmaJournalMode);
        labelJournalSizeLimit->setBuddy(spinPragmaJournalSizeLimit);
        labelPragmaLockingMode->setBuddy(comboboxPragmaLockingMode);
        labelPragmaMaxPageCount->setBuddy(spinPragmaMaxPageCount);
        labelPragmaPageSize->setBuddy(comboPragmaPageSize);
        labelPragmaRecursiveTriggers->setBuddy(checkboxPragmaRecursiveTriggers);
        labelPragmaSecureDelete->setBuddy(checkboxPragmaSecureDelete);
        labelPragmaSynchronous->setBuddy(comboboxPragmaSynchronous);
        labelPragmaTempStore->setBuddy(comboboxPragmaTempStore);
        labelPragmaUserVersion->setBuddy(spinPragmaUserVersion);
        labelPragmaWalAutoCheckpoint->setBuddy(spinPragmaWalAutoCheckpoint);
        labelLogSubmittedBy->setBuddy(comboLogSubmittedBy);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(mainTab, dbTreeWidget);
        QWidget::setTabOrder(dbTreeWidget, comboLogSubmittedBy);
        QWidget::setTabOrder(comboLogSubmittedBy, buttonLogClear);
        QWidget::setTabOrder(buttonLogClear, treeSchemaDock);
        QWidget::setTabOrder(treeSchemaDock, scrollareaPragmas);
        QWidget::setTabOrder(scrollareaPragmas, comboboxPragmaAutoVacuum);
        QWidget::setTabOrder(comboboxPragmaAutoVacuum, checkboxPragmaAutomaticIndex);
        QWidget::setTabOrder(checkboxPragmaAutomaticIndex, checkboxPragmaCaseSensitiveLike);
        QWidget::setTabOrder(checkboxPragmaCaseSensitiveLike, checkboxPragmaCheckpointFullFsync);
        QWidget::setTabOrder(checkboxPragmaCheckpointFullFsync, checkboxPragmaForeignKeys);
        QWidget::setTabOrder(checkboxPragmaForeignKeys, checkboxPragmaFullFsync);
        QWidget::setTabOrder(checkboxPragmaFullFsync, checkboxPragmaIgnoreCheckConstraints);
        QWidget::setTabOrder(checkboxPragmaIgnoreCheckConstraints, comboboxPragmaJournalMode);
        QWidget::setTabOrder(comboboxPragmaJournalMode, spinPragmaJournalSizeLimit);
        QWidget::setTabOrder(spinPragmaJournalSizeLimit, comboboxPragmaLockingMode);
        QWidget::setTabOrder(comboboxPragmaLockingMode, spinPragmaMaxPageCount);
        QWidget::setTabOrder(spinPragmaMaxPageCount, comboPragmaPageSize);
        QWidget::setTabOrder(comboPragmaPageSize, checkboxPragmaSecureDelete);
        QWidget::setTabOrder(checkboxPragmaSecureDelete, checkboxPragmaRecursiveTriggers);
        QWidget::setTabOrder(checkboxPragmaRecursiveTriggers, comboboxPragmaSynchronous);
        QWidget::setTabOrder(comboboxPragmaSynchronous, comboboxPragmaTempStore);
        QWidget::setTabOrder(comboboxPragmaTempStore, spinPragmaUserVersion);
        QWidget::setTabOrder(spinPragmaUserVersion, spinPragmaWalAutoCheckpoint);
        QWidget::setTabOrder(spinPragmaWalAutoCheckpoint, tabSqlAreas);

        dbToolbar->addAction(editCreateTableAction);
        dbToolbar->addAction(editCreateIndexAction);
        dbToolbar->addAction(editModifyObjectAction);
        dbToolbar->addAction(editDeleteObjectAction);
        dbToolbar->addSeparator();
        dbToolbar->addAction(actionDbPrint);
        toolbarSql->addAction(actionSqlOpenTab);
        toolbarSql->addAction(actionSqlOpenFile);
        toolbarSql->addAction(actionSqlSaveFilePopup);
        toolbarSql->addAction(actionSqlPrint);
        toolbarSql->addSeparator();
        toolbarSql->addAction(actionExecuteSql);
        toolbarSql->addAction(actionSqlExecuteLine);
        toolbarSql->addAction(actionSqlStop);
        toolbarSql->addSeparator();
        toolbarSql->addAction(actionSqlResultsSave);
        toolbarSql->addSeparator();
        toolbarSql->addAction(actionSqlFind);
        toolbarSql->addAction(actionSqlFindReplace);
        toolbarSql->addSeparator();
        toolbarSql->addAction(actionSqlToggleComment);
        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(editMenu->menuAction());
        menubar->addAction(viewMenu->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(helpMenu->menuAction());
        fileMenu->addAction(fileNewAction);
        fileMenu->addAction(fileNewInMemoryDatabaseAction);
        fileMenu->addAction(fileOpenAction);
        fileMenu->addAction(fileOpenReadOnlyAction);
        fileMenu->addAction(fileAttachAction);
        fileMenu->addAction(fileCloseAction);
        fileMenu->addSeparator();
        fileMenu->addAction(fileSaveAction);
        fileMenu->addAction(fileRevertAction);
        fileMenu->addSeparator();
        fileMenu->addAction(menuImport->menuAction());
        fileMenu->addAction(menuExport->menuAction());
        fileMenu->addSeparator();
        fileMenu->addAction(actionOpenProject);
        fileMenu->addAction(actionSaveProject);
        fileMenu->addAction(actionSaveProjectAs);
        fileMenu->addSeparator();
        fileMenu->addAction(actionSaveAll);
        fileMenu->addSeparator();
        fileMenu->addAction(fileExitAction);
        menuImport->addAction(fileImportSQLAction);
        menuImport->addAction(fileImportCSVAction);
        menuExport->addAction(fileExportSQLAction);
        menuExport->addAction(fileExportCSVAction);
        menuExport->addAction(fileExportJsonAction);
        editMenu->addAction(editCreateTableAction);
        editMenu->addAction(editModifyObjectAction);
        editMenu->addAction(editDeleteObjectAction);
        editMenu->addSeparator();
        editMenu->addAction(editCreateIndexAction);
        editMenu->addSeparator();
        editMenu->addAction(viewPreferencesAction);
        viewMenu->addAction(viewDBToolbarAction);
        viewMenu->addAction(viewExtraDBToolbarAction);
        viewMenu->addAction(viewProjectToolbarAction);
        viewMenu->addSeparator();
        helpMenu->addAction(helpWhatsThisAction);
        helpMenu->addSeparator();
        helpMenu->addAction(actionWebsite);
        helpMenu->addAction(actionWiki);
        helpMenu->addAction(actionSqlCipherFaq);
        helpMenu->addSeparator();
        helpMenu->addAction(actionBug_report);
        helpMenu->addAction(actionFeature_Request);
        helpMenu->addAction(actionDonatePatreon);
        helpMenu->addSeparator();
        helpMenu->addAction(helpAboutAction);
        menuTools->addAction(fileCompactAction);
        menuTools->addAction(actionEncryption);
        menuTools->addSeparator();
        menuTools->addAction(actionLoadExtension);
        menuTools->addSeparator();
        menuTools->addAction(actionIntegrityCheck);
        menuTools->addAction(actionQuickCheck);
        menuTools->addAction(actionForeignKeyCheck);
        menuTools->addAction(actionOptimize);
        toolbarDB->addAction(fileNewAction);
        toolbarDB->addAction(fileOpenActionPopup);
        toolbarDB->addSeparator();
        toolbarDB->addAction(fileSaveAction);
        toolbarDB->addAction(fileRevertAction);
        toolbarProject->addAction(actionOpenProject);
        toolbarProject->addAction(actionSaveProject);
        toolbarExtraDB->addAction(fileAttachAction);
        toolbarExtraDB->addAction(fileCloseAction);

        retranslateUi(MainWindow);
        QObject::connect(fileExitAction, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(fileOpenAction, SIGNAL(triggered()), MainWindow, SLOT(fileOpen()));
        QObject::connect(fileNewAction, SIGNAL(triggered()), MainWindow, SLOT(fileNew()));
        QObject::connect(fileCloseAction, SIGNAL(triggered()), MainWindow, SLOT(fileClose()));
        QObject::connect(fileCompactAction, SIGNAL(triggered()), MainWindow, SLOT(compact()));
        QObject::connect(helpWhatsThisAction, SIGNAL(triggered()), MainWindow, SLOT(helpWhatsThis()));
        QObject::connect(helpAboutAction, SIGNAL(triggered()), MainWindow, SLOT(helpAbout()));
        QObject::connect(mainTab, SIGNAL(currentChanged(int)), MainWindow, SLOT(mainTabSelected(int)));
        QObject::connect(fileImportCSVAction, SIGNAL(triggered()), MainWindow, SLOT(importTableFromCSV()));
        QObject::connect(fileExportCSVAction, SIGNAL(triggered()), MainWindow, SLOT(exportTableToCSV()));
        QObject::connect(fileRevertAction, SIGNAL(triggered()), MainWindow, SLOT(fileRevert()));
        QObject::connect(fileSaveAction, SIGNAL(triggered()), MainWindow, SLOT(fileSave()));
        QObject::connect(editCreateIndexAction, SIGNAL(triggered()), MainWindow, SLOT(createIndex()));
        QObject::connect(editDeleteObjectAction, SIGNAL(triggered()), MainWindow, SLOT(deleteObject()));
        QObject::connect(editModifyObjectAction, SIGNAL(triggered()), MainWindow, SLOT(editObject()));
        QObject::connect(fileExportSQLAction, SIGNAL(triggered()), MainWindow, SLOT(exportDatabaseToSQL()));
        QObject::connect(fileImportSQLAction, SIGNAL(triggered()), MainWindow, SLOT(importDatabaseFromSQL()));
        QObject::connect(viewPreferencesAction, SIGNAL(triggered()), MainWindow, SLOT(openPreferences()));
        QObject::connect(dbTreeWidget, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(createTreeContextMenu(QPoint)));
        QObject::connect(treeSchemaDock, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(createSchemaDockContextMenu(QPoint)));
        QObject::connect(viewDBToolbarAction, SIGNAL(toggled(bool)), toolbarDB, SLOT(setVisible(bool)));
        QObject::connect(actionSqlFind, SIGNAL(toggled(bool)), MainWindow, SLOT(setFindFrameVisibility(bool)));
        QObject::connect(actionSqlFindReplace, SIGNAL(triggered()), MainWindow, SLOT(openFindReplaceDialog()));
        QObject::connect(editCreateTableAction, SIGNAL(triggered()), MainWindow, SLOT(createTable()));
        QObject::connect(buttonBoxPragmas, SIGNAL(rejected()), MainWindow, SLOT(loadPragmas()));
        QObject::connect(buttonBoxPragmas, SIGNAL(accepted()), MainWindow, SLOT(savePragmas()));
        QObject::connect(buttonLogClear, SIGNAL(clicked()), editLogApplication, SLOT(clear()));
        QObject::connect(buttonLogClear, SIGNAL(clicked()), editLogUser, SLOT(clear()));
        QObject::connect(buttonLogClear, SIGNAL(clicked()), editLogErrorLog, SLOT(clear()));
        QObject::connect(comboLogSubmittedBy, SIGNAL(currentIndexChanged(int)), stackLog, SLOT(setCurrentIndex(int)));
        QObject::connect(tabSqlAreas, SIGNAL(tabCloseRequested(int)), MainWindow, SLOT(closeSqlTab(int)));
        QObject::connect(tabSqlAreas, SIGNAL(currentChanged(int)), MainWindow, SLOT(changeSqlTab(int)));
        QObject::connect(actionExecuteSql, SIGNAL(triggered()), MainWindow, SLOT(executeQuery()));
        QObject::connect(actionSqlOpenTab, SIGNAL(triggered()), MainWindow, SLOT(openSqlTab()));
        QObject::connect(actionSqlOpenFile, SIGNAL(triggered()), MainWindow, SLOT(openSqlFile()));
        QObject::connect(actionSqlSaveFile, SIGNAL(triggered()), MainWindow, SLOT(saveSqlFile()));
        QObject::connect(actionLoadExtension, SIGNAL(triggered()), MainWindow, SLOT(loadExtension()));
        QObject::connect(actionSqlExecuteLine, SIGNAL(triggered()), MainWindow, SLOT(executeQuery()));
        QObject::connect(actionExportCsvPopup, SIGNAL(triggered()), MainWindow, SLOT(exportTableToCSV()));
        QObject::connect(actionOpenProject, SIGNAL(triggered()), MainWindow, SLOT(loadProject()));
        QObject::connect(actionSaveProject, SIGNAL(triggered()), MainWindow, SLOT(saveProject()));
        QObject::connect(fileAttachAction, SIGNAL(triggered()), MainWindow, SLOT(fileAttach()));
        QObject::connect(actionEncryption, SIGNAL(triggered()), MainWindow, SLOT(editEncryption()));
        QObject::connect(actionSqlSaveFilePopup, SIGNAL(triggered()), MainWindow, SLOT(saveSqlFile()));
        QObject::connect(actionSqlSaveFileAs, SIGNAL(triggered()), MainWindow, SLOT(saveSqlFileAs()));
        QObject::connect(actionEditBrowseTable, SIGNAL(triggered()), MainWindow, SLOT(switchToBrowseDataTab()));
        QObject::connect(actionEditCopyCreateStatement, SIGNAL(triggered()), MainWindow, SLOT(copyCurrentCreateStatement()));
        QObject::connect(fileExportJsonAction, SIGNAL(triggered()), MainWindow, SLOT(exportTableToJson()));
        QObject::connect(fileOpenReadOnlyAction, SIGNAL(triggered()), MainWindow, SLOT(fileOpenReadOnly()));
        QObject::connect(actionSqlResultsExportCsv, SIGNAL(triggered()), MainWindow, SLOT(saveSqlResultsAsCsv()));
        QObject::connect(actionSqlResultsSaveAsView, SIGNAL(triggered()), MainWindow, SLOT(saveSqlResultsAsView()));
        QObject::connect(tabSqlAreas, SIGNAL(tabBarDoubleClicked(int)), MainWindow, SLOT(renameSqlTab(int)));
        QObject::connect(viewProjectToolbarAction, SIGNAL(toggled(bool)), toolbarProject, SLOT(setVisible(bool)));
        QObject::connect(viewExtraDBToolbarAction, SIGNAL(toggled(bool)), toolbarExtraDB, SLOT(setVisible(bool)));
        QObject::connect(MainWindow, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), toolbarDB, SLOT(setToolButtonStyle(Qt::ToolButtonStyle)));
        QObject::connect(MainWindow, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), toolbarExtraDB, SLOT(setToolButtonStyle(Qt::ToolButtonStyle)));
        QObject::connect(MainWindow, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), toolbarProject, SLOT(setToolButtonStyle(Qt::ToolButtonStyle)));
        QObject::connect(fileOpenActionPopup, SIGNAL(triggered()), MainWindow, SLOT(fileOpen()));
        QObject::connect(fileNewInMemoryDatabaseAction, SIGNAL(triggered()), MainWindow, SLOT(fileNewInMemoryDatabase()));
        QObject::connect(actionSqlPrint, SIGNAL(triggered()), MainWindow, SLOT(openSqlPrintDialog()));
        QObject::connect(actionDbPrint, SIGNAL(triggered()), MainWindow, SLOT(printDbStructure()));
        QObject::connect(actionSqlToggleComment, SIGNAL(triggered()), MainWindow, SLOT(toggleSqlBlockComment()));
        QObject::connect(labelPragmaAutomaticIndex, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaCaseSensitiveLike, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaCheckpointFullFsync, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaForeignKeys, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaFullFsync, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaIgnoreCheckConstraints, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaJournalMode, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaLockingMode, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaMaxPageCount, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaPageSize, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaRecursiveTriggers, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaSecureDelete, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaSynchronous, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaTempStore, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaUserVersion, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaWalAutoCheckpoint, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaAutoVacuum, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelPragmaAutoVacuum, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(labelJournalSizeLimit, SIGNAL(linkHovered(QString)), MainWindow, SLOT(showStatusMessage5s(QString)));
        QObject::connect(actionSaveProjectAs, SIGNAL(triggered()), MainWindow, SLOT(saveProjectAs()));
        QObject::connect(actionSaveAll, SIGNAL(triggered()), MainWindow, SLOT(saveAll()));
        QObject::connect(tabSqlAreas, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(showContextMenuSqlTabBar(QPoint)));

        mainTab->setCurrentIndex(0);
        tabSqlAreas->setCurrentIndex(-1);
        stackLog->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "vSongBook", nullptr));
        fileNewAction->setText(QApplication::translate("MainWindow", "&New Database...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileNewAction->setToolTip(QApplication::translate("MainWindow", "Create a new database file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileNewAction->setStatusTip(QApplication::translate("MainWindow", "Create a new database file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileNewAction->setWhatsThis(QApplication::translate("MainWindow", "This option is used to create a new database file.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        fileNewAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        fileOpenAction->setText(QApplication::translate("MainWindow", "&Open Database...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileOpenAction->setToolTip(QApplication::translate("MainWindow", "Open an existing database file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileOpenAction->setStatusTip(QApplication::translate("MainWindow", "Open an existing database file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileOpenAction->setWhatsThis(QApplication::translate("MainWindow", "This option is used to open an existing database file.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        fileOpenAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        fileCloseAction->setText(QApplication::translate("MainWindow", "&Close Database", nullptr));
#ifndef QT_NO_TOOLTIP
        fileCloseAction->setToolTip(QApplication::translate("MainWindow", "Close the current database file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileCloseAction->setStatusTip(QApplication::translate("MainWindow", "Close the current database file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileCloseAction->setWhatsThis(QApplication::translate("MainWindow", "This button closes the connection to the currently open database file", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        fileCloseAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", nullptr));
#endif // QT_NO_SHORTCUT
        fileRevertAction->setText(QApplication::translate("MainWindow", "&Revert Changes", nullptr));
#ifndef QT_NO_TOOLTIP
        fileRevertAction->setToolTip(QApplication::translate("MainWindow", "Revert database to last saved state", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileRevertAction->setStatusTip(QApplication::translate("MainWindow", "Revert database to last saved state", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileRevertAction->setWhatsThis(QApplication::translate("MainWindow", "This option is used to revert the current database file to its last saved state. All changes made since the last save operation are lost.", nullptr));
#endif // QT_NO_WHATSTHIS
        fileSaveAction->setText(QApplication::translate("MainWindow", "&Write Changes", nullptr));
#ifndef QT_NO_TOOLTIP
        fileSaveAction->setToolTip(QApplication::translate("MainWindow", "Write changes to the database file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileSaveAction->setStatusTip(QApplication::translate("MainWindow", "Write changes to the database file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileSaveAction->setWhatsThis(QApplication::translate("MainWindow", "This option is used to save changes to the database file.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        fileSaveAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        fileCompactAction->setText(QApplication::translate("MainWindow", "Compact &Database...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileCompactAction->setToolTip(QApplication::translate("MainWindow", "Compact the database file, removing space wasted by deleted records", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileCompactAction->setStatusTip(QApplication::translate("MainWindow", "Compact the database file, removing space wasted by deleted records.", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileCompactAction->setWhatsThis(QApplication::translate("MainWindow", "Compact the database file, removing space wasted by deleted records.", nullptr));
#endif // QT_NO_WHATSTHIS
        fileExitAction->setText(QApplication::translate("MainWindow", "E&xit", nullptr));
#ifndef QT_NO_SHORTCUT
        fileExitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        fileImportSQLAction->setText(QApplication::translate("MainWindow", "&Database from SQL file...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileImportSQLAction->setToolTip(QApplication::translate("MainWindow", "Import data from an .sql dump text file into a new or existing database.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        fileImportSQLAction->setWhatsThis(QApplication::translate("MainWindow", "This option lets you import data from an .sql dump text file into a new or existing database. SQL dump files can be created on most database engines, including MySQL and PostgreSQL.", nullptr));
#endif // QT_NO_WHATSTHIS
        fileImportCSVAction->setText(QApplication::translate("MainWindow", "&Table from CSV file...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileImportCSVAction->setToolTip(QApplication::translate("MainWindow", "Open a wizard that lets you import data from a comma separated text file into a database table.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        fileImportCSVAction->setWhatsThis(QApplication::translate("MainWindow", "Open a wizard that lets you import data from a comma separated text file into a database table. CSV files can be created on most database and spreadsheet applications.", nullptr));
#endif // QT_NO_WHATSTHIS
        fileExportSQLAction->setText(QApplication::translate("MainWindow", "&Database to SQL file...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileExportSQLAction->setToolTip(QApplication::translate("MainWindow", "Export a database to a .sql dump text file.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        fileExportSQLAction->setWhatsThis(QApplication::translate("MainWindow", "This option lets you export a database to a .sql dump text file. SQL dump files contain all data necessary to recreate the database on most database engines, including MySQL and PostgreSQL.", nullptr));
#endif // QT_NO_WHATSTHIS
        fileExportCSVAction->setText(QApplication::translate("MainWindow", "&Table(s) as CSV file...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileExportCSVAction->setToolTip(QApplication::translate("MainWindow", "Export a database table as a comma separated text file.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        fileExportCSVAction->setWhatsThis(QApplication::translate("MainWindow", "Export a database table as a comma separated text file, ready to be imported into other database or spreadsheet applications.", nullptr));
#endif // QT_NO_WHATSTHIS
        editCreateTableAction->setText(QApplication::translate("MainWindow", "&Create Table...", nullptr));
#ifndef QT_NO_WHATSTHIS
        editCreateTableAction->setWhatsThis(QApplication::translate("MainWindow", "Open the Create Table wizard, where it is possible to define the name and fields for a new table in the database", nullptr));
#endif // QT_NO_WHATSTHIS
        editDeleteObjectAction->setText(QApplication::translate("MainWindow", "&Delete Table...", nullptr));
#ifndef QT_NO_TOOLTIP
        editDeleteObjectAction->setToolTip(QApplication::translate("MainWindow", "Delete Table", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        editDeleteObjectAction->setWhatsThis(QApplication::translate("MainWindow", "Open the Delete Table wizard, where you can select a database table to be dropped.", nullptr));
#endif // QT_NO_WHATSTHIS
        editModifyObjectAction->setText(QApplication::translate("MainWindow", "&Modify Table...", nullptr));
#ifndef QT_NO_WHATSTHIS
        editModifyObjectAction->setWhatsThis(QApplication::translate("MainWindow", "Open the Modify Table wizard, where it is possible to rename an existing table. It is also possible to add or delete fields form a table, as well as modify field names and types.", nullptr));
#endif // QT_NO_WHATSTHIS
        editCreateIndexAction->setText(QApplication::translate("MainWindow", "Create &Index...", nullptr));
#ifndef QT_NO_WHATSTHIS
        editCreateIndexAction->setWhatsThis(QApplication::translate("MainWindow", "Open the Create Index wizard, where it is possible to define a new index on an existing database table.", nullptr));
#endif // QT_NO_WHATSTHIS
        viewPreferencesAction->setText(QApplication::translate("MainWindow", "&Preferences...", nullptr));
#ifndef QT_NO_TOOLTIP
        viewPreferencesAction->setToolTip(QApplication::translate("MainWindow", "Open the preferences window.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        viewPreferencesAction->setWhatsThis(QApplication::translate("MainWindow", "Open the preferences window.", nullptr));
#endif // QT_NO_WHATSTHIS
        viewDBToolbarAction->setText(QApplication::translate("MainWindow", "&DB Toolbar", nullptr));
#ifndef QT_NO_WHATSTHIS
        viewDBToolbarAction->setWhatsThis(QApplication::translate("MainWindow", "Shows or hides the Database toolbar.", nullptr));
#endif // QT_NO_WHATSTHIS
        helpWhatsThisAction->setText(QApplication::translate("MainWindow", "W&hat's This?", nullptr));
#ifndef QT_NO_SHORTCUT
        helpWhatsThisAction->setShortcut(QApplication::translate("MainWindow", "Shift+F1", nullptr));
#endif // QT_NO_SHORTCUT
        helpAboutAction->setText(QApplication::translate("MainWindow", "&About", nullptr));
        actionRecent_y_opened->setText(QApplication::translate("MainWindow", "&Recently opened", nullptr));
        actionSqlOpenTab->setText(QApplication::translate("MainWindow", "Open &tab", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionSqlOpenTab->setWhatsThis(QApplication::translate("MainWindow", "This button opens a new tab for the SQL editor", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSqlOpenTab->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        actionExecuteSql->setText(QApplication::translate("MainWindow", "&Execute SQL", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExecuteSql->setToolTip(QApplication::translate("MainWindow", "Execute all/selected SQL", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionExecuteSql->setWhatsThis(QApplication::translate("MainWindow", "This button executes the currently selected SQL statements. If no text is selected, all SQL statements are executed.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionExecuteSql->setShortcut(QApplication::translate("MainWindow", "Ctrl+Return", nullptr));
#endif // QT_NO_SHORTCUT
        actionSqlOpenFile->setText(QApplication::translate("MainWindow", "Open SQL file", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionSqlOpenFile->setWhatsThis(QApplication::translate("MainWindow", "This button opens a file containing SQL statements and loads it in a new editor tab", nullptr));
#endif // QT_NO_WHATSTHIS
        actionSqlSaveFile->setText(QApplication::translate("MainWindow", "Save SQL file", nullptr));
        actionLoadExtension->setText(QApplication::translate("MainWindow", "&Load Extension...", nullptr));
        actionSqlExecuteLine->setText(QApplication::translate("MainWindow", "Execute current line", nullptr));
        actionSqlExecuteLine->setIconText(QApplication::translate("MainWindow", "Execute line", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlExecuteLine->setToolTip(QApplication::translate("MainWindow", "Execute current line", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlExecuteLine->setWhatsThis(QApplication::translate("MainWindow", "This button executes the SQL statement present in the current editor line", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSqlExecuteLine->setShortcut(QApplication::translate("MainWindow", "Shift+F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionExportCsvPopup->setText(QApplication::translate("MainWindow", "Export as CSV file", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExportCsvPopup->setToolTip(QApplication::translate("MainWindow", "Export table as comma separated values file", nullptr));
#endif // QT_NO_TOOLTIP
        actionWiki->setText(QApplication::translate("MainWindow", "&Wiki", nullptr));
#ifndef QT_NO_SHORTCUT
        actionWiki->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionBug_report->setText(QApplication::translate("MainWindow", "Bug &Report...", nullptr));
        actionFeature_Request->setText(QApplication::translate("MainWindow", "Feature Re&quest...", nullptr));
        actionWebsite->setText(QApplication::translate("MainWindow", "Web&site", nullptr));
        actionDonatePatreon->setText(QApplication::translate("MainWindow", "&Donate on Patreon...", nullptr));
        actionSaveProject->setText(QApplication::translate("MainWindow", "Sa&ve Project", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveProject->setToolTip(QApplication::translate("MainWindow", "Save the current session to a file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveProject->setStatusTip(QApplication::translate("MainWindow", "Save the current session to a file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSaveProject->setWhatsThis(QApplication::translate("MainWindow", "This button lets you save all the settings associated to the open DB to a DB4S project file", nullptr));
#endif // QT_NO_WHATSTHIS
        actionOpenProject->setText(QApplication::translate("MainWindow", "Open &Project...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpenProject->setToolTip(QApplication::translate("MainWindow", "Load a working session from a file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOpenProject->setStatusTip(QApplication::translate("MainWindow", "Load a working session from a file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionOpenProject->setWhatsThis(QApplication::translate("MainWindow", "This button lets you open a DB4S project file", nullptr));
#endif // QT_NO_WHATSTHIS
        fileAttachAction->setText(QApplication::translate("MainWindow", "&Attach Database...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileAttachAction->setToolTip(QApplication::translate("MainWindow", "Add another database file to the current database connection", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileAttachAction->setStatusTip(QApplication::translate("MainWindow", "Add another database file to the current database connection", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileAttachAction->setWhatsThis(QApplication::translate("MainWindow", "This button lets you add another database file to the current database connection", nullptr));
#endif // QT_NO_WHATSTHIS
        actionEncryption->setText(QApplication::translate("MainWindow", "&Set Encryption...", nullptr));
        actionSqlSaveFileAs->setText(QApplication::translate("MainWindow", "Save SQL file as", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlSaveFileAs->setToolTip(QApplication::translate("MainWindow", "Save SQL file as", nullptr));
#endif // QT_NO_TOOLTIP
        actionSqlSaveFilePopup->setText(QApplication::translate("MainWindow", "Save SQL file", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlSaveFilePopup->setToolTip(QApplication::translate("MainWindow", "Save SQL file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlSaveFilePopup->setWhatsThis(QApplication::translate("MainWindow", "This button saves the content of the current SQL editor tab to a file", nullptr));
#endif // QT_NO_WHATSTHIS
        actionEditBrowseTable->setText(QApplication::translate("MainWindow", "&Browse Table", nullptr));
        actionEditCopyCreateStatement->setText(QApplication::translate("MainWindow", "Copy Create statement", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEditCopyCreateStatement->setToolTip(QApplication::translate("MainWindow", "Copy the CREATE statement of the item to the clipboard", nullptr));
#endif // QT_NO_TOOLTIP
        actionSqlCipherFaq->setText(QApplication::translate("MainWindow", "SQLCipher &FAQ", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlCipherFaq->setToolTip(QApplication::translate("MainWindow", "Opens the SQLCipher FAQ in a browser window", nullptr));
#endif // QT_NO_TOOLTIP
        fileExportJsonAction->setText(QApplication::translate("MainWindow", "Table(&s) to JSON...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileExportJsonAction->setToolTip(QApplication::translate("MainWindow", "Export one or more table(s) to a JSON file", nullptr));
#endif // QT_NO_TOOLTIP
        fileOpenReadOnlyAction->setText(QApplication::translate("MainWindow", "Open Data&base Read Only...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileOpenReadOnlyAction->setToolTip(QApplication::translate("MainWindow", "Open an existing database file in read only mode", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileOpenReadOnlyAction->setStatusTip(QApplication::translate("MainWindow", "Open an existing database file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileOpenReadOnlyAction->setWhatsThis(QApplication::translate("MainWindow", "This option is used to open an existing database file.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        fileOpenReadOnlyAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSqlResultsSave->setText(QApplication::translate("MainWindow", "Save results", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlResultsSave->setToolTip(QApplication::translate("MainWindow", "Save the results view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlResultsSave->setWhatsThis(QApplication::translate("MainWindow", "This button lets you save the results of the last executed query", nullptr));
#endif // QT_NO_WHATSTHIS
        actionSqlFind->setText(QApplication::translate("MainWindow", "Find text in SQL editor", nullptr));
        actionSqlFind->setIconText(QApplication::translate("MainWindow", "Find", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlFind->setToolTip(QApplication::translate("MainWindow", "Find text in SQL editor", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlFind->setWhatsThis(QApplication::translate("MainWindow", "This button opens the search bar of the editor", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSqlFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionSqlFindReplace->setText(QApplication::translate("MainWindow", "Find or replace text in SQL editor", nullptr));
        actionSqlFindReplace->setIconText(QApplication::translate("MainWindow", "Find or replace", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlFindReplace->setToolTip(QApplication::translate("MainWindow", "Find or replace text in SQL editor", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlFindReplace->setWhatsThis(QApplication::translate("MainWindow", "This button opens the find/replace dialog for the current editor tab", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSqlFindReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionSqlResultsExportCsv->setText(QApplication::translate("MainWindow", "Export to &CSV", nullptr));
        actionSqlResultsSaveAsView->setText(QApplication::translate("MainWindow", "Save as &view", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlResultsSaveAsView->setToolTip(QApplication::translate("MainWindow", "Save as view", nullptr));
#endif // QT_NO_TOOLTIP
        viewProjectToolbarAction->setText(QApplication::translate("MainWindow", "Project Toolbar", nullptr));
#ifndef QT_NO_WHATSTHIS
        viewProjectToolbarAction->setWhatsThis(QApplication::translate("MainWindow", "Shows or hides the Project toolbar.", nullptr));
#endif // QT_NO_WHATSTHIS
        viewExtraDBToolbarAction->setText(QApplication::translate("MainWindow", "Extra DB Toolbar", nullptr));
        fileOpenActionPopup->setText(QApplication::translate("MainWindow", "&Open Database...", nullptr));
#ifndef QT_NO_TOOLTIP
        fileOpenActionPopup->setToolTip(QApplication::translate("MainWindow", "Open an existing database file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        fileOpenActionPopup->setStatusTip(QApplication::translate("MainWindow", "Open an existing database file", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        fileOpenActionPopup->setWhatsThis(QApplication::translate("MainWindow", "This option is used to open an existing database file.", nullptr));
#endif // QT_NO_WHATSTHIS
        fileNewInMemoryDatabaseAction->setText(QApplication::translate("MainWindow", "New In-&Memory Database", nullptr));
        actionDropQualifiedCheck->setText(QApplication::translate("MainWindow", "Drag && Drop Qualified Names", nullptr));
#ifndef QT_NO_STATUSTIP
        actionDropQualifiedCheck->setStatusTip(QApplication::translate("MainWindow", "Use qualified names (e.g. \"Table\".\"Field\") when dragging the objects and dropping them into the editor ", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionDropQualifiedCheck->setWhatsThis(QApplication::translate("MainWindow", "Use qualified names (e.g. \"Table\".\"Field\") when dragging the objects and dropping them into the editor ", nullptr));
#endif // QT_NO_WHATSTHIS
        actionEnquoteNamesCheck->setText(QApplication::translate("MainWindow", "Drag && Drop Enquoted Names", nullptr));
#ifndef QT_NO_STATUSTIP
        actionEnquoteNamesCheck->setStatusTip(QApplication::translate("MainWindow", "Use escaped identifiers (e.g. \"Table1\") when dragging the objects and dropping them into the editor ", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionEnquoteNamesCheck->setWhatsThis(QApplication::translate("MainWindow", "Use escaped identifiers (e.g. \"Table1\") when dragging the objects and dropping them into the editor ", nullptr));
#endif // QT_NO_WHATSTHIS
        actionIntegrityCheck->setText(QApplication::translate("MainWindow", "&Integrity Check", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionIntegrityCheck->setWhatsThis(QApplication::translate("MainWindow", "Runs the integrity_check pragma over the opened database and returns the results in the Execute SQL tab. This pragma does an integrity check of the entire database.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionForeignKeyCheck->setText(QApplication::translate("MainWindow", "&Foreign-Key Check", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionForeignKeyCheck->setWhatsThis(QApplication::translate("MainWindow", "Runs the foreign_key_check pragma over the opened database and returns the results in the Execute SQL tab", nullptr));
#endif // QT_NO_WHATSTHIS
        actionQuickCheck->setText(QApplication::translate("MainWindow", "&Quick Integrity Check", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQuickCheck->setToolTip(QApplication::translate("MainWindow", "Run a quick integrity check over the open DB", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionQuickCheck->setWhatsThis(QApplication::translate("MainWindow", "Runs the quick_check pragma over the opened database and returns the results in the Execute SQL tab. This command does most of the checking of PRAGMA integrity_check but runs much faster.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionOptimize->setText(QApplication::translate("MainWindow", "&Optimize", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOptimize->setToolTip(QApplication::translate("MainWindow", "Attempt to optimize the database", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionOptimize->setWhatsThis(QApplication::translate("MainWindow", "Runs the optimize pragma over the opened database. This pragma might perform optimizations that will improve the performance of future queries.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionSqlPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlPrint->setToolTip(QApplication::translate("MainWindow", "Print text from current SQL editor tab", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSqlPrint->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlPrint->setWhatsThis(QApplication::translate("MainWindow", "Open a dialog for printing the text in the current SQL editor tab", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSqlPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionDbPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDbPrint->setToolTip(QApplication::translate("MainWindow", "Print the structure of the opened database", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDbPrint->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionDbPrint->setWhatsThis(QApplication::translate("MainWindow", "Open a dialog for printing the structure of the opened database", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionDbPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionSqlToggleComment->setText(QApplication::translate("MainWindow", "Un/comment block of SQL code", nullptr));
        actionSqlToggleComment->setIconText(QApplication::translate("MainWindow", "Un/comment block", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlToggleComment->setToolTip(QApplication::translate("MainWindow", "Comment or uncomment current line or selected block of code", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionSqlToggleComment->setWhatsThis(QApplication::translate("MainWindow", "Comment or uncomment the selected lines or the current line, when there is no selection. All the block is toggled according to the first line.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSqlToggleComment->setShortcut(QApplication::translate("MainWindow", "Ctrl+/", nullptr));
#endif // QT_NO_SHORTCUT
        actionSqlStop->setText(QApplication::translate("MainWindow", "Stop SQL execution", nullptr));
        actionSqlStop->setIconText(QApplication::translate("MainWindow", "Stop execution", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSqlStop->setToolTip(QApplication::translate("MainWindow", "Stop the currently running SQL script", nullptr));
#endif // QT_NO_TOOLTIP
        actionSaveProjectAs->setText(QApplication::translate("MainWindow", "&Save Project As...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveProjectAs->setToolTip(QApplication::translate("MainWindow", "Save the project in a file selected in a dialog", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveProjectAs->setStatusTip(QApplication::translate("MainWindow", "Save the project in a file selected in a dialog", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSaveProjectAs->setWhatsThis(QApplication::translate("MainWindow", "Save the project in a file selected in a dialog", nullptr));
#endif // QT_NO_WHATSTHIS
        actionSaveAll->setText(QApplication::translate("MainWindow", "Save A&ll", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveAll->setToolTip(QApplication::translate("MainWindow", "Save DB file, project file and opened SQL files", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveAll->setStatusTip(QApplication::translate("MainWindow", "Save DB file, project file and opened SQL files", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSaveAll->setWhatsThis(QApplication::translate("MainWindow", "Save DB file, project file and opened SQL files", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionSaveAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionPopupSchemaDockBrowseTable->setText(QApplication::translate("MainWindow", "Browse Table", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        structure->setAccessibleName(QApplication::translate("MainWindow", "Database Structure", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_WHATSTHIS
        dbTreeWidget->setWhatsThis(QApplication::translate("MainWindow", "This is the structure of the opened database.\n"
"You can drag SQL statements from an object row and drop them into other applications or into another instance of 'vSongBook'.\n"
"", nullptr));
#endif // QT_NO_WHATSTHIS
        mainTab->setTabText(mainTab->indexOf(structure), QApplication::translate("MainWindow", "Database Structure", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        browser->setAccessibleName(QApplication::translate("MainWindow", "Browse Data", nullptr));
#endif // QT_NO_ACCESSIBILITY
        mainTab->setTabText(mainTab->indexOf(browser), QApplication::translate("MainWindow", "Browse Data", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        pragmas->setAccessibleName(QApplication::translate("MainWindow", "Edit Pragmas", nullptr));
#endif // QT_NO_ACCESSIBILITY

        checkboxPragmaAutomaticIndex->setText(QString());
#ifndef QT_NO_TOOLTIP
        checkboxPragmaCaseSensitiveLike->setToolTip(QApplication::translate("MainWindow", "Warning: this pragma is not readable and this value has been inferred. Writing the pragma might overwrite a redefined LIKE provided by an SQLite extension.", nullptr));
#endif // QT_NO_TOOLTIP
        checkboxPragmaCaseSensitiveLike->setText(QString());
        checkboxPragmaCheckpointFullFsync->setText(QString());
        checkboxPragmaForeignKeys->setText(QString());
        checkboxPragmaFullFsync->setText(QString());
        checkboxPragmaIgnoreCheckConstraints->setText(QString());



        checkboxPragmaRecursiveTriggers->setText(QString());
        checkboxPragmaSecureDelete->setText(QString());


        mainTab->setTabText(mainTab->indexOf(pragmas), QApplication::translate("MainWindow", "Edit Pragmas", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        query->setAccessibleName(QApplication::translate("MainWindow", "Execute SQL", nullptr));
#endif // QT_NO_ACCESSIBILITY
        toolbarSql->setWindowTitle(QApplication::translate("MainWindow", "toolBar1", nullptr));
        mainTab->setTabText(mainTab->indexOf(query), QApplication::translate("MainWindow", "Execute SQL", nullptr));
        fileMenu->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuImport->setTitle(QApplication::translate("MainWindow", "&Import", nullptr));
        menuExport->setTitle(QApplication::translate("MainWindow", "&Export", nullptr));
        editMenu->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
        viewMenu->setTitle(QApplication::translate("MainWindow", "&View", nullptr));
        helpMenu->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "&Tools", nullptr));
        toolbarDB->setWindowTitle(QApplication::translate("MainWindow", "DB Toolbar", nullptr));
        dockEdit->setWindowTitle(QApplication::translate("MainWindow", "Edit Database &Cell", nullptr));
        dockLog->setWindowTitle(QApplication::translate("MainWindow", "SQL &Log", nullptr));
        labelLogSubmittedBy->setText(QApplication::translate("MainWindow", "Show S&QL submitted by", nullptr));
        comboLogSubmittedBy->setItemText(0, QApplication::translate("MainWindow", "User", nullptr));
        comboLogSubmittedBy->setItemText(1, QApplication::translate("MainWindow", "Application", nullptr));
        comboLogSubmittedBy->setItemText(2, QApplication::translate("MainWindow", "Error Log", nullptr));

#ifndef QT_NO_WHATSTHIS
        buttonLogClear->setWhatsThis(QApplication::translate("MainWindow", "This button clears the contents of the SQL logs", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonLogClear->setText(QApplication::translate("MainWindow", "&Clear", nullptr));
#ifndef QT_NO_WHATSTHIS
        stackLog->setWhatsThis(QApplication::translate("MainWindow", "This panel lets you examine a log of all SQL commands issued by the application or by yourself", nullptr));
#endif // QT_NO_WHATSTHIS
        dockPlot->setWindowTitle(QApplication::translate("MainWindow", "&Plot", nullptr));
        dockSchema->setWindowTitle(QApplication::translate("MainWindow", "DB Sche&ma", nullptr));
#ifndef QT_NO_WHATSTHIS
        treeSchemaDock->setWhatsThis(QApplication::translate("MainWindow", "This is the structure of the opened database.\n"
"You can drag multiple object names from the Name column and drop them into the SQL editor and you can adjust the properties of the dropped names using the context menu. This would help you in composing SQL statements.\n"
"You can drag SQL statements from the Schema column and drop them into the SQL editor or into other applications.\n"
"", nullptr));
#endif // QT_NO_WHATSTHIS
        dockRemote->setWindowTitle(QApplication::translate("MainWindow", "&Remote", nullptr));
        toolbarProject->setWindowTitle(QApplication::translate("MainWindow", "Project Toolbar", nullptr));
        toolbarExtraDB->setWindowTitle(QApplication::translate("MainWindow", "Extra DB toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        toolbarExtraDB->setToolTip(QApplication::translate("MainWindow", "Close the current database file", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
