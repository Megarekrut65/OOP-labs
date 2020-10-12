#include "editingtimer.h"
#include "ui_editingtimer.h"

EditingTimer::EditingTimer(MyTimer* timer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditingTimer)
{
    ui->setupUi(this);
    this->timer = timer;
}

EditingTimer::~EditingTimer()
{
    delete ui;
}

void EditingTimer::on_btnSave_clicked()
{
    if(timer)
    {
        timer->name = ui->lineEditName->text();
        timer->setTime(ui->timeEditTime->time());
        timer->turnOn();
    }
    this->close();
}

void EditingTimer::on_btnCancel_clicked()
{
    this->close();
}
