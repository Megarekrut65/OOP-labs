/********************************************************************************
** Form generated from reading UI file 'showmonsters.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWMONSTERS_H
#define UI_SHOWMONSTERS_H

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

class Ui_ShowMonsters
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *ShowMonsters)
    {
        if (ShowMonsters->objectName().isEmpty())
            ShowMonsters->setObjectName(QString::fromUtf8("ShowMonsters"));
        ShowMonsters->resize(830, 470);
        ShowMonsters->setMinimumSize(QSize(830, 470));
        ShowMonsters->setMaximumSize(QSize(830, 470));
        verticalLayoutWidget = new QWidget(ShowMonsters);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 801, 391));
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

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->horizontalHeader()->setMinimumSectionSize(160);
        tableView->horizontalHeader()->setDefaultSectionSize(160);

        verticalLayout->addWidget(tableView);

        pushButtonClose = new QPushButton(ShowMonsters);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(380, 420, 75, 31));
        QFont font1;
        font1.setPointSize(16);
        pushButtonClose->setFont(font1);

        retranslateUi(ShowMonsters);

        QMetaObject::connectSlotsByName(ShowMonsters);
    } // setupUi

    void retranslateUi(QDialog *ShowMonsters)
    {
        ShowMonsters->setWindowTitle(QCoreApplication::translate("ShowMonsters", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ShowMonsters", "Monsters", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("ShowMonsters", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowMonsters: public Ui_ShowMonsters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWMONSTERS_H
