#include "editingtimer.h"
#include "ui_editingtimer.h"

EditingTimer::EditingTimer(MyTimer* timer, QStringListModel *model, int indexOfTimer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditingTimer)
{
    ui->setupUi(this);
    this->timer = timer;
    if(timer)
    {
        timer->turnOff();
        ui->lineEditName->setText(timer->name);
        ui->timeEditTime->setTime(timer->getTime());
    }
    this->model = model;
    this->indexOfTimer = indexOfTimer;
}

EditingTimer::~EditingTimer()
{
    timer = nullptr;
    model = nullptr;
    delete ui;
}

void EditingTimer::on_btnSave_clicked()
{
    if(timer && model)
    {
        timer->name = ui->lineEditName->text();
        timer->setTime(ui->timeEditTime->time());
        QModelIndex index = model->index(indexOfTimer);
        model->setData(index, timer->getQStringTimer());
    }
    this->close();
}

void EditingTimer::on_btnCancel_clicked()
{
    this->close();
}
