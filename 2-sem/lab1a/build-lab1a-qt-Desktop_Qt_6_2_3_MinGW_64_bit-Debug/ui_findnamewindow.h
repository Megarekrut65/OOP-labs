/********************************************************************************
** Form generated from reading UI file 'findnamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
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
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *FindNameWindow)
    {
        if (FindNameWindow->objectName().isEmpty())
            FindNameWindow->setObjectName(QString::fromUtf8("FindNameWindow"));
        FindNameWindow->resize(320, 200);
        FindNameWindow->setMinimumSize(QSize(320, 200));
        FindNameWindow->setMaximumSize(QSize(320, 200));
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
        pushButtonOK = new QPushButton(horizontalLayoutWidget);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        QFont font2;
        font2.setPointSize(12);
        pushButtonOK->setFont(font2);

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(horizontalLayoutWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setFont(font2);

        horizontalLayout->addWidget(pushButtonCancel);


        retranslateUi(FindNameWindow);

        QMetaObject::connectSlotsByName(FindNameWindow);
    } // setupUi

    void retranslateUi(QDialog *FindNameWindow)
    {
        FindNameWindow->setWindowTitle(QCoreApplication::translate("FindNameWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FindNameWindow", "Enter name or fragment name", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("FindNameWindow", "OK", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("FindNameWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindNameWindow: public Ui_FindNameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDNAMEWINDOW_H
