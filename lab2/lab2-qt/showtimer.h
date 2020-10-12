#ifndef SHOWTIMER_H
#define SHOWTIMER_H

#include <QDialog>
#include "mytimer.h"
#include "editingtimer.h"

namespace Ui {
class ShowTimer;
}

class ShowTimer : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTimer(QWidget *parent = nullptr);
    ~ShowTimer();
    void updateTimer();
    void setTimer(MyTimer* timer);
private slots:
    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ShowTimer *ui;
    MyTimer* timer;
};

#endif // SHOWTIMER_H
