/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QLabel *label_2;
    QSpinBox *spinBoxHP;
    QLabel *label_3;
    QSpinBox *spinBoxDamage;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxChance;
    QLabel *label_5;
    QRadioButton *radioButtonIncrease;
    QRadioButton *radioButtonParalize;
    QRadioButton *radioButtonRepeat;
    QRadioButton *radioButtonCure;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName(QString::fromUtf8("AddWindow"));
        AddWindow->resize(425, 475);
        AddWindow->setMinimumSize(QSize(425, 475));
        AddWindow->setMaximumSize(QSize(425, 475));
        QFont font;
        font.setPointSize(13);
        AddWindow->setFont(font);
        formLayoutWidget = new QWidget(AddWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 402, 411));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditName = new QLineEdit(formLayoutWidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setFont(font1);
        lineEditName->setMaxLength(18);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditName);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinBoxHP = new QSpinBox(formLayoutWidget);
        spinBoxHP->setObjectName(QString::fromUtf8("spinBoxHP"));
        spinBoxHP->setFont(font1);
        spinBoxHP->setMinimum(1);
        spinBoxHP->setMaximum(50000);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxHP);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBoxDamage = new QSpinBox(formLayoutWidget);
        spinBoxDamage->setObjectName(QString::fromUtf8("spinBoxDamage"));
        spinBoxDamage->setFont(font1);
        spinBoxDamage->setMinimum(1);
        spinBoxDamage->setMaximum(1000);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxDamage);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setWordWrap(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBoxChance = new QDoubleSpinBox(formLayoutWidget);
        spinBoxChance->setObjectName(QString::fromUtf8("spinBoxChance"));
        spinBoxChance->setFont(font1);
        spinBoxChance->setMaximum(1.000000000000000);
        spinBoxChance->setSingleStep(0.010000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxChance);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setWordWrap(false);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        radioButtonIncrease = new QRadioButton(formLayoutWidget);
        radioButtonIncrease->setObjectName(QString::fromUtf8("radioButtonIncrease"));
        radioButtonIncrease->setFont(font1);
        radioButtonIncrease->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, radioButtonIncrease);

        radioButtonParalize = new QRadioButton(formLayoutWidget);
        radioButtonParalize->setObjectName(QString::fromUtf8("radioButtonParalize"));
        radioButtonParalize->setFont(font1);

        formLayout->setWidget(7, QFormLayout::FieldRole, radioButtonParalize);

        radioButtonRepeat = new QRadioButton(formLayoutWidget);
        radioButtonRepeat->setObjectName(QString::fromUtf8("radioButtonRepeat"));
        radioButtonRepeat->setFont(font1);

        formLayout->setWidget(5, QFormLayout::FieldRole, radioButtonRepeat);

        radioButtonCure = new QRadioButton(formLayoutWidget);
        radioButtonCure->setObjectName(QString::fromUtf8("radioButtonCure"));
        radioButtonCure->setFont(font1);

        formLayout->setWidget(6, QFormLayout::FieldRole, radioButtonCure);

        pushButtonSave = new QPushButton(AddWindow);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(60, 432, 75, 31));
        QFont font2;
        font2.setPointSize(16);
        pushButtonSave->setFont(font2);
        pushButtonCancel = new QPushButton(AddWindow);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(280, 430, 75, 31));
        pushButtonCancel->setFont(font2);

        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QDialog *AddWindow)
    {
        AddWindow->setWindowTitle(QCoreApplication::translate("AddWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddWindow", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("AddWindow", "Health units", nullptr));
        label_3->setText(QCoreApplication::translate("AddWindow", "Attack units", nullptr));
        label_4->setText(QCoreApplication::translate("AddWindow", "Chance to launch the special attack", nullptr));
        label_5->setText(QCoreApplication::translate("AddWindow", "Type of special attack", nullptr));
        radioButtonIncrease->setText(QCoreApplication::translate("AddWindow", "Increase damage", nullptr));
        radioButtonParalize->setText(QCoreApplication::translate("AddWindow", "Paralyze the enemy", nullptr));
        radioButtonRepeat->setText(QCoreApplication::translate("AddWindow", "Repeat the attack", nullptr));
        radioButtonCure->setText(QCoreApplication::translate("AddWindow", "Cure yourself", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("AddWindow", "Save", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("AddWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
