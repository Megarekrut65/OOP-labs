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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindMenuWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonName;
    QPushButton *pushButtonHp;
    QPushButton *pushButtonType;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *FindMenuWindow)
    {
        if (FindMenuWindow->objectName().isEmpty())
            FindMenuWindow->setObjectName(QString::fromUtf8("FindMenuWindow"));
        FindMenuWindow->resize(200, 180);
        FindMenuWindow->setMinimumSize(QSize(200, 180));
        FindMenuWindow->setMaximumSize(QSize(200, 180));
        verticalLayoutWidget = new QWidget(FindMenuWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 181, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonName = new QPushButton(verticalLayoutWidget);
        pushButtonName->setObjectName(QString::fromUtf8("pushButtonName"));
        QFont font;
        font.setPointSize(12);
        pushButtonName->setFont(font);

        verticalLayout->addWidget(pushButtonName);

        pushButtonHp = new QPushButton(verticalLayoutWidget);
        pushButtonHp->setObjectName(QString::fromUtf8("pushButtonHp"));
        pushButtonHp->setFont(font);

        verticalLayout->addWidget(pushButtonHp);

        pushButtonType = new QPushButton(verticalLayoutWidget);
        pushButtonType->setObjectName(QString::fromUtf8("pushButtonType"));
        pushButtonType->setFont(font);

        verticalLayout->addWidget(pushButtonType);

        pushButtonClose = new QPushButton(FindMenuWindow);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(50, 140, 91, 33));
        QFont font1;
        font1.setPointSize(16);
        pushButtonClose->setFont(font1);

        retranslateUi(FindMenuWindow);

        QMetaObject::connectSlotsByName(FindMenuWindow);
    } // setupUi

    void retranslateUi(QDialog *FindMenuWindow)
    {
        FindMenuWindow->setWindowTitle(QCoreApplication::translate("FindMenuWindow", "Dialog", nullptr));
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
