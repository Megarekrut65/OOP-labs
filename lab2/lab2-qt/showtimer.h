#ifndef SHOWTIMER_H
#define SHOWTIMER_H

#include <QDialog>
#include "mytimer.h"
#include "editingandaddingtimers.h"

namespace Ui {
class ShowTimer;
}

class ShowTimer : public QDialog
{
    Q_OBJECT

public:
    MyTimer* timer;
    explicit ShowTimer(QWidget *parent = nullptr, MyTimer* timer = nullptr);
    ~ShowTimer();
    void updateTimer();
private slots:
    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ShowTimer *ui;
};

#endif // SHOWTIMER_H
