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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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

    void setupUi(QDialog *EditingTimer)
    {
        if (EditingTimer->objectName().isEmpty())
            EditingTimer->setObjectName(QString::fromUtf8("EditingTimer"));
        EditingTimer->resize(580, 350);
        EditingTimer->setMinimumSize(QSize(580, 350));
        EditingTimer->setMaximumSize(QSize(580, 350));
        btnCancel = new QPushButton(EditingTimer);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(330, 270, 61, 31));
        QFont font;
        font.setPointSize(11);
        btnCancel->setFont(font);
        lineEditName = new QLineEdit(EditingTimer);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(150, 130, 271, 41));
        QFont font1;
        font1.setPointSize(18);
        lineEditName->setFont(font1);
        lineEditName->setAlignment(Qt::AlignCenter);
        btnSave = new QPushButton(EditingTimer);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(190, 270, 61, 31));
        btnSave->setFont(font);
        labelEdit = new QLabel(EditingTimer);
        labelEdit->setObjectName(QString::fromUtf8("labelEdit"));
        labelEdit->setEnabled(true);
        labelEdit->setGeometry(QRect(40, 40, 491, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font2.setPointSize(48);
        labelEdit->setFont(font2);
        labelEdit->setAlignment(Qt::AlignCenter);
        timeEditTime = new QTimeEdit(EditingTimer);
        timeEditTime->setObjectName(QString::fromUtf8("timeEditTime"));
        timeEditTime->setGeometry(QRect(190, 200, 201, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nirmala UI"));
        font3.setPointSize(28);
        timeEditTime->setFont(font3);
        timeEditTime->setCursor(QCursor(Qt::PointingHandCursor));
        timeEditTime->setAlignment(Qt::AlignCenter);
        timeEditTime->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);

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
    } // retranslateUi

};

namespace Ui {
    class EditingTimer: public Ui_EditingTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINGTIMER_H
