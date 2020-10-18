#pragma once
#ifndef NOTDISTURBMODE_H
#define NOTDISTURBMODE_H

#include <QDialog>
#include "timeperiod.h"

namespace Ui {
class NotDisturbMode;
}

class NotDisturbMode : public QDialog
{
    Q_OBJECT

public:
    explicit NotDisturbMode(TimePeriod& period, QWidget *parent = nullptr);
    ~NotDisturbMode();

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

private:
    Ui::NotDisturbMode *ui;
    TimePeriod& period;
};

#endif // NOTDISTURBMODE_H
