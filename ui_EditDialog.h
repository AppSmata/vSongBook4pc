/********************************************************************************
** Form generated from reading UI file 'EditDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QAction *actionPrintImage;
    QAction *actionPrint;
    QAction *actionCopyHexAscii;
    QAction *actionIndent;
    QAction *actionExport;
    QAction *actionImport;
    QAction *actionNull;
    QAction *actionWordWrap;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *labelMode;
    QComboBox *comboMode;
    QToolButton *buttonAutoSwitchMode;
    QSpacerItem *horizontalSpacer;
    QToolBar *editCellToolbar;
    QStackedWidget *editorStack;
    QWidget *editorSci;
    QWidget *rtlVerticalLayout;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *qtEdit;
    QWidget *editorBinary;
    QScrollArea *editorImageScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *editorImage;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelType;
    QLabel *labelSize;
    QPushButton *buttonApply;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QString::fromUtf8("EditDialog"));
        EditDialog->resize(618, 382);
        actionPrintImage = new QAction(EditDialog);
        actionPrintImage->setObjectName(QString::fromUtf8("actionPrintImage"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/print"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintImage->setIcon(icon);
        actionPrint = new QAction(EditDialog);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionPrint->setIcon(icon);
        actionPrint->setShortcutContext(Qt::WidgetShortcut);
        actionCopyHexAscii = new QAction(EditDialog);
        actionCopyHexAscii->setObjectName(QString::fromUtf8("actionCopyHexAscii"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/special_copy"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopyHexAscii->setIcon(icon1);
        actionIndent = new QAction(EditDialog);
        actionIndent->setObjectName(QString::fromUtf8("actionIndent"));
        actionIndent->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/text_indent"), QSize(), QIcon::Normal, QIcon::Off);
        actionIndent->setIcon(icon2);
        actionExport = new QAction(EditDialog);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/save_sql"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport->setIcon(icon3);
        actionImport = new QAction(EditDialog);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/document_open"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport->setIcon(icon4);
        actionNull = new QAction(EditDialog);
        actionNull->setObjectName(QString::fromUtf8("actionNull"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/set_to_null"), QSize(), QIcon::Normal, QIcon::Off);
        actionNull->setIcon(icon5);
        actionWordWrap = new QAction(EditDialog);
        actionWordWrap->setObjectName(QString::fromUtf8("actionWordWrap"));
        actionWordWrap->setCheckable(true);
        actionWordWrap->setChecked(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/word_wrap"), QSize(), QIcon::Normal, QIcon::Off);
        actionWordWrap->setIcon(icon6);
        verticalLayout_5 = new QVBoxLayout(EditDialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelMode = new QLabel(EditDialog);
        labelMode->setObjectName(QString::fromUtf8("labelMode"));
        labelMode->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(labelMode);

        comboMode = new QComboBox(EditDialog);
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->setObjectName(QString::fromUtf8("comboMode"));
        comboMode->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(comboMode);

        buttonAutoSwitchMode = new QToolButton(EditDialog);
        buttonAutoSwitchMode->setObjectName(QString::fromUtf8("buttonAutoSwitchMode"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/keyword"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/icons/cog_go.png"), QSize(), QIcon::Normal, QIcon::On);
        buttonAutoSwitchMode->setIcon(icon7);
        buttonAutoSwitchMode->setCheckable(true);
        buttonAutoSwitchMode->setChecked(true);

        horizontalLayout->addWidget(buttonAutoSwitchMode);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        editCellToolbar = new QToolBar(EditDialog);
        editCellToolbar->setObjectName(QString::fromUtf8("editCellToolbar"));

        horizontalLayout->addWidget(editCellToolbar);


        verticalLayout_5->addLayout(horizontalLayout);

        editorStack = new QStackedWidget(EditDialog);
        editorStack->setObjectName(QString::fromUtf8("editorStack"));
        editorSci = new QWidget();
        editorSci->setObjectName(QString::fromUtf8("editorSci"));
        editorStack->addWidget(editorSci);
        rtlVerticalLayout = new QWidget();
        rtlVerticalLayout->setObjectName(QString::fromUtf8("rtlVerticalLayout"));
        verticalLayout_3 = new QVBoxLayout(rtlVerticalLayout);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        qtEdit = new QTextEdit(rtlVerticalLayout);
        qtEdit->setObjectName(QString::fromUtf8("qtEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        qtEdit->setFont(font);
        qtEdit->setAcceptRichText(false);

        verticalLayout_3->addWidget(qtEdit);

        editorStack->addWidget(rtlVerticalLayout);
        editorBinary = new QWidget();
        editorBinary->setObjectName(QString::fromUtf8("editorBinary"));
        editorBinary->setContextMenuPolicy(Qt::ActionsContextMenu);
        editorStack->addWidget(editorBinary);
        editorImageScrollArea = new QScrollArea();
        editorImageScrollArea->setObjectName(QString::fromUtf8("editorImageScrollArea"));
        editorImageScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 264));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        editorImage = new QLabel(scrollAreaWidgetContents);
        editorImage->setObjectName(QString::fromUtf8("editorImage"));
        editorImage->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout_2->addWidget(editorImage);

        editorImageScrollArea->setWidget(scrollAreaWidgetContents);
        editorStack->addWidget(editorImageScrollArea);

        verticalLayout_5->addWidget(editorStack);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelType = new QLabel(EditDialog);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelType->sizePolicy().hasHeightForWidth());
        labelType->setSizePolicy(sizePolicy);
        labelType->setMinimumSize(QSize(100, 0));
        labelType->setWordWrap(true);

        verticalLayout->addWidget(labelType);

        labelSize = new QLabel(EditDialog);
        labelSize->setObjectName(QString::fromUtf8("labelSize"));
        sizePolicy.setHeightForWidth(labelSize->sizePolicy().hasHeightForWidth());
        labelSize->setSizePolicy(sizePolicy);
        labelSize->setMinimumSize(QSize(100, 0));
        labelSize->setTextFormat(Qt::PlainText);
        labelSize->setWordWrap(true);

        verticalLayout->addWidget(labelSize);


        horizontalLayout_2->addLayout(verticalLayout);

        buttonApply = new QPushButton(EditDialog);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonApply->sizePolicy().hasHeightForWidth());
        buttonApply->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(buttonApply);


        verticalLayout_5->addLayout(horizontalLayout_2);

#ifndef QT_NO_SHORTCUT
        labelMode->setBuddy(comboMode);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboMode, buttonAutoSwitchMode);
        QWidget::setTabOrder(buttonAutoSwitchMode, buttonApply);

        editCellToolbar->addAction(actionWordWrap);
        editCellToolbar->addAction(actionIndent);
        editCellToolbar->addAction(actionImport);
        editCellToolbar->addAction(actionExport);
        editCellToolbar->addAction(actionNull);
        editCellToolbar->addAction(actionPrint);

        retranslateUi(EditDialog);
        QObject::connect(buttonApply, SIGNAL(clicked()), EditDialog, SLOT(accept()));
        QObject::connect(comboMode, SIGNAL(currentIndexChanged(int)), EditDialog, SLOT(editModeChanged(int)));
        QObject::connect(qtEdit, SIGNAL(textChanged()), EditDialog, SLOT(editTextChanged()));
        QObject::connect(actionIndent, SIGNAL(toggled(bool)), EditDialog, SLOT(setMustIndentAndCompact(bool)));
        QObject::connect(buttonAutoSwitchMode, SIGNAL(toggled(bool)), EditDialog, SLOT(switchEditorMode(bool)));
        QObject::connect(actionPrintImage, SIGNAL(triggered()), EditDialog, SLOT(openPrintImageDialog()));
        QObject::connect(actionPrint, SIGNAL(triggered()), EditDialog, SLOT(openPrintDialog()));
        QObject::connect(actionCopyHexAscii, SIGNAL(triggered()), EditDialog, SLOT(copyHexAscii()));
        QObject::connect(actionNull, SIGNAL(triggered()), EditDialog, SLOT(setNull()));
        QObject::connect(actionImport, SIGNAL(triggered()), EditDialog, SLOT(importData()));
        QObject::connect(actionExport, SIGNAL(triggered()), EditDialog, SLOT(exportData()));
        QObject::connect(actionWordWrap, SIGNAL(toggled(bool)), EditDialog, SLOT(setWordWrapping(bool)));

        editorStack->setCurrentIndex(0);
        buttonApply->setDefault(true);


        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "Edit database cell", nullptr));
#ifndef QT_NO_WHATSTHIS
        EditDialog->setWhatsThis(QApplication::translate("EditDialog", "This area displays information about the data present in this database cell", nullptr));
#endif // QT_NO_WHATSTHIS
        actionPrintImage->setText(QApplication::translate("EditDialog", "Print...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPrintImage->setToolTip(QApplication::translate("EditDialog", "Open preview dialog for printing displayed image", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionPrintImage->setShortcut(QApplication::translate("EditDialog", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionPrint->setText(QApplication::translate("EditDialog", "Print...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPrint->setToolTip(QApplication::translate("EditDialog", "Open preview dialog for printing displayed text", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionPrint->setWhatsThis(QApplication::translate("EditDialog", "Open preview dialog for printing the data currently stored in the cell", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        actionPrint->setShortcut(QApplication::translate("EditDialog", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopyHexAscii->setText(QApplication::translate("EditDialog", "Copy Hex and ASCII", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCopyHexAscii->setToolTip(QApplication::translate("EditDialog", "Copy selected hexadecimal and ASCII columns to the clipboard", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCopyHexAscii->setShortcut(QApplication::translate("EditDialog", "Ctrl+Shift+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionIndent->setText(QApplication::translate("EditDialog", "Autoformat", nullptr));
#ifndef QT_NO_TOOLTIP
        actionIndent->setToolTip(QApplication::translate("EditDialog", "Auto-format: pretty print on loading, compact on saving.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionIndent->setWhatsThis(QApplication::translate("EditDialog", "When enabled, the auto-format feature formats the data on loading, breaking the text in lines and indenting it for maximum readability. On data saving, the auto-format feature compacts the data removing end of lines, and unnecessary whitespace.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionExport->setText(QApplication::translate("EditDialog", "&Export...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExport->setToolTip(QApplication::translate("EditDialog", "Export to file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionExport->setWhatsThis(QApplication::translate("EditDialog", "Opens a file dialog used to export the contents of this database cell to a file.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionImport->setText(QApplication::translate("EditDialog", "&Import...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionImport->setToolTip(QApplication::translate("EditDialog", "Import from file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionImport->setWhatsThis(QApplication::translate("EditDialog", "Opens a file dialog used to import any kind of data to this database cell.", nullptr));
#endif // QT_NO_WHATSTHIS
        actionNull->setText(QApplication::translate("EditDialog", "Set as &NULL", nullptr));
#ifndef QT_NO_WHATSTHIS
        actionNull->setWhatsThis(QApplication::translate("EditDialog", "Erases the contents of the cell", nullptr));
#endif // QT_NO_WHATSTHIS
        actionWordWrap->setText(QApplication::translate("EditDialog", "Word Wrap", nullptr));
#ifndef QT_NO_TOOLTIP
        actionWordWrap->setToolTip(QApplication::translate("EditDialog", "Wrap lines on word boundaries", nullptr));
#endif // QT_NO_TOOLTIP
        labelMode->setText(QApplication::translate("EditDialog", "Mode:", nullptr));
        comboMode->setItemText(0, QApplication::translate("EditDialog", "Text", nullptr));
        comboMode->setItemText(1, QApplication::translate("EditDialog", "RTL Text", nullptr));
        comboMode->setItemText(2, QApplication::translate("EditDialog", "Binary", nullptr));
        comboMode->setItemText(3, QApplication::translate("EditDialog", "Image", nullptr));
        comboMode->setItemText(4, QApplication::translate("EditDialog", "JSON", nullptr));
        comboMode->setItemText(5, QApplication::translate("EditDialog", "XML", nullptr));

#ifndef QT_NO_WHATSTHIS
        comboMode->setWhatsThis(QApplication::translate("EditDialog", "This is the list of supported modes for the cell editor. Choose a mode for viewing or editing the data of the current cell.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        buttonAutoSwitchMode->setToolTip(QApplication::translate("EditDialog", "Automatically adjust the editor mode to the loaded data type", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        buttonAutoSwitchMode->setStatusTip(QApplication::translate("EditDialog", "Automatically adjust the editor mode to the loaded data type", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        buttonAutoSwitchMode->setWhatsThis(QApplication::translate("EditDialog", "This checkable button enables or disables the automatic switching of the editor mode. When a new cell is selected or new data is imported and the automatic switching is enabled, the mode adjusts to the detected data type. You can then change the editor mode manually. If you want to keep this manually switched mode while moving through the cells, switch the button off.", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonAutoSwitchMode->setText(QApplication::translate("EditDialog", "Auto-switch", nullptr));
#ifndef QT_NO_WHATSTHIS
        editorSci->setWhatsThis(QApplication::translate("EditDialog", "The text editor modes let you edit plain text, as well as JSON or XML data with syntax highlighting, automatic formatting and validation before saving.\n"
"\n"
"Errors are indicated with a red squiggle underline.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        qtEdit->setWhatsThis(QApplication::translate("EditDialog", "This Qt editor is used for right-to-left scripts, which are not supported by the default Text editor. The presence of right-to-left characters is detected and this editor mode is automatically selected.", nullptr));
#endif // QT_NO_WHATSTHIS
        editorImage->setText(QString());
        labelType->setText(QApplication::translate("EditDialog", "Type of data currently in cell", nullptr));
        labelSize->setText(QApplication::translate("EditDialog", "Size of data currently in table", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonApply->setToolTip(QApplication::translate("EditDialog", "Apply data to cell", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        buttonApply->setWhatsThis(QApplication::translate("EditDialog", "This button saves the changes performed in the cell editor to the database cell.", nullptr));
#endif // QT_NO_WHATSTHIS
        buttonApply->setText(QApplication::translate("EditDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
