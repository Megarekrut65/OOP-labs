/********************************************************************************
** Form generated from reading UI file 'editingandaddingtimers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINGANDADDINGTIMERS_H
#define UI_EDITINGANDADDINGTIMERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_EditingAndAddingTimers
{
public:
    QGroupBox *groupBoxAdding;
    QTimeEdit *timeEditAdd;
    QPushButton *btnCreate;
    QLineEdit *lineEditNameTimer;
    QPushButton *btnCancel;
    QLabel *labelAdd;

    void setupUi(QDialog *EditingAndAddingTimers)
    {
        if (EditingAndAddingTimers->objectName().isEmpty())
            EditingAndAddingTimers->setObjectName(QString::fromUtf8("EditingAndAddingTimers"));
        EditingAndAddingTimers->resize(580, 350);
        EditingAndAddingTimers->setMinimumSize(QSize(580, 350));
        EditingAndAddingTimers->setMaximumSize(QSize(580, 350));
        groupBoxAdding = new QGroupBox(EditingAndAddingTimers);
        groupBoxAdding->setObjectName(QString::fromUtf8("groupBoxAdding"));
        groupBoxAdding->setEnabled(true);
        groupBoxAdding->setGeometry(QRect(10, 10, 560, 320));
        groupBoxAdding->setMinimumSize(QSize(560, 320));
        groupBoxAdding->setMaximumSize(QSize(560, 320));
        timeEditAdd = new QTimeEdit(groupBoxAdding);
        timeEditAdd->setObjectName(QString::fromUtf8("timeEditAdd"));
        timeEditAdd->setGeometry(QRect(180, 190, 201, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(28);
        timeEditAdd->setFont(font);
        timeEditAdd->setCursor(QCursor(Qt::PointingHandCursor));
        timeEditAdd->setAlignment(Qt::AlignCenter);
        timeEditAdd->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        btnCreate = new QPushButton(groupBoxAdding);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setGeometry(QRect(180, 260, 61, 31));
        QFont font1;
        font1.setPointSize(11);
        btnCreate->setFont(font1);
        lineEditNameTimer = new QLineEdit(groupBoxAdding);
        lineEditNameTimer->setObjectName(QString::fromUtf8("lineEditNameTimer"));
        lineEditNameTimer->setGeometry(QRect(140, 120, 271, 41));
        QFont font2;
        font2.setPointSize(18);
        lineEditNameTimer->setFont(font2);
        lineEditNameTimer->setAlignment(Qt::AlignCenter);
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

        retranslateUi(EditingAndAddingTimers);

        QMetaObject::connectSlotsByName(EditingAndAddingTimers);
    } // setupUi

    void retranslateUi(QDialog *EditingAndAddingTimers)
    {
        EditingAndAddingTimers->setWindowTitle(QCoreApplication::translate("EditingAndAddingTimers", "Dialog", nullptr));
        groupBoxAdding->setTitle(QCoreApplication::translate("EditingAndAddingTimers", "GroupBoxAdding", nullptr));
        timeEditAdd->setDisplayFormat(QCoreApplication::translate("EditingAndAddingTimers", "HH:mm:ss", nullptr));
        btnCreate->setText(QCoreApplication::translate("EditingAndAddingTimers", "Create", nullptr));
        lineEditNameTimer->setText(QCoreApplication::translate("EditingAndAddingTimers", "Enter timer name...", nullptr));
        btnCancel->setText(QCoreApplication::translate("EditingAndAddingTimers", "Cancel", nullptr));
        labelAdd->setText(QCoreApplication::translate("EditingAndAddingTimers", "Add new timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditingAndAddingTimers: public Ui_EditingAndAddingTimers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINGANDADDINGTIMERS_H
