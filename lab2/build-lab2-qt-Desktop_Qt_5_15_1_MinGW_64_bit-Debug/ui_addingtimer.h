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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddingTimer
{
public:
    QGroupBox *groupBoxAdding;
    QTimeEdit *timeAdd;
    QPushButton *btnCreate;
    QLineEdit *lineAddName;
    QPushButton *btnCancel;
    QLabel *labelAdd;

    void setupUi(QDialog *AddingTimer)
    {
        if (AddingTimer->objectName().isEmpty())
            AddingTimer->setObjectName(QString::fromUtf8("AddingTimer"));
        AddingTimer->resize(580, 350);
        AddingTimer->setMinimumSize(QSize(580, 350));
        AddingTimer->setMaximumSize(QSize(580, 350));
        groupBoxAdding = new QGroupBox(AddingTimer);
        groupBoxAdding->setObjectName(QString::fromUtf8("groupBoxAdding"));
        groupBoxAdding->setEnabled(true);
        groupBoxAdding->setGeometry(QRect(10, 10, 560, 320));
        groupBoxAdding->setMinimumSize(QSize(560, 320));
        groupBoxAdding->setMaximumSize(QSize(560, 320));
        timeAdd = new QTimeEdit(groupBoxAdding);
        timeAdd->setObjectName(QString::fromUtf8("timeAdd"));
        timeAdd->setGeometry(QRect(180, 190, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(28);
        timeAdd->setFont(font);
        timeAdd->setCursor(QCursor(Qt::PointingHandCursor));
        timeAdd->setAlignment(Qt::AlignCenter);
        timeAdd->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        btnCreate = new QPushButton(groupBoxAdding);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setGeometry(QRect(180, 260, 61, 31));
        QFont font1;
        font1.setPointSize(11);
        btnCreate->setFont(font1);
        lineAddName = new QLineEdit(groupBoxAdding);
        lineAddName->setObjectName(QString::fromUtf8("lineAddName"));
        lineAddName->setGeometry(QRect(140, 120, 271, 41));
        QFont font2;
        font2.setPointSize(18);
        lineAddName->setFont(font2);
        lineAddName->setAlignment(Qt::AlignCenter);
        btnCancel = new QPushButton(groupBoxAdding);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(320, 260, 61, 31));
        btnCancel->setFont(font1);
        labelAdd = new QLabel(groupBoxAdding);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setEnabled(true);
        labelAdd->setGeometry(QRect(30, 30, 491, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font3.setPointSize(48);
        labelAdd->setFont(font3);
        labelAdd->setAlignment(Qt::AlignCenter);

        retranslateUi(AddingTimer);

        QMetaObject::connectSlotsByName(AddingTimer);
    } // setupUi

    void retranslateUi(QDialog *AddingTimer)
    {
        AddingTimer->setWindowTitle(QCoreApplication::translate("AddingTimer", "Dialog", nullptr));
        groupBoxAdding->setTitle(QCoreApplication::translate("AddingTimer", "GroupBoxAdding", nullptr));
        timeAdd->setDisplayFormat(QCoreApplication::translate("AddingTimer", "HH:mm:ss", nullptr));
        btnCreate->setText(QCoreApplication::translate("AddingTimer", "Create", nullptr));
        lineAddName->setText(QCoreApplication::translate("AddingTimer", "Enter timer name...", nullptr));
        btnCancel->setText(QCoreApplication::translate("AddingTimer", "Cancel", nullptr));
        labelAdd->setText(QCoreApplication::translate("AddingTimer", "Add new timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddingTimer: public Ui_AddingTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINGTIMER_H
