#ifndef ADDINGTIMER_H
#define ADDINGTIMER_H

#include <QDialog>
#include "mytimer.h"
#include <QStringListModel>

namespace Ui {
class AddingTimer;
}

class AddingTimer : public QDialog
{
    Q_OBJECT

public:
    explicit AddingTimer( QVector<MyTimer*>* timers = nullptr,
    QStringListModel *model = nullptr, QWidget *parent = nullptr);
    ~AddingTimer();

private slots:
    void on_btnCreate_clicked();

    void on_btnCancel_clicked();

private:
    Ui::AddingTimer *ui;
    QVector<MyTimer*>* timers;
    QStringListModel *model;
};

#endif // ADDINGTIMER_H
