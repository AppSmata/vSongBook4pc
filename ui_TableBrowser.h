/********************************************************************************
** Form generated from reading UI file 'TableBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEBROWSER_H
#define UI_TABLEBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ExtendedTableWidget.h"
#include "FilterLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_TableBrowser
{
public:
    QAction *actionShowRowidColumn;
    QAction *actionUnlockViewEditing;
    QAction *actionBrowseTableEditDisplayFormat;
    QAction *actionNewRecord;
    QAction *actionDeleteRecord;
    QAction *newRecordAction;
    QAction *insertValuesAction;
    QAction *actionFilteredTableExportCsv;
    QAction *actionFilterSaveAsView;
    QAction *actionSaveFilterAsPopup;
    QAction *actionHideColumns;
    QAction *actionShowAllColumns;
    QAction *actionSetTableEncoding;
    QAction *actionSetAllTablesEncoding;
    QAction *actionClearFilters;
    QAction *actionClearSorting;
    QAction *actionPrintTable;
    QAction *actionRefresh;
    QAction *actionFind;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actionRightAlign;
    QAction *actionLeftAlign;
    QAction *actionCenter;
    QAction *actionJustify;
    QAction *actionEditCondFormats;
    QAction *actionClearFormat;
    QAction *actionFontColor;
    QAction *actionBackgroundColor;
    QAction *actionToggleFormatToolbar;
    QAction *actionSelectColumn;
    QAction *actionReplace;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBrowseTable;
    QToolBar *browseToolbar;
    FilterLineEdit *editGlobalFilter;
    QSpacerItem *horizontalSpacer;
    QFrame *formatFrame;
    QHBoxLayout *horizontalLayoutFormat;
    QFontComboBox *fontComboBox;
    QSpinBox *fontSizeBox;
    QToolBar *formatToolbar;
    ExtendedTableWidget *dataTable;
    QFrame *frameFind;
    QVBoxLayout *vboxLayout;
    QWidget *widgetFind;
    QHBoxLayout *layoutFind;
    QLineEdit *editFindExpression;
    QToolButton *buttonFindPrevious;
    QToolButton *buttonFindNext;
    QCheckBox *checkFindCaseSensitive;
    QCheckBox *checkFindWholeCell;
    QCheckBox *checkFindRegEx;
    QSpacerItem *horizontalSpacer_1;
    QToolButton *buttonFindClose;
    QWidget *widgetReplace;
    QHBoxLayout *layoutReplace;
    QLineEdit *editReplaceExpression;
    QToolButton *buttonReplaceNext;
    QToolButton *buttonReplaceAll;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *buttonBegin;
    QToolButton *buttonPrevious;
    QLabel *labelRecordset;
    QToolButton *buttonNext;
    QToolButton *buttonEnd;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonGoto;
    QLineEdit *editGoto;

    void setupUi(QWidget *TableBrowser)
    {
        if (TableBrowser->objectName().isEmpty())
            TableBrowser->setObjectName(QString::fromUtf8("TableBrowser"));
        TableBrowser->resize(695, 400);
        actionShowRowidColumn = new QAction(TableBrowser);
        actionShowRowidColumn->setObjectName(QString::fromUtf8("actionShowRowidColumn"));
        actionShowRowidColumn->setCheckable(true);
        actionUnlockViewEditing = new QAction(TableBrowser);
        actionUnlockViewEditing->setObjectName(QString::fromUtf8("actionUnlockViewEditing"));
        actionUnlockViewEditing->setCheckable(true);
        actionBrowseTableEditDisplayFormat = new QAction(TableBrowser);
        actionBrowseTableEditDisplayFormat->setObjectName(QString::fromUtf8("actionBrowseTableEditDisplayFormat"));
        actionNewRecord = new QAction(TableBrowser);
        actionNewRecord->setObjectName(QString::fromUtf8("actionNewRecord"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add_record"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewRecord->setIcon(icon);
        actionDeleteRecord = new QAction(TableBrowser);
        actionDeleteRecord->setObjectName(QString::fromUtf8("actionDeleteRecord"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete_record"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteRecord->setIcon(icon1);
        newRecordAction = new QAction(TableBrowser);
        newRecordAction->setObjectName(QString::fromUtf8("newRecordAction"));
        newRecordAction->setIcon(icon);
        insertValuesAction = new QAction(TableBrowser);
        insertValuesAction->setObjectName(QString::fromUtf8("insertValuesAction"));
        actionFilteredTableExportCsv = new QAction(TableBrowser);
        actionFilteredTableExportCsv->setObjectName(QString::fromUtf8("actionFilteredTableExportCsv"));
        actionFilterSaveAsView = new QAction(TableBrowser);
        actionFilterSaveAsView->setObjectName(QString::fromUtf8("actionFilterSaveAsView"));
        actionSaveFilterAsPopup = new QAction(TableBrowser);
        actionSaveFilterAsPopup->setObjectName(QString::fromUtf8("actionSaveFilterAsPopup"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/save_table"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveFilterAsPopup->setIcon(icon2);
        actionHideColumns = new QAction(TableBrowser);
        actionHideColumns->setObjectName(QString::fromUtf8("actionHideColumns"));
        actionShowAllColumns = new QAction(TableBrowser);
        actionShowAllColumns->setObjectName(QString::fromUtf8("actionShowAllColumns"));
        actionSetTableEncoding = new QAction(TableBrowser);
        actionSetTableEncoding->setObjectName(QString::fromUtf8("actionSetTableEncoding"));
        actionSetAllTablesEncoding = new QAction(TableBrowser);
        actionSetAllTablesEncoding->setObjectName(QString::fromUtf8("actionSetAllTablesEncoding"));
        actionClearFilters = new QAction(TableBrowser);
        actionClearFilters->setObjectName(QString::fromUtf8("actionClearFilters"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/clear_filters"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearFilters->setIcon(icon3);
        actionClearSorting = new QAction(TableBrowser);
        actionClearSorting->setObjectName(QString::fromUtf8("actionClearSorting"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/clear_sorting"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearSorting->setIcon(icon4);
        actionPrintTable = new QAction(TableBrowser);
        actionPrintTable->setObjectName(QString::fromUtf8("actionPrintTable"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/print"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintTable->setIcon(icon5);
        actionPrintTable->setShortcutContext(Qt::WidgetShortcut);
        actionRefresh = new QAction(TableBrowser);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/refresh"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon6);
        actionRefresh->setShortcutContext(Qt::WidgetShortcut);
        actionFind = new QAction(TableBrowser);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/find"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon7);
        actionBold = new QAction(TableBrowser);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionBold->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/text_bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon8);
        actionItalic = new QAction(TableBrowser);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionItalic->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/text_italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon9);
        actionUnderline = new QAction(TableBrowser);
        actionUnderline->setObjectName(QString::fromUtf8("actionUnderline"));
        actionUnderline->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/text_underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderline->setIcon(icon10);
        actionRightAlign = new QAction(TableBrowser);
        actionRightAlign->setObjectName(QString::fromUtf8("actionRightAlign"));
        actionRightAlign->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/text_align_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRightAlign->setIcon(icon11);
        actionLeftAlign = new QAction(TableBrowser);
        actionLeftAlign->setObjectName(QString::fromUtf8("actionLeftAlign"));
        actionLeftAlign->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/text_align_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLeftAlign->setIcon(icon12);
        actionCenter = new QAction(TableBrowser);
        actionCenter->setObjectName(QString::fromUtf8("actionCenter"));
        actionCenter->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/text_align_center.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCenter->setIcon(icon13);
        actionJustify = new QAction(TableBrowser);
        actionJustify->setObjectName(QString::fromUtf8("actionJustify"));
        actionJustify->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/text_align_justify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionJustify->setIcon(icon14);
        actionEditCondFormats = new QAction(TableBrowser);
        actionEditCondFormats->setObjectName(QString::fromUtf8("actionEditCondFormats"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/edit_cond_formats"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditCondFormats->setIcon(icon15);
        actionClearFormat = new QAction(TableBrowser);
        actionClearFormat->setObjectName(QString::fromUtf8("actionClearFormat"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/clear_cond_formats"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearFormat->setIcon(icon16);
        actionFontColor = new QAction(TableBrowser);
        actionFontColor->setObjectName(QString::fromUtf8("actionFontColor"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/foreground_color"), QSize(), QIcon::Normal, QIcon::Off);
        actionFontColor->setIcon(icon17);
        actionBackgroundColor = new QAction(TableBrowser);
        actionBackgroundColor->setObjectName(QString::fromUtf8("actionBackgroundColor"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/background_color"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackgroundColor->setIcon(icon18);
        actionToggleFormatToolbar = new QAction(TableBrowser);
        actionToggleFormatToolbar->setObjectName(QString::fromUtf8("actionToggleFormatToolbar"));
        actionToggleFormatToolbar->setCheckable(true);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons/cond_formats"), QSize(), QIcon::Normal, QIcon::Off);
        actionToggleFormatToolbar->setIcon(icon19);
        actionSelectColumn = new QAction(TableBrowser);
        actionSelectColumn->setObjectName(QString::fromUtf8("actionSelectColumn"));
        actionReplace = new QAction(TableBrowser);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionReplace->setCheckable(true);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons/text_replace"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon20);
        verticalLayout_2 = new QVBoxLayout(TableBrowser);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, -1, 2, -1);
        label = new QLabel(TableBrowser);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBrowseTable = new QComboBox(TableBrowser);
        comboBrowseTable->setObjectName(QString::fromUtf8("comboBrowseTable"));
        comboBrowseTable->setMinimumSize(QSize(150, 0));
        comboBrowseTable->setMaxVisibleItems(30);
        comboBrowseTable->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(comboBrowseTable);

        browseToolbar = new QToolBar(TableBrowser);
        browseToolbar->setObjectName(QString::fromUtf8("browseToolbar"));
        browseToolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout->addWidget(browseToolbar);

        editGlobalFilter = new FilterLineEdit(TableBrowser);
        editGlobalFilter->setObjectName(QString::fromUtf8("editGlobalFilter"));

        horizontalLayout->addWidget(editGlobalFilter);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        formatFrame = new QFrame(TableBrowser);
        formatFrame->setObjectName(QString::fromUtf8("formatFrame"));
        horizontalLayoutFormat = new QHBoxLayout(formatFrame);
        horizontalLayoutFormat->setSpacing(5);
        horizontalLayoutFormat->setObjectName(QString::fromUtf8("horizontalLayoutFormat"));
        horizontalLayoutFormat->setContentsMargins(2, 0, 2, 0);
        fontComboBox = new QFontComboBox(formatFrame);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayoutFormat->addWidget(fontComboBox);

        fontSizeBox = new QSpinBox(formatFrame);
        fontSizeBox->setObjectName(QString::fromUtf8("fontSizeBox"));
        fontSizeBox->setMaximumSize(QSize(50, 16777215));
        fontSizeBox->setMinimum(1);

        horizontalLayoutFormat->addWidget(fontSizeBox);

        formatToolbar = new QToolBar(formatFrame);
        formatToolbar->setObjectName(QString::fromUtf8("formatToolbar"));
        formatToolbar->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayoutFormat->addWidget(formatToolbar);


        verticalLayout_2->addWidget(formatFrame);

        dataTable = new ExtendedTableWidget(TableBrowser);
        dataTable->setObjectName(QString::fromUtf8("dataTable"));
        dataTable->setAcceptDrops(true);
        dataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        dataTable->setDragDropMode(QAbstractItemView::DragDrop);
        dataTable->setDefaultDropAction(Qt::CopyAction);
        dataTable->setSelectionMode(QAbstractItemView::ContiguousSelection);

        verticalLayout_2->addWidget(dataTable);

        frameFind = new QFrame(TableBrowser);
        frameFind->setObjectName(QString::fromUtf8("frameFind"));
        frameFind->setMaximumSize(QSize(16777215, 62));
        frameFind->setFrameShape(QFrame::StyledPanel);
        frameFind->setFrameShadow(QFrame::Raised);
        vboxLayout = new QVBoxLayout(frameFind);
        vboxLayout->setSpacing(1);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(1, 1, 1, 1);
        widgetFind = new QWidget(frameFind);
        widgetFind->setObjectName(QString::fromUtf8("widgetFind"));
        layoutFind = new QHBoxLayout(widgetFind);
        layoutFind->setSpacing(3);
        layoutFind->setObjectName(QString::fromUtf8("layoutFind"));
        layoutFind->setContentsMargins(0, 0, 0, 0);
        editFindExpression = new QLineEdit(widgetFind);
        editFindExpression->setObjectName(QString::fromUtf8("editFindExpression"));
        editFindExpression->setContextMenuPolicy(Qt::DefaultContextMenu);
        editFindExpression->setClearButtonEnabled(true);

        layoutFind->addWidget(editFindExpression);

        buttonFindPrevious = new QToolButton(widgetFind);
        buttonFindPrevious->setObjectName(QString::fromUtf8("buttonFindPrevious"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons/up"), QSize(), QIcon::Normal, QIcon::Off);
        buttonFindPrevious->setIcon(icon21);

        layoutFind->addWidget(buttonFindPrevious);

        buttonFindNext = new QToolButton(widgetFind);
        buttonFindNext->setObjectName(QString::fromUtf8("buttonFindNext"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons/down"), QSize(), QIcon::Normal, QIcon::Off);
        buttonFindNext->setIcon(icon22);

        layoutFind->addWidget(buttonFindNext);

        checkFindCaseSensitive = new QCheckBox(widgetFind);
        checkFindCaseSensitive->setObjectName(QString::fromUtf8("checkFindCaseSensitive"));

        layoutFind->addWidget(checkFindCaseSensitive);

        checkFindWholeCell = new QCheckBox(widgetFind);
        checkFindWholeCell->setObjectName(QString::fromUtf8("checkFindWholeCell"));

        layoutFind->addWidget(checkFindWholeCell);

        checkFindRegEx = new QCheckBox(widgetFind);
        checkFindRegEx->setObjectName(QString::fromUtf8("checkFindRegEx"));

        layoutFind->addWidget(checkFindRegEx);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutFind->addItem(horizontalSpacer_1);

        buttonFindClose = new QToolButton(widgetFind);
        buttonFindClose->setObjectName(QString::fromUtf8("buttonFindClose"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons/close"), QSize(), QIcon::Normal, QIcon::Off);
        buttonFindClose->setIcon(icon23);
        buttonFindClose->setAutoRaise(true);

        layoutFind->addWidget(buttonFindClose);


        vboxLayout->addWidget(widgetFind);

        widgetReplace = new QWidget(frameFind);
        widgetReplace->setObjectName(QString::fromUtf8("widgetReplace"));
        layoutReplace = new QHBoxLayout(widgetReplace);
        layoutReplace->setSpacing(3);
        layoutReplace->setObjectName(QString::fromUtf8("layoutReplace"));
        layoutReplace->setContentsMargins(0, 0, 0, 0);
        editReplaceExpression = new QLineEdit(widgetReplace);
        editReplaceExpression->setObjectName(QString::fromUtf8("editReplaceExpression"));
        editReplaceExpression->setContextMenuPolicy(Qt::DefaultContextMenu);
        editReplaceExpression->setClearButtonEnabled(true);

        layoutReplace->addWidget(editReplaceExpression);

        buttonReplaceNext = new QToolButton(widgetReplace);
        buttonReplaceNext->setObjectName(QString::fromUtf8("buttonReplaceNext"));

        layoutReplace->addWidget(buttonReplaceNext);

        buttonReplaceAll = new QToolButton(widgetReplace);
        buttonReplaceAll->setObjectName(QString::fromUtf8("buttonReplaceAll"));

        layoutReplace->addWidget(buttonReplaceAll);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutReplace->addItem(horizontalSpacer_3);


        vboxLayout->addWidget(widgetReplace);


        verticalLayout_2->addWidget(frameFind);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        buttonBegin = new QToolButton(TableBrowser);
        buttonBegin->setObjectName(QString::fromUtf8("buttonBegin"));
        buttonBegin->setEnabled(false);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons/resultset_first.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonBegin->setIcon(icon24);

        horizontalLayout_2->addWidget(buttonBegin);

        buttonPrevious = new QToolButton(TableBrowser);
        buttonPrevious->setObjectName(QString::fromUtf8("buttonPrevious"));
        buttonPrevious->setEnabled(false);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/icons/resultset_previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPrevious->setIcon(icon25);

        horizontalLayout_2->addWidget(buttonPrevious);

        labelRecordset = new QLabel(TableBrowser);
        labelRecordset->setObjectName(QString::fromUtf8("labelRecordset"));

        horizontalLayout_2->addWidget(labelRecordset);

        buttonNext = new QToolButton(TableBrowser);
        buttonNext->setObjectName(QString::fromUtf8("buttonNext"));
        buttonNext->setEnabled(false);
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/icons/run"), QSize(), QIcon::Normal, QIcon::Off);
        buttonNext->setIcon(icon26);

        horizontalLayout_2->addWidget(buttonNext);

        buttonEnd = new QToolButton(TableBrowser);
        buttonEnd->setObjectName(QString::fromUtf8("buttonEnd"));
        buttonEnd->setEnabled(false);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/icons/run_line"), QSize(), QIcon::Normal, QIcon::Off);
        buttonEnd->setIcon(icon27);

        horizontalLayout_2->addWidget(buttonEnd);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        buttonGoto = new QPushButton(TableBrowser);
        buttonGoto->setObjectName(QString::fromUtf8("buttonGoto"));

        horizontalLayout_2->addWidget(buttonGoto);

        editGoto = new QLineEdit(TableBrowser);
        editGoto->setObjectName(QString::fromUtf8("editGoto"));

        horizontalLayout_2->addWidget(editGoto);


        verticalLayout_2->addLayout(horizontalLayout_2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(comboBrowseTable);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBrowseTable, editGlobalFilter);
        QWidget::setTabOrder(editGlobalFilter, fontComboBox);
        QWidget::setTabOrder(fontComboBox, fontSizeBox);
        QWidget::setTabOrder(fontSizeBox, dataTable);
        QWidget::setTabOrder(dataTable, editFindExpression);
        QWidget::setTabOrder(editFindExpression, editReplaceExpression);
        QWidget::setTabOrder(editReplaceExpression, buttonFindPrevious);
        QWidget::setTabOrder(buttonFindPrevious, buttonFindNext);
        QWidget::setTabOrder(buttonFindNext, checkFindCaseSensitive);
        QWidget::setTabOrder(checkFindCaseSensitive, checkFindWholeCell);
        QWidget::setTabOrder(checkFindWholeCell, checkFindRegEx);
        QWidget::setTabOrder(checkFindRegEx, buttonFindClose);
        QWidget::setTabOrder(buttonFindClose, buttonReplaceNext);
        QWidget::setTabOrder(buttonReplaceNext, buttonReplaceAll);
        QWidget::setTabOrder(buttonReplaceAll, buttonBegin);
        QWidget::setTabOrder(buttonBegin, buttonPrevious);
        QWidget::setTabOrder(buttonPrevious, buttonNext);
        QWidget::setTabOrder(buttonNext, buttonEnd);
        QWidget::setTabOrder(buttonEnd, buttonGoto);
        QWidget::setTabOrder(buttonGoto, editGoto);

        browseToolbar->addAction(actionRefresh);
        browseToolbar->addAction(actionClearFilters);
        browseToolbar->addAction(actionClearSorting);
        browseToolbar->addSeparator();
        browseToolbar->addAction(actionSaveFilterAsPopup);
        browseToolbar->addAction(actionPrintTable);
        browseToolbar->addSeparator();
        browseToolbar->addAction(actionNewRecord);
        browseToolbar->addAction(actionDeleteRecord);
        browseToolbar->addSeparator();
        browseToolbar->addAction(actionToggleFormatToolbar);
        browseToolbar->addAction(actionFind);
        browseToolbar->addAction(actionReplace);
        formatToolbar->addAction(actionBold);
        formatToolbar->addAction(actionItalic);
        formatToolbar->addAction(actionUnderline);
        formatToolbar->addSeparator();
        formatToolbar->addAction(actionFontColor);
        formatToolbar->addAction(actionBackgroundColor);
        formatToolbar->addSeparator();
        formatToolbar->addAction(actionLeftAlign);
        formatToolbar->addAction(actionCenter);
        formatToolbar->addAction(actionRightAlign);
        formatToolbar->addAction(actionJustify);
        formatToolbar->addSeparator();
        formatToolbar->addAction(actionEditCondFormats);
        formatToolbar->addAction(actionClearFormat);

        retranslateUi(TableBrowser);
        QObject::connect(comboBrowseTable, SIGNAL(activated(QString)), TableBrowser, SLOT(updateTable()));
        QObject::connect(buttonPrevious, SIGNAL(clicked()), TableBrowser, SLOT(navigatePrevious()));
        QObject::connect(buttonNext, SIGNAL(clicked()), TableBrowser, SLOT(navigateNext()));
        QObject::connect(buttonGoto, SIGNAL(clicked()), TableBrowser, SLOT(navigateGoto()));
        QObject::connect(editGoto, SIGNAL(returnPressed()), TableBrowser, SLOT(navigateGoto()));
        QObject::connect(buttonEnd, SIGNAL(clicked()), TableBrowser, SLOT(navigateEnd()));
        QObject::connect(buttonBegin, SIGNAL(clicked()), TableBrowser, SLOT(navigateBegin()));
        QObject::connect(dataTable, SIGNAL(foreignKeyClicked(sqlb::ObjectIdentifier,std::string,QByteArray)), TableBrowser, SLOT(jumpToRow(sqlb::ObjectIdentifier,std::string,QByteArray)));
        QObject::connect(actionShowRowidColumn, SIGNAL(triggered(bool)), TableBrowser, SLOT(showRowidColumn(bool)));
        QObject::connect(actionUnlockViewEditing, SIGNAL(toggled(bool)), TableBrowser, SLOT(unlockViewEditing(bool)));
        QObject::connect(actionBrowseTableEditDisplayFormat, SIGNAL(triggered()), TableBrowser, SLOT(editDisplayFormat()));
        QObject::connect(actionNewRecord, SIGNAL(triggered()), TableBrowser, SLOT(addRecord()));
        QObject::connect(actionDeleteRecord, SIGNAL(triggered()), TableBrowser, SLOT(deleteRecord()));
        QObject::connect(newRecordAction, SIGNAL(triggered()), TableBrowser, SLOT(addRecord()));
        QObject::connect(insertValuesAction, SIGNAL(triggered()), TableBrowser, SLOT(insertValues()));
        QObject::connect(actionFilteredTableExportCsv, SIGNAL(triggered()), TableBrowser, SLOT(exportFilteredTable()));
        QObject::connect(actionFilterSaveAsView, SIGNAL(triggered()), TableBrowser, SLOT(saveFilterAsView()));
        QObject::connect(actionSetTableEncoding, SIGNAL(triggered()), TableBrowser, SLOT(setTableEncoding()));
        QObject::connect(actionSetAllTablesEncoding, SIGNAL(triggered()), TableBrowser, SLOT(setDefaultTableEncoding()));
        QObject::connect(actionHideColumns, SIGNAL(triggered()), TableBrowser, SLOT(hideColumns()));
        QObject::connect(actionRefresh, SIGNAL(triggered()), TableBrowser, SLOT(updateTable()));
        QObject::connect(actionPrintTable, SIGNAL(triggered()), dataTable, SLOT(openPrintDialog()));

        QMetaObject::connectSlotsByName(TableBrowser);
    } // setupUi

    void retranslateUi(QWidget *TableBrowser)
    {
        TableBrowser->setWindowTitle(QApplication::translate("TableBrowser", "Browse Data", nullptr));
        actionShowRowidColumn->setText(QApplication::translate("TableBrowser", "Show rowid column", nullptr));
#ifndef QT_NO_TOOLTIP
        actionShowRowidColumn->setToolTip(QApplication::translate("TableBrowser", "Toggle the visibility of the rowid column", nullptr));
#endif // QT_NO_TOOLTIP
        actionUnlockViewEditing->setText(QApplication::translate("TableBrowser", "Unlock view editing", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUnlockViewEditing->setToolTip(QApplication::translate("TableBrowser", "This unlocks the current view for editing. However, you will need appropriate triggers for editing.", nullptr));
#endif // QT_NO_TOOLTIP
        actionBrowseTableEditDisplayFormat->setText(QApplication::translate("TableBrowser", "Edit display format", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBrowseTableEditDisplayFormat->setToolTip(QApplication::translate("TableBrowser", "Edit the display format of the data in this column", nullptr));
#endif // QT_NO_TOOLTIP
        actionNewRecord->setText(QApplication::translate("TableBrowser", "New Record", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNewRecord->setToolTip(QApplication::translate("TableBrowser", "Insert a new record in the current table", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNewRecord->setStatusTip(QApplication::translate("TableBrowser", "Insert a new record in the current table", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionNewRecord->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>This button creates a new record in the database. Hold the mouse button to open a pop-up menu of different options:</p><ul><li><span style=\" font-weight:600;\">New Record</span>: insert a new record with default values in the database.</li><li><span style=\" font-weight:600;\">Insert Values...</span>: open a dialog for entering values before they are inserted in the database. This allows to enter values acomplishing the different constraints. This dialog is also open if the <span style=\" font-weight:600;\">New Record</span> option fails due to these constraints.</li></ul></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        actionDeleteRecord->setText(QApplication::translate("TableBrowser", "Delete Record", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDeleteRecord->setToolTip(QApplication::translate("TableBrowser", "Delete the current record", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDeleteRecord->setStatusTip(QApplication::translate("TableBrowser", "This button deletes the record or records currently selected in the table", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionDeleteRecord->setWhatsThis(QApplication::translate("TableBrowser", "This button deletes the record or records currently selected in the table", nullptr));
#endif // QT_NO_WHATSTHIS
        newRecordAction->setText(QApplication::translate("TableBrowser", "New Record", nullptr));
#ifndef QT_NO_TOOLTIP
        newRecordAction->setToolTip(QApplication::translate("TableBrowser", "Insert new record using default values in browsed table", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        newRecordAction->setStatusTip(QApplication::translate("TableBrowser", "Insert new record using default values in browsed table", nullptr));
#endif // QT_NO_STATUSTIP
        insertValuesAction->setText(QApplication::translate("TableBrowser", "Insert Values...", nullptr));
#ifndef QT_NO_TOOLTIP
        insertValuesAction->setToolTip(QApplication::translate("TableBrowser", "Open a dialog for inserting values in a new record", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        insertValuesAction->setStatusTip(QApplication::translate("TableBrowser", "Open a dialog for inserting values in a new record", nullptr));
#endif // QT_NO_STATUSTIP
        actionFilteredTableExportCsv->setText(QApplication::translate("TableBrowser", "Export to &CSV", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFilteredTableExportCsv->setToolTip(QApplication::translate("TableBrowser", "Export the filtered data to CSV", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionFilteredTableExportCsv->setStatusTip(QApplication::translate("TableBrowser", "Export the filtered data to CSV", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionFilteredTableExportCsv->setWhatsThis(QApplication::translate("TableBrowser", "This button exports the data of the browsed table as currently displayed (after filters, display formats and order column) as a CSV file.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionFilterSaveAsView->setText(QApplication::translate("TableBrowser", "Save as &view", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFilterSaveAsView->setToolTip(QApplication::translate("TableBrowser", "Save the current filter, sort column and display formats as a view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionFilterSaveAsView->setStatusTip(QApplication::translate("TableBrowser", "Save the current filter, sort column and display formats as a view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionFilterSaveAsView->setWhatsThis(QApplication::translate("TableBrowser", "This button saves the current setting of the browsed table (filters, display formats and order column) as an SQL view that you can later browse or use in SQL statements.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionSaveFilterAsPopup->setText(QApplication::translate("TableBrowser", "Save Table As...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveFilterAsPopup->setToolTip(QApplication::translate("TableBrowser", "Save the table as currently displayed", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveFilterAsPopup->setStatusTip(QApplication::translate("TableBrowser", "Save the table as currently displayed", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionSaveFilterAsPopup->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>This popup menu provides the following options applying to the currently browsed and filtered table:</p><ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Export to CSV: this option exports the data of the browsed table as currently displayed (after filters, display formats and order column) to a CSV file.</li><li style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Save as view: this option saves the current setting of the browsed table (filters, display formats and order column) as an SQL view that you can later browse or use in SQL statements.</li></ul></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        actionHideColumns->setText(QApplication::translate("TableBrowser", "Hide column(s)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionHideColumns->setToolTip(QApplication::translate("TableBrowser", "Hide selected column(s)", nullptr));
#endif // QT_NO_TOOLTIP
        actionShowAllColumns->setText(QApplication::translate("TableBrowser", "Show all columns", nullptr));
#ifndef QT_NO_TOOLTIP
        actionShowAllColumns->setToolTip(QApplication::translate("TableBrowser", "Show all columns that were hidden", nullptr));
#endif // QT_NO_TOOLTIP
        actionSetTableEncoding->setText(QApplication::translate("TableBrowser", "Set encoding", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetTableEncoding->setToolTip(QApplication::translate("TableBrowser", "Change the encoding of the text in the table cells", nullptr));
#endif // QT_NO_TOOLTIP
        actionSetAllTablesEncoding->setText(QApplication::translate("TableBrowser", "Set encoding for all tables", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetAllTablesEncoding->setToolTip(QApplication::translate("TableBrowser", "Change the default encoding assumed for all tables in the database", nullptr));
#endif // QT_NO_TOOLTIP
        actionClearFilters->setText(QApplication::translate("TableBrowser", "Clear Filters", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClearFilters->setToolTip(QApplication::translate("TableBrowser", "Clear all filters", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearFilters->setStatusTip(QApplication::translate("TableBrowser", "This button clears all the filters set in the header input fields for the currently browsed table.", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionClearFilters->setWhatsThis(QApplication::translate("TableBrowser", "This button clears all the filters set in the header input fields for the currently browsed table.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionClearSorting->setText(QApplication::translate("TableBrowser", "Clear Sorting", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClearSorting->setToolTip(QApplication::translate("TableBrowser", "Reset the order of rows to the default", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearSorting->setStatusTip(QApplication::translate("TableBrowser", "This button clears the sorting columns specified for the currently browsed table and returns to the default order.", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionClearSorting->setWhatsThis(QApplication::translate("TableBrowser", "This button clears the sorting columns specified for the currently browsed table and returns to the default order.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionPrintTable->setText(QApplication::translate("TableBrowser", "Print", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPrintTable->setToolTip(QApplication::translate("TableBrowser", "Print currently browsed table data", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPrintTable->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionPrintTable->setWhatsThis(QApplication::translate("TableBrowser", "Print currently browsed table data. Print selection if more than one cell is selected.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionPrintTable->setShortcut(QApplication::translate("TableBrowser", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionRefresh->setText(QApplication::translate("TableBrowser", "Refresh", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRefresh->setToolTip(QApplication::translate("TableBrowser", "Refresh the data in the selected table", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRefresh->setStatusTip(QApplication::translate("TableBrowser", "This button refreshes the data in the currently selected table.", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionRefresh->setShortcut(QApplication::translate("TableBrowser", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("TableBrowser", "Find in cells", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFind->setToolTip(QApplication::translate("TableBrowser", "Open the find tool bar which allows you to search for values in the table view below.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("TableBrowser", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionBold->setText(QApplication::translate("TableBrowser", "Bold", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBold->setToolTip(QApplication::translate("TableBrowser", "Bold", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionBold->setShortcut(QApplication::translate("TableBrowser", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        actionItalic->setText(QApplication::translate("TableBrowser", "Italic", nullptr));
#ifndef QT_NO_TOOLTIP
        actionItalic->setToolTip(QApplication::translate("TableBrowser", "Italic", nullptr));
#endif // QT_NO_TOOLTIP
        actionUnderline->setText(QApplication::translate("TableBrowser", "Underline", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUnderline->setToolTip(QApplication::translate("TableBrowser", "Underline", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionUnderline->setShortcut(QApplication::translate("TableBrowser", "Ctrl+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionRightAlign->setText(QApplication::translate("TableBrowser", "Align Right", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRightAlign->setToolTip(QApplication::translate("TableBrowser", "Align Right", nullptr));
#endif // QT_NO_TOOLTIP
        actionLeftAlign->setText(QApplication::translate("TableBrowser", "Align Left", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLeftAlign->setToolTip(QApplication::translate("TableBrowser", "Align Left", nullptr));
#endif // QT_NO_TOOLTIP
        actionCenter->setText(QApplication::translate("TableBrowser", "Center Horizontally", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCenter->setToolTip(QApplication::translate("TableBrowser", "Center Horizontally", nullptr));
#endif // QT_NO_TOOLTIP
        actionJustify->setText(QApplication::translate("TableBrowser", "Justify", nullptr));
#ifndef QT_NO_TOOLTIP
        actionJustify->setToolTip(QApplication::translate("TableBrowser", "Justify", nullptr));
#endif // QT_NO_TOOLTIP
        actionEditCondFormats->setText(QApplication::translate("TableBrowser", "Edit Conditional Formats...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEditCondFormats->setToolTip(QApplication::translate("TableBrowser", "Edit Conditional Formats...", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionEditCondFormats->setStatusTip(QApplication::translate("TableBrowser", "Edit conditional formats for the current column", nullptr));
#endif // QT_NO_STATUSTIP
        actionClearFormat->setText(QApplication::translate("TableBrowser", "Clear Format", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClearFormat->setToolTip(QApplication::translate("TableBrowser", "Clear All Formats", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearFormat->setStatusTip(QApplication::translate("TableBrowser", "Clear all cell formatting from selected cells and all conditional formats from selected columns", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionClearFormat->setWhatsThis(QApplication::translate("TableBrowser", "Clear all cell formatting from selected cells and all conditional formats from selected columns", nullptr));
#endif // QT_NO_WHATSTHIS
        actionFontColor->setText(QApplication::translate("TableBrowser", "Font Color", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFontColor->setToolTip(QApplication::translate("TableBrowser", "Font Color", nullptr));
#endif // QT_NO_TOOLTIP
        actionBackgroundColor->setText(QApplication::translate("TableBrowser", "Background Color", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBackgroundColor->setToolTip(QApplication::translate("TableBrowser", "Background Color", nullptr));
#endif // QT_NO_TOOLTIP
        actionToggleFormatToolbar->setText(QApplication::translate("TableBrowser", "Toggle Format Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToggleFormatToolbar->setToolTip(QApplication::translate("TableBrowser", "Show/hide format toolbar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionToggleFormatToolbar->setStatusTip(QApplication::translate("TableBrowser", "This button shows or hides the formatting toolbar of the Data Browser", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionToggleFormatToolbar->setWhatsThis(QApplication::translate("TableBrowser", "This button shows or hides the formatting toolbar of the Data Browser", nullptr));
#endif // QT_NO_WHATSTHIS
        actionSelectColumn->setText(QApplication::translate("TableBrowser", "Select column", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSelectColumn->setShortcut(QApplication::translate("TableBrowser", "Ctrl+Space", nullptr));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("TableBrowser", "Replace", nullptr));
#ifndef QT_NO_TOOLTIP
        actionReplace->setToolTip(QApplication::translate("TableBrowser", "Replace text in cells", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("TableBrowser", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("TableBrowser", "&Table:", nullptr));
#ifndef QT_NO_TOOLTIP
        comboBrowseTable->setToolTip(QApplication::translate("TableBrowser", "Select a table to browse data", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        comboBrowseTable->setWhatsThis(QApplication::translate("TableBrowser", "Use this list to select a table to be displayed in the database view", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        dataTable->setWhatsThis(QApplication::translate("TableBrowser", "This is the database table view. You can do the following actions:\n"
" - Start writing for editing inline the value.\n"
" - Double-click any record to edit its contents in the cell editor window.\n"
" - Alt+Del for deleting the cell content to NULL.\n"
" - Ctrl+\" for duplicating the current record.\n"
" - Ctrl+' for copying the value from the cell above.\n"
" - Standard selection and copy/paste operations.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        editFindExpression->setWhatsThis(QApplication::translate("TableBrowser", "Text pattern to find considering the checks in this frame", nullptr));
#endif // QT_NO_WHATSTHIS
        editFindExpression->setPlaceholderText(QApplication::translate("TableBrowser", "Find in table", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonFindPrevious->setToolTip(QApplication::translate("TableBrowser", "Find previous match [Shift+F3]", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonFindPrevious->setWhatsThis(QApplication::translate("TableBrowser", "Find previous match with mapping", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        buttonFindPrevious->setShortcut(QApplication::translate("TableBrowser", "Shift+F3", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        buttonFindNext->setToolTip(QApplication::translate("TableBrowser", "Find next match [Enter, F3]", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonFindNext->setWhatsThis(QApplication::translate("TableBrowser", "Find next match with wrapping", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        buttonFindNext->setShortcut(QApplication::translate("TableBrowser", "F3", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_WHATSTHIS
        checkFindCaseSensitive->setWhatsThis(QApplication::translate("TableBrowser", "The found pattern must match in letter case", nullptr));
#endif // QT_NO_WHATSTHIS
        checkFindCaseSensitive->setText(QApplication::translate("TableBrowser", "Case Sensitive", nullptr));
#ifndef QT_NO_WHATSTHIS
        checkFindWholeCell->setWhatsThis(QApplication::translate("TableBrowser", "The found pattern must be a whole word", nullptr));
#endif // QT_NO_WHATSTHIS
        checkFindWholeCell->setText(QApplication::translate("TableBrowser", "Whole Cell", nullptr));
#ifndef QT_NO_TOOLTIP
        checkFindRegEx->setToolTip(QApplication::translate("TableBrowser", "Interpret search pattern as a regular expression", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        checkFindRegEx->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>When checked, the pattern to find is interpreted as a UNIX regular expression. See <a href=\"https://en.wikibooks.org/wiki/Regular_Expressions\">Regular Expression in Wikibooks</a>.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        checkFindRegEx->setText(QApplication::translate("TableBrowser", "Regular Expression", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonFindClose->setToolTip(QApplication::translate("TableBrowser", "Close Find Bar", nullptr));
#endif // QT_NO_TOOLTIP
        buttonFindClose->setText(QApplication::translate("TableBrowser", "Close Find Bar", nullptr));
#ifndef QT_NO_WHATSTHIS
        editReplaceExpression->setWhatsThis(QApplication::translate("TableBrowser", "Text to replace with", nullptr));
#endif // QT_NO_WHATSTHIS
        editReplaceExpression->setPlaceholderText(QApplication::translate("TableBrowser", "Replace with", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonReplaceNext->setToolTip(QApplication::translate("TableBrowser", "Replace next match", nullptr));
#endif // QT_NO_TOOLTIP
        buttonReplaceNext->setText(QApplication::translate("TableBrowser", "Replace", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonReplaceAll->setToolTip(QApplication::translate("TableBrowser", "Replace all matches", nullptr));
#endif // QT_NO_TOOLTIP
        buttonReplaceAll->setText(QApplication::translate("TableBrowser", "Replace all", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonBegin->setToolTip(QApplication::translate("TableBrowser", "<html><head/><body><p>Scroll to the beginning</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonBegin->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>Clicking this button navigates to the beginning in the table view above.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonBegin->setText(QApplication::translate("TableBrowser", "|<", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonPrevious->setToolTip(QApplication::translate("TableBrowser", "Scroll one page upwards", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonPrevious->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>Clicking this button navigates one page of records upwards in the table view above.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonPrevious->setText(QApplication::translate("TableBrowser", "<", nullptr));
        labelRecordset->setText(QApplication::translate("TableBrowser", "0 - 0 of 0", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonNext->setToolTip(QApplication::translate("TableBrowser", "Scroll one page downwards", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonNext->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>Clicking this button navigates one page of records downwards in the table view above.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonNext->setText(QApplication::translate("TableBrowser", ">", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonEnd->setToolTip(QApplication::translate("TableBrowser", "Scroll to the end", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonEnd->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Clicking this button navigates up to the end in the table view above.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonEnd->setText(QApplication::translate("TableBrowser", ">|", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonGoto->setToolTip(QApplication::translate("TableBrowser", "<html><head/><body><p>Click here to jump to the specified record</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonGoto->setWhatsThis(QApplication::translate("TableBrowser", "<html><head/><body><p>This button is used to navigate to the record number specified in the Go to area.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonGoto->setText(QApplication::translate("TableBrowser", "Go to:", nullptr));
#ifndef QT_NO_TOOLTIP
        editGoto->setToolTip(QApplication::translate("TableBrowser", "Enter record number to browse", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        editGoto->setWhatsThis(QApplication::translate("TableBrowser", "Type a record number in this area and click the Go to: button to display the record in the database view", nullptr));
#endif // QT_NO_WHATSTHIS
        editGoto->setText(QApplication::translate("TableBrowser", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableBrowser: public Ui_TableBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEBROWSER_H
