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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ShowTimer
{
public:
    QGroupBox *groupBoxTimer;
    QLabel *lblTimer;
    QPushButton *btnPause;
    QPushButton *btnStart;
    QLabel *lblTimerName;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QLabel *lblType;

    void setupUi(QDialog *ShowTimer)
    {
        if (ShowTimer->objectName().isEmpty())
            ShowTimer->setObjectName(QString::fromUtf8("ShowTimer"));
        ShowTimer->resize(500, 280);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShowTimer->sizePolicy().hasHeightForWidth());
        ShowTimer->setSizePolicy(sizePolicy);
        ShowTimer->setMinimumSize(QSize(500, 280));
        ShowTimer->setMaximumSize(QSize(500, 280));
        groupBoxTimer = new QGroupBox(ShowTimer);
        groupBoxTimer->setObjectName(QString::fromUtf8("groupBoxTimer"));
        groupBoxTimer->setEnabled(true);
        groupBoxTimer->setGeometry(QRect(10, 0, 480, 270));
        groupBoxTimer->setMinimumSize(QSize(480, 270));
        groupBoxTimer->setMaximumSize(QSize(480, 270));
        lblTimer = new QLabel(groupBoxTimer);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setGeometry(QRect(4, 81, 471, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Light"));
        font.setPointSize(48);
        lblTimer->setFont(font);
        lblTimer->setCursor(QCursor(Qt::ArrowCursor));
        lblTimer->setScaledContents(false);
        lblTimer->setAlignment(Qt::AlignCenter);
        lblTimer->setWordWrap(false);
        btnPause = new QPushButton(groupBoxTimer);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(true);
        btnPause->setGeometry(QRect(270, 190, 61, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        btnPause->setFont(font1);
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));
        btnStart = new QPushButton(groupBoxTimer);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(150, 190, 61, 41));
        btnStart->setFont(font1);
        btnStart->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimerName = new QLabel(groupBoxTimer);
        lblTimerName->setObjectName(QString::fromUtf8("lblTimerName"));
        lblTimerName->setGeometry(QRect(0, 30, 481, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Orator Std"));
        font2.setPointSize(36);
        lblTimerName->setFont(font2);
        lblTimerName->setCursor(QCursor(Qt::ArrowCursor));
        lblTimerName->setAutoFillBackground(false);
        lblTimerName->setScaledContents(false);
        lblTimerName->setAlignment(Qt::AlignCenter);
        lblTimerName->setWordWrap(false);
        lblTimerName->setMargin(0);
        lblTimerName->setIndent(-1);
        lblTimerName->setOpenExternalLinks(false);
        lblTimerName->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard);
        btnEdit = new QPushButton(groupBoxTimer);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setEnabled(true);
        btnEdit->setGeometry(QRect(40, 190, 61, 41));
        btnEdit->setFont(font1);
        btnEdit->setCursor(QCursor(Qt::PointingHandCursor));
        btnDelete = new QPushButton(groupBoxTimer);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(true);
        btnDelete->setGeometry(QRect(380, 190, 61, 41));
        btnDelete->setFont(font1);
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));
        lblType = new QLabel(groupBoxTimer);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        lblType->setGeometry(QRect(180, 155, 111, 21));
        QFont font3;
        font3.setPointSize(14);
        lblType->setFont(font3);
        lblType->setAlignment(Qt::AlignCenter);

        retranslateUi(ShowTimer);

        QMetaObject::connectSlotsByName(ShowTimer);
    } // setupUi

    void retranslateUi(QDialog *ShowTimer)
    {
        ShowTimer->setWindowTitle(QCoreApplication::translate("ShowTimer", "Dialog", nullptr));
        groupBoxTimer->setTitle(QCoreApplication::translate("ShowTimer", "GroupBoxTimer", nullptr));
        lblTimer->setText(QCoreApplication::translate("ShowTimer", "10:20:30", nullptr));
        btnPause->setText(QCoreApplication::translate("ShowTimer", "Pause", nullptr));
        btnStart->setText(QCoreApplication::translate("ShowTimer", "Start", nullptr));
        lblTimerName->setText(QCoreApplication::translate("ShowTimer", "Timer Name", nullptr));
        btnEdit->setText(QCoreApplication::translate("ShowTimer", "Edit", nullptr));
        btnDelete->setText(QCoreApplication::translate("ShowTimer", "Delete", nullptr));
        lblType->setText(QCoreApplication::translate("ShowTimer", "Timer type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowTimer: public Ui_ShowTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTIMER_H
