/********************************************************************************
** Form generated from reading UI file 'AddRecordDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECORDDIALOG_H
#define UI_ADDRECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "sqltextedit.h"

QT_BEGIN_NAMESPACE

class Ui_AddRecordDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupFields;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    SqlTextEdit *sqlTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddRecordDialog)
    {
        if (AddRecordDialog->objectName().isEmpty())
            AddRecordDialog->setObjectName(QString::fromUtf8("AddRecordDialog"));
        AddRecordDialog->resize(650, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/table"), QSize(), QIcon::Normal, QIcon::Off);
        AddRecordDialog->setWindowIcon(icon);
        AddRecordDialog->setSizeGripEnabled(true);
        verticalLayout_2 = new QVBoxLayout(AddRecordDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupFields = new QGroupBox(AddRecordDialog);
        groupFields->setObjectName(QString::fromUtf8("groupFields"));
        verticalLayout = new QVBoxLayout(groupFields);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(groupFields);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeWidget = new QTreeWidget(splitter);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMinimumSize(QSize(0, 140));
        treeWidget->setRootIsDecorated(false);
        splitter->addWidget(treeWidget);
        sqlTextEdit = new SqlTextEdit(splitter);
        sqlTextEdit->setObjectName(QString::fromUtf8("sqlTextEdit"));
        sqlTextEdit->setProperty("readOnly", QVariant(true));
        splitter->addWidget(sqlTextEdit);

        verticalLayout_4->addWidget(splitter);


        verticalLayout->addWidget(widget);


        verticalLayout_2->addWidget(groupFields);

        buttonBox = new QDialogButtonBox(AddRecordDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::RestoreDefaults|QDialogButtonBox::Save);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(treeWidget, sqlTextEdit);

        retranslateUi(AddRecordDialog);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), AddRecordDialog, SLOT(on_buttonBox_clicked(QAbstractButton*)));

        QMetaObject::connectSlotsByName(AddRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRecordDialog)
    {
        AddRecordDialog->setWindowTitle(QApplication::translate("AddRecordDialog", "Add New Record", nullptr));
        groupFields->setTitle(QApplication::translate("AddRecordDialog", "Enter values for the new record considering constraints. Fields in bold are mandatory.", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("AddRecordDialog", "Value", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("AddRecordDialog", "Type", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("AddRecordDialog", "Name", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(2, QApplication::translate("AddRecordDialog", "Values to insert. Pre-filled default values are inserted automatically unless they are changed.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        treeWidget->setWhatsThis(QApplication::translate("AddRecordDialog", "In the Value column you can specify the value for the field identified in the Name column. The Type column indicates the type of the field. Default values are displayed in the same style as NULL values.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        sqlTextEdit->setWhatsThis(QApplication::translate("AddRecordDialog", "When you edit the values in the upper frame, the SQL query for inserting this new record is shown here. You can edit manually the query before saving.", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        buttonBox->setWhatsThis(QApplication::translate("AddRecordDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Save</span> will submit the shown SQL statement to the database for inserting the new record.</p><p><span style=\" font-weight:600;\">Restore Defaults</span> will restore the initial values in the <span style=\" font-weight:600;\">Value</span> column.</p><p><span style=\" font-weight:600;\">Cancel</span> will close this dialog without executing the query.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class AddRecordDialog: public Ui_AddRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECORDDIALOG_H
