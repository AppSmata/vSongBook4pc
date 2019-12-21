/********************************************************************************
** Form generated from reading UI file 'SelectItemsPopup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTITEMSPOPUP_H
#define UI_SELECTITEMSPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectItemsPopup
{
public:
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *spacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listAvailable;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QToolButton *buttonSelect;
    QToolButton *buttonUnselect;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listSelected;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QToolButton *buttonUp;
    QToolButton *buttonDown;
    QSpacerItem *verticalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelectItemsPopup)
    {
        if (SelectItemsPopup->objectName().isEmpty())
            SelectItemsPopup->setObjectName(QString::fromUtf8("SelectItemsPopup"));
        SelectItemsPopup->resize(537, 290);
        verticalLayout_5 = new QVBoxLayout(SelectItemsPopup);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        spacer = new QSpacerItem(0, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(spacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SelectItemsPopup);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listAvailable = new QListWidget(SelectItemsPopup);
        listAvailable->setObjectName(QString::fromUtf8("listAvailable"));
        listAvailable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listAvailable->setProperty("showDropIndicator", QVariant(false));
        listAvailable->setAlternatingRowColors(true);

        verticalLayout->addWidget(listAvailable);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        buttonSelect = new QToolButton(SelectItemsPopup);
        buttonSelect->setObjectName(QString::fromUtf8("buttonSelect"));
        buttonSelect->setArrowType(Qt::RightArrow);

        verticalLayout_3->addWidget(buttonSelect);

        buttonUnselect = new QToolButton(SelectItemsPopup);
        buttonUnselect->setObjectName(QString::fromUtf8("buttonUnselect"));
        buttonUnselect->setArrowType(Qt::LeftArrow);

        verticalLayout_3->addWidget(buttonUnselect);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(SelectItemsPopup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        listSelected = new QListWidget(SelectItemsPopup);
        listSelected->setObjectName(QString::fromUtf8("listSelected"));
        listSelected->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listSelected->setProperty("showDropIndicator", QVariant(false));
        listSelected->setDragDropMode(QAbstractItemView::InternalMove);
        listSelected->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(listSelected);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        buttonUp = new QToolButton(SelectItemsPopup);
        buttonUp->setObjectName(QString::fromUtf8("buttonUp"));
        buttonUp->setArrowType(Qt::UpArrow);

        verticalLayout_4->addWidget(buttonUp);

        buttonDown = new QToolButton(SelectItemsPopup);
        buttonDown->setObjectName(QString::fromUtf8("buttonDown"));
        buttonDown->setArrowType(Qt::DownArrow);

        verticalLayout_4->addWidget(buttonDown);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(SelectItemsPopup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel);

        verticalLayout_5->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(listAvailable);
        label_2->setBuddy(listSelected);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(listAvailable, listSelected);
        QWidget::setTabOrder(listSelected, buttonSelect);
        QWidget::setTabOrder(buttonSelect, buttonUnselect);

        retranslateUi(SelectItemsPopup);
        QObject::connect(buttonSelect, SIGNAL(clicked()), SelectItemsPopup, SLOT(selectItem()));
        QObject::connect(buttonUnselect, SIGNAL(clicked()), SelectItemsPopup, SLOT(unselectItem()));
        QObject::connect(listAvailable, SIGNAL(doubleClicked(QModelIndex)), SelectItemsPopup, SLOT(selectItem(QModelIndex)));
        QObject::connect(listSelected, SIGNAL(doubleClicked(QModelIndex)), SelectItemsPopup, SLOT(unselectItem(QModelIndex)));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectItemsPopup, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), SelectItemsPopup, SLOT(buttonBoxClicked(QAbstractButton*)));
        QObject::connect(buttonDown, SIGNAL(clicked()), SelectItemsPopup, SLOT(moveItemDown()));
        QObject::connect(buttonUp, SIGNAL(clicked()), SelectItemsPopup, SLOT(moveItemUp()));

        QMetaObject::connectSlotsByName(SelectItemsPopup);
    } // setupUi

    void retranslateUi(QDialog *SelectItemsPopup)
    {
        label->setText(QApplication::translate("SelectItemsPopup", "A&vailable", nullptr));
        label_2->setText(QApplication::translate("SelectItemsPopup", "Sele&cted", nullptr));
        Q_UNUSED(SelectItemsPopup);
    } // retranslateUi

};

namespace Ui {
    class SelectItemsPopup: public Ui_SelectItemsPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTITEMSPOPUP_H
