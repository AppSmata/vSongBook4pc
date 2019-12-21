/********************************************************************************
** Form generated from reading UI file 'ExportSqlDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTSQLDIALOG_H
#define UI_EXPORTSQLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ExportSqlDialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QFormLayout *formLayout;
    QLabel *labelTable;
    QListWidget *listTables;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSelectAll;
    QPushButton *buttonDeselectAll;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkColNames;
    QCheckBox *checkMultiple;
    QSpacerItem *verticalSpacer;
    QComboBox *comboWhat;
    QComboBox *comboOldSchema;

    void setupUi(QDialog *ExportSqlDialog)
    {
        if (ExportSqlDialog->objectName().isEmpty())
            ExportSqlDialog->setObjectName(QString::fromUtf8("ExportSqlDialog"));
        ExportSqlDialog->resize(497, 352);
        gridLayout_2 = new QGridLayout(ExportSqlDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonBox = new QDialogButtonBox(ExportSqlDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        labelTable = new QLabel(ExportSqlDialog);
        labelTable->setObjectName(QString::fromUtf8("labelTable"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTable);

        listTables = new QListWidget(ExportSqlDialog);
        listTables->setObjectName(QString::fromUtf8("listTables"));
        listTables->setSelectionMode(QAbstractItemView::MultiSelection);
        listTables->setSortingEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, listTables);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(-1, 10, -1, -1);
        buttonSelectAll = new QPushButton(ExportSqlDialog);
        buttonSelectAll->setObjectName(QString::fromUtf8("buttonSelectAll"));

        horizontalLayout->addWidget(buttonSelectAll);

        buttonDeselectAll = new QPushButton(ExportSqlDialog);
        buttonDeselectAll->setObjectName(QString::fromUtf8("buttonDeselectAll"));

        horizontalLayout->addWidget(buttonDeselectAll);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        groupBox = new QGroupBox(ExportSqlDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkColNames = new QCheckBox(groupBox);
        checkColNames->setObjectName(QString::fromUtf8("checkColNames"));
        checkColNames->setChecked(true);

        gridLayout->addWidget(checkColNames, 0, 0, 1, 1);

        checkMultiple = new QCheckBox(groupBox);
        checkMultiple->setObjectName(QString::fromUtf8("checkMultiple"));

        gridLayout->addWidget(checkMultiple, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        comboWhat = new QComboBox(groupBox);
        comboWhat->addItem(QString());
        comboWhat->addItem(QString());
        comboWhat->addItem(QString());
        comboWhat->setObjectName(QString::fromUtf8("comboWhat"));

        gridLayout->addWidget(comboWhat, 2, 0, 1, 1);

        comboOldSchema = new QComboBox(groupBox);
        comboOldSchema->addItem(QString());
        comboOldSchema->addItem(QString());
        comboOldSchema->setObjectName(QString::fromUtf8("comboOldSchema"));

        gridLayout->addWidget(comboOldSchema, 3, 0, 1, 1);


        formLayout->setWidget(2, QFormLayout::SpanningRole, groupBox);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        labelTable->setBuddy(listTables);
#endif // QT_NO_SHORTCUT

        retranslateUi(ExportSqlDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExportSqlDialog, SLOT(accept()));
        QObject::connect(buttonDeselectAll, SIGNAL(clicked()), ExportSqlDialog, SLOT(doDeselectAll()));
        QObject::connect(buttonSelectAll, SIGNAL(clicked()), ExportSqlDialog, SLOT(doSelectAll()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExportSqlDialog, SLOT(reject()));
        QObject::connect(comboWhat, SIGNAL(currentIndexChanged(int)), ExportSqlDialog, SLOT(whatChanged(int)));

        QMetaObject::connectSlotsByName(ExportSqlDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportSqlDialog)
    {
        ExportSqlDialog->setWindowTitle(QApplication::translate("ExportSqlDialog", "Export SQL...", nullptr));
        labelTable->setText(QApplication::translate("ExportSqlDialog", "Tab&le(s)", nullptr));
        buttonSelectAll->setText(QApplication::translate("ExportSqlDialog", "Select All", nullptr));
        buttonDeselectAll->setText(QApplication::translate("ExportSqlDialog", "Deselect All", nullptr));
        groupBox->setTitle(QApplication::translate("ExportSqlDialog", "&Options", nullptr));
        checkColNames->setText(QApplication::translate("ExportSqlDialog", "Keep column names in INSERT INTO", nullptr));
        checkMultiple->setText(QApplication::translate("ExportSqlDialog", "Multiple rows (VALUES) per INSERT statement", nullptr));
        comboWhat->setItemText(0, QApplication::translate("ExportSqlDialog", "Export everything", nullptr));
        comboWhat->setItemText(1, QApplication::translate("ExportSqlDialog", "Export schema only", nullptr));
        comboWhat->setItemText(2, QApplication::translate("ExportSqlDialog", "Export data only", nullptr));

        comboOldSchema->setItemText(0, QApplication::translate("ExportSqlDialog", "Keep old schema (CREATE TABLE IF NOT EXISTS)", nullptr));
        comboOldSchema->setItemText(1, QApplication::translate("ExportSqlDialog", "Overwrite old schema (DROP TABLE, then CREATE TABLE)", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ExportSqlDialog: public Ui_ExportSqlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTSQLDIALOG_H
