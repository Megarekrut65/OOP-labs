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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBoxTimer;
    QPushButton *btnTimer;
    QLabel *lblTimer;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QPushButton *btnPause;
    QPushButton *btnStart;
    QLabel *lblTimerName;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QGroupBox *groupBoxAdding;
    QTimeEdit *timeEditAdd;
    QPushButton *btnCreate;
    QLineEdit *lineEditNameTimer;
    QPushButton *btnCancel;
    QLabel *labelAdd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(634, 358);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBoxTimer = new QGroupBox(centralwidget);
        groupBoxTimer->setObjectName(QString::fromUtf8("groupBoxTimer"));
        groupBoxTimer->setEnabled(true);
        groupBoxTimer->setGeometry(QRect(10, 0, 611, 321));
        btnTimer = new QPushButton(groupBoxTimer);
        btnTimer->setObjectName(QString::fromUtf8("btnTimer"));
        btnTimer->setEnabled(true);
        btnTimer->setGeometry(QRect(370, 240, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        btnTimer->setFont(font);
        btnTimer->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimer = new QLabel(groupBoxTimer);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setGeometry(QRect(94, 131, 411, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Light"));
        font1.setPointSize(48);
        lblTimer->setFont(font1);
        lblTimer->setCursor(QCursor(Qt::ArrowCursor));
        lblTimer->setScaledContents(false);
        lblTimer->setAlignment(Qt::AlignCenter);
        lblTimer->setWordWrap(false);
        btnLeft = new QPushButton(groupBoxTimer);
        btnLeft->setObjectName(QString::fromUtf8("btnLeft"));
        btnLeft->setEnabled(true);
        btnLeft->setGeometry(QRect(10, 90, 41, 141));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        btnLeft->setFont(font2);
        btnLeft->setCursor(QCursor(Qt::PointingHandCursor));
        btnRight = new QPushButton(groupBoxTimer);
        btnRight->setObjectName(QString::fromUtf8("btnRight"));
        btnRight->setEnabled(true);
        btnRight->setGeometry(QRect(560, 90, 41, 141));
        btnRight->setFont(font2);
        btnRight->setCursor(QCursor(Qt::PointingHandCursor));
        btnPause = new QPushButton(groupBoxTimer);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(true);
        btnPause->setGeometry(QRect(180, 240, 61, 41));
        btnPause->setFont(font);
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));
        btnStart = new QPushButton(groupBoxTimer);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(270, 240, 71, 41));
        btnStart->setFont(font);
        btnStart->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimerName = new QLabel(groupBoxTimer);
        lblTimerName->setObjectName(QString::fromUtf8("lblTimerName"));
        lblTimerName->setGeometry(QRect(100, 80, 401, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Orator Std"));
        font3.setPointSize(36);
        lblTimerName->setFont(font3);
        lblTimerName->setCursor(QCursor(Qt::ArrowCursor));
        lblTimerName->setAutoFillBackground(false);
        lblTimerName->setAlignment(Qt::AlignCenter);
        lblTimerName->setWordWrap(true);
        lblTimerName->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        btnEdit = new QPushButton(groupBoxTimer);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setEnabled(true);
        btnEdit->setGeometry(QRect(100, 240, 61, 41));
        btnEdit->setFont(font);
        btnEdit->setCursor(QCursor(Qt::PointingHandCursor));
        btnDelete = new QPushButton(groupBoxTimer);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(true);
        btnDelete->setGeometry(QRect(450, 240, 61, 41));
        btnDelete->setFont(font);
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));
        groupBoxAdding = new QGroupBox(centralwidget);
        groupBoxAdding->setObjectName(QString::fromUtf8("groupBoxAdding"));
        groupBoxAdding->setEnabled(true);
        groupBoxAdding->setGeometry(QRect(0, 0, 611, 311));
        timeEditAdd = new QTimeEdit(groupBoxAdding);
        timeEditAdd->setObjectName(QString::fromUtf8("timeEditAdd"));
        timeEditAdd->setGeometry(QRect(230, 190, 201, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nirmala UI"));
        font4.setPointSize(28);
        timeEditAdd->setFont(font4);
        timeEditAdd->setCursor(QCursor(Qt::PointingHandCursor));
        timeEditAdd->setAlignment(Qt::AlignCenter);
        timeEditAdd->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        btnCreate = new QPushButton(groupBoxAdding);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setGeometry(QRect(230, 260, 61, 31));
        QFont font5;
        font5.setPointSize(11);
        btnCreate->setFont(font5);
        lineEditNameTimer = new QLineEdit(groupBoxAdding);
        lineEditNameTimer->setObjectName(QString::fromUtf8("lineEditNameTimer"));
        lineEditNameTimer->setGeometry(QRect(190, 120, 271, 41));
        QFont font6;
        font6.setPointSize(18);
        lineEditNameTimer->setFont(font6);
        lineEditNameTimer->setAlignment(Qt::AlignCenter);
        btnCancel = new QPushButton(groupBoxAdding);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(370, 260, 61, 31));
        btnCancel->setFont(font5);
        labelAdd = new QLabel(groupBoxAdding);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setEnabled(true);
        labelAdd->setGeometry(QRect(30, 30, 591, 61));
        QFont font7;
        font7.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font7.setPointSize(48);
        labelAdd->setFont(font7);
        labelAdd->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 634, 21));
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
        groupBoxTimer->setTitle(QCoreApplication::translate("MainWindow", "GroupBoxTimer", nullptr));
        btnTimer->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        lblTimer->setText(QCoreApplication::translate("MainWindow", "10:20:30", nullptr));
        btnLeft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        btnRight->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        lblTimerName->setText(QCoreApplication::translate("MainWindow", "Timer Name", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        groupBoxAdding->setTitle(QCoreApplication::translate("MainWindow", "GroupBoxAdding", nullptr));
        timeEditAdd->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        btnCreate->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        lineEditNameTimer->setText(QCoreApplication::translate("MainWindow", "Enter timer name...", nullptr));
        btnCancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        labelAdd->setText(QCoreApplication::translate("MainWindow", "Add new timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
