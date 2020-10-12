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
#include <QtWidgets/QListWidget>
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
    QGroupBox *groupBoxHead;
    QListWidget *listTimers;
    QLabel *lblTitle;
    QLabel *lblName;
    QPushButton *btnStartAll;
    QPushButton *btnPauseAll;
    QPushButton *btnAdd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 361);
        MainWindow->setMinimumSize(QSize(650, 350));
        MainWindow->setMaximumSize(QSize(650, 361));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(650, 320));
        centralwidget->setMaximumSize(QSize(650, 320));
        groupBoxHead = new QGroupBox(centralwidget);
        groupBoxHead->setObjectName(QString::fromUtf8("groupBoxHead"));
        groupBoxHead->setGeometry(QRect(10, 0, 630, 310));
        groupBoxHead->setMinimumSize(QSize(630, 310));
        groupBoxHead->setMaximumSize(QSize(630, 310));
        listTimers = new QListWidget(groupBoxHead);
        listTimers->setObjectName(QString::fromUtf8("listTimers"));
        listTimers->setGeometry(QRect(360, 40, 256, 261));
        lblTitle = new QLabel(groupBoxHead);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(360, 10, 251, 31));
        QFont font;
        font.setPointSize(14);
        lblTitle->setFont(font);
        lblTitle->setAlignment(Qt::AlignCenter);
        lblName = new QLabel(groupBoxHead);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(40, 40, 241, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Papyrus"));
        font1.setPointSize(28);
        lblName->setFont(font1);
        btnStartAll = new QPushButton(groupBoxHead);
        btnStartAll->setObjectName(QString::fromUtf8("btnStartAll"));
        btnStartAll->setGeometry(QRect(30, 120, 101, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        btnStartAll->setFont(font2);
        btnPauseAll = new QPushButton(groupBoxHead);
        btnPauseAll->setObjectName(QString::fromUtf8("btnPauseAll"));
        btnPauseAll->setGeometry(QRect(180, 120, 101, 51));
        btnPauseAll->setFont(font2);
        btnAdd = new QPushButton(groupBoxHead);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(280, 270, 71, 31));
        btnAdd->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 21));
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
        groupBoxHead->setTitle(QCoreApplication::translate("MainWindow", "GroupBoxHead", nullptr));
        lblTitle->setText(QCoreApplication::translate("MainWindow", "All timers", nullptr));
        lblName->setText(QCoreApplication::translate("MainWindow", "Smart Timers", nullptr));
        btnStartAll->setText(QCoreApplication::translate("MainWindow", "Start all timers", nullptr));
        btnPauseAll->setText(QCoreApplication::translate("MainWindow", "Pause all timers", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
