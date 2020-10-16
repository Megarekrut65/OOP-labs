#ifndef EDITINGTIMER_H
#define EDITINGTIMER_H

#include <QDialog>
#include "mytimer.h"
#include <QStandardItemModel>
#include "my_colors.h"

namespace Ui {
class EditingTimer;
}

class EditingTimer : public QDialog
{
    Q_OBJECT

public:
    explicit EditingTimer(QVector<MyTimer*>& timers,
                          QStandardItemModel *model = nullptr,int indexOfTimer = 0, QWidget *parent = nullptr);
    ~EditingTimer();

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

private:
    Ui::EditingTimer *ui;
    QVector<MyTimer*>& timers;
    QStandardItemModel *model;
    int indexOfTimer;
    void turn_on_timer();
    void turn_off_timer();
};

#endif // EDITINGTIMER_H
