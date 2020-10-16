/********************************************************************************
** Form generated from reading UI file 'editingtimer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINGTIMER_H
#define UI_EDITINGTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_EditingTimer
{
public:
    QPushButton *btnCancel;
    QLineEdit *lineEditName;
    QPushButton *btnSave;
    QLabel *labelEdit;
    QTimeEdit *timeEditTime;
    QLabel *lblNumber;
    QComboBox *seletcSound;
    QLabel *lblSound;
    QSpinBox *spinBoxNumber;

    void setupUi(QDialog *EditingTimer)
    {
        if (EditingTimer->objectName().isEmpty())
            EditingTimer->setObjectName(QString::fromUtf8("EditingTimer"));
        EditingTimer->resize(380, 375);
        EditingTimer->setMinimumSize(QSize(380, 375));
        EditingTimer->setMaximumSize(QSize(380, 375));
        btnCancel = new QPushButton(EditingTimer);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(240, 320, 61, 31));
        QFont font;
        font.setPointSize(11);
        btnCancel->setFont(font);
        lineEditName = new QLineEdit(EditingTimer);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(60, 70, 271, 41));
        QFont font1;
        font1.setPointSize(18);
        lineEditName->setFont(font1);
        lineEditName->setAlignment(Qt::AlignCenter);
        btnSave = new QPushButton(EditingTimer);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(100, 320, 61, 31));
        btnSave->setFont(font);
        labelEdit = new QLabel(EditingTimer);
        labelEdit->setObjectName(QString::fromUtf8("labelEdit"));
        labelEdit->setEnabled(true);
        labelEdit->setGeometry(QRect(20, 10, 341, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font2.setPointSize(28);
        labelEdit->setFont(font2);
        labelEdit->setAlignment(Qt::AlignCenter);
        timeEditTime = new QTimeEdit(EditingTimer);
        timeEditTime->setObjectName(QString::fromUtf8("timeEditTime"));
        timeEditTime->setGeometry(QRect(90, 130, 211, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nirmala UI"));
        font3.setPointSize(28);
        timeEditTime->setFont(font3);
        timeEditTime->setCursor(QCursor(Qt::PointingHandCursor));
        timeEditTime->setAlignment(Qt::AlignCenter);
        timeEditTime->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        lblNumber = new QLabel(EditingTimer);
        lblNumber->setObjectName(QString::fromUtf8("lblNumber"));
        lblNumber->setGeometry(QRect(36, 250, 321, 20));
        QFont font4;
        font4.setPointSize(12);
        lblNumber->setFont(font4);
        lblNumber->setAlignment(Qt::AlignCenter);
        seletcSound = new QComboBox(EditingTimer);
        seletcSound->setObjectName(QString::fromUtf8("seletcSound"));
        seletcSound->setGeometry(QRect(90, 220, 211, 22));
        seletcSound->setCursor(QCursor(Qt::PointingHandCursor));
        lblSound = new QLabel(EditingTimer);
        lblSound->setObjectName(QString::fromUtf8("lblSound"));
        lblSound->setGeometry(QRect(100, 190, 201, 21));
        lblSound->setFont(font4);
        lblSound->setAlignment(Qt::AlignCenter);
        spinBoxNumber = new QSpinBox(EditingTimer);
        spinBoxNumber->setObjectName(QString::fromUtf8("spinBoxNumber"));
        spinBoxNumber->setGeometry(QRect(150, 280, 101, 22));
        spinBoxNumber->setFont(font4);
        spinBoxNumber->setCursor(QCursor(Qt::PointingHandCursor));
        spinBoxNumber->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(100);
        spinBoxNumber->setValue(15);

        retranslateUi(EditingTimer);

        QMetaObject::connectSlotsByName(EditingTimer);
    } // setupUi

    void retranslateUi(QDialog *EditingTimer)
    {
        EditingTimer->setWindowTitle(QCoreApplication::translate("EditingTimer", "Dialog", nullptr));
        btnCancel->setText(QCoreApplication::translate("EditingTimer", "Cancel", nullptr));
        lineEditName->setText(QCoreApplication::translate("EditingTimer", "Name", nullptr));
        btnSave->setText(QCoreApplication::translate("EditingTimer", "Save", nullptr));
        labelEdit->setText(QCoreApplication::translate("EditingTimer", "Edit the timer", nullptr));
        timeEditTime->setDisplayFormat(QCoreApplication::translate("EditingTimer", "HH:mm:ss", nullptr));
        lblNumber->setText(QCoreApplication::translate("EditingTimer", "Maximum number of signals:", nullptr));
        seletcSound->setCurrentText(QString());
        lblSound->setText(QCoreApplication::translate("EditingTimer", "Timer signal:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditingTimer: public Ui_EditingTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINGTIMER_H
