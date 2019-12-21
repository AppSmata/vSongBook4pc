/********************************************************************************
** Form generated from reading UI file 'RemotePushDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTEPUSHDIALOG_H
#define UI_REMOTEPUSHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RemotePushDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *editName;
    QLabel *label_3;
    QTextEdit *editCommitMessage;
    QLabel *label_2;
    QComboBox *comboLicence;
    QLabel *label_4;
    QCheckBox *checkPublic;
    QLabel *label_5;
    QComboBox *comboBranch;
    QLabel *label_6;
    QCheckBox *checkForce;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RemotePushDialog)
    {
        if (RemotePushDialog->objectName().isEmpty())
            RemotePushDialog->setObjectName(QString::fromUtf8("RemotePushDialog"));
        RemotePushDialog->resize(583, 300);
        verticalLayout = new QVBoxLayout(RemotePushDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(RemotePushDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        editName = new QLineEdit(RemotePushDialog);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setMaxLength(256);

        formLayout->setWidget(0, QFormLayout::FieldRole, editName);

        label_3 = new QLabel(RemotePushDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        editCommitMessage = new QTextEdit(RemotePushDialog);
        editCommitMessage->setObjectName(QString::fromUtf8("editCommitMessage"));
        editCommitMessage->setAcceptRichText(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, editCommitMessage);

        label_2 = new QLabel(RemotePushDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        comboLicence = new QComboBox(RemotePushDialog);
        comboLicence->setObjectName(QString::fromUtf8("comboLicence"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboLicence->sizePolicy().hasHeightForWidth());
        comboLicence->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboLicence);

        label_4 = new QLabel(RemotePushDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        checkPublic = new QCheckBox(RemotePushDialog);
        checkPublic->setObjectName(QString::fromUtf8("checkPublic"));

        formLayout->setWidget(3, QFormLayout::FieldRole, checkPublic);

        label_5 = new QLabel(RemotePushDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        comboBranch = new QComboBox(RemotePushDialog);
        comboBranch->setObjectName(QString::fromUtf8("comboBranch"));
        comboBranch->setEditable(true);
        comboBranch->setDuplicatesEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBranch);

        label_6 = new QLabel(RemotePushDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        checkForce = new QCheckBox(RemotePushDialog);
        checkForce->setObjectName(QString::fromUtf8("checkForce"));

        formLayout->setWidget(5, QFormLayout::FieldRole, checkForce);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(RemotePushDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(editName);
        label_3->setBuddy(editCommitMessage);
        label_2->setBuddy(comboLicence);
        label_4->setBuddy(checkPublic);
        label_5->setBuddy(comboBranch);
        label_6->setBuddy(checkForce);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editName, editCommitMessage);
        QWidget::setTabOrder(editCommitMessage, comboBranch);
        QWidget::setTabOrder(comboBranch, checkPublic);
        QWidget::setTabOrder(checkPublic, comboLicence);

        retranslateUi(RemotePushDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RemotePushDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RemotePushDialog, SLOT(reject()));
        QObject::connect(editName, SIGNAL(textChanged(QString)), RemotePushDialog, SLOT(checkInput()));
        QObject::connect(checkPublic, SIGNAL(toggled(bool)), RemotePushDialog, SLOT(checkInput()));
        QObject::connect(editCommitMessage, SIGNAL(textChanged()), RemotePushDialog, SLOT(checkInput()));
        QObject::connect(editName, SIGNAL(textChanged(QString)), RemotePushDialog, SLOT(reloadBranchList()));
        QObject::connect(comboBranch, SIGNAL(currentTextChanged(QString)), RemotePushDialog, SLOT(checkInput()));
        QObject::connect(checkForce, SIGNAL(toggled(bool)), RemotePushDialog, SLOT(checkInput()));

        QMetaObject::connectSlotsByName(RemotePushDialog);
    } // setupUi

    void retranslateUi(QDialog *RemotePushDialog)
    {
        RemotePushDialog->setWindowTitle(QApplication::translate("RemotePushDialog", "Push database", nullptr));
        label->setText(QApplication::translate("RemotePushDialog", "Database na&me to push to", nullptr));
        label_3->setText(QApplication::translate("RemotePushDialog", "Commit message", nullptr));
        editCommitMessage->setHtml(QApplication::translate("RemotePushDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Oxygen-Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("RemotePushDialog", "Database licence", nullptr));
        label_4->setText(QApplication::translate("RemotePushDialog", "Public", nullptr));
        label_5->setText(QApplication::translate("RemotePushDialog", "Branch", nullptr));
        label_6->setText(QApplication::translate("RemotePushDialog", "Force push", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemotePushDialog: public Ui_RemotePushDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTEPUSHDIALOG_H
