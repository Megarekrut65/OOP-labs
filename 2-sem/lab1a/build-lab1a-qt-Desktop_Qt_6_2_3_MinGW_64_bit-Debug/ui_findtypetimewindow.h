/********************************************************************************
** Form generated from reading UI file 'findtypetimewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDTYPETIMEWINDOW_H
#define UI_FINDTYPETIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindTypeTimeWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *radioButtonIncrease;
    QRadioButton *radioButtonRepeat;
    QRadioButton *radioButtonCure;
    QRadioButton *radioButtonParalize;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *FindTypeTimeWindow)
    {
        if (FindTypeTimeWindow->objectName().isEmpty())
            FindTypeTimeWindow->setObjectName(QString::fromUtf8("FindTypeTimeWindow"));
        FindTypeTimeWindow->resize(240, 320);
        FindTypeTimeWindow->setMinimumSize(QSize(240, 320));
        FindTypeTimeWindow->setMaximumSize(QSize(240, 320));
        verticalLayoutWidget = new QWidget(FindTypeTimeWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 0, 191, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        radioButtonIncrease = new QRadioButton(verticalLayoutWidget);
        radioButtonIncrease->setObjectName(QString::fromUtf8("radioButtonIncrease"));
        QFont font1;
        font1.setPointSize(12);
        radioButtonIncrease->setFont(font1);
        radioButtonIncrease->setChecked(true);

        verticalLayout->addWidget(radioButtonIncrease);

        radioButtonRepeat = new QRadioButton(verticalLayoutWidget);
        radioButtonRepeat->setObjectName(QString::fromUtf8("radioButtonRepeat"));
        radioButtonRepeat->setFont(font1);

        verticalLayout->addWidget(radioButtonRepeat);

        radioButtonCure = new QRadioButton(verticalLayoutWidget);
        radioButtonCure->setObjectName(QString::fromUtf8("radioButtonCure"));
        radioButtonCure->setFont(font1);

        verticalLayout->addWidget(radioButtonCure);

        radioButtonParalize = new QRadioButton(verticalLayoutWidget);
        radioButtonParalize->setObjectName(QString::fromUtf8("radioButtonParalize"));
        radioButtonParalize->setFont(font1);

        verticalLayout->addWidget(radioButtonParalize);

        verticalLayoutWidget_2 = new QWidget(FindTypeTimeWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 170, 221, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        verticalLayout_2->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(verticalLayoutWidget_2);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFont(font1);

        verticalLayout_2->addWidget(dateTimeEdit);

        horizontalLayoutWidget = new QWidget(FindTypeTimeWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 270, 221, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonOK = new QPushButton(horizontalLayoutWidget);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setFont(font1);

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(horizontalLayoutWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setFont(font1);

        horizontalLayout->addWidget(pushButtonCancel);


        retranslateUi(FindTypeTimeWindow);

        QMetaObject::connectSlotsByName(FindTypeTimeWindow);
    } // setupUi

    void retranslateUi(QDialog *FindTypeTimeWindow)
    {
        FindTypeTimeWindow->setWindowTitle(QCoreApplication::translate("FindTypeTimeWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FindTypeTimeWindow", "Type of attack", nullptr));
        radioButtonIncrease->setText(QCoreApplication::translate("FindTypeTimeWindow", "Increase damage", nullptr));
        radioButtonRepeat->setText(QCoreApplication::translate("FindTypeTimeWindow", "Repeat the attack", nullptr));
        radioButtonCure->setText(QCoreApplication::translate("FindTypeTimeWindow", "Cure yourself", nullptr));
        radioButtonParalize->setText(QCoreApplication::translate("FindTypeTimeWindow", "Paralyze the enemy", nullptr));
        label_2->setText(QCoreApplication::translate("FindTypeTimeWindow", "Maximum date and time the monster was created", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("FindTypeTimeWindow", "OK", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("FindTypeTimeWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindTypeTimeWindow: public Ui_FindTypeTimeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDTYPETIMEWINDOW_H
