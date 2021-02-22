/********************************************************************************
** Form generated from reading UI file 'findhpdamagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDHPDAMAGEWINDOW_H
#define UI_FINDHPDAMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindHPDamageWindow
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBoxHP;
    QLabel *label_2;
    QSpinBox *spinBoxDamage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *FindHPDamageWindow)
    {
        if (FindHPDamageWindow->objectName().isEmpty())
            FindHPDamageWindow->setObjectName(QString::fromUtf8("FindHPDamageWindow"));
        FindHPDamageWindow->resize(290, 130);
        FindHPDamageWindow->setMinimumSize(QSize(290, 130));
        FindHPDamageWindow->setMaximumSize(QSize(290, 130));
        formLayoutWidget = new QWidget(FindHPDamageWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(3, 10, 281, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBoxHP = new QSpinBox(formLayoutWidget);
        spinBoxHP->setObjectName(QString::fromUtf8("spinBoxHP"));
        QFont font1;
        font1.setPointSize(14);
        spinBoxHP->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxHP);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBoxDamage = new QSpinBox(formLayoutWidget);
        spinBoxDamage->setObjectName(QString::fromUtf8("spinBoxDamage"));
        spinBoxDamage->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxDamage);

        horizontalLayoutWidget = new QWidget(FindHPDamageWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 90, 241, 31));
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


        retranslateUi(FindHPDamageWindow);

        QMetaObject::connectSlotsByName(FindHPDamageWindow);
    } // setupUi

    void retranslateUi(QDialog *FindHPDamageWindow)
    {
        FindHPDamageWindow->setWindowTitle(QCoreApplication::translate("FindHPDamageWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FindHPDamageWindow", "Minimal health units", nullptr));
        label_2->setText(QCoreApplication::translate("FindHPDamageWindow", "Maximum attack units", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("FindHPDamageWindow", "OK", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("FindHPDamageWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindHPDamageWindow: public Ui_FindHPDamageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDHPDAMAGEWINDOW_H
