/********************************************************************************
** Form generated from reading UI file 'benchmarkwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BENCHMARKWINDOW_H
#define UI_BENCHMARKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BenchmarkWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonMemory;
    QRadioButton *radioButtonText;
    QRadioButton *radioButtonBinary;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonBack;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QDialog *BenchmarkWindow)
    {
        if (BenchmarkWindow->objectName().isEmpty())
            BenchmarkWindow->setObjectName(QString::fromUtf8("BenchmarkWindow"));
        BenchmarkWindow->resize(827, 419);
        verticalLayoutWidget = new QWidget(BenchmarkWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 201, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonMemory = new QRadioButton(verticalLayoutWidget);
        radioButtonMemory->setObjectName(QString::fromUtf8("radioButtonMemory"));
        QFont font;
        font.setPointSize(15);
        radioButtonMemory->setFont(font);
        radioButtonMemory->setChecked(true);

        verticalLayout->addWidget(radioButtonMemory);

        radioButtonText = new QRadioButton(verticalLayoutWidget);
        radioButtonText->setObjectName(QString::fromUtf8("radioButtonText"));
        radioButtonText->setFont(font);

        verticalLayout->addWidget(radioButtonText);

        radioButtonBinary = new QRadioButton(verticalLayoutWidget);
        radioButtonBinary->setObjectName(QString::fromUtf8("radioButtonBinary"));
        radioButtonBinary->setFont(font);

        verticalLayout->addWidget(radioButtonBinary);

        verticalLayoutWidget_2 = new QWidget(BenchmarkWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(40, 170, 131, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonStart = new QPushButton(verticalLayoutWidget_2);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        QFont font1;
        font1.setPointSize(14);
        pushButtonStart->setFont(font1);

        verticalLayout_2->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(verticalLayoutWidget_2);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setFont(font1);

        verticalLayout_2->addWidget(pushButtonStop);

        verticalLayoutWidget_3 = new QWidget(BenchmarkWindow);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 370, 81, 41));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonBack = new QPushButton(verticalLayoutWidget_3);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));
        pushButtonBack->setFont(font1);

        verticalLayout_3->addWidget(pushButtonBack);

        verticalLayoutWidget_4 = new QWidget(BenchmarkWindow);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(220, 20, 601, 391));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);

        verticalLayout_4->addWidget(label);

        listWidget = new QListWidget(verticalLayoutWidget_4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setBatchSize(1000000000);

        verticalLayout_4->addWidget(listWidget);


        retranslateUi(BenchmarkWindow);

        QMetaObject::connectSlotsByName(BenchmarkWindow);
    } // setupUi

    void retranslateUi(QDialog *BenchmarkWindow)
    {
        BenchmarkWindow->setWindowTitle(QCoreApplication::translate("BenchmarkWindow", "Dialog", nullptr));
        radioButtonMemory->setText(QCoreApplication::translate("BenchmarkWindow", "Memory mode", nullptr));
        radioButtonText->setText(QCoreApplication::translate("BenchmarkWindow", "Text mode", nullptr));
        radioButtonBinary->setText(QCoreApplication::translate("BenchmarkWindow", "Binary mode", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("BenchmarkWindow", "Start testing", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("BenchmarkWindow", "Stop", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("BenchmarkWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("BenchmarkWindow", "Output:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BenchmarkWindow: public Ui_BenchmarkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BENCHMARKWINDOW_H
