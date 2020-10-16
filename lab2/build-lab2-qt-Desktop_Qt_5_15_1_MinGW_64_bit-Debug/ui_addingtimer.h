/********************************************************************************
** Form generated from reading UI file 'addingtimer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINGTIMER_H
#define UI_ADDINGTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddingTimer
{
public:
    QRadioButton *radioButtonTimer;
    QPushButton *btnCreate;
    QLineEdit *lineAddName;
    QRadioButton *radioButtonAlarm;
    QTimeEdit *timeAdd;
    QLabel *labelAdd;
    QPushButton *btnCancel;

    void setupUi(QDialog *AddingTimer)
    {
        if (AddingTimer->objectName().isEmpty())
            AddingTimer->setObjectName(QString::fromUtf8("AddingTimer"));
        AddingTimer->resize(380, 310);
        AddingTimer->setMinimumSize(QSize(380, 310));
        AddingTimer->setMaximumSize(QSize(380, 310));
        radioButtonTimer = new QRadioButton(AddingTimer);
        radioButtonTimer->setObjectName(QString::fromUtf8("radioButtonTimer"));
        radioButtonTimer->setGeometry(QRect(100, 220, 82, 21));
        QFont font;
        font.setPointSize(11);
        radioButtonTimer->setFont(font);
        radioButtonTimer->setCursor(QCursor(Qt::PointingHandCursor));
        radioButtonTimer->setChecked(true);
        radioButtonTimer->setAutoRepeat(false);
        btnCreate = new QPushButton(AddingTimer);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setGeometry(QRect(90, 260, 61, 31));
        btnCreate->setFont(font);
        lineAddName = new QLineEdit(AddingTimer);
        lineAddName->setObjectName(QString::fromUtf8("lineAddName"));
        lineAddName->setGeometry(QRect(60, 110, 261, 41));
        QFont font1;
        font1.setPointSize(18);
        lineAddName->setFont(font1);
        lineAddName->setAlignment(Qt::AlignCenter);
        radioButtonAlarm = new QRadioButton(AddingTimer);
        radioButtonAlarm->setObjectName(QString::fromUtf8("radioButtonAlarm"));
        radioButtonAlarm->setGeometry(QRect(180, 220, 111, 21));
        radioButtonAlarm->setFont(font);
        radioButtonAlarm->setCursor(QCursor(Qt::PointingHandCursor));
        timeAdd = new QTimeEdit(AddingTimer);
        timeAdd->setObjectName(QString::fromUtf8("timeAdd"));
        timeAdd->setGeometry(QRect(90, 170, 201, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI"));
        font2.setPointSize(28);
        timeAdd->setFont(font2);
        timeAdd->setCursor(QCursor(Qt::PointingHandCursor));
        timeAdd->setAlignment(Qt::AlignCenter);
        timeAdd->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        labelAdd = new QLabel(AddingTimer);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setEnabled(true);
        labelAdd->setGeometry(QRect(50, 30, 301, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font3.setPointSize(36);
        labelAdd->setFont(font3);
        labelAdd->setAlignment(Qt::AlignCenter);
        btnCancel = new QPushButton(AddingTimer);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(230, 260, 61, 31));
        btnCancel->setFont(font);

        retranslateUi(AddingTimer);

        QMetaObject::connectSlotsByName(AddingTimer);
    } // setupUi

    void retranslateUi(QDialog *AddingTimer)
    {
        AddingTimer->setWindowTitle(QCoreApplication::translate("AddingTimer", "Dialog", nullptr));
        radioButtonTimer->setText(QCoreApplication::translate("AddingTimer", "Timer", nullptr));
        btnCreate->setText(QCoreApplication::translate("AddingTimer", "Create", nullptr));
        lineAddName->setText(QCoreApplication::translate("AddingTimer", "New Timer", nullptr));
        radioButtonAlarm->setText(QCoreApplication::translate("AddingTimer", "Alarm clock", nullptr));
        timeAdd->setDisplayFormat(QCoreApplication::translate("AddingTimer", "HH:mm:ss", nullptr));
        labelAdd->setText(QCoreApplication::translate("AddingTimer", "Add timer", nullptr));
        btnCancel->setText(QCoreApplication::translate("AddingTimer", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddingTimer: public Ui_AddingTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINGTIMER_H
