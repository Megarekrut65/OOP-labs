#include "editingtimer.h"
#include "ui_editingtimer.h"

EditingTimer::EditingTimer(QVector<MyTimer*>& timers, QStringListModel *model, int indexOfTimer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditingTimer), timers(timers), model(model), indexOfTimer(indexOfTimer)
{
    ui->setupUi(this);
    if(indexOfTimer>= timers.size()) this->close();
    else
    {
        if(timers[indexOfTimer])
        {
            timers[indexOfTimer]->turn_off();
            ui->lineEditName->setText(timers[indexOfTimer]->name);
            ui->timeEditTime->setTime(timers[indexOfTimer]->get_time());
        }
    }
}

EditingTimer::~EditingTimer()
{
    model = nullptr;
    delete ui;
}

void EditingTimer::on_btnSave_clicked()
{
    if(timers[indexOfTimer] && model)
    {
        timers[indexOfTimer]->name = ui->lineEditName->text();
        timers[indexOfTimer]->set_time(ui->timeEditTime->time());
        QModelIndex index = model->index(indexOfTimer);
        model->setData(index, timers[indexOfTimer]->get_qString_timer());
    }
    this->close();
}

void EditingTimer::on_btnCancel_clicked()
{
    this->close();
}
