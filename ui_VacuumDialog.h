/********************************************************************************
** Form generated from reading UI file 'VacuumDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACUUMDIALOG_H
#define UI_VACUUMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VacuumDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelSavepointWarning;
    QLabel *label;
    QTreeWidget *treeDatabases;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VacuumDialog)
    {
        if (VacuumDialog->objectName().isEmpty())
            VacuumDialog->setObjectName(QString::fromUtf8("VacuumDialog"));
        VacuumDialog->resize(475, 439);
        verticalLayout = new QVBoxLayout(VacuumDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelSavepointWarning = new QLabel(VacuumDialog);
        labelSavepointWarning->setObjectName(QString::fromUtf8("labelSavepointWarning"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelSavepointWarning->setFont(font);
        labelSavepointWarning->setWordWrap(true);
        labelSavepointWarning->setMargin(5);

        verticalLayout->addWidget(labelSavepointWarning);

        label = new QLabel(VacuumDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        treeDatabases = new QTreeWidget(VacuumDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeDatabases->setHeaderItem(__qtreewidgetitem);
        treeDatabases->setObjectName(QString::fromUtf8("treeDatabases"));
        treeDatabases->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeDatabases->setProperty("showDropIndicator", QVariant(false));
        treeDatabases->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeDatabases->setRootIsDecorated(false);
        treeDatabases->setItemsExpandable(false);
        treeDatabases->setExpandsOnDoubleClick(false);
        treeDatabases->header()->setVisible(false);

        verticalLayout->addWidget(treeDatabases);

        buttonBox = new QDialogButtonBox(VacuumDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(treeDatabases);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(treeDatabases, buttonBox);

        retranslateUi(VacuumDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VacuumDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VacuumDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VacuumDialog);
    } // setupUi

    void retranslateUi(QDialog *VacuumDialog)
    {
        VacuumDialog->setWindowTitle(QApplication::translate("VacuumDialog", "Compact Database", nullptr));
        labelSavepointWarning->setText(QApplication::translate("VacuumDialog", "Warning: Compacting the database will commit all of your changes.", nullptr));
        label->setText(QApplication::translate("VacuumDialog", "Please select the databases to co&mpact:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VacuumDialog: public Ui_VacuumDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACUUMDIALOG_H
