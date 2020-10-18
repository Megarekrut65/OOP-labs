#pragma once
#ifndef SHOWTIMER_H
#define SHOWTIMER_H

#include <QDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include "mycolors.h"
#include "mytimer.h"
#include "editingtimer.h"

namespace Ui {
class ShowTimer;
}

class ShowTimer : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTimer(QVector<MyTimer*>& timers, int& indexOfCurrentTimer, QStandardItemModel *model = nullptr, QWidget *parent = nullptr);
    ~ShowTimer();
    void update_timer();
    void set_timer(int indexOfTimer);
    static bool questions_to_delete(QWidget* that, QString title, QString sentence);
private slots:
    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ShowTimer *ui;
    QStandardItemModel *model;
    QVector<MyTimer*>& timers;
    int indexOfTimer;
    int& indexOfCurrentTimer;
    QString get_time_style();
    QString get_timer_type();
};

#endif // SHOWTIMER_H
