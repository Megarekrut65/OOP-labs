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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnAdd;
    QPushButton *btnPauseAll;
    QLabel *lblName;
    QPushButton *btnStartAll;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutTimerList;
    QLabel *lblTitle;
    QListView *listTimers;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 361);
        MainWindow->setMinimumSize(QSize(650, 361));
        MainWindow->setMaximumSize(QSize(650, 361));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(650, 320));
        centralwidget->setMaximumSize(QSize(650, 320));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(240, 270, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        btnAdd->setFont(font);
        btnPauseAll = new QPushButton(centralwidget);
        btnPauseAll->setObjectName(QString::fromUtf8("btnPauseAll"));
        btnPauseAll->setGeometry(QRect(180, 120, 101, 51));
        btnPauseAll->setFont(font);
        lblName = new QLabel(centralwidget);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(40, 40, 241, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Papyrus"));
        font1.setPointSize(28);
        lblName->setFont(font1);
        btnStartAll = new QPushButton(centralwidget);
        btnStartAll->setObjectName(QString::fromUtf8("btnStartAll"));
        btnStartAll->setGeometry(QRect(30, 120, 101, 51));
        btnStartAll->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(320, 10, 301, 291));
        layoutTimerList = new QVBoxLayout(verticalLayoutWidget);
        layoutTimerList->setObjectName(QString::fromUtf8("layoutTimerList"));
        layoutTimerList->setContentsMargins(0, 0, 0, 0);
        lblTitle = new QLabel(verticalLayoutWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        QFont font2;
        font2.setPointSize(14);
        lblTitle->setFont(font2);
        lblTitle->setAlignment(Qt::AlignCenter);

        layoutTimerList->addWidget(lblTitle);

        listTimers = new QListView(verticalLayoutWidget);
        listTimers->setObjectName(QString::fromUtf8("listTimers"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Consolas"));
        font3.setPointSize(12);
        listTimers->setFont(font3);
        listTimers->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listTimers->setTabletTracking(true);
        listTimers->setTabKeyNavigation(false);
        listTimers->setAlternatingRowColors(false);
        listTimers->setTextElideMode(Qt::ElideRight);

        layoutTimerList->addWidget(listTimers);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add timer", nullptr));
        btnPauseAll->setText(QCoreApplication::translate("MainWindow", "Pause all timers", nullptr));
        lblName->setText(QCoreApplication::translate("MainWindow", "Smart Timers", nullptr));
        btnStartAll->setText(QCoreApplication::translate("MainWindow", "Start all timers", nullptr));
        lblTitle->setText(QCoreApplication::translate("MainWindow", "All timers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
