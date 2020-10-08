/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *btnTimer;
    QLabel *lblTimer;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QPushButton *btnPause;
    QPushButton *btnStart;
    QLabel *lblTimerName;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(542, 316);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 491, 241));
        btnTimer = new QPushButton(groupBox);
        btnTimer->setObjectName(QString::fromUtf8("btnTimer"));
        btnTimer->setEnabled(true);
        btnTimer->setGeometry(QRect(200, 200, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        btnTimer->setFont(font);
        btnTimer->setCursor(QCursor(Qt::ArrowCursor));
        lblTimer = new QLabel(groupBox);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setGeometry(QRect(40, 70, 411, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Light"));
        font1.setPointSize(48);
        lblTimer->setFont(font1);
        lblTimer->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimer->setScaledContents(false);
        lblTimer->setAlignment(Qt::AlignCenter);
        lblTimer->setWordWrap(false);
        btnLeft = new QPushButton(groupBox);
        btnLeft->setObjectName(QString::fromUtf8("btnLeft"));
        btnLeft->setEnabled(true);
        btnLeft->setGeometry(QRect(0, 40, 41, 141));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        btnLeft->setFont(font2);
        btnRight = new QPushButton(groupBox);
        btnRight->setObjectName(QString::fromUtf8("btnRight"));
        btnRight->setEnabled(true);
        btnRight->setGeometry(QRect(450, 40, 41, 141));
        btnRight->setFont(font2);
        btnPause = new QPushButton(groupBox);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(true);
        btnPause->setGeometry(QRect(150, 150, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        btnPause->setFont(font3);
        btnPause->setCursor(QCursor(Qt::ArrowCursor));
        btnStart = new QPushButton(groupBox);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(280, 150, 61, 31));
        btnStart->setFont(font3);
        btnStart->setCursor(QCursor(Qt::ArrowCursor));
        lblTimerName = new QLabel(groupBox);
        lblTimerName->setObjectName(QString::fromUtf8("lblTimerName"));
        lblTimerName->setGeometry(QRect(46, 19, 401, 61));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Orator Std"));
        font4.setPointSize(36);
        lblTimerName->setFont(font4);
        lblTimerName->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimerName->setAutoFillBackground(false);
        lblTimerName->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 542, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        btnTimer->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        lblTimer->setText(QCoreApplication::translate("MainWindow", "10:20:30", nullptr));
        btnLeft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        btnRight->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        lblTimerName->setText(QCoreApplication::translate("MainWindow", "Timer Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
