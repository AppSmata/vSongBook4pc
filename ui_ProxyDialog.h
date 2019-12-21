/********************************************************************************
** Form generated from reading UI file 'ProxyDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROXYDIALOG_H
#define UI_PROXYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProxyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboType;
    QLabel *label_2;
    QLineEdit *editHost;
    QLabel *label_3;
    QSpinBox *spinPort;
    QLabel *label_6;
    QCheckBox *checkAuthentication;
    QLabel *label_4;
    QLineEdit *editUser;
    QLabel *label_5;
    QLineEdit *editPassword;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ProxyDialog)
    {
        if (ProxyDialog->objectName().isEmpty())
            ProxyDialog->setObjectName(QString::fromUtf8("ProxyDialog"));
        ProxyDialog->resize(535, 231);
        verticalLayout = new QVBoxLayout(ProxyDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(ProxyDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboType = new QComboBox(ProxyDialog);
        comboType->setObjectName(QString::fromUtf8("comboType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboType);

        label_2 = new QLabel(ProxyDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        editHost = new QLineEdit(ProxyDialog);
        editHost->setObjectName(QString::fromUtf8("editHost"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editHost);

        label_3 = new QLabel(ProxyDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinPort = new QSpinBox(ProxyDialog);
        spinPort->setObjectName(QString::fromUtf8("spinPort"));
        spinPort->setMinimum(1);
        spinPort->setMaximum(65536);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinPort);

        label_6 = new QLabel(ProxyDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        checkAuthentication = new QCheckBox(ProxyDialog);
        checkAuthentication->setObjectName(QString::fromUtf8("checkAuthentication"));

        formLayout->setWidget(3, QFormLayout::FieldRole, checkAuthentication);

        label_4 = new QLabel(ProxyDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        editUser = new QLineEdit(ProxyDialog);
        editUser->setObjectName(QString::fromUtf8("editUser"));

        formLayout->setWidget(4, QFormLayout::FieldRole, editUser);

        label_5 = new QLabel(ProxyDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        editPassword = new QLineEdit(ProxyDialog);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(5, QFormLayout::FieldRole, editPassword);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ProxyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(comboType);
        label_2->setBuddy(editHost);
        label_3->setBuddy(spinPort);
        label_6->setBuddy(checkAuthentication);
        label_4->setBuddy(editUser);
        label_5->setBuddy(editPassword);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboType, editHost);
        QWidget::setTabOrder(editHost, spinPort);
        QWidget::setTabOrder(spinPort, checkAuthentication);
        QWidget::setTabOrder(checkAuthentication, editUser);
        QWidget::setTabOrder(editUser, editPassword);

        retranslateUi(ProxyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ProxyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ProxyDialog, SLOT(reject()));
        QObject::connect(comboType, SIGNAL(currentIndexChanged(int)), ProxyDialog, SLOT(proxyTypeChanged(int)));
        QObject::connect(checkAuthentication, SIGNAL(toggled(bool)), ProxyDialog, SLOT(authenticationRequiredChanged(bool)));

        QMetaObject::connectSlotsByName(ProxyDialog);
    } // setupUi

    void retranslateUi(QDialog *ProxyDialog)
    {
        ProxyDialog->setWindowTitle(QApplication::translate("ProxyDialog", "Proxy Configuration", nullptr));
        label->setText(QApplication::translate("ProxyDialog", "Pro&xy Type", nullptr));
        label_2->setText(QApplication::translate("ProxyDialog", "Host Na&me", nullptr));
        label_3->setText(QApplication::translate("ProxyDialog", "Port", nullptr));
        label_6->setText(QApplication::translate("ProxyDialog", "Authentication Re&quired", nullptr));
        label_4->setText(QApplication::translate("ProxyDialog", "&User Name", nullptr));
        label_5->setText(QApplication::translate("ProxyDialog", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProxyDialog: public Ui_ProxyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROXYDIALOG_H
