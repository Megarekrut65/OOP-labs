#ifndef EDITINGTIMER_H
#define EDITINGTIMER_H

#include <QDialog>
#include "mytimer.h"
#include <QStringListModel>

namespace Ui {
class EditingTimer;
}

class EditingTimer : public QDialog
{
    Q_OBJECT

public:
    explicit EditingTimer(QVector<MyTimer*>& timers, QStringListModel *model = nullptr,int indexOfTimer = 0, QWidget *parent = nullptr);
    ~EditingTimer();

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

private:
    Ui::EditingTimer *ui;
    QVector<MyTimer*>& timers;
    QStringListModel *model;
    int indexOfTimer;
};

#endif // EDITINGTIMER_H
