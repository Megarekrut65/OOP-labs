/********************************************************************************
** Form generated from reading UI file 'addingtimer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINGTIMER_H
#define UI_ADDINGTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QComboBox *seletcSound;
    QLabel *lblSelectSound;
    QLabel *lblNumber;
    QSpinBox *spinBoxNumber;

    void setupUi(QDialog *AddingTimer)
    {
        if (AddingTimer->objectName().isEmpty())
            AddingTimer->setObjectName(QString::fromUtf8("AddingTimer"));
        AddingTimer->resize(380, 375);
        AddingTimer->setMinimumSize(QSize(380, 375));
        AddingTimer->setMaximumSize(QSize(380, 375));
        radioButtonTimer = new QRadioButton(AddingTimer);
        radioButtonTimer->setObjectName(QString::fromUtf8("radioButtonTimer"));
        radioButtonTimer->setGeometry(QRect(100, 170, 82, 21));
        QFont font;
        font.setPointSize(11);
        radioButtonTimer->setFont(font);
        radioButtonTimer->setCursor(QCursor(Qt::PointingHandCursor));
        radioButtonTimer->setChecked(true);
        radioButtonTimer->setAutoRepeat(false);
        btnCreate = new QPushButton(AddingTimer);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setGeometry(QRect(90, 330, 61, 31));
        btnCreate->setFont(font);
        btnCreate->setCursor(QCursor(Qt::PointingHandCursor));
        lineAddName = new QLineEdit(AddingTimer);
        lineAddName->setObjectName(QString::fromUtf8("lineAddName"));
        lineAddName->setGeometry(QRect(60, 60, 261, 41));
        QFont font1;
        font1.setPointSize(18);
        lineAddName->setFont(font1);
        lineAddName->setAlignment(Qt::AlignCenter);
        radioButtonAlarm = new QRadioButton(AddingTimer);
        radioButtonAlarm->setObjectName(QString::fromUtf8("radioButtonAlarm"));
        radioButtonAlarm->setGeometry(QRect(180, 170, 111, 21));
        radioButtonAlarm->setFont(font);
        radioButtonAlarm->setCursor(QCursor(Qt::PointingHandCursor));
        timeAdd = new QTimeEdit(AddingTimer);
        timeAdd->setObjectName(QString::fromUtf8("timeAdd"));
        timeAdd->setGeometry(QRect(90, 120, 201, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Nirmala UI")});
        font2.setPointSize(28);
        timeAdd->setFont(font2);
        timeAdd->setCursor(QCursor(Qt::PointingHandCursor));
        timeAdd->setAlignment(Qt::AlignCenter);
        timeAdd->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        labelAdd = new QLabel(AddingTimer);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setEnabled(true);
        labelAdd->setGeometry(QRect(40, 10, 301, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("MS Reference Sans Serif")});
        font3.setPointSize(28);
        labelAdd->setFont(font3);
        labelAdd->setAlignment(Qt::AlignCenter);
        btnCancel = new QPushButton(AddingTimer);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(230, 330, 61, 31));
        btnCancel->setFont(font);
        btnCancel->setCursor(QCursor(Qt::PointingHandCursor));
        seletcSound = new QComboBox(AddingTimer);
        seletcSound->setObjectName(QString::fromUtf8("seletcSound"));
        seletcSound->setGeometry(QRect(90, 230, 201, 22));
        seletcSound->setCursor(QCursor(Qt::PointingHandCursor));
        lblSelectSound = new QLabel(AddingTimer);
        lblSelectSound->setObjectName(QString::fromUtf8("lblSelectSound"));
        lblSelectSound->setGeometry(QRect(90, 200, 201, 21));
        QFont font4;
        font4.setPointSize(12);
        lblSelectSound->setFont(font4);
        lblSelectSound->setAlignment(Qt::AlignCenter);
        lblNumber = new QLabel(AddingTimer);
        lblNumber->setObjectName(QString::fromUtf8("lblNumber"));
        lblNumber->setGeometry(QRect(26, 260, 321, 20));
        lblNumber->setFont(font4);
        lblNumber->setAlignment(Qt::AlignCenter);
        spinBoxNumber = new QSpinBox(AddingTimer);
        spinBoxNumber->setObjectName(QString::fromUtf8("spinBoxNumber"));
        spinBoxNumber->setGeometry(QRect(140, 290, 101, 22));
        spinBoxNumber->setFont(font4);
        spinBoxNumber->setCursor(QCursor(Qt::PointingHandCursor));
        spinBoxNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(100);
        spinBoxNumber->setValue(15);

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
        seletcSound->setCurrentText(QString());
        lblSelectSound->setText(QCoreApplication::translate("AddingTimer", "Select the timer signal:", nullptr));
        lblNumber->setText(QCoreApplication::translate("AddingTimer", "Select the maximum number of signals:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddingTimer: public Ui_AddingTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINGTIMER_H
