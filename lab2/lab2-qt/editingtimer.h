#ifndef EDITINGTIMER_H
#define EDITINGTIMER_H

#include <QDialog>
#include "mytimer.h"

namespace Ui {
class EditingTimer;
}

class EditingTimer : public QDialog
{
    Q_OBJECT

public:
    explicit EditingTimer(MyTimer* timer, QWidget *parent = nullptr);
    ~EditingTimer();

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

private:
    Ui::EditingTimer *ui;
    MyTimer* timer;
};

#endif // EDITINGTIMER_H
