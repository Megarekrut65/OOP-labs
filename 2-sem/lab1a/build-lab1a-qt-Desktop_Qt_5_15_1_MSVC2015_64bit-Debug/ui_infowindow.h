/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
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
        InfoWindow->resize(820, 470);
        InfoWindow->setMinimumSize(QSize(820, 470));
        InfoWindow->setMaximumSize(QSize(820, 470));
        label = new QLabel(InfoWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 20, 561, 61));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label_2 = new QLabel(InfoWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 771, 121));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setWordWrap(true);
        label_3 = new QLabel(InfoWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 200, 771, 121));
        label_3->setFont(font1);
        label_3->setWordWrap(true);
        label_4 = new QLabel(InfoWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 300, 771, 121));
        label_4->setFont(font1);
        label_4->setWordWrap(true);
        pushButton = new QPushButton(InfoWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(720, 422, 75, 31));
        QFont font2;
        font2.setPointSize(15);
        pushButton->setFont(font2);

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
