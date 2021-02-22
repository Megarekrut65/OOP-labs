/********************************************************************************
** Form generated from reading UI file 'findnamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDNAMEWINDOW_H
#define UI_FINDNAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindNameWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *FindNameWindow)
    {
        if (FindNameWindow->objectName().isEmpty())
            FindNameWindow->setObjectName(QString::fromUtf8("FindNameWindow"));
        FindNameWindow->resize(319, 201);
        verticalLayoutWidget = new QWidget(FindNameWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 301, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font1;
        font1.setPointSize(15);
        lineEdit->setFont(font1);
        lineEdit->setMaxLength(18);

        verticalLayout->addWidget(lineEdit);

        horizontalLayoutWidget = new QWidget(FindNameWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 130, 301, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font2;
        font2.setPointSize(12);
        pushButton_2->setFont(font2);

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);

        horizontalLayout->addWidget(pushButton);


        retranslateUi(FindNameWindow);

        QMetaObject::connectSlotsByName(FindNameWindow);
    } // setupUi

    void retranslateUi(QDialog *FindNameWindow)
    {
        FindNameWindow->setWindowTitle(QCoreApplication::translate("FindNameWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FindNameWindow", "Enter name or fragment name", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FindNameWindow", "OK", nullptr));
        pushButton->setText(QCoreApplication::translate("FindNameWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindNameWindow: public Ui_FindNameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDNAMEWINDOW_H
