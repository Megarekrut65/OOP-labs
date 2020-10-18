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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ShowTimer
{
public:
    QPushButton *btnDelete;
    QPushButton *btnEdit;
    QPushButton *btnPause;
    QLabel *lblTimer;
    QPushButton *btnStart;
    QLabel *lblTimerName;
    QLabel *lblType;

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
        btnDelete = new QPushButton(ShowTimer);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(true);
        btnDelete->setGeometry(QRect(370, 200, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Mincho Demibold"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        btnDelete->setFont(font);
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));
        btnEdit = new QPushButton(ShowTimer);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setEnabled(true);
        btnEdit->setGeometry(QRect(30, 200, 61, 41));
        btnEdit->setFont(font);
        btnEdit->setCursor(QCursor(Qt::PointingHandCursor));
        btnPause = new QPushButton(ShowTimer);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(true);
        btnPause->setGeometry(QRect(260, 200, 61, 41));
        btnPause->setFont(font);
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimer = new QLabel(ShowTimer);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setGeometry(QRect(30, 90, 401, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(36);
        font1.setItalic(true);
        lblTimer->setFont(font1);
        lblTimer->setCursor(QCursor(Qt::ArrowCursor));
        lblTimer->setScaledContents(false);
        lblTimer->setAlignment(Qt::AlignCenter);
        lblTimer->setWordWrap(false);
        btnStart = new QPushButton(ShowTimer);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(140, 200, 61, 41));
        btnStart->setFont(font);
        btnStart->setCursor(QCursor(Qt::PointingHandCursor));
        lblTimerName = new QLabel(ShowTimer);
        lblTimerName->setObjectName(QString::fromUtf8("lblTimerName"));
        lblTimerName->setGeometry(QRect(30, 30, 401, 61));
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
        lblType = new QLabel(ShowTimer);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        lblType->setGeometry(QRect(170, 160, 111, 21));
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
        btnDelete->setText(QCoreApplication::translate("ShowTimer", "Delete", nullptr));
        btnEdit->setText(QCoreApplication::translate("ShowTimer", "Edit", nullptr));
        btnPause->setText(QCoreApplication::translate("ShowTimer", "Pause", nullptr));
        lblTimer->setText(QCoreApplication::translate("ShowTimer", "<h3 style=\"red\"> 10:20:30 </h3>", nullptr));
        btnStart->setText(QCoreApplication::translate("ShowTimer", "Start", nullptr));
        lblTimerName->setText(QCoreApplication::translate("ShowTimer", "Timer Name", nullptr));
        lblType->setText(QCoreApplication::translate("ShowTimer", "Timer type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowTimer: public Ui_ShowTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTIMER_H
