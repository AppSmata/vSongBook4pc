/********************************************************************************
** Form generated from reading UI file 'FileExtensionManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXTENSIONMANAGER_H
#define UI_FILEEXTENSIONMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileExtensionManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonUp;
    QPushButton *buttonDown;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonAdd;
    QPushButton *buttonRemove;
    QTableWidget *tableExtensions;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FileExtensionManager)
    {
        if (FileExtensionManager->objectName().isEmpty())
            FileExtensionManager->setObjectName(QString::fromUtf8("FileExtensionManager"));
        FileExtensionManager->resize(578, 463);
        verticalLayout = new QVBoxLayout(FileExtensionManager);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonUp = new QPushButton(FileExtensionManager);
        buttonUp->setObjectName(QString::fromUtf8("buttonUp"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/up"), QSize(), QIcon::Normal, QIcon::Off);
        buttonUp->setIcon(icon);

        horizontalLayout->addWidget(buttonUp);

        buttonDown = new QPushButton(FileExtensionManager);
        buttonDown->setObjectName(QString::fromUtf8("buttonDown"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/down"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDown->setIcon(icon1);

        horizontalLayout->addWidget(buttonDown);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonAdd = new QPushButton(FileExtensionManager);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/field_add"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAdd->setIcon(icon2);

        horizontalLayout->addWidget(buttonAdd);

        buttonRemove = new QPushButton(FileExtensionManager);
        buttonRemove->setObjectName(QString::fromUtf8("buttonRemove"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/field_delete"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRemove->setIcon(icon3);

        horizontalLayout->addWidget(buttonRemove);


        verticalLayout->addLayout(horizontalLayout);

        tableExtensions = new QTableWidget(FileExtensionManager);
        if (tableExtensions->columnCount() < 2)
            tableExtensions->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableExtensions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableExtensions->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableExtensions->setObjectName(QString::fromUtf8("tableExtensions"));
        tableExtensions->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableExtensions->horizontalHeader()->setStretchLastSection(true);
        tableExtensions->verticalHeader()->setMinimumSectionSize(100);
        tableExtensions->verticalHeader()->setDefaultSectionSize(100);

        verticalLayout->addWidget(tableExtensions);

        buttonBox = new QDialogButtonBox(FileExtensionManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FileExtensionManager);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileExtensionManager, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileExtensionManager, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileExtensionManager);
    } // setupUi

    void retranslateUi(QDialog *FileExtensionManager)
    {
        FileExtensionManager->setWindowTitle(QApplication::translate("FileExtensionManager", "File Extension Manager", nullptr));
        buttonUp->setText(QApplication::translate("FileExtensionManager", "&Up", nullptr));
        buttonDown->setText(QApplication::translate("FileExtensionManager", "&Down", nullptr));
        buttonAdd->setText(QApplication::translate("FileExtensionManager", "&Add", nullptr));
        buttonRemove->setText(QApplication::translate("FileExtensionManager", "&Remove", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableExtensions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FileExtensionManager", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableExtensions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FileExtensionManager", "Extensions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileExtensionManager: public Ui_FileExtensionManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXTENSIONMANAGER_H
