#pragma once
#ifndef ADDINGTIMER_H
#define ADDINGTIMER_H

#include <QDialog>
#include "mytimer.h"
#include <QStandardItemModel>
#include "mysounds.h"

namespace Ui {
class AddingTimer;
}
/*!
* \brief Class to creating new timer and adding it to List View in window of class MainWindow
*
* Can select name, time, type, sound, number of signals of new timer
*/
class AddingTimer : public QDialog
{
    Q_OBJECT

public:
/*!
* Constructor that takes a pointer to array of timers and a pointer to model of List View in MainWindow
*/
    explicit AddingTimer( QVector<MyTimer*>* timers,
    QStandardItemModel *model, QWidget *parent = nullptr);
    ~AddingTimer();

private slots:
    void on_btnCreate_clicked();//creates new timer with entered data

    void on_btnCancel_clicked();//closes this window

    void on_seletcSound_activated(const QString &arg1);//plays the selected sound

private:
    Ui::AddingTimer *ui;
    QVector<MyTimer*>* timers;//pointer to array of timers in MainWindow
    QStandardItemModel *model;//pointer to model of List View in MainWindow
    Type set_type();//returns the type of timer given the selected radio button
    void add_sounds();//adds all sounds to combo box
};

#endif // ADDINGTIMER_H
