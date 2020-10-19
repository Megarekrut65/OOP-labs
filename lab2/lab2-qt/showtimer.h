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
/*!
* \brief Class that shows the user the selected timer in a separate window
*
* Can pause / start / delete the timer. And also only here can edit the timer
*
*/
class ShowTimer : public QDialog
{
    Q_OBJECT

public:
/*!
* Constructor that takes a reference to array of timers,
* reference to index of selected timer in MainWindow
* and a pointer to model of List View in MainWindow
*
*/
    explicit ShowTimer(QVector<MyTimer*>& timers, int& indexOfCurrentTimer, QStandardItemModel *model, QWidget *parent = nullptr);
    ~ShowTimer();
/*!
* Adds the name, time, and type of the specified timer to the window
*
*/
    void update_timer();
/*!
* \brief Changes the index of the timer
*
* \param indexOfTimer new index of timer that will be showed
*
*/
    void set_timer(int indexOfTimer);
/*!
* \brief Opens window with questions
*
* Before deleting the timer the user will receive a message with a question.
* \param that pointer to parent QWidget
* \param title name of message window
* \param sentence text with questions
* \returns - true if user pressed 'Yes'
* \returns - false if user pressed 'No' or closed this window
*/
    static bool questions_to_delete(QWidget* that, QString title, QString sentence);
private slots:
    void on_btnStart_clicked();//starts the timer and changes text-color of time

    void on_btnPause_clicked();//pauses the timer and changes text-color of time

    void on_btnEdit_clicked();//opens window to editing the timer

    void on_btnDelete_clicked();//deletes the timer from 'timers' and from List View. Closes this window

private:
    Ui::ShowTimer *ui;
    QStandardItemModel *model;//reference to array of timers in MainWindow
    QVector<MyTimer*>& timers;//pointer to model of List View in MainWindow
    int indexOfTimer;//index of showed timer
    int& indexOfCurrentTimer;//index of selected timer in MainWindow
    QString get_time_style();//returns QString of time with html style
    QString get_timer_type();//returns QString of time type
};

#endif // SHOWTIMER_H
