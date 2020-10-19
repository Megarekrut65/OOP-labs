#pragma once
#ifndef NOTDISTURBMODE_H
#define NOTDISTURBMODE_H

#include <QDialog>
#include "timeperiod.h"

namespace Ui {
class NotDisturbMode;
}
/*!
* \brief Class to editing 'Do not disturb mode'
*
* It is possible to set a period of time during which the timers
* will not play a sound when the time is up.
* Сan also turn off this mode
*
*/
class NotDisturbMode : public QDialog
{
    Q_OBJECT

public:
/*!
* Constructor that takes reference to time period for
* 'do not disturb mode' and adds it to window
*
*/
    explicit NotDisturbMode(TimePeriod& period, QWidget *parent = nullptr);
    ~NotDisturbMode();

private slots:
    void on_btnSave_clicked();//saves edited time period and writes it to file. If begin of the time period is greater than its 'end' it changes their places

    void on_btnCancel_clicked();//closes this window

private:
    Ui::NotDisturbMode *ui;
    TimePeriod& period;//time period for 'do not disturb mode'
};

#endif // NOTDISTURBMODE_H
