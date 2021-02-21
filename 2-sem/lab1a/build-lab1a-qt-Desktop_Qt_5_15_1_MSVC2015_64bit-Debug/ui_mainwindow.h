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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButtonMemory;
    QPushButton *pushButtonText;
    QPushButton *pushButtonBinary;
    QPushButton *pushButton_5;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 470);
        MainWindow->setMinimumSize(QSize(820, 470));
        MainWindow->setMaximumSize(QSize(820, 470));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 731, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(58);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 400, 75, 31));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 130, 331, 51));
        QFont font2;
        font2.setPointSize(20);
        label_2->setFont(font2);
        pushButtonMemory = new QPushButton(centralwidget);
        pushButtonMemory->setObjectName(QString::fromUtf8("pushButtonMemory"));
        pushButtonMemory->setGeometry(QRect(300, 210, 171, 41));
        pushButtonMemory->setFont(font1);
        pushButtonText = new QPushButton(centralwidget);
        pushButtonText->setObjectName(QString::fromUtf8("pushButtonText"));
        pushButtonText->setGeometry(QRect(300, 270, 171, 41));
        QFont font3;
        font3.setPointSize(17);
        pushButtonText->setFont(font3);
        pushButtonBinary = new QPushButton(centralwidget);
        pushButtonBinary->setObjectName(QString::fromUtf8("pushButtonBinary"));
        pushButtonBinary->setGeometry(QRect(300, 330, 171, 41));
        pushButtonBinary->setFont(font3);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 410, 75, 23));
        QFont font4;
        font4.setPointSize(14);
        pushButton_5->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Forest of monsters", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Choose one opening mode:", nullptr));
        pushButtonMemory->setText(QCoreApplication::translate("MainWindow", "Memory mode", nullptr));
        pushButtonText->setText(QCoreApplication::translate("MainWindow", "Text mode", nullptr));
        pushButtonBinary->setText(QCoreApplication::translate("MainWindow", "Binary mode", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
