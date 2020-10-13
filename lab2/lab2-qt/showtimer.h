#ifndef SHOWTIMER_H
#define SHOWTIMER_H

#include <QDialog>
#include "mytimer.h"
#include "editingtimer.h"
#include <QStringListModel>

namespace Ui {
class ShowTimer;
}

class ShowTimer : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTimer(QVector<MyTimer*>& timers, QStringListModel *model = nullptr, QWidget *parent = nullptr);
    ~ShowTimer();
    void update_timer();
    void set_timer(int indexOfTimer);
private slots:
    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ShowTimer *ui;
    QStringListModel *model;
    QVector<MyTimer*>& timers;
    int indexOfTimer;
};

#endif // SHOWTIMER_H
