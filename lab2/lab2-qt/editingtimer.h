#pragma once
#ifndef EDITINGTIMER_H
#define EDITINGTIMER_H

#include <QDialog>
#include "mytimer.h"
#include <QStandardItemModel>
#include <QLineEdit>
#include "mycolors.h"
#include "mysounds.h"

namespace Ui {
class EditingTimer;
}
/*!
* \brief Class to editing already created timers
*
* Can edit name, time, sound, number of signals of the timer,
* but can't edit the type of timer
*/
class EditingTimer : public QDialog
{
    Q_OBJECT

public:
/*!
*  Constructor that takes reference to time period for 'do not disturb mode' and adds it to window
*
*/
    explicit EditingTimer(QVector<MyTimer*>& timers,
                          QStandardItemModel *model,
                          int indexOfTimer,
                          QLineEdit* timerName,
                          QWidget *parent = nullptr);
    ~EditingTimer();

private slots:
    void on_btnSave_clicked();//edits timer with indexOfTimer in timers and edit the timer in List View

    void on_btnCancel_clicked();//closes this window

    void on_seletcSound_activated(const QString &arg1);//plays the selected sound

private:
    Ui::EditingTimer *ui;
    QVector<MyTimer*>& timers;//reference to array of timers in MainWindow
    QStandardItemModel *model;//pointer to model of List View in MainWindow
    QLineEdit* timerName;
    int indexOfTimer;//index of timer to need to edit
    void turn_on_timer();//starts timer with indexOfTimer after closing window and edits background color of item in List View
    void turn_off_timer();//pauses timer with indexOfTimer when opens window and edits background color of item in List View
    void add_sounds();//adds all sounds to combo box
};

#endif // EDITINGTIMER_H
