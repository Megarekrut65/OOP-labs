/********************************************************************************
** Form generated from reading UI file 'showtimer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWTIMER_H
#define UI_SHOWTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowTimer
{
public:
    QLabel *lblTimer;
    QLabel *lblTimerName;
    QLabel *lblType;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEdit;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnDelete;

    void setupUi(QDialog *ShowTimer)
    {
        if (ShowTimer->objectName().isEmpty())
            ShowTimer->setObjectName(QString::fromUtf8("ShowTimer"));
        ShowTimer->resize(460, 280);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShowTimer->sizePolicy().hasHeightForWidth());
        ShowTimer->setSizePolicy(sizePolicy);
        ShowTimer->setMinimumSize(QSize(460, 280));
        ShowTimer->setMaximumSize(QSize(460, 280));
        lblTimer = new QLabel(ShowTimer);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setGeometry(QRect(30, 90, 401, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(36);
        font.setItalic(true);
        lblTimer->setFont(font);
        lblTimer->setCursor(QCursor(Qt::ArrowCursor));
        lblTimer->setScaledContents(false);
        lblTimer->setAlignment(Qt::AlignCenter);
        lblTimer->setWordWrap(false);
        lblTimerName = new QLabel(ShowTimer);
        lblTimerName->setObjectName(QString::fromUtf8("lblTimerName"));
        lblTimerName->setGeometry(QRect(30, 30, 401, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Orator Std"));
        font1.setPointSize(36);
        lblTimerName->setFont(font1);
        lblTimerName->setCursor(QCursor(Qt::ArrowCursor));
        lblTimerName->setAutoFillBackground(false);
        lblTimerName->setScaledContents(false);
        lblTimerName->setAlignment(Qt::AlignCenter);
        lblTimerName->setWordWrap(false);
        lblTimerName->setMargin(0);
        lblTimerName->setIndent(-1);
        lblTimerName->setOpenExternalLinks(false);
        lblTimerName->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard);
        lblType = new QLabel(ShowTimer);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        lblType->setGeometry(QRect(170, 160, 111, 21));
        QFont font2;
        font2.setPointSize(14);
        lblType->setFont(font2);
        lblType->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(ShowTimer);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 210, 401, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnEdit = new QPushButton(horizontalLayoutWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setEnabled(true);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        btnEdit->setFont(font3);
        btnEdit->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnEdit);

        btnStart = new QPushButton(horizontalLayoutWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setFont(font3);
        btnStart->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnStart);

        btnPause = new QPushButton(horizontalLayoutWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(true);
        btnPause->setFont(font3);
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnPause);

        btnDelete = new QPushButton(horizontalLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(true);
        btnDelete->setFont(font3);
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnDelete);


        retranslateUi(ShowTimer);

        QMetaObject::connectSlotsByName(ShowTimer);
    } // setupUi

    void retranslateUi(QDialog *ShowTimer)
    {
        ShowTimer->setWindowTitle(QCoreApplication::translate("ShowTimer", "Dialog", nullptr));
        lblTimer->setText(QCoreApplication::translate("ShowTimer", "<h3 style=\"red\"> 10:20:30 </h3>", nullptr));
        lblTimerName->setText(QCoreApplication::translate("ShowTimer", "Timer Name", nullptr));
        lblType->setText(QCoreApplication::translate("ShowTimer", "Timer type", nullptr));
        btnEdit->setText(QCoreApplication::translate("ShowTimer", "Edit", nullptr));
        btnStart->setText(QCoreApplication::translate("ShowTimer", "Start", nullptr));
        btnPause->setText(QCoreApplication::translate("ShowTimer", "Pause", nullptr));
        btnDelete->setText(QCoreApplication::translate("ShowTimer", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowTimer: public Ui_ShowTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTIMER_H
