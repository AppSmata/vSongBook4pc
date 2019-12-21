/********************************************************************************
** Form generated from reading UI file 'PlotDock.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTDOCK_H
#define UI_PLOTDOCK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PlotDock
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitterForPlot;
    QTreeWidget *treePlotColumns;
    QCustomPlot *plotWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboLineType;
    QLabel *label_3;
    QComboBox *comboPointShape;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *butSavePlot;
    QToolButton *buttonLoadAllData;

    void setupUi(QDialog *PlotDock)
    {
        if (PlotDock->objectName().isEmpty())
            PlotDock->setObjectName(QString::fromUtf8("PlotDock"));
        PlotDock->resize(515, 553);
        verticalLayout = new QVBoxLayout(PlotDock);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitterForPlot = new QSplitter(PlotDock);
        splitterForPlot->setObjectName(QString::fromUtf8("splitterForPlot"));
        splitterForPlot->setOrientation(Qt::Vertical);
        treePlotColumns = new QTreeWidget(splitterForPlot);
        treePlotColumns->setObjectName(QString::fromUtf8("treePlotColumns"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(treePlotColumns->sizePolicy().hasHeightForWidth());
        treePlotColumns->setSizePolicy(sizePolicy);
        treePlotColumns->setAlternatingRowColors(true);
        treePlotColumns->setColumnCount(4);
        splitterForPlot->addWidget(treePlotColumns);
        treePlotColumns->header()->setDefaultSectionSize(100);
        treePlotColumns->header()->setStretchLastSection(false);
        plotWidget = new QCustomPlot(splitterForPlot);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(plotWidget->sizePolicy().hasHeightForWidth());
        plotWidget->setSizePolicy(sizePolicy1);
        splitterForPlot->addWidget(plotWidget);

        verticalLayout->addWidget(splitterForPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(PlotDock);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        widget = new QWidget(PlotDock);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        comboLineType = new QComboBox(widget);
        comboLineType->addItem(QString());
        comboLineType->addItem(QString());
        comboLineType->addItem(QString());
        comboLineType->addItem(QString());
        comboLineType->addItem(QString());
        comboLineType->addItem(QString());
        comboLineType->setObjectName(QString::fromUtf8("comboLineType"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboLineType->sizePolicy().hasHeightForWidth());
        comboLineType->setSizePolicy(sizePolicy2);
        comboLineType->setMinimumSize(QSize(50, 0));

        horizontalLayout_4->addWidget(comboLineType);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        comboPointShape = new QComboBox(widget);
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->addItem(QString());
        comboPointShape->setObjectName(QString::fromUtf8("comboPointShape"));
        sizePolicy2.setHeightForWidth(comboPointShape->sizePolicy().hasHeightForWidth());
        comboPointShape->setSizePolicy(sizePolicy2);
        comboPointShape->setMinimumSize(QSize(50, 0));

        horizontalLayout_4->addWidget(comboPointShape);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        butSavePlot = new QPushButton(widget);
        butSavePlot->setObjectName(QString::fromUtf8("butSavePlot"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/image_save"), QSize(), QIcon::Normal, QIcon::Off);
        butSavePlot->setIcon(icon);
        butSavePlot->setCheckable(false);
        butSavePlot->setAutoDefault(false);
        butSavePlot->setFlat(false);

        horizontalLayout_4->addWidget(butSavePlot);

        buttonLoadAllData = new QToolButton(widget);
        buttonLoadAllData->setObjectName(QString::fromUtf8("buttonLoadAllData"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/refresh"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLoadAllData->setIcon(icon1);

        horizontalLayout_4->addWidget(buttonLoadAllData);


        horizontalLayout->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(comboLineType);
        label_3->setBuddy(comboPointShape);
#endif // QT_NO_SHORTCUT

        retranslateUi(PlotDock);
        QObject::connect(buttonLoadAllData, SIGNAL(clicked()), PlotDock, SLOT(fetchAllData()));

        comboLineType->setCurrentIndex(1);
        comboPointShape->setCurrentIndex(0);
        butSavePlot->setDefault(false);


        QMetaObject::connectSlotsByName(PlotDock);
    } // setupUi

    void retranslateUi(QDialog *PlotDock)
    {
        PlotDock->setWindowTitle(QApplication::translate("PlotDock", "Plot", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treePlotColumns->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("PlotDock", "Axis Type", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("PlotDock", "Y", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("PlotDock", "X", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("PlotDock", "Columns", nullptr));
#ifndef QT_NO_WHATSTHIS
        treePlotColumns->setWhatsThis(QApplication::translate("PlotDock", "<html><head/><body><p>This pane shows the list of columns of the currently browsed table or the just executed query. You can select the columns that you want to be used as X or Y axis for the plot pane below. The table shows detected axis type that will affect the resulting plot. For the Y axis you can only select numeric columns, but for the X axis you will be able to select:</p><ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Date/Time</span>: strings with format &quot;yyyy-MM-dd hh:mm:ss&quot; or &quot;yyyy-MM-ddThh:mm:ss&quot;</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Date</span>: strings with format &quot;yyyy-MM-dd&quot;</li><li style=\" margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Time</span>: strings with format &quot;hh:mm:ss&quot;</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Label</span>: other string formats. Selecting this column as X axis will produce a Bars plot with the column values as labels for the bars</li><li style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Numeric</span>: integer or real values</li></ul><p>Double-clicking the Y cells you can change the used color for that graph.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        plotWidget->setWhatsThis(QApplication::translate("PlotDock", "Here is a plot drawn when you select the x and y values above.\n"
"\n"
"Click on points to select them in the plot and in the table. Ctrl+Click for selecting a range of points.\n"
"\n"
"Use mouse-wheel for zooming and mouse drag for changing the axis range.\n"
"\n"
"Select the axes or axes labels to drag and zoom only in that orientation.", nullptr));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("PlotDock", "Line type:", nullptr));
        comboLineType->setItemText(0, QApplication::translate("PlotDock", "None", nullptr));
        comboLineType->setItemText(1, QApplication::translate("PlotDock", "Line", nullptr));
        comboLineType->setItemText(2, QApplication::translate("PlotDock", "StepLeft", nullptr));
        comboLineType->setItemText(3, QApplication::translate("PlotDock", "StepRight", nullptr));
        comboLineType->setItemText(4, QApplication::translate("PlotDock", "StepCenter", nullptr));
        comboLineType->setItemText(5, QApplication::translate("PlotDock", "Impulse", nullptr));

        label_3->setText(QApplication::translate("PlotDock", "Point shape:", nullptr));
        comboPointShape->setItemText(0, QApplication::translate("PlotDock", "None", nullptr));
        comboPointShape->setItemText(1, QApplication::translate("PlotDock", "Cross", nullptr));
        comboPointShape->setItemText(2, QApplication::translate("PlotDock", "Plus", nullptr));
        comboPointShape->setItemText(3, QApplication::translate("PlotDock", "Circle", nullptr));
        comboPointShape->setItemText(4, QApplication::translate("PlotDock", "Disc", nullptr));
        comboPointShape->setItemText(5, QApplication::translate("PlotDock", "Square", nullptr));
        comboPointShape->setItemText(6, QApplication::translate("PlotDock", "Diamond", nullptr));
        comboPointShape->setItemText(7, QApplication::translate("PlotDock", "Star", nullptr));
        comboPointShape->setItemText(8, QApplication::translate("PlotDock", "Triangle", nullptr));
        comboPointShape->setItemText(9, QApplication::translate("PlotDock", "TriangleInverted", nullptr));
        comboPointShape->setItemText(10, QApplication::translate("PlotDock", "CrossSquare", nullptr));
        comboPointShape->setItemText(11, QApplication::translate("PlotDock", "PlusSquare", nullptr));
        comboPointShape->setItemText(12, QApplication::translate("PlotDock", "CrossCircle", nullptr));
        comboPointShape->setItemText(13, QApplication::translate("PlotDock", "PlusCircle", nullptr));
        comboPointShape->setItemText(14, QApplication::translate("PlotDock", "Peace", nullptr));

#ifndef QT_NO_TOOLTIP
        butSavePlot->setToolTip(QApplication::translate("PlotDock", "<html><head/><body><p>Save current plot...</p><p>File format chosen by extension (png, jpg, pdf, bmp)</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        butSavePlot->setStatusTip(QApplication::translate("PlotDock", "Save current plot...", nullptr));
#endif // QT_NO_STATUSTIP
        butSavePlot->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonLoadAllData->setToolTip(QApplication::translate("PlotDock", "Load all data and redraw plot", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class PlotDock: public Ui_PlotDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDOCK_H
