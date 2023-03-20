/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLCDNumber *ln_rssi;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QChartView *chartTemp;
    QChartView *chartPressure;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *ln_kpa;
    QLabel *label_4;
    QLCDNumber *ln_atm;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLCDNumber *ln_temp;
    QLabel *label_6;
    QTextBrowser *tb_output;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbPorts;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_openSerialPort;
    QPushButton *btn_closePort;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(848, 612);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setSizeIncrement(QSize(9, 9));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(197, 104, 216, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        QBrush brush2(QColor(90, 90, 90, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(131, 131, 131, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        QBrush brush5(QColor(143, 76, 156, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush6(QColor(215, 253, 254, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        QBrush brush7(QColor(209, 208, 216, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        QBrush brush8(QColor(239, 239, 239, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        QBrush brush9(QColor(118, 118, 118, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        QBrush brush10(QColor(48, 140, 198, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        QBrush brush11(QColor(247, 247, 247, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        QBrush brush12(QColor(255, 255, 220, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush12);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        QBrush brush14(QColor(190, 190, 190, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        QBrush brush15(QColor(177, 177, 177, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        QBrush brush16(QColor(145, 145, 145, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush12);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMaximumSize(QSize(128, 128));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/logos/norasat.png")));
        label_8->setScaledContents(true);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(72);
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 0, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic"));
        font1.setPointSize(18);
        font1.setBold(true);
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        ln_rssi = new QLCDNumber(widget);
        ln_rssi->setObjectName(QString::fromUtf8("ln_rssi"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ln_rssi->sizePolicy().hasHeightForWidth());
        ln_rssi->setSizePolicy(sizePolicy3);
        ln_rssi->setMinimumSize(QSize(58, 58));
        ln_rssi->setMaximumSize(QSize(128, 128));
        ln_rssi->setFrameShape(QFrame::NoFrame);
        ln_rssi->setSmallDecimalPoint(false);
        ln_rssi->setDigitCount(3);
        ln_rssi->setSegmentStyle(QLCDNumber::Filled);
        ln_rssi->setProperty("value", QVariant(-88.000000000000000));

        horizontalLayout_2->addWidget(ln_rssi);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("URW Gothic"));
        font2.setPointSize(10);
        font2.setBold(true);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_2->addWidget(label_7);


        gridLayout->addWidget(widget, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chartTemp = new QChartView(centralwidget);
        chartTemp->setObjectName(QString::fromUtf8("chartTemp"));

        verticalLayout_2->addWidget(chartTemp);

        chartPressure = new QChartView(centralwidget);
        chartPressure->setObjectName(QString::fromUtf8("chartPressure"));

        verticalLayout_2->addWidget(chartPressure);


        gridLayout->addLayout(verticalLayout_2, 2, 1, 4, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        ln_kpa = new QLCDNumber(widget1);
        ln_kpa->setObjectName(QString::fromUtf8("ln_kpa"));
        sizePolicy3.setHeightForWidth(ln_kpa->sizePolicy().hasHeightForWidth());
        ln_kpa->setSizePolicy(sizePolicy3);
        ln_kpa->setMinimumSize(QSize(58, 58));
        ln_kpa->setMaximumSize(QSize(128, 128));
        ln_kpa->setFrameShape(QFrame::NoFrame);
        ln_kpa->setSmallDecimalPoint(false);
        ln_kpa->setDigitCount(4);
        ln_kpa->setSegmentStyle(QLCDNumber::Filled);
        ln_kpa->setProperty("value", QVariant(-88.000000000000000));

        horizontalLayout_3->addWidget(ln_kpa);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(label_4);

        ln_atm = new QLCDNumber(widget1);
        ln_atm->setObjectName(QString::fromUtf8("ln_atm"));
        sizePolicy3.setHeightForWidth(ln_atm->sizePolicy().hasHeightForWidth());
        ln_atm->setSizePolicy(sizePolicy3);
        ln_atm->setMinimumSize(QSize(58, 58));
        ln_atm->setMaximumSize(QSize(128, 128));
        ln_atm->setFrameShape(QFrame::NoFrame);
        ln_atm->setSmallDecimalPoint(false);
        ln_atm->setDigitCount(4);
        ln_atm->setSegmentStyle(QLCDNumber::Filled);
        ln_atm->setProperty("value", QVariant(-88.000000000000000));

        horizontalLayout_3->addWidget(ln_atm);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(label_5);


        gridLayout->addWidget(widget1, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        ln_temp = new QLCDNumber(centralwidget);
        ln_temp->setObjectName(QString::fromUtf8("ln_temp"));
        sizePolicy3.setHeightForWidth(ln_temp->sizePolicy().hasHeightForWidth());
        ln_temp->setSizePolicy(sizePolicy3);
        ln_temp->setMinimumSize(QSize(58, 58));
        ln_temp->setMaximumSize(QSize(128, 128));
        ln_temp->setFrameShape(QFrame::NoFrame);
        ln_temp->setSmallDecimalPoint(false);
        ln_temp->setDigitCount(4);
        ln_temp->setSegmentStyle(QLCDNumber::Filled);
        ln_temp->setProperty("value", QVariant(-88.000000000000000));

        horizontalLayout_4->addWidget(ln_temp);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_4->addWidget(label_6);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        tb_output = new QTextBrowser(centralwidget);
        tb_output->setObjectName(QString::fromUtf8("tb_output"));
        sizePolicy3.setHeightForWidth(tb_output->sizePolicy().hasHeightForWidth());
        tb_output->setSizePolicy(sizePolicy3);
        tb_output->setMaximumSize(QSize(16777215, 132));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Source Code Pro"));
        font3.setPointSize(12);
        tb_output->setFont(font3);
        tb_output->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout->addWidget(tb_output, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbPorts = new QComboBox(centralwidget);
        cbPorts->setObjectName(QString::fromUtf8("cbPorts"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbPorts->sizePolicy().hasHeightForWidth());
        cbPorts->setSizePolicy(sizePolicy4);
        cbPorts->setFont(font1);

        horizontalLayout->addWidget(cbPorts);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_openSerialPort = new QPushButton(centralwidget);
        btn_openSerialPort->setObjectName(QString::fromUtf8("btn_openSerialPort"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_openSerialPort->sizePolicy().hasHeightForWidth());
        btn_openSerialPort->setSizePolicy(sizePolicy5);
        btn_openSerialPort->setFont(font2);

        verticalLayout->addWidget(btn_openSerialPort);

        btn_closePort = new QPushButton(centralwidget);
        btn_closePort->setObjectName(QString::fromUtf8("btn_closePort"));
        sizePolicy5.setHeightForWidth(btn_closePort->sizePolicy().hasHeightForWidth());
        btn_closePort->setSizePolicy(sizePolicy5);
        btn_closePort->setFont(font2);

        verticalLayout->addWidget(btn_closePort);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "NoraSat", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RSSI:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "dBi", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pressure:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "kPa", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "atm", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Temp:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\302\272C", nullptr));
        btn_openSerialPort->setText(QCoreApplication::translate("MainWindow", "Open Port", nullptr));
        btn_closePort->setText(QCoreApplication::translate("MainWindow", "Close Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
