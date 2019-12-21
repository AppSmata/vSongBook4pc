/********************************************************************************
** Form generated from reading UI file 'ImportCsvDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTCSVDIALOG_H
#define UI_IMPORTCSVDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportCsvDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *editName;
    QLabel *labelHeader;
    QCheckBox *checkboxHeader;
    QLabel *labelSeparator;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboSeparator;
    QLineEdit *editCustomSeparator;
    QSpacerItem *horizontalSpacer;
    QLabel *labelQuote;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboQuote;
    QLineEdit *editCustomQuote;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelEncoding;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboEncoding;
    QLineEdit *editCustomEncoding;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelTrim;
    QCheckBox *checkBoxTrimFields;
    QLabel *separateTables;
    QCheckBox *checkBoxSeparateTables;
    QPushButton *buttonAdvanced;
    QCheckBox *checkIgnoreDefaults;
    QLabel *labelIgnoreDefaults;
    QCheckBox *checkFailOnMissing;
    QLabel *labelFailOnMissing;
    QLabel *labelNoTypeDetection;
    QCheckBox *checkNoTypeDetection;
    QComboBox *comboOnConflictStrategy;
    QLabel *labelOnConflictStrategy;
    QSplitter *splitter;
    QWidget *filePickerBlock;
    QHBoxLayout *filePickerLayout;
    QListWidget *filePicker;
    QVBoxLayout *verticalLayout;
    QPushButton *toggleSelected;
    QPushButton *matchSimilar;
    QSpacerItem *verticalSpacer;
    QTableWidget *tablePreview;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImportCsvDialog)
    {
        if (ImportCsvDialog->objectName().isEmpty())
            ImportCsvDialog->setObjectName(QString::fromUtf8("ImportCsvDialog"));
        ImportCsvDialog->resize(788, 717);
        verticalLayout_2 = new QVBoxLayout(ImportCsvDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        labelName = new QLabel(ImportCsvDialog);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        editName = new QLineEdit(ImportCsvDialog);
        editName->setObjectName(QString::fromUtf8("editName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editName);

        labelHeader = new QLabel(ImportCsvDialog);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelHeader);

        checkboxHeader = new QCheckBox(ImportCsvDialog);
        checkboxHeader->setObjectName(QString::fromUtf8("checkboxHeader"));

        formLayout->setWidget(1, QFormLayout::FieldRole, checkboxHeader);

        labelSeparator = new QLabel(ImportCsvDialog);
        labelSeparator->setObjectName(QString::fromUtf8("labelSeparator"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelSeparator);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboSeparator = new QComboBox(ImportCsvDialog);
        comboSeparator->addItem(QString());
        comboSeparator->addItem(QString());
        comboSeparator->addItem(QString());
        comboSeparator->addItem(QString());
        comboSeparator->addItem(QString());
        comboSeparator->setObjectName(QString::fromUtf8("comboSeparator"));

        horizontalLayout->addWidget(comboSeparator);

        editCustomSeparator = new QLineEdit(ImportCsvDialog);
        editCustomSeparator->setObjectName(QString::fromUtf8("editCustomSeparator"));
        editCustomSeparator->setMaxLength(1);

        horizontalLayout->addWidget(editCustomSeparator);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        labelQuote = new QLabel(ImportCsvDialog);
        labelQuote->setObjectName(QString::fromUtf8("labelQuote"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelQuote);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboQuote = new QComboBox(ImportCsvDialog);
        comboQuote->addItem(QString());
        comboQuote->addItem(QString());
        comboQuote->addItem(QString());
        comboQuote->addItem(QString());
        comboQuote->setObjectName(QString::fromUtf8("comboQuote"));

        horizontalLayout_2->addWidget(comboQuote);

        editCustomQuote = new QLineEdit(ImportCsvDialog);
        editCustomQuote->setObjectName(QString::fromUtf8("editCustomQuote"));
        editCustomQuote->setMaxLength(1);

        horizontalLayout_2->addWidget(editCustomQuote);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);

        labelEncoding = new QLabel(ImportCsvDialog);
        labelEncoding->setObjectName(QString::fromUtf8("labelEncoding"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelEncoding);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboEncoding = new QComboBox(ImportCsvDialog);
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->setObjectName(QString::fromUtf8("comboEncoding"));

        horizontalLayout_3->addWidget(comboEncoding);

        editCustomEncoding = new QLineEdit(ImportCsvDialog);
        editCustomEncoding->setObjectName(QString::fromUtf8("editCustomEncoding"));

        horizontalLayout_3->addWidget(editCustomEncoding);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);

        labelTrim = new QLabel(ImportCsvDialog);
        labelTrim->setObjectName(QString::fromUtf8("labelTrim"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelTrim);

        checkBoxTrimFields = new QCheckBox(ImportCsvDialog);
        checkBoxTrimFields->setObjectName(QString::fromUtf8("checkBoxTrimFields"));
        checkBoxTrimFields->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, checkBoxTrimFields);

        separateTables = new QLabel(ImportCsvDialog);
        separateTables->setObjectName(QString::fromUtf8("separateTables"));

        formLayout->setWidget(6, QFormLayout::LabelRole, separateTables);

        checkBoxSeparateTables = new QCheckBox(ImportCsvDialog);
        checkBoxSeparateTables->setObjectName(QString::fromUtf8("checkBoxSeparateTables"));

        formLayout->setWidget(6, QFormLayout::FieldRole, checkBoxSeparateTables);

        buttonAdvanced = new QPushButton(ImportCsvDialog);
        buttonAdvanced->setObjectName(QString::fromUtf8("buttonAdvanced"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/down"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAdvanced->setIcon(icon);
        buttonAdvanced->setCheckable(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, buttonAdvanced);

        checkIgnoreDefaults = new QCheckBox(ImportCsvDialog);
        checkIgnoreDefaults->setObjectName(QString::fromUtf8("checkIgnoreDefaults"));

        formLayout->setWidget(9, QFormLayout::FieldRole, checkIgnoreDefaults);

        labelIgnoreDefaults = new QLabel(ImportCsvDialog);
        labelIgnoreDefaults->setObjectName(QString::fromUtf8("labelIgnoreDefaults"));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelIgnoreDefaults);

        checkFailOnMissing = new QCheckBox(ImportCsvDialog);
        checkFailOnMissing->setObjectName(QString::fromUtf8("checkFailOnMissing"));

        formLayout->setWidget(11, QFormLayout::FieldRole, checkFailOnMissing);

        labelFailOnMissing = new QLabel(ImportCsvDialog);
        labelFailOnMissing->setObjectName(QString::fromUtf8("labelFailOnMissing"));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelFailOnMissing);

        labelNoTypeDetection = new QLabel(ImportCsvDialog);
        labelNoTypeDetection->setObjectName(QString::fromUtf8("labelNoTypeDetection"));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelNoTypeDetection);

        checkNoTypeDetection = new QCheckBox(ImportCsvDialog);
        checkNoTypeDetection->setObjectName(QString::fromUtf8("checkNoTypeDetection"));

        formLayout->setWidget(8, QFormLayout::FieldRole, checkNoTypeDetection);

        comboOnConflictStrategy = new QComboBox(ImportCsvDialog);
        comboOnConflictStrategy->addItem(QString());
        comboOnConflictStrategy->addItem(QString());
        comboOnConflictStrategy->addItem(QString());
        comboOnConflictStrategy->setObjectName(QString::fromUtf8("comboOnConflictStrategy"));

        formLayout->setWidget(12, QFormLayout::FieldRole, comboOnConflictStrategy);

        labelOnConflictStrategy = new QLabel(ImportCsvDialog);
        labelOnConflictStrategy->setObjectName(QString::fromUtf8("labelOnConflictStrategy"));

        formLayout->setWidget(12, QFormLayout::LabelRole, labelOnConflictStrategy);


        verticalLayout_2->addLayout(formLayout);

        splitter = new QSplitter(ImportCsvDialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        filePickerBlock = new QWidget(splitter);
        filePickerBlock->setObjectName(QString::fromUtf8("filePickerBlock"));
        filePickerBlock->setEnabled(true);
        filePickerLayout = new QHBoxLayout(filePickerBlock);
        filePickerLayout->setObjectName(QString::fromUtf8("filePickerLayout"));
        filePickerLayout->setContentsMargins(0, 0, 0, 0);
        filePicker = new QListWidget(filePickerBlock);
        filePicker->setObjectName(QString::fromUtf8("filePicker"));

        filePickerLayout->addWidget(filePicker);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        toggleSelected = new QPushButton(filePickerBlock);
        toggleSelected->setObjectName(QString::fromUtf8("toggleSelected"));
        toggleSelected->setCheckable(true);
        toggleSelected->setChecked(true);

        verticalLayout->addWidget(toggleSelected);

        matchSimilar = new QPushButton(filePickerBlock);
        matchSimilar->setObjectName(QString::fromUtf8("matchSimilar"));
        matchSimilar->setEnabled(false);

        verticalLayout->addWidget(matchSimilar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        filePickerLayout->addLayout(verticalLayout);

        splitter->addWidget(filePickerBlock);
        tablePreview = new QTableWidget(splitter);
        tablePreview->setObjectName(QString::fromUtf8("tablePreview"));
        splitter->addWidget(tablePreview);

        verticalLayout_2->addWidget(splitter);

        buttonBox = new QDialogButtonBox(ImportCsvDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelName->setBuddy(editName);
        labelHeader->setBuddy(checkboxHeader);
        labelSeparator->setBuddy(comboSeparator);
        labelQuote->setBuddy(comboQuote);
        labelEncoding->setBuddy(comboEncoding);
        labelTrim->setBuddy(checkBoxTrimFields);
        separateTables->setBuddy(checkBoxSeparateTables);
        labelIgnoreDefaults->setBuddy(checkIgnoreDefaults);
        labelFailOnMissing->setBuddy(checkFailOnMissing);
        labelNoTypeDetection->setBuddy(checkNoTypeDetection);
        labelOnConflictStrategy->setBuddy(comboOnConflictStrategy);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editName, checkboxHeader);
        QWidget::setTabOrder(checkboxHeader, comboSeparator);
        QWidget::setTabOrder(comboSeparator, editCustomSeparator);
        QWidget::setTabOrder(editCustomSeparator, comboQuote);
        QWidget::setTabOrder(comboQuote, editCustomQuote);
        QWidget::setTabOrder(editCustomQuote, comboEncoding);
        QWidget::setTabOrder(comboEncoding, editCustomEncoding);
        QWidget::setTabOrder(editCustomEncoding, checkBoxTrimFields);
        QWidget::setTabOrder(checkBoxTrimFields, checkBoxSeparateTables);
        QWidget::setTabOrder(checkBoxSeparateTables, buttonAdvanced);
        QWidget::setTabOrder(buttonAdvanced, checkIgnoreDefaults);
        QWidget::setTabOrder(checkIgnoreDefaults, checkNoTypeDetection);
        QWidget::setTabOrder(checkNoTypeDetection, checkFailOnMissing);
        QWidget::setTabOrder(checkFailOnMissing, comboOnConflictStrategy);
        QWidget::setTabOrder(comboOnConflictStrategy, filePicker);
        QWidget::setTabOrder(filePicker, toggleSelected);
        QWidget::setTabOrder(toggleSelected, matchSimilar);
        QWidget::setTabOrder(matchSimilar, tablePreview);

        retranslateUi(ImportCsvDialog);
        QObject::connect(comboSeparator, SIGNAL(currentIndexChanged(int)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(editName, SIGNAL(textChanged(QString)), ImportCsvDialog, SLOT(checkInput()));
        QObject::connect(editCustomSeparator, SIGNAL(textChanged(QString)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(editCustomQuote, SIGNAL(textChanged(QString)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(editCustomEncoding, SIGNAL(textChanged(QString)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(checkBoxTrimFields, SIGNAL(toggled(bool)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(comboEncoding, SIGNAL(currentIndexChanged(int)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(checkboxHeader, SIGNAL(toggled(bool)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(toggleSelected, SIGNAL(toggled(bool)), ImportCsvDialog, SLOT(updateSelection(bool)));
        QObject::connect(comboQuote, SIGNAL(currentIndexChanged(int)), ImportCsvDialog, SLOT(updatePreview()));
        QObject::connect(buttonBox, SIGNAL(accepted()), ImportCsvDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImportCsvDialog, SLOT(reject()));
        QObject::connect(checkBoxSeparateTables, SIGNAL(toggled(bool)), ImportCsvDialog, SLOT(checkInput()));
        QObject::connect(matchSimilar, SIGNAL(pressed()), ImportCsvDialog, SLOT(matchSimilar()));
        QObject::connect(buttonAdvanced, SIGNAL(toggled(bool)), ImportCsvDialog, SLOT(toggleAdvancedSection(bool)));

        QMetaObject::connectSlotsByName(ImportCsvDialog);
    } // setupUi

    void retranslateUi(QDialog *ImportCsvDialog)
    {
        ImportCsvDialog->setWindowTitle(QApplication::translate("ImportCsvDialog", "Import CSV file", nullptr));
        labelName->setText(QApplication::translate("ImportCsvDialog", "Table na&me", nullptr));
        labelHeader->setText(QApplication::translate("ImportCsvDialog", "&Column names in first line", nullptr));
        checkboxHeader->setText(QString());
        labelSeparator->setText(QApplication::translate("ImportCsvDialog", "Field &separator", nullptr));
        comboSeparator->setItemText(0, QApplication::translate("ImportCsvDialog", ",", nullptr));
        comboSeparator->setItemText(1, QApplication::translate("ImportCsvDialog", ";", nullptr));
        comboSeparator->setItemText(2, QApplication::translate("ImportCsvDialog", "Tab", nullptr));
        comboSeparator->setItemText(3, QApplication::translate("ImportCsvDialog", "|", nullptr));
        comboSeparator->setItemText(4, QApplication::translate("ImportCsvDialog", "Other", nullptr));

        labelQuote->setText(QApplication::translate("ImportCsvDialog", "&Quote character", nullptr));
        comboQuote->setItemText(0, QApplication::translate("ImportCsvDialog", "\"", nullptr));
        comboQuote->setItemText(1, QApplication::translate("ImportCsvDialog", "'", nullptr));
        comboQuote->setItemText(2, QString());
        comboQuote->setItemText(3, QApplication::translate("ImportCsvDialog", "Other", nullptr));

        labelEncoding->setText(QApplication::translate("ImportCsvDialog", "&Encoding", nullptr));
        comboEncoding->setItemText(0, QApplication::translate("ImportCsvDialog", "UTF-8", nullptr));
        comboEncoding->setItemText(1, QApplication::translate("ImportCsvDialog", "UTF-16", nullptr));
        comboEncoding->setItemText(2, QApplication::translate("ImportCsvDialog", "ISO-8859-1", nullptr));
        comboEncoding->setItemText(3, QApplication::translate("ImportCsvDialog", "Other", nullptr));

        labelTrim->setText(QApplication::translate("ImportCsvDialog", "Trim fields?", nullptr));
        checkBoxTrimFields->setText(QString());
        separateTables->setText(QApplication::translate("ImportCsvDialog", "Separate tables", nullptr));
        checkBoxSeparateTables->setText(QString());
        buttonAdvanced->setText(QApplication::translate("ImportCsvDialog", "Advanced", nullptr));
#ifndef QT_NO_TOOLTIP
        checkIgnoreDefaults->setToolTip(QApplication::translate("ImportCsvDialog", "When importing an empty value from the CSV file into an existing table with a default value for this column, that default value is inserted. Activate this option to insert an empty value instead.", nullptr));
#endif // QT_NO_TOOLTIP
        labelIgnoreDefaults->setText(QApplication::translate("ImportCsvDialog", "Ignore default &values", nullptr));
#ifndef QT_NO_TOOLTIP
        checkFailOnMissing->setToolTip(QApplication::translate("ImportCsvDialog", "Activate this option to stop the import when trying to import an empty value into a NOT NULL column without a default value.", nullptr));
#endif // QT_NO_TOOLTIP
        labelFailOnMissing->setText(QApplication::translate("ImportCsvDialog", "Fail on missing values ", nullptr));
        labelNoTypeDetection->setText(QApplication::translate("ImportCsvDialog", "Disable data type detection", nullptr));
#ifndef QT_NO_TOOLTIP
        checkNoTypeDetection->setToolTip(QApplication::translate("ImportCsvDialog", "Disable the automatic data type detection when creating a new table.", nullptr));
#endif // QT_NO_TOOLTIP
        comboOnConflictStrategy->setItemText(0, QApplication::translate("ImportCsvDialog", "Abort import", nullptr));
        comboOnConflictStrategy->setItemText(1, QApplication::translate("ImportCsvDialog", "Ignore row", nullptr));
        comboOnConflictStrategy->setItemText(2, QApplication::translate("ImportCsvDialog", "Replace existing row", nullptr));

#ifndef QT_NO_TOOLTIP
        comboOnConflictStrategy->setToolTip(QApplication::translate("ImportCsvDialog", "When importing into an existing table with a primary key, unique constraints or a unique index there is a chance for a conflict. This option allows you to select a strategy for that case: By default the import is aborted and rolled back but you can also choose to ignore and not import conflicting rows or to replace the existing row in the table.", nullptr));
#endif // QT_NO_TOOLTIP
        labelOnConflictStrategy->setText(QApplication::translate("ImportCsvDialog", "Conflict strategy", nullptr));
        toggleSelected->setText(QApplication::translate("ImportCsvDialog", "Deselect All", nullptr));
        matchSimilar->setText(QApplication::translate("ImportCsvDialog", "Match Similar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportCsvDialog: public Ui_ImportCsvDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTCSVDIALOG_H
