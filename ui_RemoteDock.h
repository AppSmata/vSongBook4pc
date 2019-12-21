/********************************************************************************
** Form generated from reading UI file 'RemoteDock.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTEDOCK_H
#define UI_REMOTEDOCK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteDock
{
public:
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stack;
    QWidget *pageMain;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboUser;
    QToolButton *buttonLogin;
    QSpacerItem *horizontalSpacer;
    QToolButton *buttonPushDatabase;
    QTreeView *treeStructure;
    QWidget *pageNoCerts;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNoCert;
    QCommandLinkButton *buttonNoCertBack;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *RemoteDock)
    {
        if (RemoteDock->objectName().isEmpty())
            RemoteDock->setObjectName(QString::fromUtf8("RemoteDock"));
        RemoteDock->resize(534, 298);
        horizontalLayout_2 = new QHBoxLayout(RemoteDock);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stack = new QStackedWidget(RemoteDock);
        stack->setObjectName(QString::fromUtf8("stack"));
        pageMain = new QWidget();
        pageMain->setObjectName(QString::fromUtf8("pageMain"));
        verticalLayout = new QVBoxLayout(pageMain);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(pageMain);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboUser = new QComboBox(pageMain);
        comboUser->setObjectName(QString::fromUtf8("comboUser"));
        comboUser->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(comboUser);

        buttonLogin = new QToolButton(pageMain);
        buttonLogin->setObjectName(QString::fromUtf8("buttonLogin"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/cog_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLogin->setIcon(icon);

        horizontalLayout->addWidget(buttonLogin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonPushDatabase = new QToolButton(pageMain);
        buttonPushDatabase->setObjectName(QString::fromUtf8("buttonPushDatabase"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/push_database"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPushDatabase->setIcon(icon1);

        horizontalLayout->addWidget(buttonPushDatabase);


        verticalLayout->addLayout(horizontalLayout);

        treeStructure = new QTreeView(pageMain);
        treeStructure->setObjectName(QString::fromUtf8("treeStructure"));

        verticalLayout->addWidget(treeStructure);

        stack->addWidget(pageMain);
        pageNoCerts = new QWidget();
        pageNoCerts->setObjectName(QString::fromUtf8("pageNoCerts"));
        verticalLayout_3 = new QVBoxLayout(pageNoCerts);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelNoCert = new QLabel(pageNoCerts);
        labelNoCert->setObjectName(QString::fromUtf8("labelNoCert"));
        labelNoCert->setWordWrap(true);

        verticalLayout_2->addWidget(labelNoCert);

        buttonNoCertBack = new QCommandLinkButton(pageNoCerts);
        buttonNoCertBack->setObjectName(QString::fromUtf8("buttonNoCertBack"));

        verticalLayout_2->addWidget(buttonNoCertBack);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stack->addWidget(pageNoCerts);

        horizontalLayout_2->addWidget(stack);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(comboUser);
#endif // QT_NO_SHORTCUT

        retranslateUi(RemoteDock);
        QObject::connect(buttonLogin, SIGNAL(clicked()), RemoteDock, SLOT(setNewIdentity()));
        QObject::connect(treeStructure, SIGNAL(doubleClicked(QModelIndex)), RemoteDock, SLOT(fetchDatabase(QModelIndex)));
        QObject::connect(buttonPushDatabase, SIGNAL(clicked()), RemoteDock, SLOT(pushDatabase()));
        QObject::connect(buttonNoCertBack, SIGNAL(clicked()), RemoteDock, SLOT(switchToMainView()));

        stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RemoteDock);
    } // setupUi

    void retranslateUi(QDialog *RemoteDock)
    {
        RemoteDock->setWindowTitle(QApplication::translate("RemoteDock", "Remote", nullptr));
        label_2->setText(QApplication::translate("RemoteDock", "Identity", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonLogin->setToolTip(QApplication::translate("RemoteDock", "Connect to the remote server using the currently selected identity. The correct server is taken from the identity as well.", nullptr));
#endif // QT_NO_TOOLTIP
        buttonLogin->setText(QApplication::translate("RemoteDock", "Go", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonPushDatabase->setToolTip(QApplication::translate("RemoteDock", "Push currently opened database to server", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        treeStructure->setWhatsThis(QApplication::translate("RemoteDock", "<html><head/><body><p>In this pane, remote databases from dbhub.io website can be added to DB4S. First you need an identity:</p><ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Login to the dbhub.io website (use your GitHub credentials or whatever you want)</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Click the button to create a DB4S certificate (that's your identity). That'll give you a certificate file (save it to your local disk).</li><li style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Go to the Remote tab in DB4S Preferences. Click the button to add a new certificate to DB4S and choose the just downloaded certificate file.</li></ol><p>Now the Remote panel shows your identity an"
                        "d you can add remote databases.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        labelNoCert->setText(QApplication::translate("RemoteDock", "<html><head/><body><p>You are currently using a built-in, read-only identity. For uploading your database, you need to configure and use your DBHub.io account.</p><p>No DBHub.io account yet? <a href=\"https://dbhub.io/\"><span style=\" text-decoration: underline; color:#007af4;\">Create one now</span></a> and import your certificate <a href=\"#preferences\"><span style=\" text-decoration: underline; color:#007af4;\">here</span></a> to share your databases.</p><p>For online help visit <a href=\"https://dbhub.io/about\"><span style=\" text-decoration: underline; color:#007af4;\">here</span></a>.</p></body></html>", nullptr));
        buttonNoCertBack->setText(QApplication::translate("RemoteDock", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteDock: public Ui_RemoteDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTEDOCK_H
