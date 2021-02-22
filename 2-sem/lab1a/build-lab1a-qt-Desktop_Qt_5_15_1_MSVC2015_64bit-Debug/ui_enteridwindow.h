/********************************************************************************
** Form generated from reading UI file 'enteridwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERIDWINDOW_H
#define UI_ENTERIDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterIdWindow
{
public:
    QSpinBox *spinBox;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *EnterIdWindow)
    {
        if (EnterIdWindow->objectName().isEmpty())
            EnterIdWindow->setObjectName(QString::fromUtf8("EnterIdWindow"));
        EnterIdWindow->resize(200, 180);
        EnterIdWindow->setMinimumSize(QSize(200, 180));
        EnterIdWindow->setMaximumSize(QSize(200, 180));
        spinBox = new QSpinBox(EnterIdWindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 70, 181, 31));
        QFont font;
        font.setPointSize(15);
        spinBox->setFont(font);
        spinBox->setMinimum(1000);
        spinBox->setMaximum(1000000);
        label = new QLabel(EnterIdWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 181, 61));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(EnterIdWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 120, 181, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonOk = new QPushButton(horizontalLayoutWidget);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        QFont font1;
        font1.setPointSize(12);
        pushButtonOk->setFont(font1);

        horizontalLayout->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(horizontalLayoutWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setFont(font1);

        horizontalLayout->addWidget(pushButtonCancel);


        retranslateUi(EnterIdWindow);

        QMetaObject::connectSlotsByName(EnterIdWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterIdWindow)
    {
        EnterIdWindow->setWindowTitle(QCoreApplication::translate("EnterIdWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EnterIdWindow", "Enter id of monster", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("EnterIdWindow", "OK", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("EnterIdWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterIdWindow: public Ui_EnterIdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERIDWINDOW_H
