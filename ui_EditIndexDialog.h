/********************************************************************************
** Form generated from reading UI file 'EditIndexDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINDEXDIALOG_H
#define UI_EDITINDEXDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "sqltextedit.h"

QT_BEGIN_NAMESPACE

class Ui_EditIndexDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *labelIndexName;
    QLineEdit *editIndexName;
    QLabel *labelTableName;
    QComboBox *comboTableName;
    QLabel *labelIndexUnique;
    QCheckBox *checkIndexUnique;
    QLabel *label;
    QLineEdit *editPartialClause;
    QLabel *labelIndexColumns;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableTableColumns;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QToolButton *buttonToIndex;
    QToolButton *buttonFromIndex;
    QToolButton *buttonAddExpressionColumn;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableIndexColumns;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QToolButton *buttonMoveColumnUp;
    QToolButton *buttonMoveColumnDown;
    QSpacerItem *verticalSpacer_3;
    SqlTextEdit *sqlTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditIndexDialog)
    {
        if (EditIndexDialog->objectName().isEmpty())
            EditIndexDialog->setObjectName(QString::fromUtf8("EditIndexDialog"));
        EditIndexDialog->resize(703, 543);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/index_create"), QSize(), QIcon::Normal, QIcon::Off);
        EditIndexDialog->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(EditIndexDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelIndexName = new QLabel(EditIndexDialog);
        labelIndexName->setObjectName(QString::fromUtf8("labelIndexName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelIndexName);

        editIndexName = new QLineEdit(EditIndexDialog);
        editIndexName->setObjectName(QString::fromUtf8("editIndexName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editIndexName);

        labelTableName = new QLabel(EditIndexDialog);
        labelTableName->setObjectName(QString::fromUtf8("labelTableName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTableName);

        comboTableName = new QComboBox(EditIndexDialog);
        comboTableName->setObjectName(QString::fromUtf8("comboTableName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboTableName);

        labelIndexUnique = new QLabel(EditIndexDialog);
        labelIndexUnique->setObjectName(QString::fromUtf8("labelIndexUnique"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelIndexUnique);

        checkIndexUnique = new QCheckBox(EditIndexDialog);
        checkIndexUnique->setObjectName(QString::fromUtf8("checkIndexUnique"));

        formLayout->setWidget(2, QFormLayout::FieldRole, checkIndexUnique);

        label = new QLabel(EditIndexDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        editPartialClause = new QLineEdit(EditIndexDialog);
        editPartialClause->setObjectName(QString::fromUtf8("editPartialClause"));

        formLayout->setWidget(3, QFormLayout::FieldRole, editPartialClause);

        labelIndexColumns = new QLabel(EditIndexDialog);
        labelIndexColumns->setObjectName(QString::fromUtf8("labelIndexColumns"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelIndexColumns);

        splitter = new QSplitter(EditIndexDialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableTableColumns = new QTableWidget(layoutWidget);
        if (tableTableColumns->columnCount() < 2)
            tableTableColumns->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableTableColumns->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableTableColumns->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableTableColumns->setObjectName(QString::fromUtf8("tableTableColumns"));
        tableTableColumns->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableTableColumns->setProperty("showDropIndicator", QVariant(false));
        tableTableColumns->setAlternatingRowColors(true);
        tableTableColumns->setSelectionMode(QAbstractItemView::SingleSelection);
        tableTableColumns->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableTableColumns->horizontalHeader()->setStretchLastSection(true);
        tableTableColumns->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableTableColumns);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonToIndex = new QToolButton(layoutWidget);
        buttonToIndex->setObjectName(QString::fromUtf8("buttonToIndex"));
        buttonToIndex->setArrowType(Qt::RightArrow);

        verticalLayout->addWidget(buttonToIndex);

        buttonFromIndex = new QToolButton(layoutWidget);
        buttonFromIndex->setObjectName(QString::fromUtf8("buttonFromIndex"));
        buttonFromIndex->setArrowType(Qt::LeftArrow);

        verticalLayout->addWidget(buttonFromIndex);

        buttonAddExpressionColumn = new QToolButton(layoutWidget);
        buttonAddExpressionColumn->setObjectName(QString::fromUtf8("buttonAddExpressionColumn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cog_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAddExpressionColumn->setIcon(icon1);

        verticalLayout->addWidget(buttonAddExpressionColumn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        tableIndexColumns = new QTableWidget(layoutWidget);
        if (tableIndexColumns->columnCount() < 2)
            tableIndexColumns->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableIndexColumns->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableIndexColumns->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableIndexColumns->setObjectName(QString::fromUtf8("tableIndexColumns"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tableIndexColumns->sizePolicy().hasHeightForWidth());
        tableIndexColumns->setSizePolicy(sizePolicy1);
        tableIndexColumns->setMinimumSize(QSize(0, 250));
        tableIndexColumns->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tableIndexColumns->setProperty("showDropIndicator", QVariant(false));
        tableIndexColumns->setAlternatingRowColors(true);
        tableIndexColumns->setSelectionMode(QAbstractItemView::SingleSelection);
        tableIndexColumns->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableIndexColumns->horizontalHeader()->setStretchLastSection(true);
        tableIndexColumns->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableIndexColumns);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        buttonMoveColumnUp = new QToolButton(layoutWidget);
        buttonMoveColumnUp->setObjectName(QString::fromUtf8("buttonMoveColumnUp"));
        buttonMoveColumnUp->setArrowType(Qt::UpArrow);

        verticalLayout_2->addWidget(buttonMoveColumnUp);

        buttonMoveColumnDown = new QToolButton(layoutWidget);
        buttonMoveColumnDown->setObjectName(QString::fromUtf8("buttonMoveColumnDown"));
        buttonMoveColumnDown->setArrowType(Qt::DownArrow);

        verticalLayout_2->addWidget(buttonMoveColumnDown);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        splitter->addWidget(layoutWidget);
        sqlTextEdit = new SqlTextEdit(splitter);
        sqlTextEdit->setObjectName(QString::fromUtf8("sqlTextEdit"));
        sqlTextEdit->setMinimumSize(QSize(0, 100));
        sqlTextEdit->setProperty("readOnly", QVariant(true));
        splitter->addWidget(sqlTextEdit);

        formLayout->setWidget(4, QFormLayout::FieldRole, splitter);


        verticalLayout_3->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(EditIndexDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelIndexName->setBuddy(editIndexName);
        labelTableName->setBuddy(comboTableName);
        labelIndexUnique->setBuddy(checkIndexUnique);
        label->setBuddy(editPartialClause);
        labelIndexColumns->setBuddy(tableIndexColumns);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editIndexName, comboTableName);
        QWidget::setTabOrder(comboTableName, checkIndexUnique);
        QWidget::setTabOrder(checkIndexUnique, editPartialClause);
        QWidget::setTabOrder(editPartialClause, tableTableColumns);
        QWidget::setTabOrder(tableTableColumns, tableIndexColumns);
        QWidget::setTabOrder(tableIndexColumns, buttonToIndex);
        QWidget::setTabOrder(buttonToIndex, buttonFromIndex);

        retranslateUi(EditIndexDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditIndexDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditIndexDialog, SLOT(reject()));
        QObject::connect(comboTableName, SIGNAL(currentIndexChanged(QString)), EditIndexDialog, SLOT(tableChanged(QString)));
        QObject::connect(editIndexName, SIGNAL(textChanged(QString)), EditIndexDialog, SLOT(checkInput()));
        QObject::connect(tableIndexColumns, SIGNAL(cellChanged(int,int)), EditIndexDialog, SLOT(checkInput()));
        QObject::connect(checkIndexUnique, SIGNAL(toggled(bool)), EditIndexDialog, SLOT(checkInput()));
        QObject::connect(buttonToIndex, SIGNAL(clicked()), EditIndexDialog, SLOT(addToIndex()));
        QObject::connect(buttonFromIndex, SIGNAL(clicked()), EditIndexDialog, SLOT(removeFromIndex()));
        QObject::connect(tableIndexColumns, SIGNAL(doubleClicked(QModelIndex)), EditIndexDialog, SLOT(removeFromIndex(QModelIndex)));
        QObject::connect(tableTableColumns, SIGNAL(doubleClicked(QModelIndex)), EditIndexDialog, SLOT(addToIndex(QModelIndex)));
        QObject::connect(editPartialClause, SIGNAL(textChanged(QString)), EditIndexDialog, SLOT(checkInput()));
        QObject::connect(buttonMoveColumnUp, SIGNAL(clicked()), EditIndexDialog, SLOT(moveColumnUp()));
        QObject::connect(buttonMoveColumnDown, SIGNAL(clicked()), EditIndexDialog, SLOT(moveColumnDown()));
        QObject::connect(buttonAddExpressionColumn, SIGNAL(clicked()), EditIndexDialog, SLOT(addExpressionColumn()));

        QMetaObject::connectSlotsByName(EditIndexDialog);
    } // setupUi

    void retranslateUi(QDialog *EditIndexDialog)
    {
        EditIndexDialog->setWindowTitle(QApplication::translate("EditIndexDialog", "Edit Index Schema", nullptr));
        labelIndexName->setText(QApplication::translate("EditIndexDialog", "&Name", nullptr));
        labelTableName->setText(QApplication::translate("EditIndexDialog", "&Table", nullptr));
        labelIndexUnique->setText(QApplication::translate("EditIndexDialog", "&Unique", nullptr));
        checkIndexUnique->setText(QString());
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("EditIndexDialog", "For restricting the index to only a part of the table you can specify a WHERE clause here that selects the part of the table that should be indexed", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("EditIndexDialog", "Partial inde&x clause", nullptr));
        labelIndexColumns->setText(QApplication::translate("EditIndexDialog", "Colu&mns", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableTableColumns->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EditIndexDialog", "Table column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableTableColumns->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EditIndexDialog", "Type", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonAddExpressionColumn->setToolTip(QApplication::translate("EditIndexDialog", "Add a new expression column to the index. Expression columns contain SQL expression rather than column names.", nullptr));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem2 = tableIndexColumns->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("EditIndexDialog", "Index column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableIndexColumns->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("EditIndexDialog", "Order", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditIndexDialog: public Ui_EditIndexDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINDEXDIALOG_H
