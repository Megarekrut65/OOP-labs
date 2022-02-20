/********************************************************************************
** Form generated from reading UI file 'showtimer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowTimer
{
public:
    QLabel *lblTimer;
    QLabel *lblType;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEdit;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnDelete;
    QLineEdit *lineTimerName;

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
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(36);
        font.setItalic(true);
        lblTimer->setFont(font);
        lblTimer->setCursor(QCursor(Qt::ArrowCursor));
        lblTimer->setScaledContents(false);
        lblTimer->setAlignment(Qt::AlignCenter);
        lblTimer->setWordWrap(false);
        lblType = new QLabel(ShowTimer);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        lblType->setGeometry(QRect(170, 170, 111, 21));
        QFont font1;
        font1.setPointSize(14);
        lblType->setFont(font1);
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
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Yu Mincho Demibold")});
        font2.setPointSize(10);
        font2.setBold(true);
        btnEdit->setFont(font2);
        btnEdit->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnEdit);

        btnStart = new QPushButton(horizontalLayoutWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setFont(font2);
        btnStart->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnStart);

        btnPause = new QPushButton(horizontalLayoutWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(true);
        btnPause->setFont(font2);
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnPause);

        btnDelete = new QPushButton(horizontalLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(true);
        btnDelete->setFont(font2);
        btnDelete->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnDelete);

        lineTimerName = new QLineEdit(ShowTimer);
        lineTimerName->setObjectName(QString::fromUtf8("lineTimerName"));
        lineTimerName->setGeometry(QRect(12, 9, 441, 81));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Nirmala UI")});
        font3.setPointSize(36);
        lineTimerName->setFont(font3);
        lineTimerName->setCursor(QCursor(Qt::SizeHorCursor));
        lineTimerName->setMouseTracking(false);
        lineTimerName->setFocusPolicy(Qt::NoFocus);
        lineTimerName->setAcceptDrops(false);
        lineTimerName->setAutoFillBackground(true);
        lineTimerName->setStyleSheet(QString::fromUtf8(""));
        lineTimerName->setMaxLength(32769);
        lineTimerName->setCursorPosition(0);
        lineTimerName->setAlignment(Qt::AlignCenter);
        lineTimerName->setDragEnabled(true);
        lineTimerName->setReadOnly(true);
        lineTimerName->setCursorMoveStyle(Qt::LogicalMoveStyle);

        retranslateUi(ShowTimer);

        QMetaObject::connectSlotsByName(ShowTimer);
    } // setupUi

    void retranslateUi(QDialog *ShowTimer)
    {
        ShowTimer->setWindowTitle(QCoreApplication::translate("ShowTimer", "Dialog", nullptr));
        lblTimer->setText(QCoreApplication::translate("ShowTimer", "<h3 style=\"red\"> 10:20:30 </h3>", nullptr));
        lblType->setText(QCoreApplication::translate("ShowTimer", "Timer type", nullptr));
        btnEdit->setText(QCoreApplication::translate("ShowTimer", "Edit", nullptr));
        btnStart->setText(QCoreApplication::translate("ShowTimer", "Start", nullptr));
        btnPause->setText(QCoreApplication::translate("ShowTimer", "Pause", nullptr));
        btnDelete->setText(QCoreApplication::translate("ShowTimer", "Delete", nullptr));
        lineTimerName->setText(QCoreApplication::translate("ShowTimer", "Timer Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowTimer: public Ui_ShowTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTIMER_H
