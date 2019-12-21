/********************************************************************************
** Form generated from reading UI file 'ExportDataDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDATADIALOG_H
#define UI_EXPORTDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportDataDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *labelTable;
    QListWidget *listTables;
    QStackedWidget *stackFormat;
    QWidget *csv;
    QFormLayout *formLayout;
    QLabel *labelHeader;
    QCheckBox *checkHeader;
    QLabel *labelFieldSeparator;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboFieldSeparator;
    QLineEdit *editCustomSeparator;
    QSpacerItem *horizontalSpacer;
    QLabel *labelQuoteCharacter;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboQuoteCharacter;
    QLineEdit *editCustomQuote;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelNewLineCharacters;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboNewLineString;
    QLineEdit *editCustomNewLine;
    QSpacerItem *horizontalSpacer_3;
    QWidget *json;
    QFormLayout *formLayout_2;
    QLabel *label;
    QCheckBox *checkPrettyPrint;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExportDataDialog)
    {
        if (ExportDataDialog->objectName().isEmpty())
            ExportDataDialog->setObjectName(QString::fromUtf8("ExportDataDialog"));
        ExportDataDialog->resize(527, 381);
        verticalLayout = new QVBoxLayout(ExportDataDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelTable = new QLabel(ExportDataDialog);
        labelTable->setObjectName(QString::fromUtf8("labelTable"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelTable);

        listTables = new QListWidget(ExportDataDialog);
        listTables->setObjectName(QString::fromUtf8("listTables"));
        listTables->setMinimumSize(QSize(360, 0));
        listTables->setSelectionMode(QAbstractItemView::MultiSelection);
        listTables->setSortingEnabled(false);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, listTables);


        verticalLayout->addLayout(formLayout_3);

        stackFormat = new QStackedWidget(ExportDataDialog);
        stackFormat->setObjectName(QString::fromUtf8("stackFormat"));
        csv = new QWidget();
        csv->setObjectName(QString::fromUtf8("csv"));
        formLayout = new QFormLayout(csv);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelHeader = new QLabel(csv);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelHeader);

        checkHeader = new QCheckBox(csv);
        checkHeader->setObjectName(QString::fromUtf8("checkHeader"));
        checkHeader->setChecked(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, checkHeader);

        labelFieldSeparator = new QLabel(csv);
        labelFieldSeparator->setObjectName(QString::fromUtf8("labelFieldSeparator"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelFieldSeparator);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboFieldSeparator = new QComboBox(csv);
        comboFieldSeparator->addItem(QString());
        comboFieldSeparator->addItem(QString());
        comboFieldSeparator->addItem(QString());
        comboFieldSeparator->addItem(QString());
        comboFieldSeparator->addItem(QString());
        comboFieldSeparator->setObjectName(QString::fromUtf8("comboFieldSeparator"));
        comboFieldSeparator->setMinimumSize(QSize(180, 0));
        comboFieldSeparator->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(comboFieldSeparator);

        editCustomSeparator = new QLineEdit(csv);
        editCustomSeparator->setObjectName(QString::fromUtf8("editCustomSeparator"));
        editCustomSeparator->setMaxLength(1);

        horizontalLayout->addWidget(editCustomSeparator);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        labelQuoteCharacter = new QLabel(csv);
        labelQuoteCharacter->setObjectName(QString::fromUtf8("labelQuoteCharacter"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelQuoteCharacter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboQuoteCharacter = new QComboBox(csv);
        comboQuoteCharacter->addItem(QString());
        comboQuoteCharacter->addItem(QString());
        comboQuoteCharacter->addItem(QString());
        comboQuoteCharacter->addItem(QString());
        comboQuoteCharacter->setObjectName(QString::fromUtf8("comboQuoteCharacter"));
        comboQuoteCharacter->setMinimumSize(QSize(180, 0));
        comboQuoteCharacter->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_2->addWidget(comboQuoteCharacter);

        editCustomQuote = new QLineEdit(csv);
        editCustomQuote->setObjectName(QString::fromUtf8("editCustomQuote"));
        editCustomQuote->setMaxLength(1);

        horizontalLayout_2->addWidget(editCustomQuote);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        labelNewLineCharacters = new QLabel(csv);
        labelNewLineCharacters->setObjectName(QString::fromUtf8("labelNewLineCharacters"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelNewLineCharacters);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboNewLineString = new QComboBox(csv);
        comboNewLineString->addItem(QString());
        comboNewLineString->addItem(QString());
        comboNewLineString->addItem(QString());
        comboNewLineString->setObjectName(QString::fromUtf8("comboNewLineString"));
        comboNewLineString->setMinimumSize(QSize(180, 0));
        comboNewLineString->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_3->addWidget(comboNewLineString);

        editCustomNewLine = new QLineEdit(csv);
        editCustomNewLine->setObjectName(QString::fromUtf8("editCustomNewLine"));
        editCustomNewLine->setMaxLength(5);

        horizontalLayout_3->addWidget(editCustomNewLine);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        stackFormat->addWidget(csv);
        json = new QWidget();
        json->setObjectName(QString::fromUtf8("json"));
        formLayout_2 = new QFormLayout(json);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(json);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        checkPrettyPrint = new QCheckBox(json);
        checkPrettyPrint->setObjectName(QString::fromUtf8("checkPrettyPrint"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, checkPrettyPrint);

        stackFormat->addWidget(json);

        verticalLayout->addWidget(stackFormat);

        buttonBox = new QDialogButtonBox(ExportDataDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelTable->setBuddy(listTables);
        labelHeader->setBuddy(checkHeader);
        labelFieldSeparator->setBuddy(comboFieldSeparator);
        labelQuoteCharacter->setBuddy(comboQuoteCharacter);
        label->setBuddy(checkPrettyPrint);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(listTables, checkHeader);
        QWidget::setTabOrder(checkHeader, comboFieldSeparator);
        QWidget::setTabOrder(comboFieldSeparator, editCustomSeparator);
        QWidget::setTabOrder(editCustomSeparator, comboQuoteCharacter);
        QWidget::setTabOrder(comboQuoteCharacter, editCustomQuote);

        retranslateUi(ExportDataDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportDataDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportDataDialog, SLOT(reject()));
        QObject::connect(comboFieldSeparator, SIGNAL(currentIndexChanged(int)), ExportDataDialog, SLOT(showCustomCharEdits()));
        QObject::connect(comboQuoteCharacter, SIGNAL(currentIndexChanged(int)), ExportDataDialog, SLOT(showCustomCharEdits()));
        QObject::connect(comboNewLineString, SIGNAL(currentIndexChanged(int)), ExportDataDialog, SLOT(showCustomCharEdits()));

        stackFormat->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ExportDataDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportDataDialog)
    {
        ExportDataDialog->setWindowTitle(QApplication::translate("ExportDataDialog", "Export data as CSV", nullptr));
        labelTable->setText(QApplication::translate("ExportDataDialog", "Tab&le(s)", nullptr));
        labelHeader->setText(QApplication::translate("ExportDataDialog", "Colu&mn names in first line", nullptr));
        checkHeader->setText(QString());
        labelFieldSeparator->setText(QApplication::translate("ExportDataDialog", "Fie&ld separator", nullptr));
        comboFieldSeparator->setItemText(0, QApplication::translate("ExportDataDialog", ",", nullptr));
        comboFieldSeparator->setItemText(1, QApplication::translate("ExportDataDialog", ";", nullptr));
        comboFieldSeparator->setItemText(2, QApplication::translate("ExportDataDialog", "Tab", nullptr));
        comboFieldSeparator->setItemText(3, QApplication::translate("ExportDataDialog", "|", nullptr));
        comboFieldSeparator->setItemText(4, QApplication::translate("ExportDataDialog", "Other", nullptr));

        labelQuoteCharacter->setText(QApplication::translate("ExportDataDialog", "&Quote character", nullptr));
        comboQuoteCharacter->setItemText(0, QApplication::translate("ExportDataDialog", "\"", nullptr));
        comboQuoteCharacter->setItemText(1, QApplication::translate("ExportDataDialog", "'", nullptr));
        comboQuoteCharacter->setItemText(2, QString());
        comboQuoteCharacter->setItemText(3, QApplication::translate("ExportDataDialog", "Other", nullptr));

        labelNewLineCharacters->setText(QApplication::translate("ExportDataDialog", "New line characters", nullptr));
        comboNewLineString->setItemText(0, QApplication::translate("ExportDataDialog", "Windows: CR+LF (\\r\\n)", nullptr));
        comboNewLineString->setItemText(1, QApplication::translate("ExportDataDialog", "Unix: LF (\\n)", nullptr));
        comboNewLineString->setItemText(2, QApplication::translate("ExportDataDialog", "Other", nullptr));

        label->setText(QApplication::translate("ExportDataDialog", "Pretty print", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExportDataDialog: public Ui_ExportDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDATADIALOG_H
