#include "editingtimer.h"
#include "ui_editingtimer.h"

EditingTimer::EditingTimer(QVector<MyTimer*>& timers, QStandardItemModel *model, int indexOfTimer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditingTimer), timers(timers), model(model), indexOfTimer(indexOfTimer)
{
    ui->setupUi(this);
    if(indexOfTimer>= timers.size()) this->close();
    else
    {
        if(timers[indexOfTimer])
        {
            turn_off_timer();
            ui->lineEditName->setText(timers[indexOfTimer]->name);
            ui->timeEditTime->setTime(timers[indexOfTimer]->get_time());
        }
    }
}
void EditingTimer::turn_off_timer()
{
    timers[indexOfTimer]->turn_off();
    if(indexOfTimer>= timers.size() || !timers[indexOfTimer]) return;
    auto item = new QStandardItem(QString::number(indexOfTimer) + "." +
                                   timers[indexOfTimer]->get_QString_timer());
    item->setBackground(QBrush(MyColors::pausedItem));
    model->setItem(indexOfTimer, item);
}
void EditingTimer::turn_on_timer()
{
    if(indexOfTimer>= timers.size() || !timers[indexOfTimer]) return;
    auto item = new QStandardItem(QString::number(indexOfTimer) + "." +
                                   timers[indexOfTimer]->get_QString_timer());
    model->setItem(indexOfTimer, item);
    timers[indexOfTimer]->turn_on();
}
EditingTimer::~EditingTimer()
{
    turn_on_timer();
    model = nullptr;
    delete ui;
}

void EditingTimer::on_btnSave_clicked()
{
    if(timers[indexOfTimer] && model)
    {
        timers[indexOfTimer]->name = ui->lineEditName->text();
        timers[indexOfTimer]->set_time(ui->timeEditTime->time());
    }
    this->close();
}

void EditingTimer::on_btnCancel_clicked()
{
    this->close();
}
