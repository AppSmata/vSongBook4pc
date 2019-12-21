/********************************************************************************
** Form generated from reading UI file 'SqlExecutionArea.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLEXECUTIONAREA_H
#define UI_SQLEXECUTIONAREA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ExtendedTableWidget.h"
#include "sqltextedit.h"

QT_BEGIN_NAMESPACE

class Ui_SqlExecutionArea
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    SqlTextEdit *editEditor;
    QFrame *findFrame;
    QGridLayout *gridLayout;
    QToolButton *previousToolButton;
    QSpacerItem *spacerItem;
    QCheckBox *wholeWordsCheckBox;
    QLineEdit *findLineEdit;
    QCheckBox *caseCheckBox;
    QToolButton *nextToolButton;
    QCheckBox *regexpCheckBox;
    QSpacerItem *horizontalSpacer;
    QToolButton *hideFindButton;
    QSplitter *splitter_2;
    ExtendedTableWidget *tableResult;
    QTextEdit *editErrors;

    void setupUi(QWidget *SqlExecutionArea)
    {
        if (SqlExecutionArea->objectName().isEmpty())
            SqlExecutionArea->setObjectName(QString::fromUtf8("SqlExecutionArea"));
        SqlExecutionArea->resize(579, 482);
        horizontalLayout_2 = new QHBoxLayout(SqlExecutionArea);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        splitter = new QSplitter(SqlExecutionArea);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editEditor = new SqlTextEdit(widget);
        editEditor->setObjectName(QString::fromUtf8("editEditor"));

        verticalLayout->addWidget(editEditor);

        findFrame = new QFrame(widget);
        findFrame->setObjectName(QString::fromUtf8("findFrame"));
        findFrame->setMaximumSize(QSize(16777215, 31));
        findFrame->setFrameShape(QFrame::StyledPanel);
        findFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(findFrame);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        previousToolButton = new QToolButton(findFrame);
        previousToolButton->setObjectName(QString::fromUtf8("previousToolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/up"), QSize(), QIcon::Normal, QIcon::Off);
        previousToolButton->setIcon(icon);

        gridLayout->addWidget(previousToolButton, 0, 1, 1, 1);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 8, 1, 1);

        wholeWordsCheckBox = new QCheckBox(findFrame);
        wholeWordsCheckBox->setObjectName(QString::fromUtf8("wholeWordsCheckBox"));

        gridLayout->addWidget(wholeWordsCheckBox, 0, 4, 1, 1);

        findLineEdit = new QLineEdit(findFrame);
        findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
        findLineEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        findLineEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(findLineEdit, 0, 0, 1, 1);

        caseCheckBox = new QCheckBox(findFrame);
        caseCheckBox->setObjectName(QString::fromUtf8("caseCheckBox"));

        gridLayout->addWidget(caseCheckBox, 0, 3, 1, 1);

        nextToolButton = new QToolButton(findFrame);
        nextToolButton->setObjectName(QString::fromUtf8("nextToolButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/down"), QSize(), QIcon::Normal, QIcon::Off);
        nextToolButton->setIcon(icon1);

        gridLayout->addWidget(nextToolButton, 0, 2, 1, 1);

        regexpCheckBox = new QCheckBox(findFrame);
        regexpCheckBox->setObjectName(QString::fromUtf8("regexpCheckBox"));

        gridLayout->addWidget(regexpCheckBox, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        hideFindButton = new QToolButton(findFrame);
        hideFindButton->setObjectName(QString::fromUtf8("hideFindButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/close"), QSize(), QIcon::Normal, QIcon::Off);
        hideFindButton->setIcon(icon2);
        hideFindButton->setAutoRaise(true);

        gridLayout->addWidget(hideFindButton, 0, 9, 1, 1);


        verticalLayout->addWidget(findFrame);

        splitter->addWidget(widget);
        splitter_2 = new QSplitter(splitter);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_2->setChildrenCollapsible(false);
        tableResult = new ExtendedTableWidget(splitter_2);
        tableResult->setObjectName(QString::fromUtf8("tableResult"));
        tableResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
        splitter_2->addWidget(tableResult);
        editErrors = new QTextEdit(splitter_2);
        editErrors->setObjectName(QString::fromUtf8("editErrors"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(120);
        sizePolicy.setHeightForWidth(editErrors->sizePolicy().hasHeightForWidth());
        editErrors->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(8);
        editErrors->setFont(font);
        editErrors->setAcceptDrops(false);
        editErrors->setFrameShape(QFrame::StyledPanel);
        editErrors->setFrameShadow(QFrame::Sunken);
        editErrors->setTabChangesFocus(true);
        editErrors->setUndoRedoEnabled(false);
        editErrors->setReadOnly(true);
        splitter_2->addWidget(editErrors);
        splitter->addWidget(splitter_2);

        horizontalLayout_2->addWidget(splitter);

        QWidget::setTabOrder(editEditor, findLineEdit);
        QWidget::setTabOrder(findLineEdit, tableResult);
        QWidget::setTabOrder(tableResult, editErrors);
        QWidget::setTabOrder(editErrors, previousToolButton);
        QWidget::setTabOrder(previousToolButton, nextToolButton);
        QWidget::setTabOrder(nextToolButton, caseCheckBox);
        QWidget::setTabOrder(caseCheckBox, wholeWordsCheckBox);

        retranslateUi(SqlExecutionArea);

        QMetaObject::connectSlotsByName(SqlExecutionArea);
    } // setupUi

    void retranslateUi(QWidget *SqlExecutionArea)
    {
        SqlExecutionArea->setWindowTitle(QApplication::translate("SqlExecutionArea", "Form", nullptr));
#ifndef QT_NO_TOOLTIP
        previousToolButton->setToolTip(QApplication::translate("SqlExecutionArea", "Find previous match [Shift+F3]", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        previousToolButton->setWhatsThis(QApplication::translate("SqlExecutionArea", "Find previous match with mapping", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        previousToolButton->setShortcut(QApplication::translate("SqlExecutionArea", "Shift+F3", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_WHATSTHIS
        wholeWordsCheckBox->setWhatsThis(QApplication::translate("SqlExecutionArea", "The found pattern must be a whole word", nullptr));
#endif // QT_NO_WHATSTHIS
        wholeWordsCheckBox->setText(QApplication::translate("SqlExecutionArea", "Whole Words", nullptr));
#ifndef QT_NO_WHATSTHIS
        findLineEdit->setWhatsThis(QApplication::translate("SqlExecutionArea", "Text pattern to find considering the checks in this frame", nullptr));
#endif // QT_NO_WHATSTHIS
        findLineEdit->setPlaceholderText(QApplication::translate("SqlExecutionArea", "Find in editor", nullptr));
#ifndef QT_NO_WHATSTHIS
        caseCheckBox->setWhatsThis(QApplication::translate("SqlExecutionArea", "The found pattern must match in letter case", nullptr));
#endif // QT_NO_WHATSTHIS
        caseCheckBox->setText(QApplication::translate("SqlExecutionArea", "Case Sensitive", nullptr));
#ifndef QT_NO_TOOLTIP
        nextToolButton->setToolTip(QApplication::translate("SqlExecutionArea", "Find next match [Enter, F3]", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        nextToolButton->setWhatsThis(QApplication::translate("SqlExecutionArea", "Find next match with wrapping", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        nextToolButton->setShortcut(QApplication::translate("SqlExecutionArea", "F3", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        regexpCheckBox->setToolTip(QApplication::translate("SqlExecutionArea", "Interpret search pattern as a regular expression", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        regexpCheckBox->setWhatsThis(QApplication::translate("SqlExecutionArea", "<html><head/><body><p>When checked, the pattern to find is interpreted as a UNIX regular expression. See <a href=\"https://en.wikibooks.org/wiki/Regular_Expressions\">Regular Expression in Wikibooks</a>.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        regexpCheckBox->setText(QApplication::translate("SqlExecutionArea", "Regular Expression", nullptr));
#ifndef QT_NO_TOOLTIP
        hideFindButton->setToolTip(QApplication::translate("SqlExecutionArea", "Close Find Bar", nullptr));
#endif // QT_NO_TOOLTIP
        hideFindButton->setText(QApplication::translate("SqlExecutionArea", "Close Find Bar", nullptr));
#ifndef QT_NO_TOOLTIP
        editErrors->setToolTip(QApplication::translate("SqlExecutionArea", "<html><head/><body><p>Results of the last executed statements.</p><p>You may want to collapse this panel and use the <span style=\" font-style:italic;\">SQL Log</span> dock with <span style=\" font-style:italic;\">User</span> selection instead.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        editErrors->setWhatsThis(QApplication::translate("SqlExecutionArea", "This field shows the results and status codes of the last executed statements.", nullptr));
#endif // QT_NO_WHATSTHIS
        editErrors->setPlaceholderText(QApplication::translate("SqlExecutionArea", "Results of the last executed statements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SqlExecutionArea: public Ui_SqlExecutionArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLEXECUTIONAREA_H
