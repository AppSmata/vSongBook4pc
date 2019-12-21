/********************************************************************************
** Form generated from reading UI file 'CipherDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIPHERDIALOG_H
#define UI_CIPHERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CipherDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *labelDialogDescription;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *labelPassword;
    QLineEdit *editPassword;
    QLabel *labelPassword2;
    QLineEdit *editPassword2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboKeyFormat;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioEncryptionSqlCipher3;
    QRadioButton *radioEncryptionSqlCipher4;
    QRadioButton *radioEncryptionCustom;
    QLabel *label_3;
    QComboBox *comboPageSize;
    QLabel *label_2;
    QSpinBox *spinKdfIterations;
    QLabel *label_4;
    QComboBox *comboHmacAlgorithm;
    QLabel *label_5;
    QComboBox *comboKdfAlgorithm;
    QLabel *label_6;
    QSpinBox *plaintextHeaderSize;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CipherDialog)
    {
        if (CipherDialog->objectName().isEmpty())
            CipherDialog->setObjectName(QString::fromUtf8("CipherDialog"));
        CipherDialog->resize(712, 299);
        verticalLayout_2 = new QVBoxLayout(CipherDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelDialogDescription = new QLabel(CipherDialog);
        labelDialogDescription->setObjectName(QString::fromUtf8("labelDialogDescription"));

        verticalLayout_2->addWidget(labelDialogDescription);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelPassword = new QLabel(CipherDialog);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPassword);

        editPassword = new QLineEdit(CipherDialog);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, editPassword);

        labelPassword2 = new QLabel(CipherDialog);
        labelPassword2->setObjectName(QString::fromUtf8("labelPassword2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword2);

        editPassword2 = new QLineEdit(CipherDialog);
        editPassword2->setObjectName(QString::fromUtf8("editPassword2"));
        editPassword2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, editPassword2);


        horizontalLayout_2->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboKeyFormat = new QComboBox(CipherDialog);
        comboKeyFormat->addItem(QString());
        comboKeyFormat->addItem(QString());
        comboKeyFormat->setObjectName(QString::fromUtf8("comboKeyFormat"));

        verticalLayout->addWidget(comboKeyFormat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(CipherDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioEncryptionSqlCipher3 = new QRadioButton(CipherDialog);
        radioEncryptionSqlCipher3->setObjectName(QString::fromUtf8("radioEncryptionSqlCipher3"));

        horizontalLayout->addWidget(radioEncryptionSqlCipher3);

        radioEncryptionSqlCipher4 = new QRadioButton(CipherDialog);
        radioEncryptionSqlCipher4->setObjectName(QString::fromUtf8("radioEncryptionSqlCipher4"));

        horizontalLayout->addWidget(radioEncryptionSqlCipher4);

        radioEncryptionCustom = new QRadioButton(CipherDialog);
        radioEncryptionCustom->setObjectName(QString::fromUtf8("radioEncryptionCustom"));

        horizontalLayout->addWidget(radioEncryptionCustom);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_3 = new QLabel(CipherDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        comboPageSize = new QComboBox(CipherDialog);
        comboPageSize->setObjectName(QString::fromUtf8("comboPageSize"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboPageSize);

        label_2 = new QLabel(CipherDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        spinKdfIterations = new QSpinBox(CipherDialog);
        spinKdfIterations->setObjectName(QString::fromUtf8("spinKdfIterations"));
        spinKdfIterations->setMinimum(1);
        spinKdfIterations->setMaximum(1000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinKdfIterations);

        label_4 = new QLabel(CipherDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        comboHmacAlgorithm = new QComboBox(CipherDialog);
        comboHmacAlgorithm->addItem(QString::fromUtf8("SHA512"));
        comboHmacAlgorithm->addItem(QString::fromUtf8("SHA256"));
        comboHmacAlgorithm->addItem(QString::fromUtf8("SHA1"));
        comboHmacAlgorithm->setObjectName(QString::fromUtf8("comboHmacAlgorithm"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, comboHmacAlgorithm);

        label_5 = new QLabel(CipherDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        comboKdfAlgorithm = new QComboBox(CipherDialog);
        comboKdfAlgorithm->addItem(QString::fromUtf8("SHA512"));
        comboKdfAlgorithm->addItem(QString::fromUtf8("SHA256"));
        comboKdfAlgorithm->addItem(QString::fromUtf8("SHA1"));
        comboKdfAlgorithm->setObjectName(QString::fromUtf8("comboKdfAlgorithm"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, comboKdfAlgorithm);

        label_6 = new QLabel(CipherDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_6);

        plaintextHeaderSize = new QSpinBox(CipherDialog);
        plaintextHeaderSize->setObjectName(QString::fromUtf8("plaintextHeaderSize"));
        plaintextHeaderSize->setMinimum(0);
        plaintextHeaderSize->setMaximum(1000000);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, plaintextHeaderSize);


        verticalLayout_2->addLayout(formLayout_2);

        buttonBox = new QDialogButtonBox(CipherDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelPassword->setBuddy(editPassword);
        labelPassword2->setBuddy(editPassword2);
        label->setBuddy(radioEncryptionSqlCipher3);
        label_3->setBuddy(comboPageSize);
        label_2->setBuddy(spinKdfIterations);
        label_4->setBuddy(comboHmacAlgorithm);
        label_5->setBuddy(comboKdfAlgorithm);
        label_6->setBuddy(plaintextHeaderSize);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editPassword, editPassword2);
        QWidget::setTabOrder(editPassword2, comboKeyFormat);
        QWidget::setTabOrder(comboKeyFormat, radioEncryptionSqlCipher3);
        QWidget::setTabOrder(radioEncryptionSqlCipher3, radioEncryptionSqlCipher4);
        QWidget::setTabOrder(radioEncryptionSqlCipher4, radioEncryptionCustom);
        QWidget::setTabOrder(radioEncryptionCustom, comboPageSize);
        QWidget::setTabOrder(comboPageSize, spinKdfIterations);
        QWidget::setTabOrder(spinKdfIterations, comboHmacAlgorithm);
        QWidget::setTabOrder(comboHmacAlgorithm, comboKdfAlgorithm);
        QWidget::setTabOrder(comboKdfAlgorithm, plaintextHeaderSize);

        retranslateUi(CipherDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CipherDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CipherDialog, SLOT(reject()));
        QObject::connect(editPassword, SIGNAL(textChanged(QString)), CipherDialog, SLOT(checkInputFields()));
        QObject::connect(editPassword2, SIGNAL(textChanged(QString)), CipherDialog, SLOT(checkInputFields()));
        QObject::connect(comboKeyFormat, SIGNAL(currentIndexChanged(int)), CipherDialog, SLOT(checkInputFields()));
        QObject::connect(radioEncryptionSqlCipher3, SIGNAL(toggled(bool)), CipherDialog, SLOT(toggleEncryptionSettings()));
        QObject::connect(radioEncryptionSqlCipher4, SIGNAL(toggled(bool)), CipherDialog, SLOT(toggleEncryptionSettings()));
        QObject::connect(radioEncryptionCustom, SIGNAL(toggled(bool)), CipherDialog, SLOT(toggleEncryptionSettings()));

        QMetaObject::connectSlotsByName(CipherDialog);
    } // setupUi

    void retranslateUi(QDialog *CipherDialog)
    {
        CipherDialog->setWindowTitle(QApplication::translate("CipherDialog", "SQLCipher encryption", nullptr));
        labelPassword->setText(QApplication::translate("CipherDialog", "&Password", nullptr));
        labelPassword2->setText(QApplication::translate("CipherDialog", "&Reenter password", nullptr));
        comboKeyFormat->setItemText(0, QApplication::translate("CipherDialog", "Passphrase", nullptr));
        comboKeyFormat->setItemText(1, QApplication::translate("CipherDialog", "Raw key", nullptr));

        label->setText(QApplication::translate("CipherDialog", "Encr&yption settings", nullptr));
        radioEncryptionSqlCipher3->setText(QApplication::translate("CipherDialog", "SQLCipher &3 defaults", nullptr));
        radioEncryptionSqlCipher4->setText(QApplication::translate("CipherDialog", "SQLCipher &4 defaults", nullptr));
        radioEncryptionCustom->setText(QApplication::translate("CipherDialog", "Custo&m", nullptr));
        label_3->setText(QApplication::translate("CipherDialog", "Page si&ze", nullptr));
        label_2->setText(QApplication::translate("CipherDialog", "&KDF iterations", nullptr));
        label_4->setText(QApplication::translate("CipherDialog", "HMAC algorithm", nullptr));

        label_5->setText(QApplication::translate("CipherDialog", "KDF algorithm", nullptr));

        label_6->setText(QApplication::translate("CipherDialog", "Plaintext Header Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CipherDialog: public Ui_CipherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIPHERDIALOG_H
