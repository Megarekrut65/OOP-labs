#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
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
using namespace mt;
QT_END_NAMESPACE
/*!
* \brief Timers (MyTimer) control class
*
* Class to save / add / start / pause / delete timers.
* It is possible to perform certain actions for all timers or only for one timer
*
* Can control the timers using the toolbar or menu
*
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/*!
*
* Constructor to initialize all variables. Some variables are read from files.
*
* The header timer is also started in the constructor,
* which reduces the time of all missed timers every second.
*
*/
    MainWindow(QWidget *parent = nullptr);
/*!
* Deletes all non-nullptr variables
*
*/
    ~MainWindow();
private slots:

    void on_listTimers_doubleClicked(const QModelIndex &index);//opens a separate window for the selected timer

    void on_actionQuit_triggered();//saves timers and close the app

    void on_actionStart_all_timers_triggered();// starts all timers and edits backgraund of List View

    void on_actionPause_all_timers_triggered();// pauses all timers and edits backgraund of List View

    void on_actionAdd_new_timer_triggered();//opens window for adding timer

    void on_actionDelete_all_timers_triggered();//shows a message with a question, if the answer is 'yes' it deletes all timers, otherwise it closes message

    void on_actionSound_on_triggered();//allows timers to play the signal and writes it to a file

    void on_actionSound_off_triggered();//prohibits timers to play the signal and writes it to a file

    void on_actionDo_not_disturb_mode_triggered();//opens window to edit "do not distrub mode"

    void on_actionStart_selected_timer_triggered();// starts the timer and edits backgraund of Item in List View

    void on_actionPause_selected_timer_triggered();// pauses the timer and edits backgraund of Item in List View

    void on_actionDelete_selected_timer_triggered();//shows a message with a question, if the answer is 'yes' it deletes the timer, otherwise it closes message

    void on_listTimers_clicked(const QModelIndex &index);//selectes the timer with index

    void on_actionShow_selected_timer_triggered();//opens a separate window for the selected timer

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;//model of List View
    QTimer *oneSecondTimer;//Timer to reduce the time of all timers
    QVector<MyTimer*> timers;//saves all timers
    ShowTimer* timerWindow;//window to showing selected timer
    bool allActive;//allows or disables all timers
    const QString timersPath;//path to file with all timers
    const QString periodPath;//path to file with information about 'do not disturb mode'
    const QString soundModePath;//path to file with 'soundMode'
    const QString allActivePath;//path to file with 'AllActive'
    QString statusBar;//text for status bar
    QString soundBar;//text for status bar
    QString notDisturbBar;//text for status bar
    QString fileModel;//file model in begin of file 'timersPath'
    int indexOfCurrentTimer;//index of timer that is selected or -1 if any timers aren't selected
    bool soundMode;//allows or disables sound of timers
    int indexOfShowedTimer;//index of timer that is open in a separate window
    TimePeriod notDisturbPeriod;//time period of 'do not disturb mode'
    QDateTime qString_to_DateTime(QString line);
    void edit_saved_timers(QDateTime savedDateTime);//takes away from timers time while the program was not active
    QTime get_time_after_saving(QDateTime savedDateTime);//determines how long the program has been inactive
    bool read_bool_variable_from_file(QString path, QString title);//reads file and if in file was "true" then returns true else return false. Before "true" or "false" in file is title - information about data
    void set_status_bar();//initializes status bar textes
    void set_list_model();//initializes List View
    void edit_file_with_bool_variable(QString path, QString title, bool value);//writes to file title and value
    void edit_status_bar(QString otherBar = "");//edits all status bar textes and adds to end 'otherBar'
    void start_header_timer();//starts 'oneSecondTimer'
    void update_all_timers();//changes the timer time and the text and color of the list. Writes all timers to file
    void read_all_timers_from_file();//reads timers from 'timersPath' and adds their to 'timers'
    void write_all_timers_to_file();//writes timers to 'timersPath' and clears timers;
    void show_the_timer(int index);//opens window for timer in 'timers' with 'index'
};
#endif // MAINWINDOW_H
