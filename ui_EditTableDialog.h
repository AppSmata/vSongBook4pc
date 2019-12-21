/********************************************************************************
** Form generated from reading UI file 'EditTableDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTABLEDIALOG_H
#define UI_EDITTABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "sqltextedit.h"

QT_BEGIN_NAMESPACE

class Ui_EditTableDialog
{
public:
    QAction *actionAddPrimaryKey;
    QAction *actionAddForeignKey;
    QAction *actionAddUniqueConstraint;
    QAction *actionAddCheckConstraint;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupTable;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *editTableName;
    QToolButton *buttonMore;
    QWidget *widgetExtension;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboSchema;
    QLabel *label_1;
    QCheckBox *checkWithoutRowid;
    QSplitter *splitter;
    QTabWidget *groupDefinition;
    QWidget *groupFieldsPage1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *addFieldButton;
    QToolButton *removeFieldButton;
    QToolButton *buttonMoveTop;
    QToolButton *buttonMoveUp;
    QToolButton *buttonMoveDown;
    QToolButton *buttonMoveBottom;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *buttonAddConstraint;
    QToolButton *buttonRemoveConstraint;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableConstraints;
    SqlTextEdit *sqlTextEdit;
    QLabel *labelEditWarning;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditTableDialog)
    {
        if (EditTableDialog->objectName().isEmpty())
            EditTableDialog->setObjectName(QString::fromUtf8("EditTableDialog"));
        EditTableDialog->resize(652, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/table"), QSize(), QIcon::Normal, QIcon::Off);
        EditTableDialog->setWindowIcon(icon);
        EditTableDialog->setSizeGripEnabled(true);
        actionAddPrimaryKey = new QAction(EditTableDialog);
        actionAddPrimaryKey->setObjectName(QString::fromUtf8("actionAddPrimaryKey"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/field_key"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddPrimaryKey->setIcon(icon1);
        actionAddForeignKey = new QAction(EditTableDialog);
        actionAddForeignKey->setObjectName(QString::fromUtf8("actionAddForeignKey"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/field_fk"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddForeignKey->setIcon(icon2);
        actionAddUniqueConstraint = new QAction(EditTableDialog);
        actionAddUniqueConstraint->setObjectName(QString::fromUtf8("actionAddUniqueConstraint"));
        actionAddCheckConstraint = new QAction(EditTableDialog);
        actionAddCheckConstraint->setObjectName(QString::fromUtf8("actionAddCheckConstraint"));
        verticalLayout_2 = new QVBoxLayout(EditTableDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupTable = new QGroupBox(EditTableDialog);
        groupTable->setObjectName(QString::fromUtf8("groupTable"));
        verticalLayout_3 = new QVBoxLayout(groupTable);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        editTableName = new QLineEdit(groupTable);
        editTableName->setObjectName(QString::fromUtf8("editTableName"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        editTableName->setFont(font);

        verticalLayout_3->addWidget(editTableName);

        buttonMore = new QToolButton(groupTable);
        buttonMore->setObjectName(QString::fromUtf8("buttonMore"));
        buttonMore->setCheckable(true);
        buttonMore->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonMore->setArrowType(Qt::DownArrow);

        verticalLayout_3->addWidget(buttonMore);

        widgetExtension = new QWidget(groupTable);
        widgetExtension->setObjectName(QString::fromUtf8("widgetExtension"));
        formLayout = new QFormLayout(widgetExtension);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widgetExtension);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboSchema = new QComboBox(widgetExtension);
        comboSchema->setObjectName(QString::fromUtf8("comboSchema"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboSchema);

        label_1 = new QLabel(widgetExtension);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_1);

        checkWithoutRowid = new QCheckBox(widgetExtension);
        checkWithoutRowid->setObjectName(QString::fromUtf8("checkWithoutRowid"));

        formLayout->setWidget(1, QFormLayout::FieldRole, checkWithoutRowid);


        verticalLayout_3->addWidget(widgetExtension);


        verticalLayout_2->addWidget(groupTable);

        splitter = new QSplitter(EditTableDialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupDefinition = new QTabWidget(splitter);
        groupDefinition->setObjectName(QString::fromUtf8("groupDefinition"));
        groupFieldsPage1 = new QWidget();
        groupFieldsPage1->setObjectName(QString::fromUtf8("groupFieldsPage1"));
        verticalLayout = new QVBoxLayout(groupFieldsPage1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addFieldButton = new QToolButton(groupFieldsPage1);
        addFieldButton->setObjectName(QString::fromUtf8("addFieldButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/field_add"), QSize(), QIcon::Normal, QIcon::Off);
        addFieldButton->setIcon(icon3);
        addFieldButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addFieldButton->setAutoRaise(true);

        horizontalLayout->addWidget(addFieldButton);

        removeFieldButton = new QToolButton(groupFieldsPage1);
        removeFieldButton->setObjectName(QString::fromUtf8("removeFieldButton"));
        removeFieldButton->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/field_delete"), QSize(), QIcon::Normal, QIcon::Off);
        removeFieldButton->setIcon(icon4);
        removeFieldButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        removeFieldButton->setAutoRaise(true);

        horizontalLayout->addWidget(removeFieldButton);

        buttonMoveTop = new QToolButton(groupFieldsPage1);
        buttonMoveTop->setObjectName(QString::fromUtf8("buttonMoveTop"));
        buttonMoveTop->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/arrow_top"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMoveTop->setIcon(icon5);
        buttonMoveTop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonMoveTop->setAutoRaise(true);
        buttonMoveTop->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(buttonMoveTop);

        buttonMoveUp = new QToolButton(groupFieldsPage1);
        buttonMoveUp->setObjectName(QString::fromUtf8("buttonMoveUp"));
        buttonMoveUp->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/up"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMoveUp->setIcon(icon6);
        buttonMoveUp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonMoveUp->setAutoRaise(true);

        horizontalLayout->addWidget(buttonMoveUp);

        buttonMoveDown = new QToolButton(groupFieldsPage1);
        buttonMoveDown->setObjectName(QString::fromUtf8("buttonMoveDown"));
        buttonMoveDown->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/down"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMoveDown->setIcon(icon7);
        buttonMoveDown->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonMoveDown->setAutoRaise(true);

        horizontalLayout->addWidget(buttonMoveDown);

        buttonMoveBottom = new QToolButton(groupFieldsPage1);
        buttonMoveBottom->setObjectName(QString::fromUtf8("buttonMoveBottom"));
        buttonMoveBottom->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/arrow_bottom"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMoveBottom->setIcon(icon8);
        buttonMoveBottom->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonMoveBottom->setAutoRaise(true);

        horizontalLayout->addWidget(buttonMoveBottom);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(groupFieldsPage1);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMinimumSize(QSize(0, 140));
        treeWidget->setRootIsDecorated(false);

        verticalLayout->addWidget(treeWidget);

        groupDefinition->addTab(groupFieldsPage1, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonAddConstraint = new QToolButton(tab);
        buttonAddConstraint->setObjectName(QString::fromUtf8("buttonAddConstraint"));
        buttonAddConstraint->setIcon(icon3);
        buttonAddConstraint->setPopupMode(QToolButton::InstantPopup);
        buttonAddConstraint->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonAddConstraint->setAutoRaise(true);

        horizontalLayout_2->addWidget(buttonAddConstraint);

        buttonRemoveConstraint = new QToolButton(tab);
        buttonRemoveConstraint->setObjectName(QString::fromUtf8("buttonRemoveConstraint"));
        buttonRemoveConstraint->setEnabled(false);
        buttonRemoveConstraint->setIcon(icon4);
        buttonRemoveConstraint->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonRemoveConstraint->setAutoRaise(true);

        horizontalLayout_2->addWidget(buttonRemoveConstraint);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tableConstraints = new QTableWidget(tab);
        if (tableConstraints->columnCount() < 4)
            tableConstraints->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableConstraints->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableConstraints->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableConstraints->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableConstraints->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableConstraints->setObjectName(QString::fromUtf8("tableConstraints"));
        tableConstraints->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout_4->addWidget(tableConstraints);

        groupDefinition->addTab(tab, QString());
        splitter->addWidget(groupDefinition);
        sqlTextEdit = new SqlTextEdit(splitter);
        sqlTextEdit->setObjectName(QString::fromUtf8("sqlTextEdit"));
        sqlTextEdit->setProperty("readOnly", QVariant(true));
        splitter->addWidget(sqlTextEdit);

        verticalLayout_2->addWidget(splitter);

        labelEditWarning = new QLabel(EditTableDialog);
        labelEditWarning->setObjectName(QString::fromUtf8("labelEditWarning"));
        labelEditWarning->setWordWrap(true);

        verticalLayout_2->addWidget(labelEditWarning);

        buttonBox = new QDialogButtonBox(EditTableDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(comboSchema);
        label_1->setBuddy(checkWithoutRowid);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editTableName, buttonMore);
        QWidget::setTabOrder(buttonMore, comboSchema);
        QWidget::setTabOrder(comboSchema, checkWithoutRowid);
        QWidget::setTabOrder(checkWithoutRowid, groupDefinition);
        QWidget::setTabOrder(groupDefinition, addFieldButton);
        QWidget::setTabOrder(addFieldButton, removeFieldButton);
        QWidget::setTabOrder(removeFieldButton, buttonMoveTop);
        QWidget::setTabOrder(buttonMoveTop, buttonMoveUp);
        QWidget::setTabOrder(buttonMoveUp, buttonMoveDown);
        QWidget::setTabOrder(buttonMoveDown, buttonMoveBottom);
        QWidget::setTabOrder(buttonMoveBottom, treeWidget);
        QWidget::setTabOrder(treeWidget, sqlTextEdit);
        QWidget::setTabOrder(sqlTextEdit, buttonAddConstraint);
        QWidget::setTabOrder(buttonAddConstraint, buttonRemoveConstraint);
        QWidget::setTabOrder(buttonRemoveConstraint, tableConstraints);

        retranslateUi(EditTableDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditTableDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditTableDialog, SLOT(reject()));
        QObject::connect(treeWidget, SIGNAL(itemSelectionChanged()), EditTableDialog, SLOT(fieldSelectionChanged()));
        QObject::connect(addFieldButton, SIGNAL(clicked()), EditTableDialog, SLOT(addField()));
        QObject::connect(removeFieldButton, SIGNAL(clicked()), EditTableDialog, SLOT(removeField()));
        QObject::connect(editTableName, SIGNAL(textChanged(QString)), EditTableDialog, SLOT(checkInput()));
        QObject::connect(buttonMoveUp, SIGNAL(clicked()), EditTableDialog, SLOT(moveUp()));
        QObject::connect(buttonMoveDown, SIGNAL(clicked()), EditTableDialog, SLOT(moveDown()));
        QObject::connect(buttonMore, SIGNAL(toggled(bool)), widgetExtension, SLOT(setVisible(bool)));
        QObject::connect(checkWithoutRowid, SIGNAL(toggled(bool)), EditTableDialog, SLOT(setWithoutRowid(bool)));
        QObject::connect(treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), EditTableDialog, SLOT(fieldSelectionChanged()));
        QObject::connect(comboSchema, SIGNAL(currentIndexChanged(QString)), EditTableDialog, SLOT(changeSchema(QString)));
        QObject::connect(buttonRemoveConstraint, SIGNAL(clicked()), EditTableDialog, SLOT(removeConstraint()));
        QObject::connect(buttonMoveTop, SIGNAL(clicked()), EditTableDialog, SLOT(moveTop()));
        QObject::connect(buttonMoveBottom, SIGNAL(clicked()), EditTableDialog, SLOT(moveBottom()));

        groupDefinition->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditTableDialog);
    } // setupUi

    void retranslateUi(QDialog *EditTableDialog)
    {
        EditTableDialog->setWindowTitle(QApplication::translate("EditTableDialog", "Edit table definition", nullptr));
        actionAddPrimaryKey->setText(QApplication::translate("EditTableDialog", "Primary Key", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAddPrimaryKey->setToolTip(QApplication::translate("EditTableDialog", "Add a primary key constraint", nullptr));
#endif // QT_NO_TOOLTIP
        actionAddForeignKey->setText(QApplication::translate("EditTableDialog", "Foreign Key", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAddForeignKey->setToolTip(QApplication::translate("EditTableDialog", "Add a foreign key constraint", nullptr));
#endif // QT_NO_TOOLTIP
        actionAddUniqueConstraint->setText(QApplication::translate("EditTableDialog", "Unique", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAddUniqueConstraint->setToolTip(QApplication::translate("EditTableDialog", "Add a unique constraint", nullptr));
#endif // QT_NO_TOOLTIP
        actionAddCheckConstraint->setText(QApplication::translate("EditTableDialog", "Check", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAddCheckConstraint->setToolTip(QApplication::translate("EditTableDialog", "Add a check constraint", nullptr));
#endif // QT_NO_TOOLTIP
        groupTable->setTitle(QApplication::translate("EditTableDialog", "Table", nullptr));
        buttonMore->setText(QApplication::translate("EditTableDialog", "Advanced", nullptr));
        label->setText(QApplication::translate("EditTableDialog", "Database sche&ma", nullptr));
        label_1->setText(QApplication::translate("EditTableDialog", "Without Rowid", nullptr));
#ifndef QT_NO_TOOLTIP
        checkWithoutRowid->setToolTip(QApplication::translate("EditTableDialog", "Make this a 'WITHOUT rowid' table. Setting this flag requires a field of type INTEGER with the primary key flag set and the auto increment flag unset.", nullptr));
#endif // QT_NO_TOOLTIP
        addFieldButton->setText(QApplication::translate("EditTableDialog", "Add", nullptr));
        removeFieldButton->setText(QApplication::translate("EditTableDialog", "Remove", nullptr));
        buttonMoveTop->setText(QApplication::translate("EditTableDialog", "Move to top", nullptr));
        buttonMoveUp->setText(QApplication::translate("EditTableDialog", "Move up", nullptr));
        buttonMoveDown->setText(QApplication::translate("EditTableDialog", "Move down", nullptr));
        buttonMoveBottom->setText(QApplication::translate("EditTableDialog", "Move to bottom", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(9, QApplication::translate("EditTableDialog", "Foreign Key", nullptr));
        ___qtreewidgetitem->setText(8, QApplication::translate("EditTableDialog", "Collation", nullptr));
        ___qtreewidgetitem->setText(7, QApplication::translate("EditTableDialog", "Check", nullptr));
        ___qtreewidgetitem->setText(6, QApplication::translate("EditTableDialog", "Default", nullptr));
        ___qtreewidgetitem->setText(5, QApplication::translate("EditTableDialog", "U", nullptr));
        ___qtreewidgetitem->setText(4, QApplication::translate("EditTableDialog", "AI", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("EditTableDialog", "PK", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("EditTableDialog", "NN", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("EditTableDialog", "Type", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("EditTableDialog", "Name", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(7, QApplication::translate("EditTableDialog", "Check constraint", nullptr));
        ___qtreewidgetitem->setToolTip(6, QApplication::translate("EditTableDialog", "Default value", nullptr));
        ___qtreewidgetitem->setToolTip(5, QApplication::translate("EditTableDialog", "Unique", nullptr));
        ___qtreewidgetitem->setToolTip(4, QApplication::translate("EditTableDialog", "Autoincrement", nullptr));
        ___qtreewidgetitem->setToolTip(3, QApplication::translate("EditTableDialog", "Primary key", nullptr));
        ___qtreewidgetitem->setToolTip(2, QApplication::translate("EditTableDialog", "Not null", nullptr));
#endif // QT_NO_TOOLTIP
        groupDefinition->setTabText(groupDefinition->indexOf(groupFieldsPage1), QApplication::translate("EditTableDialog", "Fields", nullptr));
        buttonAddConstraint->setText(QApplication::translate("EditTableDialog", "Add constraint", nullptr));
        buttonRemoveConstraint->setText(QApplication::translate("EditTableDialog", "Remove constraint", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableConstraints->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EditTableDialog", "Columns", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableConstraints->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EditTableDialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableConstraints->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EditTableDialog", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableConstraints->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("EditTableDialog", "SQL", nullptr));
        groupDefinition->setTabText(groupDefinition->indexOf(tab), QApplication::translate("EditTableDialog", "Constraints", nullptr));
        labelEditWarning->setText(QApplication::translate("EditTableDialog", "<html><head/><body><p><span style=\" font-weight:600; color:#ff0000;\">Warning: </span>There is something with this table definition that our parser doesn't fully understand. Modifying and saving this table might result in problems.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditTableDialog: public Ui_EditTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTABLEDIALOG_H
