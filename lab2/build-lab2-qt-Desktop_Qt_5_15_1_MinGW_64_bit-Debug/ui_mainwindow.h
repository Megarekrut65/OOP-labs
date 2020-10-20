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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionStart_all_timers;
    QAction *actionPause_all_timers;
    QAction *actionAdd_new_timer;
    QAction *actionDelete_all_timers;
    QAction *actionSound_on;
    QAction *actionSound_off;
    QAction *actionDo_not_disturb_mode;
    QAction *actionStart_selected_timer;
    QAction *actionPause_selected_timer;
    QAction *actionDelete_selected_timer;
    QAction *actionShow_selected_timer;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutTimerList;
    QLabel *lblTitle;
    QListView *listTimers;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuSetting;
    QMenu *menuTimer;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(375, 390);
        MainWindow->setMinimumSize(QSize(375, 390));
        MainWindow->setMaximumSize(QSize(375, 390));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/png/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon);
        actionStart_all_timers = new QAction(MainWindow);
        actionStart_all_timers->setObjectName(QString::fromUtf8("actionStart_all_timers"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/png/start-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_all_timers->setIcon(icon1);
        actionPause_all_timers = new QAction(MainWindow);
        actionPause_all_timers->setObjectName(QString::fromUtf8("actionPause_all_timers"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/images/png/pause-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause_all_timers->setIcon(icon2);
        actionAdd_new_timer = new QAction(MainWindow);
        actionAdd_new_timer->setObjectName(QString::fromUtf8("actionAdd_new_timer"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/images/png/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_new_timer->setIcon(icon3);
        actionDelete_all_timers = new QAction(MainWindow);
        actionDelete_all_timers->setObjectName(QString::fromUtf8("actionDelete_all_timers"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/images/png/delete-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_all_timers->setIcon(icon4);
        actionSound_on = new QAction(MainWindow);
        actionSound_on->setObjectName(QString::fromUtf8("actionSound_on"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/images/png/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSound_on->setIcon(icon5);
        actionSound_off = new QAction(MainWindow);
        actionSound_off->setObjectName(QString::fromUtf8("actionSound_off"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/images/png/sound-off.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSound_off->setIcon(icon6);
        actionDo_not_disturb_mode = new QAction(MainWindow);
        actionDo_not_disturb_mode->setObjectName(QString::fromUtf8("actionDo_not_disturb_mode"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/images/png/not-distrub.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDo_not_disturb_mode->setIcon(icon7);
        actionStart_selected_timer = new QAction(MainWindow);
        actionStart_selected_timer->setObjectName(QString::fromUtf8("actionStart_selected_timer"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/images/png/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_selected_timer->setIcon(icon8);
        actionPause_selected_timer = new QAction(MainWindow);
        actionPause_selected_timer->setObjectName(QString::fromUtf8("actionPause_selected_timer"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/images/png/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause_selected_timer->setIcon(icon9);
        actionDelete_selected_timer = new QAction(MainWindow);
        actionDelete_selected_timer->setObjectName(QString::fromUtf8("actionDelete_selected_timer"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/images/png/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_selected_timer->setIcon(icon10);
        actionShow_selected_timer = new QAction(MainWindow);
        actionShow_selected_timer->setObjectName(QString::fromUtf8("actionShow_selected_timer"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/images/png/show.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_selected_timer->setIcon(icon11);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(330, 120));
        centralwidget->setMaximumSize(QSize(500, 500));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 10, 311, 291));
        layoutTimerList = new QVBoxLayout(verticalLayoutWidget);
        layoutTimerList->setObjectName(QString::fromUtf8("layoutTimerList"));
        layoutTimerList->setContentsMargins(0, 0, 0, 0);
        lblTitle = new QLabel(verticalLayoutWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        QFont font;
        font.setPointSize(11);
        lblTitle->setFont(font);
        lblTitle->setStyleSheet(QString::fromUtf8("background: white;"));
        lblTitle->setAlignment(Qt::AlignCenter);

        layoutTimerList->addWidget(lblTitle);

        listTimers = new QListView(verticalLayoutWidget);
        listTimers->setObjectName(QString::fromUtf8("listTimers"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(12);
        listTimers->setFont(font1);
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
        menubar->setGeometry(QRect(0, 0, 375, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuTimer = new QMenu(menubar);
        menuTimer->setObjectName(QString::fromUtf8("menuTimer"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuTimer->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menuFile->addAction(actionQuit);
        menuTools->addAction(actionAdd_new_timer);
        menuTools->addSeparator();
        menuTools->addAction(actionStart_all_timers);
        menuTools->addAction(actionPause_all_timers);
        menuTools->addAction(actionDelete_all_timers);
        menuSetting->addAction(actionSound_on);
        menuSetting->addAction(actionSound_off);
        menuSetting->addSeparator();
        menuSetting->addAction(actionDo_not_disturb_mode);
        menuTimer->addAction(actionShow_selected_timer);
        menuTimer->addAction(actionStart_selected_timer);
        menuTimer->addAction(actionPause_selected_timer);
        menuTimer->addAction(actionDelete_selected_timer);
        toolBar->addAction(actionAdd_new_timer);
        toolBar->addAction(actionStart_all_timers);
        toolBar->addAction(actionPause_all_timers);
        toolBar->addAction(actionDelete_all_timers);
        toolBar->addSeparator();
        toolBar->addAction(actionShow_selected_timer);
        toolBar->addAction(actionStart_selected_timer);
        toolBar->addAction(actionPause_selected_timer);
        toolBar->addAction(actionDelete_selected_timer);
        toolBar->addSeparator();
        toolBar->addAction(actionSound_on);
        toolBar->addAction(actionSound_off);
        toolBar->addAction(actionDo_not_disturb_mode);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Save and quit", nullptr));
        actionStart_all_timers->setText(QCoreApplication::translate("MainWindow", "Start all timers", nullptr));
        actionPause_all_timers->setText(QCoreApplication::translate("MainWindow", "Pause all timers", nullptr));
        actionAdd_new_timer->setText(QCoreApplication::translate("MainWindow", "Add new timer", nullptr));
        actionDelete_all_timers->setText(QCoreApplication::translate("MainWindow", "Delete all timers", nullptr));
        actionSound_on->setText(QCoreApplication::translate("MainWindow", "Sound on", nullptr));
        actionSound_off->setText(QCoreApplication::translate("MainWindow", "Sound off", nullptr));
        actionDo_not_disturb_mode->setText(QCoreApplication::translate("MainWindow", "Do not disturb mode", nullptr));
        actionStart_selected_timer->setText(QCoreApplication::translate("MainWindow", "Start selected timer", nullptr));
        actionPause_selected_timer->setText(QCoreApplication::translate("MainWindow", "Pause selected timer", nullptr));
        actionDelete_selected_timer->setText(QCoreApplication::translate("MainWindow", "Delete selected timer", nullptr));
        actionShow_selected_timer->setText(QCoreApplication::translate("MainWindow", "Show selected timer", nullptr));
        lblTitle->setText(QCoreApplication::translate("MainWindow", "ID, Type, Time, Name", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        menuTimer->setTitle(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
