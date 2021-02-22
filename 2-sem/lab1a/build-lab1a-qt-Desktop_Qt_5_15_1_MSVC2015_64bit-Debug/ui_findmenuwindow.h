/********************************************************************************
** Form generated from reading UI file 'findmenuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDMENUWINDOW_H
#define UI_FINDMENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindMenuWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButtonName;
    QPushButton *pushButtonHp;
    QPushButton *pushButtonType;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *FindMenuWindow)
    {
        if (FindMenuWindow->objectName().isEmpty())
            FindMenuWindow->setObjectName(QString::fromUtf8("FindMenuWindow"));
        FindMenuWindow->resize(200, 190);
        FindMenuWindow->setMinimumSize(QSize(200, 190));
        FindMenuWindow->setMaximumSize(QSize(200, 190));
        verticalLayoutWidget = new QWidget(FindMenuWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 181, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButtonName = new QPushButton(verticalLayoutWidget);
        pushButtonName->setObjectName(QString::fromUtf8("pushButtonName"));
        QFont font1;
        font1.setPointSize(12);
        pushButtonName->setFont(font1);

        verticalLayout->addWidget(pushButtonName);

        pushButtonHp = new QPushButton(verticalLayoutWidget);
        pushButtonHp->setObjectName(QString::fromUtf8("pushButtonHp"));
        pushButtonHp->setFont(font1);

        verticalLayout->addWidget(pushButtonHp);

        pushButtonType = new QPushButton(verticalLayoutWidget);
        pushButtonType->setObjectName(QString::fromUtf8("pushButtonType"));
        pushButtonType->setFont(font1);

        verticalLayout->addWidget(pushButtonType);

        pushButtonClose = new QPushButton(verticalLayoutWidget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        QFont font2;
        font2.setPointSize(16);
        pushButtonClose->setFont(font2);

        verticalLayout->addWidget(pushButtonClose);


        retranslateUi(FindMenuWindow);

        QMetaObject::connectSlotsByName(FindMenuWindow);
    } // setupUi

    void retranslateUi(QDialog *FindMenuWindow)
    {
        FindMenuWindow->setWindowTitle(QCoreApplication::translate("FindMenuWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FindMenuWindow", "Find menu", nullptr));
        pushButtonName->setText(QCoreApplication::translate("FindMenuWindow", "Find by name", nullptr));
        pushButtonHp->setText(QCoreApplication::translate("FindMenuWindow", "Find by hp and damage", nullptr));
        pushButtonType->setText(QCoreApplication::translate("FindMenuWindow", "Find by type and time", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("FindMenuWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindMenuWindow: public Ui_FindMenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDMENUWINDOW_H
