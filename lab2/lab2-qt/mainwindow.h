#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStandardItemModel>
#include <QFile>
#include "mytimer.h"
#include "addingtimer.h"
#include "showtimer.h"
#include "mycolors.h"
#include "timeperiod.h"
#include "notdisturbmode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_listTimers_doubleClicked(const QModelIndex &index);

    void on_actionQuit_triggered();

    void on_actionStart_all_timers_triggered();

    void on_actionPause_all_timers_triggered();

    void on_actionAdd_new_timer_triggered();

    void on_actionDelete_all_timers_triggered();

    void on_actionSound_on_triggered();

    void on_actionSound_off_triggered();

    void on_actionDo_not_disturb_mode_triggered();

    void on_actionStart_selected_timer_triggered();

    void on_actionPause_selected_timer_triggered();

    void on_actionDelete_selected_timer_triggered();

    void on_listTimers_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QTimer *oneSecondTimer;
    QVector<MyTimer*> timers;
    ShowTimer* timerWindow;
    bool AllActive;
    const QString timersPath;
    const QString periodPath;
    QString statusBar;
    QString soundBar;
    QString notDisturbBar;
    QString fileModel;
    int indexOfCurrentTimer;
    bool soundMode;
    int indexOfShowedTimer;
    TimePeriod notDisturbPeriod;
    void set_status_bar();
    void start_header_timer();
    void update_all_timers();
    void read_all_timers_from_file();
    void write_all_timers_to_file();
};
#endif // MAINWINDOW_H
