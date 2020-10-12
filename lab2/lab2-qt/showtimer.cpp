#include "showtimer.h"
#include "ui_showtimer.h"

ShowTimer::ShowTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTimer)
{
    ui->setupUi(this);
    timer = nullptr;
}

ShowTimer::~ShowTimer()
{
    delete ui;
}
void ShowTimer::updateTimer()
{
    if(timer)
    {
        ui->lblTimerName->setText(timer->name);
        ui->lblTimer->setText(timer->getQStringTime());
    }
}
void ShowTimer::on_btnStart_clicked()
{
    timer->turnOn();
}

void ShowTimer::on_btnPause_clicked()
{
    timer->turnOff();
}

void ShowTimer::on_btnEdit_clicked()
{
    EditingTimer newWindow(timer);
    newWindow.setModal(true);
    newWindow.exec();
}

void ShowTimer::on_btnDelete_clicked()
{

}
void ShowTimer::setTimer(MyTimer* timer)
{
    if(this->timer) timer->openOutside = false;
    this->timer = timer;
    if(this->timer) timer->openOutside = true;
    updateTimer();
}
