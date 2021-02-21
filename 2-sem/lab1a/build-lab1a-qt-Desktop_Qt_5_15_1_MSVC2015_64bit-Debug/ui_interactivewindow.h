/********************************************************************************
** Form generated from reading UI file 'interactivewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIVEWINDOW_H
#define UI_INTERACTIVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InteractiveWindow
{
public:
    QLabel *label;
    QPushButton *pushButtonBack;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonFind;
    QLabel *label_2;
    QTableView *tableView;

    void setupUi(QDialog *InteractiveWindow)
    {
        if (InteractiveWindow->objectName().isEmpty())
            InteractiveWindow->setObjectName(QString::fromUtf8("InteractiveWindow"));
        InteractiveWindow->resize(840, 460);
        InteractiveWindow->setMinimumSize(QSize(840, 460));
        InteractiveWindow->setMaximumSize(QSize(840, 460));
        label = new QLabel(InteractiveWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 301, 121));
        QFont font;
        font.setPointSize(39);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButtonBack = new QPushButton(InteractiveWindow);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(750, 420, 75, 31));
        QFont font1;
        font1.setPointSize(13);
        pushButtonBack->setFont(font1);
        verticalLayoutWidget = new QWidget(InteractiveWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 130, 251, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAdd = new QPushButton(verticalLayoutWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        QFont font2;
        font2.setPointSize(20);
        pushButtonAdd->setFont(font2);

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonEdit = new QPushButton(verticalLayoutWidget);
        pushButtonEdit->setObjectName(QString::fromUtf8("pushButtonEdit"));
        pushButtonEdit->setFont(font2);

        verticalLayout->addWidget(pushButtonEdit);

        pushButtonDelete = new QPushButton(verticalLayoutWidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setFont(font2);

        verticalLayout->addWidget(pushButtonDelete);

        pushButtonFind = new QPushButton(verticalLayoutWidget);
        pushButtonFind->setObjectName(QString::fromUtf8("pushButtonFind"));
        pushButtonFind->setFont(font2);

        verticalLayout->addWidget(pushButtonFind);

        label_2 = new QLabel(InteractiveWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 50, 491, 41));
        QFont font3;
        font3.setPointSize(27);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);
        tableView = new QTableView(InteractiveWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(330, 100, 490, 310));
        tableView->setMinimumSize(QSize(490, 310));
        tableView->setMaximumSize(QSize(490, 310));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        retranslateUi(InteractiveWindow);

        QMetaObject::connectSlotsByName(InteractiveWindow);
    } // setupUi

    void retranslateUi(QDialog *InteractiveWindow)
    {
        InteractiveWindow->setWindowTitle(QCoreApplication::translate("InteractiveWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("InteractiveWindow", "Menu", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("InteractiveWindow", "Back", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("InteractiveWindow", "Add new monster", nullptr));
        pushButtonEdit->setText(QCoreApplication::translate("InteractiveWindow", "Edit the monster", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("InteractiveWindow", "Delete the monster", nullptr));
        pushButtonFind->setText(QCoreApplication::translate("InteractiveWindow", "Find monsters", nullptr));
        label_2->setText(QCoreApplication::translate("InteractiveWindow", "All monsters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InteractiveWindow: public Ui_InteractiveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIVEWINDOW_H
