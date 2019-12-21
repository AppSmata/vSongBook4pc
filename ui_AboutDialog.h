/********************************************************************************
** Form generated from reading UI file 'AboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_version;
    QSpacerItem *verticalSpacer;
    QLabel *label_imagelogo;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(653, 502);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/appicon"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        AboutDialog->setSizeGripEnabled(false);
        verticalLayout_2 = new QVBoxLayout(AboutDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_version = new QLabel(AboutDialog);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setMargin(5);
        label_version->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout->addWidget(label_version);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        label_imagelogo = new QLabel(AboutDialog);
        label_imagelogo->setObjectName(QString::fromUtf8("label_imagelogo"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_imagelogo->sizePolicy().hasHeightForWidth());
        label_imagelogo->setSizePolicy(sizePolicy);
        label_imagelogo->setMaximumSize(QSize(128, 128));
        label_imagelogo->setPixmap(QPixmap(QString::fromUtf8(":/icons/appicon")));
        label_imagelogo->setScaledContents(true);

        horizontalLayout->addWidget(label_imagelogo);


        verticalLayout_2->addLayout(horizontalLayout);

        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label);

        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About vSongBook", nullptr));
        label_version->setText(QApplication::translate("AboutDialog", "Version", nullptr));
        label_imagelogo->setText(QString());
        label->setText(QApplication::translate("AboutDialog", "<html><head/><body><p>vSongBook is an open source, freeware visual tool used to create, design and edit SQLite database files.</p><p>It is bi-licensed under the Mozilla Public License Version 2, as well as the GNU General Public License Version 3 or later. You can modify or redistribute it under the conditions of these licenses.</p><p>See <a href=\"http://www.gnu.org/licenses/gpl.html\">http://www.gnu.org/licenses/gpl.html</a> and <a href=\"https://www.mozilla.org/MPL/2.0/index.txt\">https://www.mozilla.org/MPL/2.0/index.txt</a> for details.</p><p>For more information on this program please visit our website at: <a href=\"http://vSongBook.org\">http://vSongBook.org</a></p><p><span style=\" font-size:small;\">This software uses the GPL/LGPL Qt Toolkit from </span><a href=\"http://qt-project.org/\"><span style=\" font-size:small;\">http://qt-project.org/</span></a><span style=\" font-size:small;\"><br/>See </span><a href=\"http://qt-project.org/doc/qt-5/licensing.html\"><span style=\" font-size:small;\">http://q"
                        "t-project.org/doc/qt-5/licensing.html</span></a><span style=\" font-size:small;\"> for licensing terms and information.</span></p><p><span style=\" font-size:small;\">It also uses the Silk icon set by Mark James licensed under a Creative Commons Attribution 2.5 and 3.0 license.<br/>See </span><a href=\"http://www.famfamfam.com/lab/icons/silk/\"><span style=\" font-size:small;\">http://www.famfamfam.com/lab/icons/silk/</span></a><span style=\" font-size:small;\"> for details.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
