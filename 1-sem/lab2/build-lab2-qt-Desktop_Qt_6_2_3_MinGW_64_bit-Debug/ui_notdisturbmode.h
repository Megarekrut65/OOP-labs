/********************************************************************************
** Form generated from reading UI file 'notdisturbmode.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTDISTURBMODE_H
#define UI_NOTDISTURBMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotDisturbMode
{
public:
    QLabel *lblTitle;
    QTimeEdit *timeEditBegin;
    QTimeEdit *timeEditEnd;
    QLabel *lblBegin;
    QLabel *lblEnd;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QRadioButton *radioButtonOn;
    QRadioButton *radioButtonOff;

    void setupUi(QDialog *NotDisturbMode)
    {
        if (NotDisturbMode->objectName().isEmpty())
            NotDisturbMode->setObjectName(QString::fromUtf8("NotDisturbMode"));
        NotDisturbMode->resize(400, 270);
        NotDisturbMode->setMinimumSize(QSize(400, 270));
        NotDisturbMode->setMaximumSize(QSize(400, 270));
        lblTitle = new QLabel(NotDisturbMode);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(10, 20, 381, 101));
        QFont font;
        font.setPointSize(16);
        lblTitle->setFont(font);
        lblTitle->setAlignment(Qt::AlignCenter);
        timeEditBegin = new QTimeEdit(NotDisturbMode);
        timeEditBegin->setObjectName(QString::fromUtf8("timeEditBegin"));
        timeEditBegin->setGeometry(QRect(20, 160, 141, 31));
        QFont font1;
        font1.setPointSize(20);
        timeEditBegin->setFont(font1);
        timeEditBegin->setAlignment(Qt::AlignCenter);
        timeEditEnd = new QTimeEdit(NotDisturbMode);
        timeEditEnd->setObjectName(QString::fromUtf8("timeEditEnd"));
        timeEditEnd->setGeometry(QRect(240, 160, 141, 31));
        timeEditEnd->setFont(font1);
        timeEditEnd->setAlignment(Qt::AlignCenter);
        lblBegin = new QLabel(NotDisturbMode);
        lblBegin->setObjectName(QString::fromUtf8("lblBegin"));
        lblBegin->setGeometry(QRect(20, 130, 141, 21));
        QFont font2;
        font2.setPointSize(12);
        lblBegin->setFont(font2);
        lblBegin->setAlignment(Qt::AlignCenter);
        lblEnd = new QLabel(NotDisturbMode);
        lblEnd->setObjectName(QString::fromUtf8("lblEnd"));
        lblEnd->setGeometry(QRect(240, 130, 141, 21));
        lblEnd->setFont(font2);
        lblEnd->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(NotDisturbMode);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 220, 361, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnSave = new QPushButton(horizontalLayoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(horizontalLayoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        radioButtonOn = new QRadioButton(NotDisturbMode);
        radioButtonOn->setObjectName(QString::fromUtf8("radioButtonOn"));
        radioButtonOn->setGeometry(QRect(120, 200, 71, 17));
        QFont font3;
        font3.setPointSize(10);
        radioButtonOn->setFont(font3);
        radioButtonOff = new QRadioButton(NotDisturbMode);
        radioButtonOff->setObjectName(QString::fromUtf8("radioButtonOff"));
        radioButtonOff->setGeometry(QRect(220, 200, 71, 17));
        radioButtonOff->setFont(font3);

        retranslateUi(NotDisturbMode);

        QMetaObject::connectSlotsByName(NotDisturbMode);
    } // setupUi

    void retranslateUi(QDialog *NotDisturbMode)
    {
        NotDisturbMode->setWindowTitle(QCoreApplication::translate("NotDisturbMode", "Dialog", nullptr));
        lblTitle->setText(QCoreApplication::translate("NotDisturbMode", "Specify the time period\n"
"when no notifications will be received\n"
"from the program", nullptr));
        timeEditBegin->setDisplayFormat(QCoreApplication::translate("NotDisturbMode", "HH:mm:ss", nullptr));
        timeEditEnd->setDisplayFormat(QCoreApplication::translate("NotDisturbMode", "HH:mm:ss", nullptr));
        lblBegin->setText(QCoreApplication::translate("NotDisturbMode", "Begin", nullptr));
        lblEnd->setText(QCoreApplication::translate("NotDisturbMode", "End", nullptr));
        btnSave->setText(QCoreApplication::translate("NotDisturbMode", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("NotDisturbMode", "Cancel", nullptr));
        radioButtonOn->setText(QCoreApplication::translate("NotDisturbMode", "Turn on", nullptr));
        radioButtonOff->setText(QCoreApplication::translate("NotDisturbMode", "Turn off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotDisturbMode: public Ui_NotDisturbMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTDISTURBMODE_H
