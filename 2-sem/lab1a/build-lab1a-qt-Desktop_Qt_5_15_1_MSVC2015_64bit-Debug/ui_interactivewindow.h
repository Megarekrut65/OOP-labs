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
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
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
        pushButtonBack->setGeometry(QRect(20, 410, 75, 31));
        QFont font1;
        font1.setPointSize(13);
        pushButtonBack->setFont(font1);
        verticalLayoutWidget = new QWidget(InteractiveWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 130, 221, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAdd = new QPushButton(verticalLayoutWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        QFont font2;
        font2.setPointSize(18);
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

        verticalLayoutWidget_2 = new QWidget(InteractiveWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(270, 40, 552, 361));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setPointSize(27);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tableView = new QTableView(verticalLayoutWidget_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(550, 310));
        tableView->setMaximumSize(QSize(550, 310));
        QFont font4;
        font4.setPointSize(12);
        tableView->setFont(font4);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->horizontalHeader()->setMinimumSectionSize(160);
        tableView->horizontalHeader()->setDefaultSectionSize(160);

        verticalLayout_2->addWidget(tableView);


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
