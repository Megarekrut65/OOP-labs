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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_EditingTimer
{
public:
    QGroupBox *groupBoxAdding;
    QTimeEdit *timeEditTime;
    QPushButton *btnSave;
    QLineEdit *lineEditName;
    QPushButton *btnCancel;
    QLabel *labelEdit;

    void setupUi(QDialog *EditingTimer)
    {
        if (EditingTimer->objectName().isEmpty())
            EditingTimer->setObjectName(QString::fromUtf8("EditingTimer"));
        EditingTimer->resize(580, 350);
        EditingTimer->setMinimumSize(QSize(580, 350));
        EditingTimer->setMaximumSize(QSize(580, 350));
        groupBoxAdding = new QGroupBox(EditingTimer);
        groupBoxAdding->setObjectName(QString::fromUtf8("groupBoxAdding"));
        groupBoxAdding->setEnabled(true);
        groupBoxAdding->setGeometry(QRect(10, 10, 560, 320));
        groupBoxAdding->setMinimumSize(QSize(560, 320));
        groupBoxAdding->setMaximumSize(QSize(560, 320));
        timeEditTime = new QTimeEdit(groupBoxAdding);
        timeEditTime->setObjectName(QString::fromUtf8("timeEditTime"));
        timeEditTime->setGeometry(QRect(180, 190, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(28);
        timeEditTime->setFont(font);
        timeEditTime->setCursor(QCursor(Qt::PointingHandCursor));
        timeEditTime->setAlignment(Qt::AlignCenter);
        timeEditTime->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        btnSave = new QPushButton(groupBoxAdding);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(180, 260, 61, 31));
        QFont font1;
        font1.setPointSize(11);
        btnSave->setFont(font1);
        lineEditName = new QLineEdit(groupBoxAdding);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(140, 120, 271, 41));
        QFont font2;
        font2.setPointSize(18);
        lineEditName->setFont(font2);
        lineEditName->setAlignment(Qt::AlignCenter);
        btnCancel = new QPushButton(groupBoxAdding);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(320, 260, 61, 31));
        btnCancel->setFont(font1);
        labelEdit = new QLabel(groupBoxAdding);
        labelEdit->setObjectName(QString::fromUtf8("labelEdit"));
        labelEdit->setEnabled(true);
        labelEdit->setGeometry(QRect(30, 30, 491, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font3.setPointSize(48);
        labelEdit->setFont(font3);
        labelEdit->setAlignment(Qt::AlignCenter);

        retranslateUi(EditingTimer);

        QMetaObject::connectSlotsByName(EditingTimer);
    } // setupUi

    void retranslateUi(QDialog *EditingTimer)
    {
        EditingTimer->setWindowTitle(QCoreApplication::translate("EditingTimer", "Dialog", nullptr));
        groupBoxAdding->setTitle(QCoreApplication::translate("EditingTimer", "GroupBoxAdding", nullptr));
        timeEditTime->setDisplayFormat(QCoreApplication::translate("EditingTimer", "HH:mm:ss", nullptr));
        btnSave->setText(QCoreApplication::translate("EditingTimer", "Save", nullptr));
        lineEditName->setText(QCoreApplication::translate("EditingTimer", "Name", nullptr));
        btnCancel->setText(QCoreApplication::translate("EditingTimer", "Cancel", nullptr));
        labelEdit->setText(QCoreApplication::translate("EditingTimer", "Edit new timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditingTimer: public Ui_EditingTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINGTIMER_H
