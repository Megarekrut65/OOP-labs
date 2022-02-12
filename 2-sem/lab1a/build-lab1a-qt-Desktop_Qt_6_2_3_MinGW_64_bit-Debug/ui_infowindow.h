/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InfoWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->resize(650, 410);
        InfoWindow->setMinimumSize(QSize(650, 410));
        InfoWindow->setMaximumSize(QSize(650, 410));
        QFont font;
        font.setPointSize(8);
        InfoWindow->setFont(font);
        label = new QLabel(InfoWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 561, 61));
        QFont font1;
        font1.setPointSize(23);
        label->setFont(font1);
        label_2 = new QLabel(InfoWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 651, 111));
        QFont font2;
        font2.setPointSize(16);
        label_2->setFont(font2);
        label_2->setWordWrap(true);
        label_3 = new QLabel(InfoWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 180, 631, 101));
        label_3->setFont(font2);
        label_3->setWordWrap(true);
        label_4 = new QLabel(InfoWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 270, 631, 101));
        label_4->setFont(font2);
        label_4->setWordWrap(true);
        pushButton = new QPushButton(InfoWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 370, 75, 31));
        QFont font3;
        font3.setPointSize(15);
        pushButton->setFont(font3);

        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QDialog *InfoWindow)
    {
        InfoWindow->setWindowTitle(QCoreApplication::translate("InfoWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("InfoWindow", "Information about opening modes", nullptr));
        label_2->setText(QCoreApplication::translate("InfoWindow", "1) Memory opening mode - all monsters are saved in memory (std::vector) and after closing the program all monsters will be deleted", nullptr));
        label_3->setText(QCoreApplication::translate("InfoWindow", "2) Text opening mode - all monsters are saved in text file and after closing the program all monsters will be saved.", nullptr));
        label_4->setText(QCoreApplication::translate("InfoWindow", "3) Binary opening mode - all monsters are saved in binary file and after closing the program all monsters will be saved.", nullptr));
        pushButton->setText(QCoreApplication::translate("InfoWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
