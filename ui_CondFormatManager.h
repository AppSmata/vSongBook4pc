/********************************************************************************
** Form generated from reading UI file 'CondFormatManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONDFORMATMANAGER_H
#define UI_CONDFORMATMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CondFormatManager
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QHBoxLayout *horizontalLayout;
    QToolButton *buttonAdd;
    QToolButton *buttonRemove;
    QToolButton *buttonUp;
    QToolButton *buttonDown;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *tableCondFormats;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CondFormatManager)
    {
        if (CondFormatManager->objectName().isEmpty())
            CondFormatManager->setObjectName(QString::fromUtf8("CondFormatManager"));
        CondFormatManager->resize(750, 400);
        verticalLayout = new QVBoxLayout(CondFormatManager);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitle = new QLabel(CondFormatManager);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setWordWrap(true);

        verticalLayout->addWidget(labelTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonAdd = new QToolButton(CondFormatManager);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/field_add"), QSize(), QIcon::Normal, QIcon::Off);
        buttonAdd->setIcon(icon);
        buttonAdd->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonAdd->setAutoRaise(true);

        horizontalLayout->addWidget(buttonAdd);

        buttonRemove = new QToolButton(CondFormatManager);
        buttonRemove->setObjectName(QString::fromUtf8("buttonRemove"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/field_delete"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRemove->setIcon(icon1);
        buttonRemove->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonRemove->setAutoRaise(true);

        horizontalLayout->addWidget(buttonRemove);

        buttonUp = new QToolButton(CondFormatManager);
        buttonUp->setObjectName(QString::fromUtf8("buttonUp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/up"), QSize(), QIcon::Normal, QIcon::Off);
        buttonUp->setIcon(icon2);
        buttonUp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonUp->setAutoRaise(true);

        horizontalLayout->addWidget(buttonUp);

        buttonDown = new QToolButton(CondFormatManager);
        buttonDown->setObjectName(QString::fromUtf8("buttonDown"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/down"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDown->setIcon(icon3);
        buttonDown->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        buttonDown->setAutoRaise(true);

        horizontalLayout->addWidget(buttonDown);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableCondFormats = new QTreeWidget(CondFormatManager);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/text_bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        tableCondFormats->headerItem()->setText(4, QString());
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/text_italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        tableCondFormats->headerItem()->setText(5, QString());
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/text_underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        tableCondFormats->headerItem()->setText(6, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setIcon(6, icon6);
        __qtreewidgetitem->setIcon(5, icon5);
        __qtreewidgetitem->setIcon(4, icon4);
        tableCondFormats->setHeaderItem(__qtreewidgetitem);
        tableCondFormats->setObjectName(QString::fromUtf8("tableCondFormats"));
        tableCondFormats->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableCondFormats->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tableCondFormats->setTabKeyNavigation(true);
        tableCondFormats->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableCondFormats->setIndentation(0);
        tableCondFormats->setRootIsDecorated(false);
        tableCondFormats->setUniformRowHeights(true);
        tableCondFormats->setItemsExpandable(false);
        tableCondFormats->setExpandsOnDoubleClick(false);
        tableCondFormats->header()->setMinimumSectionSize(25);

        verticalLayout->addWidget(tableCondFormats);

        buttonBox = new QDialogButtonBox(CondFormatManager);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CondFormatManager);
        QObject::connect(buttonBox, SIGNAL(accepted()), CondFormatManager, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CondFormatManager, SLOT(reject()));

        QMetaObject::connectSlotsByName(CondFormatManager);
    } // setupUi

    void retranslateUi(QDialog *CondFormatManager)
    {
        CondFormatManager->setWindowTitle(QApplication::translate("CondFormatManager", "Conditional Format Manager", nullptr));
        labelTitle->setText(QApplication::translate("CondFormatManager", "This dialog allows creating and editing conditional formats. Each cell style will be selected by the first accomplished condition for that cell data. Conditional formats can be moved up and down, where those at higher rows take precedence over those at lower. Syntax for conditions is the same as for filters and an empty condition applies to all values.", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonAdd->setToolTip(QApplication::translate("CondFormatManager", "Add new conditional format", nullptr));
#endif // QT_NO_TOOLTIP
        buttonAdd->setText(QApplication::translate("CondFormatManager", "&Add", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonRemove->setToolTip(QApplication::translate("CondFormatManager", "Remove selected conditional format", nullptr));
#endif // QT_NO_TOOLTIP
        buttonRemove->setText(QApplication::translate("CondFormatManager", "&Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonUp->setToolTip(QApplication::translate("CondFormatManager", "Move selected conditional format up", nullptr));
#endif // QT_NO_TOOLTIP
        buttonUp->setText(QApplication::translate("CondFormatManager", "Move &up", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonDown->setToolTip(QApplication::translate("CondFormatManager", "Move selected conditional format down", nullptr));
#endif // QT_NO_TOOLTIP
        buttonDown->setText(QApplication::translate("CondFormatManager", "Move &down", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tableCondFormats->headerItem();
        ___qtreewidgetitem->setText(8, QApplication::translate("CondFormatManager", "Condition", nullptr));
        ___qtreewidgetitem->setText(7, QApplication::translate("CondFormatManager", "Alignment", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("CondFormatManager", "Size", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("CondFormatManager", "Font", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("CondFormatManager", "Background", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("CondFormatManager", "Foreground", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(6, QApplication::translate("CondFormatManager", "Underline", nullptr));
        ___qtreewidgetitem->setToolTip(5, QApplication::translate("CondFormatManager", "Italic", nullptr));
        ___qtreewidgetitem->setToolTip(4, QApplication::translate("CondFormatManager", "Bold", nullptr));
        ___qtreewidgetitem->setToolTip(1, QApplication::translate("CondFormatManager", "Background color", nullptr));
        ___qtreewidgetitem->setToolTip(0, QApplication::translate("CondFormatManager", "Text color", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class CondFormatManager: public Ui_CondFormatManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONDFORMATMANAGER_H
